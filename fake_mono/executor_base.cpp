#include "stdafx.h"
#include "executor_base.h"

executor_base::executor_base(mono_wrapper::functions_cptr functions)
    : functions_(functions)
{}

mono_wrapper::functions_cptr executor_base::functions() const
{
    return functions_;
}

void executor_base::mono_thread_suspend_all_other_threads()
{
    return functions_->mono_thread_suspend_all_other_threads();
}

void executor_base::mono_thread_pool_cleanup()
{
    return functions_->mono_thread_pool_cleanup();
}

void executor_base::mono_threads_set_shutting_down()
{
    return functions_->mono_threads_set_shutting_down();
}

void executor_base::mono_runtime_set_shutting_down()
{
    return functions_->mono_runtime_set_shutting_down();
}

gboolean executor_base::mono_domain_finalize(MonoDomain* domain, int timeout)
{
    return functions_->mono_domain_finalize(domain, timeout);
}

void executor_base::mono_runtime_cleanup(MonoDomain* domain)
{
    return functions_->mono_runtime_cleanup(domain);
}

MonoMethodDesc* executor_base::mono_method_desc_new(const char* name, gboolean include_namespace)
{
    return functions_->mono_method_desc_new(name, include_namespace);
}

MonoMethod* executor_base::mono_method_desc_search_in_image(MonoMethodDesc* desc, MonoImage* image)
{
    return functions_->mono_method_desc_search_in_image(desc, image);
}

void executor_base::mono_verifier_set_mode(MiniVerifierMode m)
{
    return functions_->mono_verifier_set_mode(m);
}

void executor_base::mono_security_set_mode(MonoSecurityMode m)
{
    return functions_->mono_security_set_mode(m);
}

void executor_base::mono_add_internal_call(const char* name, gconstpointer method)
{
    return functions_->mono_add_internal_call(name, method);
}

void executor_base::mono_jit_cleanup(MonoDomain* domain)
{
    return functions_->mono_jit_cleanup(domain);
}

MonoDomain* executor_base::mono_jit_init(const char* file)
{
    return functions_->mono_jit_init(file);
}

MonoDomain* executor_base::mono_jit_init_version(const char* file, const char* runtime_version)
{
    return functions_->mono_jit_init_version(file, runtime_version);
}

int executor_base::mono_jit_exec(MonoDomain* domain, MonoAssembly* assembly, int argc, char* argv[])
{
    return functions_->mono_jit_exec(domain, assembly, argc, argv);
}

MonoClass* executor_base::mono_class_from_name(MonoImage* image, const char* name_space, const char* name)
{
    return functions_->mono_class_from_name(image, name_space, name);
}

MonoAssembly* executor_base::mono_domain_assembly_open(MonoDomain* domain, const char* name)
{
    return functions_->mono_domain_assembly_open(domain, name);
}

MonoDomain* executor_base::mono_domain_create_appdomain(const char* domainname, const char* configfile)
{
    return functions_->mono_domain_create_appdomain(domainname, configfile);
}

void executor_base::mono_domain_unload(MonoDomain* domain)
{
    return functions_->mono_domain_unload(domain);
}

MonoObject* executor_base::mono_object_new(MonoDomain* domain, MonoClass* klass)
{
    return functions_->mono_object_new(domain, klass);
}

void executor_base::mono_runtime_object_init(MonoObject* this_obj)
{
    return functions_->mono_runtime_object_init(this_obj);
}

MonoObject* executor_base::mono_runtime_invoke(MonoMethod* method, void* obj, void** params, MonoObject** exc)
{
    return functions_->mono_runtime_invoke(method, obj, params, exc);
}

void executor_base::mono_field_set_value(MonoObject* obj, MonoClassField* field, void* value)
{
    return functions_->mono_field_set_value(obj, field, value);
}

void executor_base::mono_field_get_value(MonoObject* obj, MonoClassField* field, void* value)
{
    return functions_->mono_field_get_value(obj, field, value);
}

int executor_base::mono_field_get_offset(MonoClassField* field)
{
    return functions_->mono_field_get_offset(field);
}

MonoClassField* executor_base::mono_class_get_fields(MonoClass* klass, gpointer* iter)
{
    return functions_->mono_class_get_fields(klass, iter);
}

MonoMethod* executor_base::mono_class_get_methods(MonoClass* klass, gpointer* iter)
{
    return functions_->mono_class_get_methods(klass, iter);
}

MonoDomain* executor_base::mono_domain_get()
{
    return functions_->mono_domain_get();
}

MonoDomain* executor_base::mono_get_root_domain()
{
    return functions_->mono_get_root_domain();
}

gint32 executor_base::mono_domain_get_id(MonoDomain* domain)
{
    return functions_->mono_domain_get_id(domain);
}

void executor_base::mono_assembly_foreach(GFunc func, gpointer user_data)
{
    return functions_->mono_assembly_foreach(func, user_data);
}

void executor_base::mono_image_close(MonoImage* image)
{
    return functions_->mono_image_close(image);
}

void executor_base::mono_unity_socket_security_enabled_set(gboolean b)
{
    return functions_->mono_unity_socket_security_enabled_set(b);
}

const char* executor_base::mono_image_get_name(MonoImage* image)
{
    return functions_->mono_image_get_name(image);
}

MonoClass* executor_base::mono_get_object_class()
{
    return functions_->mono_get_object_class();
}

void executor_base::mono_set_commandline_arguments(int i, const char* argv[], const char* s)
{
    return functions_->mono_set_commandline_arguments(i, argv, s);
}

const char* executor_base::mono_field_get_name(MonoClassField* field)
{
    return functions_->mono_field_get_name(field);
}

MonoType* executor_base::mono_field_get_type(MonoClassField* field)
{
    return functions_->mono_field_get_type(field);
}

int executor_base::mono_type_get_type(MonoType* type)
{
    return functions_->mono_type_get_type(type);
}

const char* executor_base::mono_method_get_name(MonoMethod* method)
{
    return functions_->mono_method_get_name(method);
}

MonoImage* executor_base::mono_assembly_get_image(MonoAssembly* assembly)
{
    return functions_->mono_assembly_get_image(assembly);
}

MonoClass* executor_base::mono_method_get_class(MonoMethod* method)
{
    return functions_->mono_method_get_class(method);
}

MonoClass* executor_base::mono_object_get_class(MonoObject* obj)
{
    return functions_->mono_object_get_class(obj);
}

gboolean executor_base::mono_class_is_valuetype(MonoClass* klass)
{
    return functions_->mono_class_is_valuetype(klass);
}

guint32 executor_base::mono_signature_get_param_count(MonoMethodSignature* sig)
{
    return functions_->mono_signature_get_param_count(sig);
}

char* executor_base::mono_string_to_utf8(MonoString* string_obj)
{
    return functions_->mono_string_to_utf8(string_obj);
}

MonoString* executor_base::mono_string_new_wrapper(const char* text)
{
    return functions_->mono_string_new_wrapper(text);
}

MonoClass* executor_base::mono_class_get_parent(MonoClass* klass)
{
    return functions_->mono_class_get_parent(klass);
}

const char* executor_base::mono_class_get_namespace(MonoClass* klass)
{
    return functions_->mono_class_get_namespace(klass);
}

gboolean executor_base::mono_class_is_subclass_of(MonoClass* klass, MonoClass* klassc, gboolean check_interfaces)
{
    return functions_->mono_class_is_subclass_of(klass, klassc, check_interfaces);
}

const char* executor_base::mono_class_get_name(MonoClass* klass)
{
    return functions_->mono_class_get_name(klass);
}

char* executor_base::mono_type_get_name(MonoType* type)
{
    return functions_->mono_type_get_name(type);
}

MonoClass* executor_base::mono_type_get_class(MonoType* type)
{
    return functions_->mono_type_get_class(type);
}

MonoException* executor_base::mono_exception_from_name_msg(MonoImage* image, const char* name_space, const char* name, const char* msg)
{
    return functions_->mono_exception_from_name_msg(image, name_space, name, msg);
}

void executor_base::mono_raise_exception(MonoException* ex)
{
    return functions_->mono_raise_exception(ex);
}

MonoClass* executor_base::mono_get_exception_class()
{
    return functions_->mono_get_exception_class();
}

MonoClass* executor_base::mono_get_array_class()
{
    return functions_->mono_get_array_class();
}

MonoClass* executor_base::mono_get_string_class()
{
    return functions_->mono_get_string_class();
}

MonoClass* executor_base::mono_get_int32_class()
{
    return functions_->mono_get_int32_class();
}

MonoArray* executor_base::mono_array_new(MonoDomain* domain, MonoClass* eclass, guint32 n)
{
    return functions_->mono_array_new(domain, eclass, n);
}

MonoArray* executor_base::mono_array_new_full(MonoDomain* domain, MonoClass* array_class, guint32* lengths, guint32* lower_bounds)
{
    return functions_->mono_array_new_full(domain, array_class, lengths, lower_bounds);
}

MonoClass* executor_base::mono_array_class_get(MonoClass* eclass, guint32 rank)
{
    return functions_->mono_array_class_get(eclass, rank);
}

gint32 executor_base::mono_class_array_element_size(MonoClass* ac)
{
    return functions_->mono_class_array_element_size(ac);
}

MonoObject* executor_base::mono_type_get_object(MonoDomain* domain, MonoType* type)
{
    return functions_->mono_type_get_object(domain, type);
}

MonoThread* executor_base::mono_thread_attach(MonoDomain* domain)
{
    return functions_->mono_thread_attach(domain);
}

void executor_base::mono_thread_detach(MonoThread* thread)
{
    return functions_->mono_thread_detach(thread);
}

MonoThread* executor_base::mono_thread_exit()
{
    return functions_->mono_thread_exit();
}

MonoThread* executor_base::mono_thread_current()
{
    return functions_->mono_thread_current();
}

void executor_base::mono_thread_set_main(MonoThread* thread)
{
    return functions_->mono_thread_set_main(thread);
}

void executor_base::mono_set_find_plugin_callback(gconstpointer method)
{
    return functions_->mono_set_find_plugin_callback(method);
}

void executor_base::mono_security_enable_core_clr()
{
    return functions_->mono_security_enable_core_clr();
}

bool executor_base::mono_security_set_core_clr_platform_callback(MonoCoreClrPlatformCB a)
{
    return functions_->mono_security_set_core_clr_platform_callback(a);
}

MonoRuntimeUnhandledExceptionPolicy executor_base::mono_runtime_unhandled_exception_policy_get()
{
    return functions_->mono_runtime_unhandled_exception_policy_get();
}

void executor_base::mono_runtime_unhandled_exception_policy_set(MonoRuntimeUnhandledExceptionPolicy policy)
{
    return functions_->mono_runtime_unhandled_exception_policy_set(policy);
}

MonoClass* executor_base::mono_class_get_nesting_type(MonoClass* klass)
{
    return functions_->mono_class_get_nesting_type(klass);
}

MonoVTable* executor_base::mono_class_vtable(MonoDomain* domain, MonoClass* klass)
{
    return functions_->mono_class_vtable(domain, klass);
}

MonoReflectionMethod* executor_base::mono_method_get_object(MonoDomain* domain, MonoMethod* method, MonoClass* refclass)
{
    return functions_->mono_method_get_object(domain, method, refclass);
}

MonoMethodSignature* executor_base::mono_method_signature(MonoMethod* method)
{
    return functions_->mono_method_signature(method);
}

MonoType* executor_base::mono_signature_get_params(MonoMethodSignature* sig, gpointer* iter)
{
    return functions_->mono_signature_get_params(sig, iter);
}

MonoType* executor_base::mono_signature_get_return_type(MonoMethodSignature* sig)
{
    return functions_->mono_signature_get_return_type(sig);
}

MonoType* executor_base::mono_class_get_type(MonoClass* klass)
{
    return functions_->mono_class_get_type(klass);
}

void executor_base::mono_set_ignore_version_and_key_when_finding_assemblies_already_loaded(gboolean value)
{
    return functions_->mono_set_ignore_version_and_key_when_finding_assemblies_already_loaded(value);
}

void executor_base::mono_debug_init(int format)
{
    return functions_->mono_debug_init(format);
}

void executor_base::mono_debug_open_image_from_memory(MonoImage* image, const char* raw_contents, int size)
{
    return functions_->mono_debug_open_image_from_memory(image, raw_contents, size);
}

guint32 executor_base::mono_field_get_flags(MonoClassField* field)
{
    return functions_->mono_field_get_flags(field);
}

MonoImage* executor_base::mono_image_open_from_data_full(const void* data, guint32 data_len, gboolean need_copy, int* status, gboolean ref_only)
{
    return functions_->mono_image_open_from_data_full(data, data_len, need_copy, status, ref_only);
}

MonoImage* executor_base::mono_image_open_from_data_with_name(char* data, guint32 data_len, gboolean need_copy, int* status, gboolean refonly, const char* name)
{
    return functions_->mono_image_open_from_data_with_name(data, data_len, need_copy, status, refonly, name);
}

MonoAssembly* executor_base::mono_assembly_load_from(MonoImage* image, const char* fname, int* status)
{
    return functions_->mono_assembly_load_from(image, fname, status);
}

MonoObject* executor_base::mono_value_box(MonoDomain* domain, MonoClass* klass, gpointer val)
{
    return functions_->mono_value_box(domain, klass, val);
}

MonoImage* executor_base::mono_class_get_image(MonoClass* klass)
{
    return functions_->mono_class_get_image(klass);
}

char executor_base::mono_signature_is_instance(MonoMethodSignature* signature)
{
    return functions_->mono_signature_is_instance(signature);
}

MonoMethod* executor_base::mono_method_get_last_managed()
{
    return functions_->mono_method_get_last_managed();
}

MonoClass* executor_base::mono_get_enum_class()
{
    return functions_->mono_get_enum_class();
}

MonoType* executor_base::mono_class_get_byref_type(MonoClass* klass)
{
    return functions_->mono_class_get_byref_type(klass);
}

void executor_base::mono_field_static_get_value(MonoVTable* vt, MonoClassField* field, void* value)
{
    return functions_->mono_field_static_get_value(vt, field, value);
}

void executor_base::mono_unity_set_embeddinghostname(const char* name)
{
    return functions_->mono_unity_set_embeddinghostname(name);
}

void executor_base::mono_set_assemblies_path(const char* name)
{
    return functions_->mono_set_assemblies_path(name);
}

guint32 executor_base::mono_gchandle_new(MonoObject* obj, gboolean pinned)
{
    return functions_->mono_gchandle_new(obj, pinned);
}

MonoObject* executor_base::mono_gchandle_get_target(guint32 gchandle)
{
    return functions_->mono_gchandle_get_target(gchandle);
}

guint32 executor_base::mono_gchandle_new_weakref(MonoObject* obj, gboolean track_resurrection)
{
    return functions_->mono_gchandle_new_weakref(obj, track_resurrection);
}

MonoObject* executor_base::mono_assembly_get_object(MonoDomain* domain, MonoAssembly* assembly)
{
    return functions_->mono_assembly_get_object(domain, assembly);
}

void executor_base::mono_gchandle_free(guint32 gchandle)
{
    return functions_->mono_gchandle_free(gchandle);
}

MonoProperty* executor_base::mono_class_get_properties(MonoClass* klass, gpointer* iter)
{
    return functions_->mono_class_get_properties(klass, iter);
}

MonoMethod* executor_base::mono_property_get_get_method(MonoProperty* prop)
{
    return functions_->mono_property_get_get_method(prop);
}

MonoObject* executor_base::mono_object_new_alloc_specific(MonoVTable* vtable)
{
    return functions_->mono_object_new_alloc_specific(vtable);
}

MonoObject* executor_base::mono_object_new_specific(MonoVTable* vtable)
{
    return functions_->mono_object_new_specific(vtable);
}

void executor_base::mono_gc_collect(int generation)
{
    return functions_->mono_gc_collect(generation);
}

int executor_base::mono_gc_max_generation()
{
    return functions_->mono_gc_max_generation();
}

MonoAssembly* executor_base::mono_image_get_assembly(MonoImage* image)
{
    return functions_->mono_image_get_assembly(image);
}

MonoAssembly* executor_base::mono_assembly_open(const char* filename, int* status)
{
    return functions_->mono_assembly_open(filename, status);
}

gboolean executor_base::mono_class_is_enum(MonoClass* klass)
{
    return functions_->mono_class_is_enum(klass);
}

gint32 executor_base::mono_class_instance_size(MonoClass* klass)
{
    return functions_->mono_class_instance_size(klass);
}

guint32 executor_base::mono_object_get_size(MonoObject* obj)
{
    return functions_->mono_object_get_size(obj);
}

const char* executor_base::mono_image_get_filename(MonoImage* image)
{
    return functions_->mono_image_get_filename(image);
}

MonoAssembly* executor_base::mono_assembly_load_from_full(MonoImage* image, const char* fname, int* status, gboolean refonly)
{
    return functions_->mono_assembly_load_from_full(image, fname, status, refonly);
}

MonoClass* executor_base::mono_class_get_interfaces(MonoClass* klass, gpointer* iter)
{
    return functions_->mono_class_get_interfaces(klass, iter);
}

void executor_base::mono_assembly_close(MonoAssembly* assembly)
{
    return functions_->mono_assembly_close(assembly);
}

MonoProperty* executor_base::mono_class_get_property_from_name(MonoClass* klass, const char* name)
{
    return functions_->mono_class_get_property_from_name(klass, name);
}

MonoMethod* executor_base::mono_class_get_method_from_name(MonoClass* klass, const char* name, int param_count)
{
    return functions_->mono_class_get_method_from_name(klass, name, param_count);
}

MonoClass* executor_base::mono_class_from_mono_type(MonoType* image)
{
    return functions_->mono_class_from_mono_type(image);
}

gboolean executor_base::mono_domain_set(MonoDomain* domain, gboolean force)
{
    return functions_->mono_domain_set(domain, force);
}

void executor_base::mono_thread_push_appdomain_ref(MonoDomain* domain)
{
    return functions_->mono_thread_push_appdomain_ref(domain);
}

void executor_base::mono_thread_pop_appdomain_ref()
{
    return functions_->mono_thread_pop_appdomain_ref();
}

int executor_base::mono_runtime_exec_main(MonoMethod* method, MonoArray* args, MonoObject** exc)
{
    return functions_->mono_runtime_exec_main(method, args, exc);
}

MonoImage* executor_base::mono_get_corlib()
{
    return functions_->mono_get_corlib();
}

MonoClassField* executor_base::mono_class_get_field_from_name(MonoClass* klass, const char* name)
{
    return functions_->mono_class_get_field_from_name(klass, name);
}

guint32 executor_base::mono_class_get_flags(MonoClass* klass)
{
    return functions_->mono_class_get_flags(klass);
}

int executor_base::mono_parse_default_optimizations(const char* p)
{
    return functions_->mono_parse_default_optimizations(p);
}

void executor_base::mono_set_defaults(int verbose_level, guint32 opts)
{
    return functions_->mono_set_defaults(verbose_level, opts);
}

void executor_base::mono_set_dirs(const char* assembly_dir, const char* config_dir)
{
    return functions_->mono_set_dirs(assembly_dir, config_dir);
}

void executor_base::mono_jit_parse_options(int argc, char* argv[])
{
    return functions_->mono_jit_parse_options(argc, argv);
}

gpointer executor_base::mono_object_unbox(MonoObject* o)
{
    return functions_->mono_object_unbox(o);
}

MonoObject* executor_base::mono_custom_attrs_get_attr(MonoCustomAttrInfo* ainfo, MonoClass* attr_klass)
{
    return functions_->mono_custom_attrs_get_attr(ainfo, attr_klass);
}

gboolean executor_base::mono_custom_attrs_has_attr(MonoCustomAttrInfo* ainfo, MonoClass* attr_klass)
{
    return functions_->mono_custom_attrs_has_attr(ainfo, attr_klass);
}

MonoCustomAttrInfo* executor_base::mono_custom_attrs_from_field(MonoClass* klass, MonoClassField* field)
{
    return functions_->mono_custom_attrs_from_field(klass, field);
}

MonoCustomAttrInfo* executor_base::mono_custom_attrs_from_method(MonoMethod* method)
{
    return functions_->mono_custom_attrs_from_method(method);
}

MonoCustomAttrInfo* executor_base::mono_custom_attrs_from_class(MonoClass* klass)
{
    return functions_->mono_custom_attrs_from_class(klass);
}

void executor_base::mono_custom_attrs_free(MonoCustomAttrInfo* attr)
{
    return functions_->mono_custom_attrs_free(attr);
}

void executor_base::g_free(void* p)
{
    return functions_->g_free(p);
}

gboolean executor_base::mono_runtime_is_shutting_down()
{
    return functions_->mono_runtime_is_shutting_down();
}

MonoMethod* executor_base::mono_object_get_virtual_method(MonoObject* obj, MonoMethod* method)
{
    return functions_->mono_object_get_virtual_method(obj, method);
}

gpointer executor_base::mono_jit_info_get_code_start(MonoJitInfo* ji)
{
    return functions_->mono_jit_info_get_code_start(ji);
}

int executor_base::mono_jit_info_get_code_size(MonoJitInfo* ji)
{
    return functions_->mono_jit_info_get_code_size(ji);
}

MonoClass* executor_base::mono_class_from_name_case(MonoImage* image, const char* name_space, const char* name)
{
    return functions_->mono_class_from_name_case(image, name_space, name);
}

MonoClass* executor_base::mono_class_get_nested_types(MonoClass* klass, gpointer* iter)
{
    return functions_->mono_class_get_nested_types(klass, iter);
}

int executor_base::mono_class_get_userdata_offset()
{
    return functions_->mono_class_get_userdata_offset();
}

void* executor_base::mono_class_get_userdata(MonoClass* klass)
{
    return functions_->mono_class_get_userdata(klass);
}

void executor_base::mono_class_set_userdata(MonoClass* klass, void* userdata)
{
    return functions_->mono_class_set_userdata(klass, userdata);
}

void executor_base::mono_set_signal_chaining(gboolean chain_signals)
{
    return functions_->mono_set_signal_chaining(chain_signals);
}

LONG executor_base::mono_unity_seh_handler(EXCEPTION_POINTERS* ep)
{
    return functions_->mono_unity_seh_handler(ep);
}

void executor_base::mono_unity_set_unhandled_exception_handler(void* handler)
{
    return functions_->mono_unity_set_unhandled_exception_handler(handler);
}

MonoObject* executor_base::mono_runtime_invoke_array(MonoMethod* method, void* obj, MonoArray* params, MonoObject** exc)
{
    return functions_->mono_runtime_invoke_array(method, obj, params, exc);
}

char* executor_base::mono_array_addr_with_size(MonoArray* array, int size, uintptr_t idx)
{
    return functions_->mono_array_addr_with_size(array, size, idx);
}

gunichar2* executor_base::mono_string_to_utf16(MonoString* string_obj)
{
    return functions_->mono_string_to_utf16(string_obj);
}

MonoClass* executor_base::mono_field_get_parent(MonoClassField* field)
{
    return functions_->mono_field_get_parent(field);
}

char* executor_base::mono_method_full_name(MonoMethod* method, gboolean signature)
{
    return functions_->mono_method_full_name(method, signature);
}

MonoObject* executor_base::mono_object_isinst(MonoObject* obj, MonoClass* klass)
{
    return functions_->mono_object_isinst(obj, klass);
}

MonoString* executor_base::mono_string_new_len(MonoDomain* domain, const char* text, guint length)
{
    return functions_->mono_string_new_len(domain, text, length);
}

MonoString* executor_base::mono_string_from_utf16(gunichar2* data)
{
    return functions_->mono_string_from_utf16(data);
}

MonoException* executor_base::mono_get_exception_argument_null(const char* arg)
{
    return functions_->mono_get_exception_argument_null(arg);
}

MonoClass* executor_base::mono_get_boolean_class()
{
    return functions_->mono_get_boolean_class();
}

MonoClass* executor_base::mono_get_byte_class()
{
    return functions_->mono_get_byte_class();
}

MonoClass* executor_base::mono_get_char_class()
{
    return functions_->mono_get_char_class();
}

MonoClass* executor_base::mono_get_int16_class()
{
    return functions_->mono_get_int16_class();
}

MonoClass* executor_base::mono_get_int64_class()
{
    return functions_->mono_get_int64_class();
}

MonoClass* executor_base::mono_get_single_class()
{
    return functions_->mono_get_single_class();
}

MonoClass* executor_base::mono_get_double_class()
{
    return functions_->mono_get_double_class();
}

gboolean executor_base::mono_class_is_generic(MonoClass* klass)
{
    return functions_->mono_class_is_generic(klass);
}

gboolean executor_base::mono_class_is_inflated(MonoClass* klass)
{
    return functions_->mono_class_is_inflated(klass);
}

gboolean executor_base::unity_mono_method_is_generic(MonoMethod* method)
{
    return functions_->unity_mono_method_is_generic(method);
}

gboolean executor_base::unity_mono_method_is_inflated(MonoMethod* method)
{
    return functions_->unity_mono_method_is_inflated(method);
}

gboolean executor_base::mono_is_debugger_attached()
{
    return functions_->mono_is_debugger_attached();
}

gboolean executor_base::mono_assembly_fill_assembly_name(MonoImage* image, MonoAssemblyName* aname)
{
    return functions_->mono_assembly_fill_assembly_name(image, aname);
}

char* executor_base::mono_stringify_assembly_name(MonoAssemblyName* aname)
{
    return functions_->mono_stringify_assembly_name(aname);
}

gboolean executor_base::mono_assembly_name_parse(const char* name, MonoAssemblyName* aname)
{
    return functions_->mono_assembly_name_parse(name, aname);
}

MonoAssembly* executor_base::mono_assembly_loaded(MonoAssemblyName* aname)
{
    return functions_->mono_assembly_loaded(aname);
}

int executor_base::mono_image_get_table_rows(MonoImage* image, int table_id)
{
    return functions_->mono_image_get_table_rows(image, table_id);
}

MonoClass* executor_base::mono_class_get(MonoImage* image, guint32 type_token)
{
    return functions_->mono_class_get(image, type_token);
}

gboolean executor_base::mono_metadata_signature_equal(MonoMethodSignature* sig1, MonoMethodSignature* sig2)
{
    return functions_->mono_metadata_signature_equal(sig1, sig2);
}

gboolean executor_base::mono_gchandle_is_in_domain(guint32 gchandle, MonoDomain* domain)
{
    return functions_->mono_gchandle_is_in_domain(gchandle, domain);
}

void executor_base::mono_stack_walk(MonoStackWalk func, gpointer user_data)
{
    return functions_->mono_stack_walk(func, user_data);
}

char* executor_base::mono_pmip(void* ip)
{
    return functions_->mono_pmip(ip);
}

MonoObject* executor_base::mono_runtime_delegate_invoke(MonoObject* delegate, void** params, MonoObject** exc)
{
    return functions_->mono_runtime_delegate_invoke(delegate, params, exc);
}

MonoJitInfo* executor_base::mono_jit_info_table_find(MonoDomain* domain, char* addr)
{
    return functions_->mono_jit_info_table_find(domain, addr);
}

MonoDebugSourceLocation* executor_base::mono_debug_lookup_source_location(MonoMethod* method, guint32 address, MonoDomain* domain)
{
    return functions_->mono_debug_lookup_source_location(method, address, domain);
}

void executor_base::mono_debug_free_source_location(MonoDebugSourceLocation* location)
{
    return functions_->mono_debug_free_source_location(location);
}

void executor_base::mono_gc_wbarrier_generic_store(gpointer ptr, MonoObject* value)
{
    return functions_->mono_gc_wbarrier_generic_store(ptr, value);
}

MonoType* executor_base::mono_class_enum_basetype(MonoClass* klass)
{
    return functions_->mono_class_enum_basetype(klass);
}

guint32 executor_base::mono_class_get_type_token(MonoClass* klass)
{
    return functions_->mono_class_get_type_token(klass);
}

int executor_base::mono_class_get_rank(MonoClass* klass)
{
    return functions_->mono_class_get_rank(klass);
}

MonoClass* executor_base::mono_class_get_element_class(MonoClass* klass)
{
    return functions_->mono_class_get_element_class(klass);
}

gboolean executor_base::mono_unity_class_is_interface(MonoClass* klass)
{
    return functions_->mono_unity_class_is_interface(klass);
}

gboolean executor_base::mono_unity_class_is_abstract(MonoClass* klass)
{
    return functions_->mono_unity_class_is_abstract(klass);
}

gint32 executor_base::mono_array_element_size(MonoClass* ac)
{
    return functions_->mono_array_element_size(ac);
}

void executor_base::mono_config_parse(const char* filename)
{
    return functions_->mono_config_parse(filename);
}

void executor_base::mono_set_break_policy(MonoBreakPolicyFunc policy_callback)
{
    return functions_->mono_set_break_policy(policy_callback);
}

MonoArray* executor_base::mono_custom_attrs_construct(MonoCustomAttrInfo* cinfo)
{
    return functions_->mono_custom_attrs_construct(cinfo);
}

MonoCustomAttrInfo* executor_base::mono_custom_attrs_from_assembly(MonoAssembly* assembly)
{
    return functions_->mono_custom_attrs_from_assembly(assembly);
}

MonoArray* executor_base::mono_reflection_get_custom_attrs_by_type(MonoObject* obj, MonoClass* attr_klass)
{
    return functions_->mono_reflection_get_custom_attrs_by_type(obj, attr_klass);
}

MonoLoaderError* executor_base::mono_loader_get_last_error()
{
    return functions_->mono_loader_get_last_error();
}

MonoException* executor_base::mono_loader_error_prepare_exception(MonoLoaderError* error)
{
    return functions_->mono_loader_error_prepare_exception(error);
}

MonoDlFallbackHandler* executor_base::mono_dl_fallback_register(MonoDlFallbackLoad load_func, MonoDlFallbackSymbol symbol_func, MonoDlFallbackClose close_func, void* user_data)
{
    return functions_->mono_dl_fallback_register(load_func, symbol_func, close_func, user_data);
}

void executor_base::mono_dl_fallback_unregister(MonoDlFallbackHandler* handler)
{
    return functions_->mono_dl_fallback_unregister(handler);
}

LivenessState* executor_base::mono_unity_liveness_allocate_struct(MonoClass* filter, guint max_count, register_object_callback callback, void* callback_userdata)
{
    return functions_->mono_unity_liveness_allocate_struct(filter, max_count, callback, callback_userdata);
}

void executor_base::mono_unity_liveness_stop_gc_world()
{
    return functions_->mono_unity_liveness_stop_gc_world();
}

void executor_base::mono_unity_liveness_finalize(LivenessState* state)
{
    return functions_->mono_unity_liveness_finalize(state);
}

void executor_base::mono_unity_liveness_start_gc_world()
{
    return functions_->mono_unity_liveness_start_gc_world();
}

void executor_base::mono_unity_liveness_free_struct(LivenessState* state)
{
    return functions_->mono_unity_liveness_free_struct(state);
}

LivenessState* executor_base::mono_unity_liveness_calculation_begin(MonoClass* filter, guint max_count, register_object_callback callback, void* callback_userdata)
{
    return functions_->mono_unity_liveness_calculation_begin(filter, max_count, callback, callback_userdata);
}

void executor_base::mono_unity_liveness_calculation_end(LivenessState* state)
{
    return functions_->mono_unity_liveness_calculation_end(state);
}

void executor_base::mono_unity_liveness_calculation_from_root(MonoObject* root, LivenessState* state)
{
    return functions_->mono_unity_liveness_calculation_from_root(root, state);
}

void executor_base::mono_unity_liveness_calculation_from_statics(LivenessState* state)
{
    return functions_->mono_unity_liveness_calculation_from_statics(state);
}

void executor_base::mono_trace_set_level_string(const char* value)
{
    return functions_->mono_trace_set_level_string(value);
}

void executor_base::mono_trace_set_mask_string(char* value)
{
    return functions_->mono_trace_set_mask_string(value);
}

gint64 executor_base::mono_gc_get_used_size()
{
    return functions_->mono_gc_get_used_size();
}

gint64 executor_base::mono_gc_get_heap_size()
{
    return functions_->mono_gc_get_heap_size();
}

