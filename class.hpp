#pragma once
 
auto replace(std::string& str, const std::string& from, const std::string& to, unsigned count = 1337) -> void
{
	std::string::size_type prev_pos{ 0 };

	for (auto i = 0U; i < count; ++i)
	{
		if (const auto pos = str.find(from, prev_pos); pos != std::string::npos)
		{
			str.replace(pos, std::size(from), to);
			prev_pos = pos;
			continue;
		}
		break;
	}
}

struct parametr {
	std::string type;
	std::string name;
};

class c_Property;

class c_Method
{
private:
	friend class c_Property;
	MethodInfo* method_info;
	uintptr_t rva;
	std::string name;
	std::string return_type;
	std::vector<parametr> parametrs;
	int param_count;
	bool is_static = false;
public:
	c_Method() {}

	c_Method(MethodInfo* method_info_) {
		if (!method_info_) return;
		parametr par;
		method_info = method_info_;
		if ((il2cpp_api::il2cpp_method_get_flags(method_info, reinterpret_cast<uint32_t*>(method_info->iflags)) & METHOD_ATTRIBUTE_STATIC) != 0)
			is_static = true;
		name = il2cpp_api::il2cpp_method_get_name(method_info);
		return_type = il2cpp_api::il2cpp_type_get_name(il2cpp_api::il2cpp_method_get_return_type(method_info));
		param_count = il2cpp_api::il2cpp_method_get_param_count(method_info);
		for (int i = 0; i < param_count; i++) {
			par.name = il2cpp_api::il2cpp_method_get_param_name(method_info, i);
			par.type = il2cpp_api::il2cpp_type_get_name(il2cpp_api::il2cpp_method_get_param(method_info, i));

			parametrs.push_back(par);
		}
		rva = (uintptr_t)method_info->methodPointer - module_base;

		replace(name, ".", "_");
		replace(name, "/", "_");
		replace(name, "<", "_");
		replace(name, ">", "_");
		replace(name, "`", "_");
		replace(name, "|", "_");
	}

	std::string& get_name() {
		return name;
	}

	std::string& get_return_type() {
		return return_type;
	}

	parametr& get_parametr(int index) {
		return parametrs[index];
	}

	int get_parametrs_count() {
		return param_count;
	}

	uintptr_t get_rva(){
		return rva;
	}

	bool get_is_static() {
		return is_static;
	}
};

class c_Field 
{
private:
	std::string name;
	std::string type;
	int offset;
	bool is_static = false;
public:
	FieldInfo* field_info;
	c_Field() {}

	c_Field(FieldInfo* field_info_) {
		if (!field_info_) return;
		field_info = field_info_;
		name = il2cpp_api::il2cpp_field_get_name(field_info);
		type = il2cpp_api::il2cpp_type_get_name(il2cpp_api::il2cpp_field_get_type(field_info));
		Il2CppType* type = il2cpp_api::il2cpp_field_get_type(field_info);
		if ((type->attrs) & (FIELD_ATTRIBUTE_STATIC))
			is_static = true;
		offset = il2cpp_api::il2cpp_field_get_offset(field_info);

		replace(name, ".", "_");
		replace(name, "/", "_");
		replace(name, "<", "_");
		replace(name, ">", "_");
		replace(name, "`", "_");
		replace(name, "|", "_");
	}

	std::string& get_name() {
		return name;
	}

	std::string& get_type() {
		return type;
	}

	int get_offset() {
		return offset;
	}

	bool get_is_static() {
		return is_static;
	}
};

class c_Property : private c_Method
{
private:
	PropertyInfo* property_info;
public:
	c_Property() {}

	c_Property(PropertyInfo* property_info_) {
		if (!property_info_) return;
		property_info = property_info_;
		c_Method method = c_Method(il2cpp_api::il2cpp_property_get_get_method(property_info));
		name = method.get_name();
		return_type = method.get_return_type();
		for (auto par : method.parametrs)
			parametrs.push_back(par);
	}

	c_Method convert() {
		c_Method method;
		method.name = name;
		method.return_type = return_type;
		method.parametrs = parametrs;
		return method;
	}
};

class c_Klass
{
private:
	std::string name;
	std::string name_space;
	std::string assembly_name;
	std::vector<c_Method> method_list;
	std::vector<c_Field> field_list;
public:
	Il2CppClass* il2cpp_class;
	void parse_methods() {
		MethodInfo* il2cpp_method;
		void* iter = nullptr;

		while ((il2cpp_method = il2cpp_api::il2cpp_class_get_methods(il2cpp_class, &iter)) != nullptr) {
			if (!il2cpp_method) continue;
			c_Method method = c_Method(il2cpp_method);
			method_list.push_back(method);
		}
	}

	void parse_fields() {
		FieldInfo* il2cpp_field;
		void* iter = nullptr;

		while ((il2cpp_field = il2cpp_api::il2cpp_class_get_fields(il2cpp_class, &iter)) != nullptr) {
			if (!il2cpp_field) continue;
			c_Field field = c_Field(il2cpp_field);
			field_list.push_back(field);
		}
	}

	void parse_properties() {
		PropertyInfo* il2cpp_property;
		void* iter = nullptr;
		
		while ((il2cpp_property = il2cpp_api::il2cpp_class_get_properties(il2cpp_class, &iter)) != nullptr) {
			if (!il2cpp_property) continue;
			c_Property property_ = c_Property(il2cpp_property);
			method_list.push_back(property_.convert());
		}
	}

	c_Klass(Il2CppClass* il2cpp_class_) {
		if (!il2cpp_class_) return;
		il2cpp_class = il2cpp_class_;
		name = il2cpp_api::il2cpp_class_get_name(il2cpp_class);
		name_space = il2cpp_api::il2cpp_class_get_namespace(il2cpp_class);
		assembly_name = il2cpp_api::il2cpp_class_get_assemblyname(il2cpp_class);
		parse_methods();
		parse_fields();
		parse_properties();
		replace(name, ".", "_");
		replace(name, "/", "_");
		replace(name, "<", "_");
		replace(name, ">", "_");
		replace(name, "`", "_");
		replace(name, "|", "_");
		replace(name_space, ".", "_");
		replace(name_space, "/", "_");
		replace(name_space, "<", "_");
		replace(name_space, ">", "_");
		replace(name_space, "`", "_");
		replace(name_space, "|", "_");
	}

	size_t get_method_count() {
		return method_list.size();
	}

	c_Field& get_field(int index) {
		return field_list[index];
	}

	c_Method& get_method(int index) {
		return method_list[index];
	}

	size_t get_field_count() {
		return field_list.size();
	}

	std::string& get_name() {
		return name;
	}

	std::string& get_name_space() {
		return name_space;
	}

	std::string& get_assembly_name() {
		return assembly_name;
	}
};