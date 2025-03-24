#pragma once
#define add_tab(str) str += ' ';str += ' ';str += ' ';str += ' ';str += ' ';
	
class c_Generator
{
private:
	c_Klass* klass;
	std::vector<c_Method> generated_methodes;
public:
	std::string type_to_cpp(std::string& type) {
		if (type.find("Void") != std::string::npos)
			return "void";
		if (type.find("Int32") != std::string::npos)
			return "int32_t";
		if (type.find("Int64") != std::string::npos)
			return "int64_t";
		if (type.find("Double") != std::string::npos)
			return "float";
		if (type.find("Vector3") != std::string::npos)
			return "Vector3";
		if (type.find("Quaternion") != std::string::npos)
			return "Quaternion";
		if (type.find("Boolean") != std::string::npos)
			return "bool";
		return "uintptr_t";
	}

    std::string write_class() {
        std::string to_write;
        if (klass->get_name_space().size() > 0) {
            to_write += "namespace " + klass->get_name_space() + " {\n";
            add_tab(to_write)
        }
        to_write += "namespace " + klass->get_name() + " {\n";

        for (int i = 0; i < klass->get_method_count(); i++) {
            int need_to_skip = false;
            c_Method method = klass->get_method(i);
            for (auto meth : generated_methodes) {
                if (meth.get_name() == method.get_name())
                    need_to_skip = true;
            }
            if (need_to_skip) continue;
            add_tab(to_write)
                to_write += "uintptr_t " + method.get_name() + "_va" + "() {\n";
            add_tab(to_write);
            add_tab(to_write);
            to_write += "return module_base + " + std::to_string(method.get_rva()) + ";\n";
            add_tab(to_write);
            to_write += "}\n";

            add_tab(to_write);
            to_write += type_to_cpp(method.get_return_type()) + " " + method.get_name();
            to_write += "(";
            if (!method.get_is_static())
                to_write += "uintptr_t this_";
            if (!method.get_is_static() && method.get_parametrs_count() > 0)
                to_write += ", ";
            for (int i = 0; i < method.get_parametrs_count(); i++) {
                parametr par = method.get_parametr(i);
                if (i != 0 && i != method.get_parametrs_count())
                    to_write += ", ";
                to_write += type_to_cpp(par.type) + " " + par.name;
            }
            to_write += ") {\n";
            add_tab(to_write);
            add_tab(to_write);
            to_write += "typedef " + type_to_cpp(method.get_return_type()) + "(__fastcall* hui_t)";
            to_write += "(";
            if (!method.get_is_static())
                to_write += "uintptr_t"; 
            if (!method.get_is_static() && method.get_parametrs_count() > 0)
                to_write += ", ";
            for (int i = 0; i < method.get_parametrs_count(); i++) {
                parametr par = method.get_parametr(i);
                if (i != 0 && i != method.get_parametrs_count())
                    to_write += ", ";
                to_write += type_to_cpp(par.type);
            }
            to_write += ");\n";
            add_tab(to_write);
            add_tab(to_write);
            to_write += "hui_t hui = (hui_t)(" + method.get_name() + "_va" + "());\n";
            add_tab(to_write);
            add_tab(to_write);
            to_write += "return hui(";
            if (!method.get_is_static())
                to_write += "this_";
            if (!method.get_is_static() && method.get_parametrs_count() > 0)
                to_write += ", ";
            for (int i = 0; i < method.get_parametrs_count(); i++) {
                parametr par = method.get_parametr(i);
                if (i != 0 && i != method.get_parametrs_count())
                    to_write += ", ";
                to_write += par.name;
            }
            to_write += ");\n";
            add_tab(to_write);
            to_write += "}\n";
            generated_methodes.push_back(method);
        }

        for (int i = 0; i < klass->get_field_count(); i++) {
            c_Field field = klass->get_field(i);
            if (!field.get_is_static()) {
                add_tab(to_write);
                to_write += type_to_cpp(field.get_type()) + "* " + field.get_name() + "(uintptr_t this_) {\n";
                add_tab(to_write);
                add_tab(to_write);
                to_write += "return (" + type_to_cpp(field.get_type()) + "*)" + "(this_ + " + std::to_string(field.get_offset()) + ");\n";
                add_tab(to_write);
                to_write += "}\n";
            }
            else {
                add_tab(to_write);
                to_write += type_to_cpp(field.get_type()) + " " + field.get_name() + "(uintptr_t this_) {\n";
                add_tab(to_write);
                add_tab(to_write);

                to_write += "Il2CppAssembly * assembly;\n";
                add_tab(to_write);
                add_tab(to_write);
                to_write += "for (auto assembly_ : assembly_list) {\n";
                add_tab(to_write);
                add_tab(to_write);
                add_tab(to_write);
                to_write += "if (strcmp(assembly_->aname.name, ";
                to_write += "\"";
                to_write += klass->get_assembly_name();
                to_write += "\"";
                to_write += ") == 0);\n";
                add_tab(to_write);
                add_tab(to_write);
                add_tab(to_write);
                add_tab(to_write);
                to_write += "assembly = assembly_;\n";
                add_tab(to_write);
                add_tab(to_write);
                to_write += "}\n";

                add_tab(to_write);
                add_tab(to_write);
                to_write += "Il2CppClass* klass_ = il2cpp_api::il2cpp_class_from_name(il2cpp_api::il2cpp_assembly_get_image(assembly), ";
                to_write += "\"";
                to_write += klass->get_name_space().c_str();
                to_write += "\"";
                to_write += ", ";
                to_write += "\"";
                to_write += klass->get_name().c_str();
                to_write += "\"";
                to_write += ");\n";
                add_tab(to_write);
                add_tab(to_write);
                to_write += "FieldInfo* info = il2cpp_api::il2cpp_class_get_field_from_name(klass_, ";
                to_write += "\"";
                to_write += field.get_name();
                to_write += "\"";
                to_write += ");\n";
                add_tab(to_write);
                add_tab(to_write);
                to_write += type_to_cpp(field.get_type()) + " value;\n";
                add_tab(to_write);
                add_tab(to_write);
                to_write += "il2cpp_api::il2cpp_field_static_get_value(info, &value);\n";
                add_tab(to_write);
                add_tab(to_write);
                to_write += "return value;\n";
                add_tab(to_write);
                to_write += "}\n";
            }
        }

        to_write += "}\n";
        if (klass->get_name_space().size() > 0)
            to_write += "}\n";
        return to_write;
    }

	c_Generator(c_Klass* klass_, std::string path) {
		if (!klass_) return;
		klass = klass_;
		if (klass->get_assembly_name() == "Assembly-CSharp")
			path += "\\GameClasses";
		else
			path += "\\UnityEngine";

		if (klass->get_name_space().size() > 0)
			path += "\\" + klass->get_name_space();
		path += "\\" + klass->get_name() + ".hpp";
		std::wstring wpathh(path.begin(), path.end());
		auto wpath = wpathh.c_str();
		std::ofstream file(path, std::ios::app);
		if (!file.is_open()) {
			HANDLE handle = CreateFileW(wpath, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_NEW, FILE_ATTRIBUTE_ARCHIVE, NULL);
			CloseHandle(handle);
		}
		std::string to_write = write_class();
		file << to_write;

		file.close();
	}
};

#undef add_tab