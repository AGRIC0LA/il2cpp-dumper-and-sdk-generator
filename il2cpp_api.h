#pragma once

#define DO_API(r, n, p) r(__fastcall* n)p
#define DO_APII(r, n, p)  typedef r (__fastcall* n##_t)p; n = (n##_t)GetProcAddress(GetModuleHandleA("GameAssembly.dll"), #n); 


namespace il2cpp_api
{
	DO_API(void, il2cpp_init, ( char* domain_name));
	DO_API(void, il2cpp_init_utf16, ( Il2CppChar* domain_name));
	DO_API(void, il2cpp_shutdown, ());
	DO_API(void, il2cpp_dumping_memory, (bool val));
	DO_API(void, il2cpp_set_config_dir, ( char* config_path));
	DO_API(void, il2cpp_set_data_dir, ( char* data_path));
	DO_API(void, il2cpp_set_temp_dir, ( char* temp_path));
	DO_API(void, il2cpp_set_commandline_arguments, (int argc,  char*  argv[],  char* basedir));
	DO_API(void, il2cpp_set_commandline_arguments_utf16, (int argc,  Il2CppChar*  argv[],  char* basedir));
	DO_API(void, il2cpp_set_config_utf16, ( Il2CppChar* executablePath));
	DO_API(void, il2cpp_set_config, ( char* executablePath));

	DO_API(void, il2cpp_set_memory_callbacks, (Il2CppMemoryCallbacks* callbacks));
	DO_API( Il2CppImage*, il2cpp_get_corlib, ());
	DO_API(void, il2cpp_add_internal_call, ( char* name, Il2CppMethodPointer method));
	DO_API(Il2CppMethodPointer, il2cpp_resolve_icall, ( char* name));

	DO_API(void*, il2cpp_alloc, (size_t size));
	DO_API(void, il2cpp_free, (void* ptr));

	// array
	DO_API(Il2CppClass*, il2cpp_array_class_get, (Il2CppClass* element_class, uint32_t rank));
	DO_API(uint32_t, il2cpp_array_length, (Il2CppArray* array));
	DO_API(uint32_t, il2cpp_array_get_byte_length, (Il2CppArray* array));
	DO_API(Il2CppArray*, il2cpp_array_new, (Il2CppClass* elementTypeInfo, il2cpp_array_size_t length));
	DO_API(Il2CppArray*, il2cpp_array_new_specific, (Il2CppClass* arrayTypeInfo, il2cpp_array_size_t length));
	DO_API(Il2CppArray*, il2cpp_array_new_full, (Il2CppClass* array_class, il2cpp_array_size_t* lengths, il2cpp_array_size_t* lower_bounds));
	DO_API(Il2CppClass*, il2cpp_bounded_array_class_get, (Il2CppClass* element_class, uint32_t rank, bool bounded));
	DO_API(int, il2cpp_array_element_size, ( Il2CppClass* array_class));

	// assembly
	DO_API( Il2CppImage*, il2cpp_assembly_get_image, ( Il2CppAssembly* assembly));

	// class
	DO_API( Il2CppType*, il2cpp_class_enum_basetype, (Il2CppClass* klass));
	DO_API(bool, il2cpp_class_is_generic, ( Il2CppClass* klass));
	DO_API(bool, il2cpp_class_is_inflated, ( Il2CppClass* klass));
	DO_API(bool, il2cpp_class_is_assignable_from, (Il2CppClass* klass, Il2CppClass* oklass));
	DO_API(bool, il2cpp_class_is_subclass_of, (Il2CppClass* klass, Il2CppClass* klassc, bool check_interfaces));
	DO_API(bool, il2cpp_class_has_parent, (Il2CppClass* klass, Il2CppClass* klassc));
	DO_API(Il2CppClass*, il2cpp_class_from_il2cpp_type, ( Il2CppType* type));
	DO_API(Il2CppClass*, il2cpp_class_from_name, ( Il2CppImage* image,  char* namespaze,  char* name));
	DO_API(Il2CppClass*, il2cpp_class_from_system_type, (Il2CppReflectionType* type));
	DO_API(Il2CppClass*, il2cpp_class_get_element_class, (Il2CppClass* klass));
	DO_API( EventInfo*, il2cpp_class_get_events, (Il2CppClass* klass, void** iter));
	DO_API(FieldInfo*, il2cpp_class_get_fields, (Il2CppClass* klass, void** iter));
	DO_API(Il2CppClass*, il2cpp_class_get_nested_types, (Il2CppClass* klass, void** iter));
	DO_API(Il2CppClass*, il2cpp_class_get_interfaces, (Il2CppClass* klass, void** iter));
	DO_API( PropertyInfo*, il2cpp_class_get_properties, (Il2CppClass* klass, void** iter));
	DO_API( PropertyInfo*, il2cpp_class_get_property_from_name, (Il2CppClass* klass,  char* name));
	DO_API(FieldInfo*, il2cpp_class_get_field_from_name, (Il2CppClass* klass,  char* name));
	DO_API( MethodInfo*, il2cpp_class_get_methods, (Il2CppClass* klass, void** iter));
	DO_API( MethodInfo*, il2cpp_class_get_method_from_name, (Il2CppClass* klass,  char* name, int argsCount));
	DO_API( char*, il2cpp_class_get_name, (Il2CppClass* klass));
	DO_API( char*, il2cpp_class_get_namespace, (Il2CppClass* klass));
	DO_API(Il2CppClass*, il2cpp_class_get_parent, (Il2CppClass* klass));
	DO_API(Il2CppClass*, il2cpp_class_get_declaring_type, (Il2CppClass* klass));
	DO_API(int32_t, il2cpp_class_instance_size, (Il2CppClass* klass));
	DO_API(size_t, il2cpp_class_num_fields, ( Il2CppClass* enumKlass));
	DO_API(bool, il2cpp_class_is_valuetype, ( Il2CppClass* klass));
	DO_API(int32_t, il2cpp_class_value_size, (Il2CppClass* klass, uint32_t* align));
	DO_API(bool, il2cpp_class_is_blittable, ( Il2CppClass* klass));
	DO_API(int, il2cpp_class_get_flags, ( Il2CppClass* klass));
	DO_API(bool, il2cpp_class_is_abstract, ( Il2CppClass* klass));
	DO_API(bool, il2cpp_class_is_interface, ( Il2CppClass* klass));
	DO_API(int, il2cpp_class_array_element_size, ( Il2CppClass* klass));
	DO_API(Il2CppClass*, il2cpp_class_from_type, ( Il2CppType* type));
	DO_API( Il2CppType*, il2cpp_class_get_type, (Il2CppClass* klass));
	DO_API(uint32_t, il2cpp_class_get_type_token, (Il2CppClass* klass));
	DO_API(bool, il2cpp_class_has_attribute, (Il2CppClass* klass, Il2CppClass* attr_class));
	DO_API(bool, il2cpp_class_has_references, (Il2CppClass* klass));
	DO_API(bool, il2cpp_class_is_enum, ( Il2CppClass* klass));
	DO_API( Il2CppImage*, il2cpp_class_get_image, (Il2CppClass* klass));
	DO_API( char*, il2cpp_class_get_assemblyname, ( Il2CppClass* klass));
	DO_API(int, il2cpp_class_get_rank, ( Il2CppClass* klass));

	// testing only
	DO_API(size_t, il2cpp_class_get_bitmap_size, ( Il2CppClass* klass));
	DO_API(void, il2cpp_class_get_bitmap, (Il2CppClass* klass, size_t* bitmap));

	// stats
	DO_API(bool, il2cpp_stats_dump_to_file, ( char* path));
	DO_API(uint64_t, il2cpp_stats_get_value, (Il2CppStat stat));

	// domain
	DO_API(Il2CppDomain*, il2cpp_domain_get, ());
	DO_API( Il2CppAssembly*, il2cpp_domain_assembly_open, (Il2CppDomain* domain,  char* name));
	DO_API( Il2CppAssembly**, il2cpp_domain_get_assemblies, ( Il2CppDomain* domain, size_t* size));

	// exception
	//DO_API_NO_RETURN(void, il2cpp_raise_exception, (Il2CppException*));
	DO_API(Il2CppException*, il2cpp_exception_from_name_msg, ( Il2CppImage* image,  char* name_space,  char* name,  char* msg));
	DO_API(Il2CppException*, il2cpp_get_exception_argument_null, ( char* arg));
	DO_API(void, il2cpp_format_exception, ( Il2CppException* ex, char* message, int message_size));
	DO_API(void, il2cpp_format_stack_trace, ( Il2CppException* ex, char* output, int output_size));
	DO_API(void, il2cpp_unhandled_exception, (Il2CppException*));

	// field
	DO_API(int, il2cpp_field_get_flags, (FieldInfo* field));
	DO_API( char*, il2cpp_field_get_name, (FieldInfo* field));
	DO_API(Il2CppClass*, il2cpp_field_get_parent, (FieldInfo* field));
	DO_API(size_t, il2cpp_field_get_offset, (FieldInfo* field));
	DO_API( Il2CppType*, il2cpp_field_get_type, (FieldInfo* field));
	DO_API(void, il2cpp_field_get_value, (Il2CppObject* obj, FieldInfo* field, void* value));
	DO_API(Il2CppObject*, il2cpp_field_get_value_object, (FieldInfo* field, Il2CppObject* obj));
	DO_API(bool, il2cpp_field_has_attribute, (FieldInfo* field, Il2CppClass* attr_class));
	DO_API(void, il2cpp_field_set_value, (Il2CppObject* obj, FieldInfo* field, void* value));
	DO_API(void, il2cpp_field_static_get_value, (FieldInfo* field, void* value));
	DO_API(void, il2cpp_field_static_set_value, (FieldInfo* field, void* value));
	DO_API(void, il2cpp_field_set_value_object, (Il2CppObject* instance, FieldInfo* field, Il2CppObject* value));

	// gc
	DO_API(void, il2cpp_gc_collect, (int maxGenerations));
	DO_API(int32_t, il2cpp_gc_collect_a_little, ());
	DO_API(void, il2cpp_gc_disable, ());
	DO_API(void, il2cpp_gc_enable, ());
	DO_API(bool, il2cpp_gc_is_disabled, ());
	DO_API(int64_t, il2cpp_gc_get_used_size, ());
	DO_API(int64_t, il2cpp_gc_get_heap_size, ());
	DO_API(void, il2cpp_gc_wbarrier_set_field, (Il2CppObject* obj, void** targetAddress, void* object));

	// gchandle
	DO_API(uint32_t, il2cpp_gchandle_new, (Il2CppObject* obj, bool pinned));
	DO_API(uint32_t, il2cpp_gchandle_new_weakref, (Il2CppObject* obj, bool track_resurrection));
	DO_API(Il2CppObject*, il2cpp_gchandle_get_target, (uint32_t gchandle));
	DO_API(void, il2cpp_gchandle_free, (uint32_t gchandle));

	// liveness
	DO_API(void*, il2cpp_unity_liveness_calculation_begin, (Il2CppClass* filter, int max_object_count, il2cpp_register_object_callback callback, void* userdata, il2cpp_WorldChangedCallback onWorldStarted, il2cpp_WorldChangedCallback onWorldStopped));
	DO_API(void, il2cpp_unity_liveness_calculation_end, (void* state));
	DO_API(void, il2cpp_unity_liveness_calculation_from_root, (Il2CppObject* root, void* state));
	DO_API(void, il2cpp_unity_liveness_calculation_from_statics, (void* state));

	// method
	DO_API( Il2CppType*, il2cpp_method_get_return_type, ( MethodInfo* method));
	DO_API(Il2CppClass*, il2cpp_method_get_declaring_type, ( MethodInfo* method));
	DO_API( char*, il2cpp_method_get_name, ( MethodInfo* method));
	DO_API( MethodInfo*, il2cpp_method_get_from_reflection, ( Il2CppReflectionMethod* method));
	DO_API(Il2CppReflectionMethod*, il2cpp_method_get_object, ( MethodInfo* method, Il2CppClass* refclass));
	DO_API(bool, il2cpp_method_is_generic, ( MethodInfo* method));
	DO_API(bool, il2cpp_method_is_inflated, ( MethodInfo* method));
	DO_API(bool, il2cpp_method_is_instance, ( MethodInfo* method));
	DO_API(uint32_t, il2cpp_method_get_param_count, ( MethodInfo* method));
	DO_API( Il2CppType*, il2cpp_method_get_param, ( MethodInfo* method, uint32_t index));
	DO_API(Il2CppClass*, il2cpp_method_get_class, ( MethodInfo* method));
	DO_API(bool, il2cpp_method_has_attribute, ( MethodInfo* method, Il2CppClass* attr_class));
	DO_API(uint32_t, il2cpp_method_get_flags, ( MethodInfo* method, uint32_t* iflags));
	DO_API(uint32_t, il2cpp_method_get_token, ( MethodInfo* method));
	DO_API( char*, il2cpp_method_get_param_name, ( MethodInfo* method, uint32_t index));

	// profiler
#if IL2CPP_ENABLE_PROFILER

	DO_API(void, il2cpp_profiler_install, (Il2CppProfiler* prof, Il2CppProfileFunc shutdown_callback));
	DO_API(void, il2cpp_profiler_set_events, (Il2CppProfileFlags events));
	DO_API(void, il2cpp_profiler_install_enter_leave, (Il2CppProfileMethodFunc enter, Il2CppProfileMethodFunc fleave));
	DO_API(void, il2cpp_profiler_install_allocation, (Il2CppProfileAllocFunc callback));
	DO_API(void, il2cpp_profiler_install_gc, (Il2CppProfileGCFunc callback, Il2CppProfileGCResizeFunc heap_resize_callback));
	DO_API(void, il2cpp_profiler_install_fileio, (Il2CppProfileFileIOFunc callback));
	DO_API(void, il2cpp_profiler_install_thread, (Il2CppProfileThreadFunc start, Il2CppProfileThreadFunc end));

#endif

	// property
	DO_API(uint32_t, il2cpp_property_get_flags, (PropertyInfo* prop));
	DO_API( MethodInfo*, il2cpp_property_get_get_method, (PropertyInfo* prop));
	DO_API( MethodInfo*, il2cpp_property_get_set_method, (PropertyInfo* prop));
	DO_API( char*, il2cpp_property_get_name, (PropertyInfo* prop));
	DO_API(Il2CppClass*, il2cpp_property_get_parent, (PropertyInfo* prop));

	// object
	DO_API(Il2CppClass*, il2cpp_object_get_class, (Il2CppObject* obj));
	DO_API(uint32_t, il2cpp_object_get_size, (Il2CppObject* obj));
	DO_API( MethodInfo*, il2cpp_object_get_virtual_method, (Il2CppObject* obj,  MethodInfo* method));
	DO_API(Il2CppObject*, il2cpp_object_new, ( Il2CppClass* klass));
	DO_API(void*, il2cpp_object_unbox, (Il2CppObject* obj));

	DO_API(Il2CppObject*, il2cpp_value_box, (Il2CppClass* klass, void* data));

	// monitor
	DO_API(void, il2cpp_monitor_enter, (Il2CppObject* obj));
	DO_API(bool, il2cpp_monitor_try_enter, (Il2CppObject* obj, uint32_t timeout));
	DO_API(void, il2cpp_monitor_exit, (Il2CppObject* obj));
	DO_API(void, il2cpp_monitor_pulse, (Il2CppObject* obj));
	DO_API(void, il2cpp_monitor_pulse_all, (Il2CppObject* obj));
	DO_API(void, il2cpp_monitor_wait, (Il2CppObject* obj));
	DO_API(bool, il2cpp_monitor_try_wait, (Il2CppObject* obj, uint32_t timeout));

	// runtime
	DO_API(Il2CppObject*, il2cpp_runtime_invoke, ( MethodInfo* method, void* obj, void** params, Il2CppException** exc));
	DO_API(Il2CppObject*, il2cpp_runtime_invoke_convert_args, ( MethodInfo* method, void* obj, Il2CppObject** params, int paramCount, Il2CppException** exc));
	DO_API(void, il2cpp_runtime_class_init, (Il2CppClass* klass));
	DO_API(void, il2cpp_runtime_object_init, (Il2CppObject* obj));

	DO_API(void, il2cpp_runtime_object_init_exception, (Il2CppObject* obj, Il2CppException** exc));

	DO_API(void, il2cpp_runtime_unhandled_exception_policy_set, (Il2CppRuntimeUnhandledExceptionPolicy value));

	// string
	DO_API(int32_t, il2cpp_string_length, (Il2CppString* str));
	DO_API(Il2CppChar*, il2cpp_string_chars, (Il2CppString* str));
	DO_API(Il2CppString*, il2cpp_string_new, ( char* str));
	DO_API(Il2CppString*, il2cpp_string_new_len, ( char* str, uint32_t length));
	DO_API(Il2CppString*, il2cpp_string_new_utf16, ( Il2CppChar* text, int32_t len));
	DO_API(Il2CppString*, il2cpp_string_new_wrapper, ( char* str));
	DO_API(Il2CppString*, il2cpp_string_intern, (Il2CppString* str));
	DO_API(Il2CppString*, il2cpp_string_is_interned, (Il2CppString* str));

	// thread
	DO_API(Il2CppThread*, il2cpp_thread_current, ());
	DO_API(Il2CppThread*, il2cpp_thread_attach, (Il2CppDomain* domain));
	DO_API(void, il2cpp_thread_detach, (Il2CppThread* thread));

	DO_API(Il2CppThread**, il2cpp_thread_get_all_attached_threads, (size_t* size));
	DO_API(bool, il2cpp_is_vm_thread, (Il2CppThread* thread));

	// stacktrace
	DO_API(void, il2cpp_current_thread_walk_frame_stack, (Il2CppFrameWalkFunc func, void* user_data));
	DO_API(void, il2cpp_thread_walk_frame_stack, (Il2CppThread* thread, Il2CppFrameWalkFunc func, void* user_data));
	DO_API(bool, il2cpp_current_thread_get_top_frame, (Il2CppStackFrameInfo* frame));
	DO_API(bool, il2cpp_thread_get_top_frame, (Il2CppThread* thread, Il2CppStackFrameInfo* frame));
	DO_API(bool, il2cpp_current_thread_get_frame_at, (int32_t offset, Il2CppStackFrameInfo* frame));
	DO_API(bool, il2cpp_thread_get_frame_at, (Il2CppThread* thread, int32_t offset, Il2CppStackFrameInfo* frame));
	DO_API(int32_t, il2cpp_current_thread_get_stack_depth, ());
	DO_API(int32_t, il2cpp_thread_get_stack_depth, (Il2CppThread* thread));

	// type
	DO_API(Il2CppObject*, il2cpp_type_get_object, ( Il2CppType* type));
	DO_API(int, il2cpp_type_get_type, ( Il2CppType* type));
	DO_API(Il2CppClass*, il2cpp_type_get_class_or_element_class, ( Il2CppType* type));
	DO_API(char*, il2cpp_type_get_name, ( Il2CppType* type));
	DO_API(bool, il2cpp_type_is_byref, ( Il2CppType* type));
	DO_API(uint32_t, il2cpp_type_get_attrs, ( Il2CppType* type));
	DO_API(bool, il2cpp_type_equals, ( Il2CppType* type,  Il2CppType* otherType));
	DO_API(char*, il2cpp_type_get_assembly_qualified_name, ( Il2CppType* type));

	// image
	DO_API( Il2CppAssembly*, il2cpp_image_get_assembly, ( Il2CppImage* image));
	DO_API( char*, il2cpp_image_get_name, ( Il2CppImage* image));
	DO_API( char*, il2cpp_image_get_filename, ( Il2CppImage* image));
	DO_API( MethodInfo*, il2cpp_image_get_entry_point, ( Il2CppImage* image));

	DO_API(size_t, il2cpp_image_get_class_count, ( Il2CppImage* image));
	DO_API( Il2CppClass*, il2cpp_image_get_class, ( Il2CppImage* image, size_t index));

	// Memory information
	DO_API(Il2CppManagedMemorySnapshot*, il2cpp_capture_memory_snapshot, ());
	DO_API(void, il2cpp_free_captured_memory_snapshot, (Il2CppManagedMemorySnapshot* snapshot));

	DO_API(void, il2cpp_set_find_plugin_callback, (Il2CppSetFindPlugInCallback method));

	// Logging
	DO_API(void, il2cpp_register_log_callback, (Il2CppLogCallback method));

	// Debugger
	DO_API(void, il2cpp_debugger_set_agent_options, ( char* options));
	DO_API(bool, il2cpp_is_debugger_attached, ());

	// TLS module
	DO_API(void, il2cpp_unity_install_unitytls_interface, ( void* unitytlsInterfaceStruct));

	// custom attributes
	DO_API(Il2CppCustomAttrInfo*, il2cpp_custom_attrs_from_class, (Il2CppClass* klass));
	DO_API(Il2CppCustomAttrInfo*, il2cpp_custom_attrs_from_method, ( MethodInfo* method));

	DO_API(Il2CppObject*, il2cpp_custom_attrs_get_attr, (Il2CppCustomAttrInfo* ainfo, Il2CppClass* attr_klass));
	DO_API(bool, il2cpp_custom_attrs_has_attr, (Il2CppCustomAttrInfo* ainfo, Il2CppClass* attr_klass));
	DO_API(Il2CppArray*, il2cpp_custom_attrs_ruct, (Il2CppCustomAttrInfo* cinfo));

	DO_API(void, il2cpp_custom_attrs_free, (Il2CppCustomAttrInfo* ainfo));

	void initialize() {
		HMODULE module = GetModuleHandleA("GameAssembly.dll");
		
		DO_APII(void, il2cpp_init, ( char* domain_name));
		DO_APII(void, il2cpp_init_utf16, ( Il2CppChar * domain_name));
		DO_APII(void, il2cpp_shutdown, ());
		DO_APII(void, il2cpp_dumping_memory, (bool val));
		DO_APII(void, il2cpp_set_config_dir, ( char* config_path));
		DO_APII(void, il2cpp_set_data_dir, ( char* data_path));
		DO_APII(void, il2cpp_set_temp_dir, ( char* temp_path));
		DO_APII(void, il2cpp_set_commandline_arguments, (int argc,  char*  argv[],  char* basedir));
		DO_APII(void, il2cpp_set_commandline_arguments_utf16, (int argc,  Il2CppChar*  argv[],  char* basedir));
		DO_APII(void, il2cpp_set_config_utf16, ( Il2CppChar * executablePath));
		DO_APII(void, il2cpp_set_config, ( char* executablePath));

		DO_APII(void, il2cpp_set_memory_callbacks, (Il2CppMemoryCallbacks * callbacks));
		DO_APII( Il2CppImage*, il2cpp_get_corlib, ());
		DO_APII(void, il2cpp_add_internal_call, ( char* name, Il2CppMethodPointer method));
		DO_APII(Il2CppMethodPointer, il2cpp_resolve_icall, ( char* name));

		DO_APII(void*, il2cpp_alloc, (size_t size));
		DO_APII(void, il2cpp_free, (void* ptr));

		// array
		DO_APII(Il2CppClass*, il2cpp_array_class_get, (Il2CppClass * element_class, uint32_t rank));
		DO_APII(uint32_t, il2cpp_array_length, (Il2CppArray * array));
		DO_APII(uint32_t, il2cpp_array_get_byte_length, (Il2CppArray * array));
		DO_APII(Il2CppArray*, il2cpp_array_new, (Il2CppClass * elementTypeInfo, il2cpp_array_size_t length));
		DO_APII(Il2CppArray*, il2cpp_array_new_specific, (Il2CppClass * arrayTypeInfo, il2cpp_array_size_t length));
		DO_APII(Il2CppArray*, il2cpp_array_new_full, (Il2CppClass * array_class, il2cpp_array_size_t * lengths, il2cpp_array_size_t * lower_bounds));
		DO_APII(Il2CppClass*, il2cpp_bounded_array_class_get, (Il2CppClass * element_class, uint32_t rank, bool bounded));
		DO_APII(int, il2cpp_array_element_size, ( Il2CppClass * array_class));

		// assembly
		DO_APII( Il2CppImage*, il2cpp_assembly_get_image, ( Il2CppAssembly * assembly));

		// class
		DO_APII( Il2CppType*, il2cpp_class_enum_basetype, (Il2CppClass * klass));
		DO_APII(bool, il2cpp_class_is_generic, ( Il2CppClass * klass));
		DO_APII(bool, il2cpp_class_is_inflated, ( Il2CppClass * klass));
		DO_APII(bool, il2cpp_class_is_assignable_from, (Il2CppClass * klass, Il2CppClass * oklass));
		DO_APII(bool, il2cpp_class_is_subclass_of, (Il2CppClass * klass, Il2CppClass * klassc, bool check_interfaces));
		DO_APII(bool, il2cpp_class_has_parent, (Il2CppClass * klass, Il2CppClass * klassc));
		DO_APII(Il2CppClass*, il2cpp_class_from_il2cpp_type, ( Il2CppType * type));
		DO_APII(Il2CppClass*, il2cpp_class_from_name, ( Il2CppImage * image,  char* namespaze,  char* name));
		DO_APII(Il2CppClass*, il2cpp_class_from_system_type, (Il2CppReflectionType * type));
		DO_APII(Il2CppClass*, il2cpp_class_get_element_class, (Il2CppClass * klass));
		DO_APII( EventInfo*, il2cpp_class_get_events, (Il2CppClass * klass, void** iter));
		DO_APII(FieldInfo*, il2cpp_class_get_fields, (Il2CppClass * klass, void** iter));
		DO_APII(Il2CppClass*, il2cpp_class_get_nested_types, (Il2CppClass * klass, void** iter));
		DO_APII(Il2CppClass*, il2cpp_class_get_interfaces, (Il2CppClass * klass, void** iter));
		DO_APII( PropertyInfo*, il2cpp_class_get_properties, (Il2CppClass * klass, void** iter));
		DO_APII( PropertyInfo*, il2cpp_class_get_property_from_name, (Il2CppClass * klass,  char* name));
		DO_APII(FieldInfo*, il2cpp_class_get_field_from_name, (Il2CppClass * klass,  char* name));
		DO_APII( MethodInfo*, il2cpp_class_get_methods, (Il2CppClass * klass, void** iter));
		DO_APII( MethodInfo*, il2cpp_class_get_method_from_name, (Il2CppClass * klass,  char* name, int argsCount));
		DO_APII( char*, il2cpp_class_get_name, (Il2CppClass * klass));
		DO_APII( char*, il2cpp_class_get_namespace, (Il2CppClass * klass));
		DO_APII(Il2CppClass*, il2cpp_class_get_parent, (Il2CppClass * klass));
		DO_APII(Il2CppClass*, il2cpp_class_get_declaring_type, (Il2CppClass * klass));
		DO_APII(int32_t, il2cpp_class_instance_size, (Il2CppClass * klass));
		DO_APII(size_t, il2cpp_class_num_fields, ( Il2CppClass * enumKlass));
		DO_APII(bool, il2cpp_class_is_valuetype, ( Il2CppClass * klass));
		DO_APII(int32_t, il2cpp_class_value_size, (Il2CppClass * klass, uint32_t * align));
		DO_APII(bool, il2cpp_class_is_blittable, ( Il2CppClass * klass));
		DO_APII(int, il2cpp_class_get_flags, ( Il2CppClass * klass));
		DO_APII(bool, il2cpp_class_is_abstract, ( Il2CppClass * klass));
		DO_APII(bool, il2cpp_class_is_interface, ( Il2CppClass * klass));
		DO_APII(int, il2cpp_class_array_element_size, ( Il2CppClass * klass));
		DO_APII(Il2CppClass*, il2cpp_class_from_type, ( Il2CppType * type));
		DO_APII( Il2CppType*, il2cpp_class_get_type, (Il2CppClass * klass));
		DO_APII(uint32_t, il2cpp_class_get_type_token, (Il2CppClass * klass));
		DO_APII(bool, il2cpp_class_has_attribute, (Il2CppClass * klass, Il2CppClass * attr_class));
		DO_APII(bool, il2cpp_class_has_references, (Il2CppClass * klass));
		DO_APII(bool, il2cpp_class_is_enum, ( Il2CppClass * klass));
		DO_APII( Il2CppImage*, il2cpp_class_get_image, (Il2CppClass * klass));
		DO_APII( char*, il2cpp_class_get_assemblyname, ( Il2CppClass * klass));
		DO_APII(int, il2cpp_class_get_rank, ( Il2CppClass * klass));

		// testing only
		DO_APII(size_t, il2cpp_class_get_bitmap_size, ( Il2CppClass * klass));
		DO_APII(void, il2cpp_class_get_bitmap, (Il2CppClass * klass, size_t * bitmap));

		// stats
		DO_APII(bool, il2cpp_stats_dump_to_file, ( char* path));
		DO_APII(uint64_t, il2cpp_stats_get_value, (Il2CppStat stat));

		// domain
		DO_APII(Il2CppDomain*, il2cpp_domain_get, ());
		DO_APII( Il2CppAssembly*, il2cpp_domain_assembly_open, (Il2CppDomain * domain,  char* name));
		DO_APII( Il2CppAssembly**, il2cpp_domain_get_assemblies, ( Il2CppDomain * domain, size_t * size));

		// exception
		//DO_API_NO_RETURN(void, il2cpp_raise_exception, (Il2CppException*));
		DO_APII(Il2CppException*, il2cpp_exception_from_name_msg, ( Il2CppImage * image,  char* name_space,  char* name,  char* msg));
		DO_APII(Il2CppException*, il2cpp_get_exception_argument_null, ( char* arg));
		DO_APII(void, il2cpp_format_exception, ( Il2CppException * ex, char* message, int message_size));
		DO_APII(void, il2cpp_format_stack_trace, ( Il2CppException * ex, char* output, int output_size));
		DO_APII(void, il2cpp_unhandled_exception, (Il2CppException*));

		// field
		DO_APII(int, il2cpp_field_get_flags, (FieldInfo * field));
		DO_APII( char*, il2cpp_field_get_name, (FieldInfo * field));
		DO_APII(Il2CppClass*, il2cpp_field_get_parent, (FieldInfo * field));
		DO_APII(size_t, il2cpp_field_get_offset, (FieldInfo * field));
		DO_APII( Il2CppType*, il2cpp_field_get_type, (FieldInfo * field));
		DO_APII(void, il2cpp_field_get_value, (Il2CppObject * obj, FieldInfo * field, void* value));
		DO_APII(Il2CppObject*, il2cpp_field_get_value_object, (FieldInfo * field, Il2CppObject * obj));
		DO_APII(bool, il2cpp_field_has_attribute, (FieldInfo * field, Il2CppClass * attr_class));
		DO_APII(void, il2cpp_field_set_value, (Il2CppObject * obj, FieldInfo * field, void* value));
		DO_APII(void, il2cpp_field_static_get_value, (FieldInfo * field, void* value));
		DO_APII(void, il2cpp_field_static_set_value, (FieldInfo * field, void* value));
		DO_APII(void, il2cpp_field_set_value_object, (Il2CppObject * instance, FieldInfo * field, Il2CppObject * value));

		// gc
		DO_APII(void, il2cpp_gc_collect, (int maxGenerations));
		DO_APII(int32_t, il2cpp_gc_collect_a_little, ());
		DO_APII(void, il2cpp_gc_disable, ());
		DO_APII(void, il2cpp_gc_enable, ());
		DO_APII(bool, il2cpp_gc_is_disabled, ());
		DO_APII(int64_t, il2cpp_gc_get_used_size, ());
		DO_APII(int64_t, il2cpp_gc_get_heap_size, ());
		DO_APII(void, il2cpp_gc_wbarrier_set_field, (Il2CppObject * obj, void** targetAddress, void* object));

		// gchandle
		DO_APII(uint32_t, il2cpp_gchandle_new, (Il2CppObject * obj, bool pinned));
		DO_APII(uint32_t, il2cpp_gchandle_new_weakref, (Il2CppObject * obj, bool track_resurrection));
		DO_APII(Il2CppObject*, il2cpp_gchandle_get_target, (uint32_t gchandle));
		DO_APII(void, il2cpp_gchandle_free, (uint32_t gchandle));

		// liveness
		DO_APII(void*, il2cpp_unity_liveness_calculation_begin, (Il2CppClass * filter, int max_object_count, il2cpp_register_object_callback callback, void* userdata, il2cpp_WorldChangedCallback onWorldStarted, il2cpp_WorldChangedCallback onWorldStopped));
		DO_APII(void, il2cpp_unity_liveness_calculation_end, (void* state));
		DO_APII(void, il2cpp_unity_liveness_calculation_from_root, (Il2CppObject * root, void* state));
		DO_APII(void, il2cpp_unity_liveness_calculation_from_statics, (void* state));

		// method
		DO_APII( Il2CppType*, il2cpp_method_get_return_type, ( MethodInfo * method));
		DO_APII(Il2CppClass*, il2cpp_method_get_declaring_type, ( MethodInfo * method));
		DO_APII( char*, il2cpp_method_get_name, ( MethodInfo * method));
		DO_APII( MethodInfo*, il2cpp_method_get_from_reflection, ( Il2CppReflectionMethod * method));
		DO_APII(Il2CppReflectionMethod*, il2cpp_method_get_object, ( MethodInfo * method, Il2CppClass * refclass));
		DO_APII(bool, il2cpp_method_is_generic, ( MethodInfo * method));
		DO_APII(bool, il2cpp_method_is_inflated, ( MethodInfo * method));
		DO_APII(bool, il2cpp_method_is_instance, ( MethodInfo * method));
		DO_APII(uint32_t, il2cpp_method_get_param_count, ( MethodInfo * method));
		DO_APII( Il2CppType*, il2cpp_method_get_param, ( MethodInfo * method, uint32_t index));
		DO_APII(Il2CppClass*, il2cpp_method_get_class, ( MethodInfo * method));
		DO_APII(bool, il2cpp_method_has_attribute, ( MethodInfo * method, Il2CppClass * attr_class));
		DO_APII(uint32_t, il2cpp_method_get_flags, ( MethodInfo * method, uint32_t * iflags));
		DO_APII(uint32_t, il2cpp_method_get_token, ( MethodInfo * method));
		DO_APII( char*, il2cpp_method_get_param_name, ( MethodInfo * method, uint32_t index));

		// profiler
#if IL2CPP_ENABLE_PROFILER

		DO_API(void, il2cpp_profiler_install, (Il2CppProfiler * prof, Il2CppProfileFunc shutdown_callback));
		DO_API(void, il2cpp_profiler_set_events, (Il2CppProfileFlags events));
		DO_API(void, il2cpp_profiler_install_enter_leave, (Il2CppProfileMethodFunc enter, Il2CppProfileMethodFunc fleave));
		DO_API(void, il2cpp_profiler_install_allocation, (Il2CppProfileAllocFunc callback));
		DO_API(void, il2cpp_profiler_install_gc, (Il2CppProfileGCFunc callback, Il2CppProfileGCResizeFunc heap_resize_callback));
		DO_API(void, il2cpp_profiler_install_fileio, (Il2CppProfileFileIOFunc callback));
		DO_API(void, il2cpp_profiler_install_thread, (Il2CppProfileThreadFunc start, Il2CppProfileThreadFunc end));

#endif

		// property
		DO_APII(uint32_t, il2cpp_property_get_flags, (PropertyInfo * prop));
		DO_APII( MethodInfo*, il2cpp_property_get_get_method, (PropertyInfo * prop));
		DO_APII( MethodInfo*, il2cpp_property_get_set_method, (PropertyInfo * prop));
		DO_APII( char*, il2cpp_property_get_name, (PropertyInfo * prop));
		DO_APII(Il2CppClass*, il2cpp_property_get_parent, (PropertyInfo * prop));

		// object
		DO_APII(Il2CppClass*, il2cpp_object_get_class, (Il2CppObject * obj));
		DO_APII(uint32_t, il2cpp_object_get_size, (Il2CppObject * obj));
		DO_APII( MethodInfo*, il2cpp_object_get_virtual_method, (Il2CppObject * obj,  MethodInfo * method));
		DO_APII(Il2CppObject*, il2cpp_object_new, ( Il2CppClass * klass));
		DO_APII(void*, il2cpp_object_unbox, (Il2CppObject * obj));

		DO_APII(Il2CppObject*, il2cpp_value_box, (Il2CppClass * klass, void* data));

		// monitor
		DO_APII(void, il2cpp_monitor_enter, (Il2CppObject * obj));
		DO_APII(bool, il2cpp_monitor_try_enter, (Il2CppObject * obj, uint32_t timeout));
		DO_APII(void, il2cpp_monitor_exit, (Il2CppObject * obj));
		DO_APII(void, il2cpp_monitor_pulse, (Il2CppObject * obj));
		DO_APII(void, il2cpp_monitor_pulse_all, (Il2CppObject * obj));
		DO_APII(void, il2cpp_monitor_wait, (Il2CppObject * obj));
		DO_APII(bool, il2cpp_monitor_try_wait, (Il2CppObject * obj, uint32_t timeout));

		// runtime
		DO_APII(Il2CppObject*, il2cpp_runtime_invoke, ( MethodInfo * method, void* obj, void** params, Il2CppException * *exc));
		DO_APII(Il2CppObject*, il2cpp_runtime_invoke_convert_args, ( MethodInfo * method, void* obj, Il2CppObject * *params, int paramCount, Il2CppException * *exc));
		DO_APII(void, il2cpp_runtime_class_init, (Il2CppClass * klass));
		DO_APII(void, il2cpp_runtime_object_init, (Il2CppObject * obj));

		DO_APII(void, il2cpp_runtime_object_init_exception, (Il2CppObject * obj, Il2CppException * *exc));

		DO_APII(void, il2cpp_runtime_unhandled_exception_policy_set, (Il2CppRuntimeUnhandledExceptionPolicy value));

		// string
		DO_APII(int32_t, il2cpp_string_length, (Il2CppString * str));
		DO_APII(Il2CppChar*, il2cpp_string_chars, (Il2CppString * str));
		DO_APII(Il2CppString*, il2cpp_string_new, ( char* str));
		DO_APII(Il2CppString*, il2cpp_string_new_len, ( char* str, uint32_t length));
		DO_APII(Il2CppString*, il2cpp_string_new_utf16, ( Il2CppChar * text, int32_t len));
		DO_APII(Il2CppString*, il2cpp_string_new_wrapper, ( char* str));
		DO_APII(Il2CppString*, il2cpp_string_intern, (Il2CppString * str));
		DO_APII(Il2CppString*, il2cpp_string_is_interned, (Il2CppString * str));

		// thread
		DO_APII(Il2CppThread*, il2cpp_thread_current, ());
		DO_APII(Il2CppThread*, il2cpp_thread_attach, (Il2CppDomain * domain));
		DO_APII(void, il2cpp_thread_detach, (Il2CppThread * thread));

		DO_APII(Il2CppThread**, il2cpp_thread_get_all_attached_threads, (size_t * size));
		DO_APII(bool, il2cpp_is_vm_thread, (Il2CppThread * thread));

		// stacktrace
		DO_APII(void, il2cpp_current_thread_walk_frame_stack, (Il2CppFrameWalkFunc func, void* user_data));
		DO_APII(void, il2cpp_thread_walk_frame_stack, (Il2CppThread * thread, Il2CppFrameWalkFunc func, void* user_data));
		DO_APII(bool, il2cpp_current_thread_get_top_frame, (Il2CppStackFrameInfo * frame));
		DO_APII(bool, il2cpp_thread_get_top_frame, (Il2CppThread * thread, Il2CppStackFrameInfo * frame));
		DO_APII(bool, il2cpp_current_thread_get_frame_at, (int32_t offset, Il2CppStackFrameInfo * frame));
		DO_APII(bool, il2cpp_thread_get_frame_at, (Il2CppThread * thread, int32_t offset, Il2CppStackFrameInfo * frame));
		DO_APII(int32_t, il2cpp_current_thread_get_stack_depth, ());
		DO_APII(int32_t, il2cpp_thread_get_stack_depth, (Il2CppThread * thread));

		// type
		DO_APII(Il2CppObject*, il2cpp_type_get_object, ( Il2CppType * type));
		DO_APII(int, il2cpp_type_get_type, ( Il2CppType * type));
		DO_APII(Il2CppClass*, il2cpp_type_get_class_or_element_class, ( Il2CppType * type));
		DO_APII(char*, il2cpp_type_get_name, ( Il2CppType * type));
		DO_APII(bool, il2cpp_type_is_byref, ( Il2CppType * type));
		DO_APII(uint32_t, il2cpp_type_get_attrs, ( Il2CppType * type));
		DO_APII(bool, il2cpp_type_equals, ( Il2CppType * type,  Il2CppType * otherType));
		DO_APII(char*, il2cpp_type_get_assembly_qualified_name, ( Il2CppType * type));

		// image
		DO_APII( Il2CppAssembly*, il2cpp_image_get_assembly, ( Il2CppImage * image));
		DO_APII( char*, il2cpp_image_get_name, ( Il2CppImage * image));
		DO_APII( char*, il2cpp_image_get_filename, ( Il2CppImage * image));
		DO_APII( MethodInfo*, il2cpp_image_get_entry_point, ( Il2CppImage * image));

		DO_APII(size_t, il2cpp_image_get_class_count, ( Il2CppImage * image));
		DO_APII( Il2CppClass*, il2cpp_image_get_class, ( Il2CppImage * image, size_t index));

		// Memory information
		DO_APII(Il2CppManagedMemorySnapshot*, il2cpp_capture_memory_snapshot, ());
		DO_APII(void, il2cpp_free_captured_memory_snapshot, (Il2CppManagedMemorySnapshot * snapshot));

		DO_APII(void, il2cpp_set_find_plugin_callback, (Il2CppSetFindPlugInCallback method));

		// Logging
		DO_APII(void, il2cpp_register_log_callback, (Il2CppLogCallback method));

		// Debugger
		DO_APII(void, il2cpp_debugger_set_agent_options, ( char* options));
		DO_APII(bool, il2cpp_is_debugger_attached, ());

		// TLS module
		DO_APII(void, il2cpp_unity_install_unitytls_interface, ( void* unitytlsInterfaceStruct));

		// custom attributes
		DO_APII(Il2CppCustomAttrInfo*, il2cpp_custom_attrs_from_class, (Il2CppClass * klass));
		DO_APII(Il2CppCustomAttrInfo*, il2cpp_custom_attrs_from_method, ( MethodInfo * method));

		DO_APII(Il2CppObject*, il2cpp_custom_attrs_get_attr, (Il2CppCustomAttrInfo * ainfo, Il2CppClass * attr_klass));
		DO_APII(bool, il2cpp_custom_attrs_has_attr, (Il2CppCustomAttrInfo * ainfo, Il2CppClass * attr_klass));
		DO_APII(Il2CppArray*, il2cpp_custom_attrs_ruct, (Il2CppCustomAttrInfo * cinfo));

		DO_APII(void, il2cpp_custom_attrs_free, (Il2CppCustomAttrInfo * ainfo));
	}
}

#undef DO_API
#undef DO_APII