#pragma once

class c_Dumper
{
private:
	Il2CppDomain* domain;
	std::vector<Il2CppAssembly*> assembly_list;
public:
	c_Dumper() {
		domain = il2cpp_api::il2cpp_domain_get();
		if (!domain) return;
		size_t size;
		Il2CppAssembly** assemblies = il2cpp_api::il2cpp_domain_get_assemblies(domain, &size);
		if (!assemblies) return;

		for (int i = 0; i < size; i++) {
			Il2CppAssembly* assembly = (Il2CppAssembly*)assemblies[i];
			if (!assembly) continue;
			assembly_list.push_back(assembly);
		}
	}

	size_t get_assembly_list_size() const {
		return assembly_list.size();
	}

	Il2CppAssembly* get_assembly(int index) {
		return assembly_list[index];
	}

	std::vector<Il2CppClass*> dump_classes() {
		std::vector<Il2CppClass*> klass_vector;
		size_t assembly_list_size = this->get_assembly_list_size();
		for (int i = 0; i < assembly_list_size; i++)
		{
			auto assembly = this->get_assembly(i);
			if (!assembly) continue;
			//if (strcmp(assembly->aname.name, assembly_name.c_str()) == 0) {
				Il2CppImage* image = assembly->image;
				if (!image) continue;
				size_t image_class_count = il2cpp_api::il2cpp_image_get_class_count(image);

				for (int i = 0; i < image_class_count; i++) {
					Il2CppClass* klass = (Il2CppClass*)il2cpp_api::il2cpp_image_get_class(image, i);
					if (!klass) continue;
					klass_vector.push_back(klass);
				}
			}
		//}
		return klass_vector;
	}
};