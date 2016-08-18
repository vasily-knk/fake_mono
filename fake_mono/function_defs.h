#pragma once

extern "C"
{
    void mono_thread_suspend_all_other_threads();
    void mono_thread_pool_cleanup();
    void mono_threads_set_shutting_down();
    void mono_runtime_set_shutting_down();
    gboolean mono_domain_finalize(MonoDomain* domain, int timeout);
    void mono_runtime_cleanup(MonoDomain* domain);
    MonoMethodDesc* mono_method_desc_new(const char* name, gboolean include_namespace);
    MonoMethod* mono_method_desc_search_in_image(MonoMethodDesc* desc, MonoImage* image);
    void mono_verifier_set_mode(MiniVerifierMode m);
    void mono_security_set_mode(MonoSecurityMode m);
    void mono_add_internal_call(const char* name, gconstpointer method);
    void mono_jit_cleanup(MonoDomain* domain);
    MonoDomain* mono_jit_init(const char* file);
    MonoDomain* mono_jit_init_version(const char* file, const char* runtime_version);
    int mono_jit_exec(MonoDomain* domain, MonoAssembly* assembly, int argc, char* argv[]);
    MonoClass* mono_class_from_name(MonoImage* image, const char* name_space, const char* name);
    MonoAssembly* mono_domain_assembly_open(MonoDomain* domain, const char* name);
    MonoDomain* mono_domain_create_appdomain(const char* domainname, const char* configfile);
    void mono_domain_unload(MonoDomain* domain);
    MonoObject* mono_object_new(MonoDomain* domain, MonoClass* klass);
    void mono_runtime_object_init(MonoObject* this_obj);
    MonoObject* mono_runtime_invoke(MonoMethod* method, void* obj, void** params, MonoObject** exc);
    void mono_field_set_value(MonoObject* obj, MonoClassField* field, void* value);
    void mono_field_get_value(MonoObject* obj, MonoClassField* field, void* value);
    int mono_field_get_offset(MonoClassField* field);
    MonoClassField* mono_class_get_fields(MonoClass* klass, gpointer* iter);
    MonoMethod* mono_class_get_methods(MonoClass* klass, gpointer* iter);
    MonoDomain* mono_domain_get();
    MonoDomain* mono_get_root_domain();
    gint32 mono_domain_get_id(MonoDomain* domain);
    void mono_assembly_foreach(GFunc func, gpointer user_data);
    void mono_image_close(MonoImage* image);
    void mono_unity_socket_security_enabled_set(gboolean b);
    const char* mono_image_get_name(MonoImage* image);
    MonoClass* mono_get_object_class();
    void mono_set_commandline_arguments(int i, const char* argv[], const char* s);
    const char* mono_field_get_name(MonoClassField* field);
    MonoType* mono_field_get_type(MonoClassField* field);
    int mono_type_get_type(MonoType* type);
    const char* mono_method_get_name(MonoMethod* method);
    MonoImage* mono_assembly_get_image(MonoAssembly* assembly);
    MonoClass* mono_method_get_class(MonoMethod* method);
    MonoClass* mono_object_get_class(MonoObject* obj);
    gboolean mono_class_is_valuetype(MonoClass* klass);
    guint32 mono_signature_get_param_count(MonoMethodSignature* sig);
    char* mono_string_to_utf8(MonoString* string_obj);
    MonoString* mono_string_new_wrapper(const char* text);
    MonoClass* mono_class_get_parent(MonoClass* klass);
    const char* mono_class_get_namespace(MonoClass* klass);
    gboolean mono_class_is_subclass_of(MonoClass* klass, MonoClass* klassc, gboolean check_interfaces);
    const char* mono_class_get_name(MonoClass* klass);
    char* mono_type_get_name(MonoType* type);
    MonoClass* mono_type_get_class(MonoType* type);
    MonoException* mono_exception_from_name_msg(MonoImage* image, const char* name_space, const char* name, const char* msg);
    void mono_raise_exception(MonoException* ex);
    MonoClass* mono_get_exception_class();
    MonoClass* mono_get_array_class();
    MonoClass* mono_get_string_class();
    MonoClass* mono_get_int32_class();
    MonoArray* mono_array_new(MonoDomain* domain, MonoClass* eclass, guint32 n);
    MonoArray* mono_array_new_full(MonoDomain* domain, MonoClass* array_class, guint32* lengths, guint32* lower_bounds);
    MonoClass* mono_array_class_get(MonoClass* eclass, guint32 rank);
    gint32 mono_class_array_element_size(MonoClass* ac);
    MonoObject* mono_type_get_object(MonoDomain* domain, MonoType* type);
    MonoThread* mono_thread_attach(MonoDomain* domain);
    void mono_thread_detach(MonoThread* thread);
    MonoThread* mono_thread_exit();
    MonoThread* mono_thread_current();
    void mono_thread_set_main(MonoThread* thread);
    void mono_set_find_plugin_callback(gconstpointer method);
    void mono_security_enable_core_clr();
    bool mono_security_set_core_clr_platform_callback(MonoCoreClrPlatformCB a);
    MonoRuntimeUnhandledExceptionPolicy mono_runtime_unhandled_exception_policy_get();
    void mono_runtime_unhandled_exception_policy_set(MonoRuntimeUnhandledExceptionPolicy policy);
    MonoClass* mono_class_get_nesting_type(MonoClass* klass);
    MonoVTable* mono_class_vtable(MonoDomain* domain, MonoClass* klass);
    MonoReflectionMethod* mono_method_get_object(MonoDomain* domain, MonoMethod* method, MonoClass* refclass);
    MonoMethodSignature* mono_method_signature(MonoMethod* method);
    MonoType* mono_signature_get_params(MonoMethodSignature* sig, gpointer* iter);
    MonoType* mono_signature_get_return_type(MonoMethodSignature* sig);
    MonoType* mono_class_get_type(MonoClass* klass);
    void mono_set_ignore_version_and_key_when_finding_assemblies_already_loaded(gboolean value);
    void mono_debug_init(int format);
    void mono_debug_open_image_from_memory(MonoImage* image, const char* raw_contents, int size);
    guint32 mono_field_get_flags(MonoClassField* field);
    MonoImage* mono_image_open_from_data_full(const void* data, guint32 data_len, gboolean need_copy, int* status, gboolean ref_only);
    MonoImage* mono_image_open_from_data_with_name(char* data, guint32 data_len, gboolean need_copy, int* status, gboolean refonly, const char* name);
    MonoAssembly* mono_assembly_load_from(MonoImage* image, const char* fname, int* status);
    MonoObject* mono_value_box(MonoDomain* domain, MonoClass* klass, gpointer val);
    MonoImage* mono_class_get_image(MonoClass* klass);
    char mono_signature_is_instance(MonoMethodSignature* signature);
    MonoMethod* mono_method_get_last_managed();
    MonoClass* mono_get_enum_class();
    MonoType* mono_class_get_byref_type(MonoClass* klass);
    void mono_field_static_get_value(MonoVTable* vt, MonoClassField* field, void* value);
    void mono_unity_set_embeddinghostname(const char* name);
    void mono_set_assemblies_path(const char* name);
    guint32 mono_gchandle_new(MonoObject* obj, gboolean pinned);
    MonoObject* mono_gchandle_get_target(guint32 gchandle);
    guint32 mono_gchandle_new_weakref(MonoObject* obj, gboolean track_resurrection);
    MonoObject* mono_assembly_get_object(MonoDomain* domain, MonoAssembly* assembly);
    void mono_gchandle_free(guint32 gchandle);
    MonoProperty* mono_class_get_properties(MonoClass* klass, gpointer* iter);
    MonoMethod* mono_property_get_get_method(MonoProperty* prop);
    MonoObject* mono_object_new_alloc_specific(MonoVTable* vtable);
    MonoObject* mono_object_new_specific(MonoVTable* vtable);
    void mono_gc_collect(int generation);
    int mono_gc_max_generation();
    MonoAssembly* mono_image_get_assembly(MonoImage* image);
    MonoAssembly* mono_assembly_open(const char* filename, int* status);
    gboolean mono_class_is_enum(MonoClass* klass);
    gint32 mono_class_instance_size(MonoClass* klass);
    guint32 mono_object_get_size(MonoObject* obj);
    const char* mono_image_get_filename(MonoImage* image);
    MonoAssembly* mono_assembly_load_from_full(MonoImage* image, const char* fname, int* status, gboolean refonly);
    MonoClass* mono_class_get_interfaces(MonoClass* klass, gpointer* iter);
    void mono_assembly_close(MonoAssembly* assembly);
    MonoProperty* mono_class_get_property_from_name(MonoClass* klass, const char* name);
    MonoMethod* mono_class_get_method_from_name(MonoClass* klass, const char* name, int param_count);
    MonoClass* mono_class_from_mono_type(MonoType* image);
    gboolean mono_domain_set(MonoDomain* domain, gboolean force);
    void mono_thread_push_appdomain_ref(MonoDomain* domain);
    void mono_thread_pop_appdomain_ref();
    int mono_runtime_exec_main(MonoMethod* method, MonoArray* args, MonoObject** exc);
    MonoImage* mono_get_corlib();
    MonoClassField* mono_class_get_field_from_name(MonoClass* klass, const char* name);
    guint32 mono_class_get_flags(MonoClass* klass);
    int mono_parse_default_optimizations(const char* p);
    void mono_set_defaults(int verbose_level, guint32 opts);
    void mono_set_dirs(const char* assembly_dir, const char* config_dir);
    void mono_jit_parse_options(int argc, char* argv[]);
    gpointer mono_object_unbox(MonoObject* o);
    MonoObject* mono_custom_attrs_get_attr(MonoCustomAttrInfo* ainfo, MonoClass* attr_klass);
    gboolean mono_custom_attrs_has_attr(MonoCustomAttrInfo* ainfo, MonoClass* attr_klass);
    MonoCustomAttrInfo* mono_custom_attrs_from_field(MonoClass* klass, MonoClassField* field);
    MonoCustomAttrInfo* mono_custom_attrs_from_method(MonoMethod* method);
    MonoCustomAttrInfo* mono_custom_attrs_from_class(MonoClass* klass);
    void mono_custom_attrs_free(MonoCustomAttrInfo* attr);
    void g_free(void* p);
    gboolean mono_runtime_is_shutting_down();
    MonoMethod* mono_object_get_virtual_method(MonoObject* obj, MonoMethod* method);
    gpointer mono_jit_info_get_code_start(MonoJitInfo* ji);
    int mono_jit_info_get_code_size(MonoJitInfo* ji);
    MonoClass* mono_class_from_name_case(MonoImage* image, const char* name_space, const char* name);
    MonoClass* mono_class_get_nested_types(MonoClass* klass, gpointer* iter);
    int mono_class_get_userdata_offset();
    void* mono_class_get_userdata(MonoClass* klass);
    void mono_class_set_userdata(MonoClass* klass, void* userdata);
    void mono_set_signal_chaining(gboolean chain_signals);
    LONG mono_unity_seh_handler(EXCEPTION_POINTERS* ep);
    void mono_unity_set_unhandled_exception_handler(void* handler);
    MonoObject* mono_runtime_invoke_array(MonoMethod* method, void* obj, MonoArray* params, MonoObject** exc);
    char* mono_array_addr_with_size(MonoArray* array, int size, uintptr_t idx);
    gunichar2* mono_string_to_utf16(MonoString* string_obj);
    MonoClass* mono_field_get_parent(MonoClassField* field);
    char* mono_method_full_name(MonoMethod* method, gboolean signature);
    MonoObject* mono_object_isinst(MonoObject* obj, MonoClass* klass);
    MonoString* mono_string_new_len(MonoDomain* domain, const char* text, guint length);
    MonoString* mono_string_from_utf16(gunichar2* data);
    MonoException* mono_get_exception_argument_null(const char* arg);
    MonoClass* mono_get_boolean_class();
    MonoClass* mono_get_byte_class();
    MonoClass* mono_get_char_class();
    MonoClass* mono_get_int16_class();
    MonoClass* mono_get_int64_class();
    MonoClass* mono_get_single_class();
    MonoClass* mono_get_double_class();
    gboolean mono_class_is_generic(MonoClass* klass);
    gboolean mono_class_is_inflated(MonoClass* klass);
    gboolean unity_mono_method_is_generic(MonoMethod* method);
    gboolean unity_mono_method_is_inflated(MonoMethod* method);
    gboolean mono_is_debugger_attached();
    gboolean mono_assembly_fill_assembly_name(MonoImage* image, MonoAssemblyName* aname);
    char* mono_stringify_assembly_name(MonoAssemblyName* aname);
    gboolean mono_assembly_name_parse(const char* name, MonoAssemblyName* aname);
    MonoAssembly* mono_assembly_loaded(MonoAssemblyName* aname);
    int mono_image_get_table_rows(MonoImage* image, int table_id);
    MonoClass* mono_class_get(MonoImage* image, guint32 type_token);
    gboolean mono_metadata_signature_equal(MonoMethodSignature* sig1, MonoMethodSignature* sig2);
    gboolean mono_gchandle_is_in_domain(guint32 gchandle, MonoDomain* domain);
    void mono_stack_walk(MonoStackWalk func, gpointer user_data);
    char* mono_pmip(void* ip);
    MonoObject* mono_runtime_delegate_invoke(MonoObject* delegate, void** params, MonoObject** exc);
    MonoJitInfo* mono_jit_info_table_find(MonoDomain* domain, char* addr);
    MonoDebugSourceLocation* mono_debug_lookup_source_location(MonoMethod* method, guint32 address, MonoDomain* domain);
    void mono_debug_free_source_location(MonoDebugSourceLocation* location);
    void mono_gc_wbarrier_generic_store(gpointer ptr, MonoObject* value);
    MonoType* mono_class_enum_basetype(MonoClass* klass);
    guint32 mono_class_get_type_token(MonoClass* klass);
    int mono_class_get_rank(MonoClass* klass);
    MonoClass* mono_class_get_element_class(MonoClass* klass);
    gboolean mono_unity_class_is_interface(MonoClass* klass);
    gboolean mono_unity_class_is_abstract(MonoClass* klass);
    gint32 mono_array_element_size(MonoClass* ac);
    void mono_config_parse(const char* filename);
    void mono_set_break_policy(MonoBreakPolicyFunc policy_callback);
    MonoArray* mono_custom_attrs_construct(MonoCustomAttrInfo* cinfo);
    MonoCustomAttrInfo* mono_custom_attrs_from_assembly(MonoAssembly* assembly);
    MonoArray* mono_reflection_get_custom_attrs_by_type(MonoObject* obj, MonoClass* attr_klass);
    MonoLoaderError* mono_loader_get_last_error();
    MonoException* mono_loader_error_prepare_exception(MonoLoaderError* error);
    MonoDlFallbackHandler* mono_dl_fallback_register(MonoDlFallbackLoad load_func, MonoDlFallbackSymbol symbol_func, MonoDlFallbackClose close_func, void* user_data);
    void mono_dl_fallback_unregister(MonoDlFallbackHandler* handler);
    LivenessState* mono_unity_liveness_allocate_struct(MonoClass* filter, guint max_count, register_object_callback callback, void* callback_userdata);
    void mono_unity_liveness_stop_gc_world();
    void mono_unity_liveness_finalize(LivenessState* state);
    void mono_unity_liveness_start_gc_world();
    void mono_unity_liveness_free_struct(LivenessState* state);
    LivenessState* mono_unity_liveness_calculation_begin(MonoClass* filter, guint max_count, register_object_callback callback, void* callback_userdata);
    void mono_unity_liveness_calculation_end(LivenessState* state);
    void mono_unity_liveness_calculation_from_root(MonoObject* root, LivenessState* state);
    void mono_unity_liveness_calculation_from_statics(LivenessState* state);
    void mono_trace_set_level_string(const char* value);
    void mono_trace_set_mask_string(char* value);
    gint64 mono_gc_get_used_size();
    gint64 mono_gc_get_heap_size();
}
