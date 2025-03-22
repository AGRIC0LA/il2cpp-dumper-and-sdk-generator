#include "Windows.h"
#include <iostream>
#include <thread>
#include <vector>>
#include <filesystem>
#include <fstream>

static const uintptr_t module_base = (uintptr_t)GetModuleHandleA("GameAssembly.dll");

#include "il2cpp_types.h"
#include "il2cpp_api.h"
#include "class.hpp"
#include "dumper.h"
#include "generator.hpp"

void attach_console() {
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);
}

void initialize() {
	const std::string path_to_dump = "C:\\Users\\z\\AppData\\Roaming\\Dump";

	std::filesystem::create_directory(path_to_dump);
	std::filesystem::create_directory(path_to_dump + "\\UnityEngine");
	std::filesystem::create_directory(path_to_dump + "\\GameClasses");

	static std::vector<c_Klass*> all_dumped_classes;
	attach_console();
	std::cout << "Dumper loaded" << std::endl;
	il2cpp_api::initialize();

	std::string path_to_init = path_to_dump + "\\init.hpp";
	std::wstring wpath_to_init(path_to_init.begin(), path_to_init.end());
	auto cw_path_to_dump = wpath_to_init.c_str();
	HANDLE handle = CreateFileW(cw_path_to_dump, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_NEW, FILE_ATTRIBUTE_ARCHIVE, NULL);
	CloseHandle(handle);
	std::ofstream file(cw_path_to_dump, std::ios::app);
	if (!file.is_open()) {
		std::cout << "error with create init file" << std::endl;
		return;
	}
	file << "#pragma once\n namespace il2cpp_sdk_gen { Il2CppDomain* domain; std::vector<Il2CppAssembly*> assembly_list; void init() { domain = il2cpp_api::il2cpp_domain_get(); if (!domain) return; size_t size; Il2CppAssembly** assemblies = il2cpp_api::il2cpp_domain_get_assemblies(domain, &size); if (!assemblies) return; for (int i = 0; i < size; i++) { Il2CppAssembly* assembly = (Il2CppAssembly*)assemblies[i]; if (!assembly) continue; assembly_list.push_back(assembly); } } }";
	file.close();

	c_Dumper* dumper = new c_Dumper;

	std::vector<Il2CppClass*> dumped_classes = dumper->dump_classes();
	for (auto dumped_klass : dumped_classes) {
		c_Klass* klass = new c_Klass(dumped_klass);
		if (klass->get_assembly_name() == "Assembly-CSharp") 
			std::filesystem::create_directory(path_to_dump + "\\GameClasses\\" + klass->get_name_space());
		else
			std::filesystem::create_directory(path_to_dump + "\\UnityEngine\\" + klass->get_name_space());

		all_dumped_classes.push_back(klass);
	}

	for (auto dumpd : all_dumped_classes) {
		c_Generator generator = c_Generator(dumpd, path_to_dump);
	}
	std::cout << "Dump succesfly loaded in directory " << path_to_dump << std::endl;
	delete dumper;
}

BOOL WINAPI DllMain(HINSTANCE hinst, DWORD reason, LPVOID reserved) {
	if (reason == 1) {
		std::thread potok(initialize);
		potok.detach();
	}
	return TRUE;
}