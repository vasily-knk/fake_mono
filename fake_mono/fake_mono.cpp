#include "stdafx.h"
#include "executor.h"
#include "function_defs.h"

namespace 
{
executor_ptr executor_instance()
{
    static executor_ptr ex = create_executor();
    return ex;
}

} // namespace 
void mono_thread_suspend_all_other_threads()
{
    return executor_instance()->mono_thread_suspend_all_other_threads();
}

void mono_thread_pool_cleanup()
{
    return executor_instance()->mono_thread_pool_cleanup();
}

void mono_threads_set_shutting_down()
{
    return executor_instance()->mono_threads_set_shutting_down();
}

void mono_runtime_set_shutting_down()
{
    return executor_instance()->mono_runtime_set_shutting_down();
}

gboolean mono_domain_finalize(MonoDomain* domain, int timeout)
{
    return executor_instance()->mono_domain_finalize(domain, timeout);
}

void mono_runtime_cleanup(MonoDomain* domain)
{
    return executor_instance()->mono_runtime_cleanup(domain);
}

MonoMethodDesc* mono_method_desc_new(const char* name, gboolean include_namespace)
{
    return executor_instance()->mono_method_desc_new(name, include_namespace);
}

MonoMethod* mono_method_desc_search_in_image(MonoMethodDesc* desc, MonoImage* image)
{
    return executor_instance()->mono_method_desc_search_in_image(desc, image);
}

void mono_verifier_set_mode(MiniVerifierMode m)
{
    return executor_instance()->mono_verifier_set_mode(m);
}

void mono_security_set_mode(MonoSecurityMode m)
{
    return executor_instance()->mono_security_set_mode(m);
}

void mono_add_internal_call(const char* name, gconstpointer method)
{
    return executor_instance()->mono_add_internal_call(name, method);
}

void mono_jit_cleanup(MonoDomain* domain)
{
    return executor_instance()->mono_jit_cleanup(domain);
}

MonoDomain* mono_jit_init(const char* file)
{
    return executor_instance()->mono_jit_init(file);
}

MonoDomain* mono_jit_init_version(const char* file, const char* runtime_version)
{
    return executor_instance()->mono_jit_init_version(file, runtime_version);
}

int mono_jit_exec(MonoDomain* domain, MonoAssembly* assembly, int argc, char* argv[])
{
    return executor_instance()->mono_jit_exec(domain, assembly, argc, argv);
}

MonoClass* mono_class_from_name(MonoImage* image, const char* name_space, const char* name)
{
    return executor_instance()->mono_class_from_name(image, name_space, name);
}

MonoAssembly* mono_domain_assembly_open(MonoDomain* domain, const char* name)
{
    return executor_instance()->mono_domain_assembly_open(domain, name);
}

MonoDomain* mono_domain_create_appdomain(const char* domainname, const char* configfile)
{
    return executor_instance()->mono_domain_create_appdomain(domainname, configfile);
}

void mono_domain_unload(MonoDomain* domain)
{
    return executor_instance()->mono_domain_unload(domain);
}

MonoObject* mono_object_new(MonoDomain* domain, MonoClass* klass)
{
    return executor_instance()->mono_object_new(domain, klass);
}

void mono_runtime_object_init(MonoObject* this_obj)
{
    return executor_instance()->mono_runtime_object_init(this_obj);
}

MonoObject* mono_runtime_invoke(MonoMethod* method, void* obj, void** params, MonoObject** exc)
{
    return executor_instance()->mono_runtime_invoke(method, obj, params, exc);
}

void mono_field_set_value(MonoObject* obj, MonoClassField* field, void* value)
{
    return executor_instance()->mono_field_set_value(obj, field, value);
}

void mono_field_get_value(MonoObject* obj, MonoClassField* field, void* value)
{
    return executor_instance()->mono_field_get_value(obj, field, value);
}

int mono_field_get_offset(MonoClassField* field)
{
    return executor_instance()->mono_field_get_offset(field);
}

MonoClassField* mono_class_get_fields(MonoClass* klass, gpointer* iter)
{
    return executor_instance()->mono_class_get_fields(klass, iter);
}

MonoMethod* mono_class_get_methods(MonoClass* klass, gpointer* iter)
{
    return executor_instance()->mono_class_get_methods(klass, iter);
}

MonoDomain* mono_domain_get()
{
    return executor_instance()->mono_domain_get();
}

MonoDomain* mono_get_root_domain()
{
    return executor_instance()->mono_get_root_domain();
}

gint32 mono_domain_get_id(MonoDomain* domain)
{
    return executor_instance()->mono_domain_get_id(domain);
}

void mono_assembly_foreach(GFunc func, gpointer user_data)
{
    return executor_instance()->mono_assembly_foreach(func, user_data);
}

void mono_image_close(MonoImage* image)
{
    return executor_instance()->mono_image_close(image);
}

void mono_unity_socket_security_enabled_set(gboolean b)
{
    return executor_instance()->mono_unity_socket_security_enabled_set(b);
}

const char* mono_image_get_name(MonoImage* image)
{
    return executor_instance()->mono_image_get_name(image);
}

MonoClass* mono_get_object_class()
{
    return executor_instance()->mono_get_object_class();
}

void mono_set_commandline_arguments(int i, const char* argv[], const char* s)
{
    return executor_instance()->mono_set_commandline_arguments(i, argv, s);
}

const char* mono_field_get_name(MonoClassField* field)
{
    return executor_instance()->mono_field_get_name(field);
}

MonoType* mono_field_get_type(MonoClassField* field)
{
    return executor_instance()->mono_field_get_type(field);
}

int mono_type_get_type(MonoType* type)
{
    return executor_instance()->mono_type_get_type(type);
}

const char* mono_method_get_name(MonoMethod* method)
{
    return executor_instance()->mono_method_get_name(method);
}

MonoImage* mono_assembly_get_image(MonoAssembly* assembly)
{
    return executor_instance()->mono_assembly_get_image(assembly);
}

MonoClass* mono_method_get_class(MonoMethod* method)
{
    return executor_instance()->mono_method_get_class(method);
}

MonoClass* mono_object_get_class(MonoObject* obj)
{
    return executor_instance()->mono_object_get_class(obj);
}

gboolean mono_class_is_valuetype(MonoClass* klass)
{
    return executor_instance()->mono_class_is_valuetype(klass);
}

guint32 mono_signature_get_param_count(MonoMethodSignature* sig)
{
    return executor_instance()->mono_signature_get_param_count(sig);
}

char* mono_string_to_utf8(MonoString* string_obj)
{
    return executor_instance()->mono_string_to_utf8(string_obj);
}

MonoString* mono_string_new_wrapper(const char* text)
{
    return executor_instance()->mono_string_new_wrapper(text);
}

MonoClass* mono_class_get_parent(MonoClass* klass)
{
    return executor_instance()->mono_class_get_parent(klass);
}

const char* mono_class_get_namespace(MonoClass* klass)
{
    return executor_instance()->mono_class_get_namespace(klass);
}

gboolean mono_class_is_subclass_of(MonoClass* klass, MonoClass* klassc, gboolean check_interfaces)
{
    return executor_instance()->mono_class_is_subclass_of(klass, klassc, check_interfaces);
}

const char* mono_class_get_name(MonoClass* klass)
{
    return executor_instance()->mono_class_get_name(klass);
}

char* mono_type_get_name(MonoType* type)
{
    return executor_instance()->mono_type_get_name(type);
}

MonoClass* mono_type_get_class(MonoType* type)
{
    return executor_instance()->mono_type_get_class(type);
}

MonoException* mono_exception_from_name_msg(MonoImage* image, const char* name_space, const char* name, const char* msg)
{
    return executor_instance()->mono_exception_from_name_msg(image, name_space, name, msg);
}

void mono_raise_exception(MonoException* ex)
{
    return executor_instance()->mono_raise_exception(ex);
}

MonoClass* mono_get_exception_class()
{
    return executor_instance()->mono_get_exception_class();
}

MonoClass* mono_get_array_class()
{
    return executor_instance()->mono_get_array_class();
}

MonoClass* mono_get_string_class()
{
    return executor_instance()->mono_get_string_class();
}

MonoClass* mono_get_int32_class()
{
    return executor_instance()->mono_get_int32_class();
}

MonoArray* mono_array_new(MonoDomain* domain, MonoClass* eclass, guint32 n)
{
    return executor_instance()->mono_array_new(domain, eclass, n);
}

MonoArray* mono_array_new_full(MonoDomain* domain, MonoClass* array_class, guint32* lengths, guint32* lower_bounds)
{
    return executor_instance()->mono_array_new_full(domain, array_class, lengths, lower_bounds);
}

MonoClass* mono_array_class_get(MonoClass* eclass, guint32 rank)
{
    return executor_instance()->mono_array_class_get(eclass, rank);
}

gint32 mono_class_array_element_size(MonoClass* ac)
{
    return executor_instance()->mono_class_array_element_size(ac);
}

MonoObject* mono_type_get_object(MonoDomain* domain, MonoType* type)
{
    return executor_instance()->mono_type_get_object(domain, type);
}

MonoThread* mono_thread_attach(MonoDomain* domain)
{
    return executor_instance()->mono_thread_attach(domain);
}

void mono_thread_detach(MonoThread* thread)
{
    return executor_instance()->mono_thread_detach(thread);
}

MonoThread* mono_thread_exit()
{
    return executor_instance()->mono_thread_exit();
}

MonoThread* mono_thread_current()
{
    return executor_instance()->mono_thread_current();
}

void mono_thread_set_main(MonoThread* thread)
{
    return executor_instance()->mono_thread_set_main(thread);
}

void mono_set_find_plugin_callback(gconstpointer method)
{
    return executor_instance()->mono_set_find_plugin_callback(method);
}

void mono_security_enable_core_clr()
{
    return executor_instance()->mono_security_enable_core_clr();
}

bool mono_security_set_core_clr_platform_callback(MonoCoreClrPlatformCB a)
{
    return executor_instance()->mono_security_set_core_clr_platform_callback(a);
}

MonoRuntimeUnhandledExceptionPolicy mono_runtime_unhandled_exception_policy_get()
{
    return executor_instance()->mono_runtime_unhandled_exception_policy_get();
}

void mono_runtime_unhandled_exception_policy_set(MonoRuntimeUnhandledExceptionPolicy policy)
{
    return executor_instance()->mono_runtime_unhandled_exception_policy_set(policy);
}

MonoClass* mono_class_get_nesting_type(MonoClass* klass)
{
    return executor_instance()->mono_class_get_nesting_type(klass);
}

MonoVTable* mono_class_vtable(MonoDomain* domain, MonoClass* klass)
{
    return executor_instance()->mono_class_vtable(domain, klass);
}

MonoReflectionMethod* mono_method_get_object(MonoDomain* domain, MonoMethod* method, MonoClass* refclass)
{
    return executor_instance()->mono_method_get_object(domain, method, refclass);
}

MonoMethodSignature* mono_method_signature(MonoMethod* method)
{
    return executor_instance()->mono_method_signature(method);
}

MonoType* mono_signature_get_params(MonoMethodSignature* sig, gpointer* iter)
{
    return executor_instance()->mono_signature_get_params(sig, iter);
}

MonoType* mono_signature_get_return_type(MonoMethodSignature* sig)
{
    return executor_instance()->mono_signature_get_return_type(sig);
}

MonoType* mono_class_get_type(MonoClass* klass)
{
    return executor_instance()->mono_class_get_type(klass);
}

void mono_set_ignore_version_and_key_when_finding_assemblies_already_loaded(gboolean value)
{
    return executor_instance()->mono_set_ignore_version_and_key_when_finding_assemblies_already_loaded(value);
}

void mono_debug_init(int format)
{
    return executor_instance()->mono_debug_init(format);
}

void mono_debug_open_image_from_memory(MonoImage* image, const char* raw_contents, int size)
{
    return executor_instance()->mono_debug_open_image_from_memory(image, raw_contents, size);
}

guint32 mono_field_get_flags(MonoClassField* field)
{
    return executor_instance()->mono_field_get_flags(field);
}

MonoImage* mono_image_open_from_data_full(const void* data, guint32 data_len, gboolean need_copy, int* status, gboolean ref_only)
{
    return executor_instance()->mono_image_open_from_data_full(data, data_len, need_copy, status, ref_only);
}

MonoImage* mono_image_open_from_data_with_name(char* data, guint32 data_len, gboolean need_copy, int* status, gboolean refonly, const char* name)
{
    return executor_instance()->mono_image_open_from_data_with_name(data, data_len, need_copy, status, refonly, name);
}

MonoAssembly* mono_assembly_load_from(MonoImage* image, const char* fname, int* status)
{
    return executor_instance()->mono_assembly_load_from(image, fname, status);
}

MonoObject* mono_value_box(MonoDomain* domain, MonoClass* klass, gpointer val)
{
    return executor_instance()->mono_value_box(domain, klass, val);
}

MonoImage* mono_class_get_image(MonoClass* klass)
{
    return executor_instance()->mono_class_get_image(klass);
}

char mono_signature_is_instance(MonoMethodSignature* signature)
{
    return executor_instance()->mono_signature_is_instance(signature);
}

MonoMethod* mono_method_get_last_managed()
{
    return executor_instance()->mono_method_get_last_managed();
}

MonoClass* mono_get_enum_class()
{
    return executor_instance()->mono_get_enum_class();
}

MonoType* mono_class_get_byref_type(MonoClass* klass)
{
    return executor_instance()->mono_class_get_byref_type(klass);
}

void mono_field_static_get_value(MonoVTable* vt, MonoClassField* field, void* value)
{
    return executor_instance()->mono_field_static_get_value(vt, field, value);
}

void mono_unity_set_embeddinghostname(const char* name)
{
    return executor_instance()->mono_unity_set_embeddinghostname(name);
}

void mono_set_assemblies_path(const char* name)
{
    return executor_instance()->mono_set_assemblies_path(name);
}

guint32 mono_gchandle_new(MonoObject* obj, gboolean pinned)
{
    return executor_instance()->mono_gchandle_new(obj, pinned);
}

MonoObject* mono_gchandle_get_target(guint32 gchandle)
{
    return executor_instance()->mono_gchandle_get_target(gchandle);
}

guint32 mono_gchandle_new_weakref(MonoObject* obj, gboolean track_resurrection)
{
    return executor_instance()->mono_gchandle_new_weakref(obj, track_resurrection);
}

MonoObject* mono_assembly_get_object(MonoDomain* domain, MonoAssembly* assembly)
{
    return executor_instance()->mono_assembly_get_object(domain, assembly);
}

void mono_gchandle_free(guint32 gchandle)
{
    return executor_instance()->mono_gchandle_free(gchandle);
}

MonoProperty* mono_class_get_properties(MonoClass* klass, gpointer* iter)
{
    return executor_instance()->mono_class_get_properties(klass, iter);
}

MonoMethod* mono_property_get_get_method(MonoProperty* prop)
{
    return executor_instance()->mono_property_get_get_method(prop);
}

MonoObject* mono_object_new_alloc_specific(MonoVTable* vtable)
{
    return executor_instance()->mono_object_new_alloc_specific(vtable);
}

MonoObject* mono_object_new_specific(MonoVTable* vtable)
{
    return executor_instance()->mono_object_new_specific(vtable);
}

void mono_gc_collect(int generation)
{
    return executor_instance()->mono_gc_collect(generation);
}

int mono_gc_max_generation()
{
    return executor_instance()->mono_gc_max_generation();
}

MonoAssembly* mono_image_get_assembly(MonoImage* image)
{
    return executor_instance()->mono_image_get_assembly(image);
}

MonoAssembly* mono_assembly_open(const char* filename, int* status)
{
    return executor_instance()->mono_assembly_open(filename, status);
}

gboolean mono_class_is_enum(MonoClass* klass)
{
    return executor_instance()->mono_class_is_enum(klass);
}

gint32 mono_class_instance_size(MonoClass* klass)
{
    return executor_instance()->mono_class_instance_size(klass);
}

guint32 mono_object_get_size(MonoObject* obj)
{
    return executor_instance()->mono_object_get_size(obj);
}

const char* mono_image_get_filename(MonoImage* image)
{
    return executor_instance()->mono_image_get_filename(image);
}

MonoAssembly* mono_assembly_load_from_full(MonoImage* image, const char* fname, int* status, gboolean refonly)
{
    return executor_instance()->mono_assembly_load_from_full(image, fname, status, refonly);
}

MonoClass* mono_class_get_interfaces(MonoClass* klass, gpointer* iter)
{
    return executor_instance()->mono_class_get_interfaces(klass, iter);
}

void mono_assembly_close(MonoAssembly* assembly)
{
    return executor_instance()->mono_assembly_close(assembly);
}

MonoProperty* mono_class_get_property_from_name(MonoClass* klass, const char* name)
{
    return executor_instance()->mono_class_get_property_from_name(klass, name);
}

MonoMethod* mono_class_get_method_from_name(MonoClass* klass, const char* name, int param_count)
{
    return executor_instance()->mono_class_get_method_from_name(klass, name, param_count);
}

MonoClass* mono_class_from_mono_type(MonoType* image)
{
    return executor_instance()->mono_class_from_mono_type(image);
}

gboolean mono_domain_set(MonoDomain* domain, gboolean force)
{
    return executor_instance()->mono_domain_set(domain, force);
}

void mono_thread_push_appdomain_ref(MonoDomain* domain)
{
    return executor_instance()->mono_thread_push_appdomain_ref(domain);
}

void mono_thread_pop_appdomain_ref()
{
    return executor_instance()->mono_thread_pop_appdomain_ref();
}

int mono_runtime_exec_main(MonoMethod* method, MonoArray* args, MonoObject** exc)
{
    return executor_instance()->mono_runtime_exec_main(method, args, exc);
}

MonoImage* mono_get_corlib()
{
    return executor_instance()->mono_get_corlib();
}

MonoClassField* mono_class_get_field_from_name(MonoClass* klass, const char* name)
{
    return executor_instance()->mono_class_get_field_from_name(klass, name);
}

guint32 mono_class_get_flags(MonoClass* klass)
{
    return executor_instance()->mono_class_get_flags(klass);
}

int mono_parse_default_optimizations(const char* p)
{
    return executor_instance()->mono_parse_default_optimizations(p);
}

void mono_set_defaults(int verbose_level, guint32 opts)
{
    return executor_instance()->mono_set_defaults(verbose_level, opts);
}

void mono_set_dirs(const char* assembly_dir, const char* config_dir)
{
    return executor_instance()->mono_set_dirs(assembly_dir, config_dir);
}

void mono_jit_parse_options(int argc, char* argv[])
{
    return executor_instance()->mono_jit_parse_options(argc, argv);
}

gpointer mono_object_unbox(MonoObject* o)
{
    return executor_instance()->mono_object_unbox(o);
}

MonoObject* mono_custom_attrs_get_attr(MonoCustomAttrInfo* ainfo, MonoClass* attr_klass)
{
    return executor_instance()->mono_custom_attrs_get_attr(ainfo, attr_klass);
}

gboolean mono_custom_attrs_has_attr(MonoCustomAttrInfo* ainfo, MonoClass* attr_klass)
{
    return executor_instance()->mono_custom_attrs_has_attr(ainfo, attr_klass);
}

MonoCustomAttrInfo* mono_custom_attrs_from_field(MonoClass* klass, MonoClassField* field)
{
    return executor_instance()->mono_custom_attrs_from_field(klass, field);
}

MonoCustomAttrInfo* mono_custom_attrs_from_method(MonoMethod* method)
{
    return executor_instance()->mono_custom_attrs_from_method(method);
}

MonoCustomAttrInfo* mono_custom_attrs_from_class(MonoClass* klass)
{
    return executor_instance()->mono_custom_attrs_from_class(klass);
}

void mono_custom_attrs_free(MonoCustomAttrInfo* attr)
{
    return executor_instance()->mono_custom_attrs_free(attr);
}

void g_free(void* p)
{
    return executor_instance()->g_free(p);
}

gboolean mono_runtime_is_shutting_down()
{
    return executor_instance()->mono_runtime_is_shutting_down();
}

MonoMethod* mono_object_get_virtual_method(MonoObject* obj, MonoMethod* method)
{
    return executor_instance()->mono_object_get_virtual_method(obj, method);
}

gpointer mono_jit_info_get_code_start(MonoJitInfo* ji)
{
    return executor_instance()->mono_jit_info_get_code_start(ji);
}

int mono_jit_info_get_code_size(MonoJitInfo* ji)
{
    return executor_instance()->mono_jit_info_get_code_size(ji);
}

MonoClass* mono_class_from_name_case(MonoImage* image, const char* name_space, const char* name)
{
    return executor_instance()->mono_class_from_name_case(image, name_space, name);
}

MonoClass* mono_class_get_nested_types(MonoClass* klass, gpointer* iter)
{
    return executor_instance()->mono_class_get_nested_types(klass, iter);
}

int mono_class_get_userdata_offset()
{
    return executor_instance()->mono_class_get_userdata_offset();
}

void* mono_class_get_userdata(MonoClass* klass)
{
    return executor_instance()->mono_class_get_userdata(klass);
}

void mono_class_set_userdata(MonoClass* klass, void* userdata)
{
    return executor_instance()->mono_class_set_userdata(klass, userdata);
}

void mono_set_signal_chaining(gboolean chain_signals)
{
    return executor_instance()->mono_set_signal_chaining(chain_signals);
}

LONG mono_unity_seh_handler(EXCEPTION_POINTERS* ep)
{
    return executor_instance()->mono_unity_seh_handler(ep);
}

void mono_unity_set_unhandled_exception_handler(void* handler)
{
    return executor_instance()->mono_unity_set_unhandled_exception_handler(handler);
}

MonoObject* mono_runtime_invoke_array(MonoMethod* method, void* obj, MonoArray* params, MonoObject** exc)
{
    return executor_instance()->mono_runtime_invoke_array(method, obj, params, exc);
}

char* mono_array_addr_with_size(MonoArray* array, int size, uintptr_t idx)
{
    return executor_instance()->mono_array_addr_with_size(array, size, idx);
}

gunichar2* mono_string_to_utf16(MonoString* string_obj)
{
    return executor_instance()->mono_string_to_utf16(string_obj);
}

MonoClass* mono_field_get_parent(MonoClassField* field)
{
    return executor_instance()->mono_field_get_parent(field);
}

char* mono_method_full_name(MonoMethod* method, gboolean signature)
{
    return executor_instance()->mono_method_full_name(method, signature);
}

MonoObject* mono_object_isinst(MonoObject* obj, MonoClass* klass)
{
    return executor_instance()->mono_object_isinst(obj, klass);
}

MonoString* mono_string_new_len(MonoDomain* domain, const char* text, guint length)
{
    return executor_instance()->mono_string_new_len(domain, text, length);
}

MonoString* mono_string_from_utf16(gunichar2* data)
{
    return executor_instance()->mono_string_from_utf16(data);
}

MonoException* mono_get_exception_argument_null(const char* arg)
{
    return executor_instance()->mono_get_exception_argument_null(arg);
}

MonoClass* mono_get_boolean_class()
{
    return executor_instance()->mono_get_boolean_class();
}

MonoClass* mono_get_byte_class()
{
    return executor_instance()->mono_get_byte_class();
}

MonoClass* mono_get_char_class()
{
    return executor_instance()->mono_get_char_class();
}

MonoClass* mono_get_int16_class()
{
    return executor_instance()->mono_get_int16_class();
}

MonoClass* mono_get_int64_class()
{
    return executor_instance()->mono_get_int64_class();
}

MonoClass* mono_get_single_class()
{
    return executor_instance()->mono_get_single_class();
}

MonoClass* mono_get_double_class()
{
    return executor_instance()->mono_get_double_class();
}

gboolean mono_class_is_generic(MonoClass* klass)
{
    return executor_instance()->mono_class_is_generic(klass);
}

gboolean mono_class_is_inflated(MonoClass* klass)
{
    return executor_instance()->mono_class_is_inflated(klass);
}

gboolean unity_mono_method_is_generic(MonoMethod* method)
{
    return executor_instance()->unity_mono_method_is_generic(method);
}

gboolean unity_mono_method_is_inflated(MonoMethod* method)
{
    return executor_instance()->unity_mono_method_is_inflated(method);
}

gboolean mono_is_debugger_attached()
{
    return executor_instance()->mono_is_debugger_attached();
}

gboolean mono_assembly_fill_assembly_name(MonoImage* image, MonoAssemblyName* aname)
{
    return executor_instance()->mono_assembly_fill_assembly_name(image, aname);
}

char* mono_stringify_assembly_name(MonoAssemblyName* aname)
{
    return executor_instance()->mono_stringify_assembly_name(aname);
}

gboolean mono_assembly_name_parse(const char* name, MonoAssemblyName* aname)
{
    return executor_instance()->mono_assembly_name_parse(name, aname);
}

MonoAssembly* mono_assembly_loaded(MonoAssemblyName* aname)
{
    return executor_instance()->mono_assembly_loaded(aname);
}

int mono_image_get_table_rows(MonoImage* image, int table_id)
{
    return executor_instance()->mono_image_get_table_rows(image, table_id);
}

MonoClass* mono_class_get(MonoImage* image, guint32 type_token)
{
    return executor_instance()->mono_class_get(image, type_token);
}

gboolean mono_metadata_signature_equal(MonoMethodSignature* sig1, MonoMethodSignature* sig2)
{
    return executor_instance()->mono_metadata_signature_equal(sig1, sig2);
}

gboolean mono_gchandle_is_in_domain(guint32 gchandle, MonoDomain* domain)
{
    return executor_instance()->mono_gchandle_is_in_domain(gchandle, domain);
}

void mono_stack_walk(MonoStackWalk func, gpointer user_data)
{
    return executor_instance()->mono_stack_walk(func, user_data);
}

char* mono_pmip(void* ip)
{
    return executor_instance()->mono_pmip(ip);
}

MonoObject* mono_runtime_delegate_invoke(MonoObject* delegate, void** params, MonoObject** exc)
{
    return executor_instance()->mono_runtime_delegate_invoke(delegate, params, exc);
}

MonoJitInfo* mono_jit_info_table_find(MonoDomain* domain, char* addr)
{
    return executor_instance()->mono_jit_info_table_find(domain, addr);
}

MonoDebugSourceLocation* mono_debug_lookup_source_location(MonoMethod* method, guint32 address, MonoDomain* domain)
{
    return executor_instance()->mono_debug_lookup_source_location(method, address, domain);
}

void mono_debug_free_source_location(MonoDebugSourceLocation* location)
{
    return executor_instance()->mono_debug_free_source_location(location);
}

void mono_gc_wbarrier_generic_store(gpointer ptr, MonoObject* value)
{
    return executor_instance()->mono_gc_wbarrier_generic_store(ptr, value);
}

MonoType* mono_class_enum_basetype(MonoClass* klass)
{
    return executor_instance()->mono_class_enum_basetype(klass);
}

guint32 mono_class_get_type_token(MonoClass* klass)
{
    return executor_instance()->mono_class_get_type_token(klass);
}

int mono_class_get_rank(MonoClass* klass)
{
    return executor_instance()->mono_class_get_rank(klass);
}

MonoClass* mono_class_get_element_class(MonoClass* klass)
{
    return executor_instance()->mono_class_get_element_class(klass);
}

gboolean mono_unity_class_is_interface(MonoClass* klass)
{
    return executor_instance()->mono_unity_class_is_interface(klass);
}

gboolean mono_unity_class_is_abstract(MonoClass* klass)
{
    return executor_instance()->mono_unity_class_is_abstract(klass);
}

gint32 mono_array_element_size(MonoClass* ac)
{
    return executor_instance()->mono_array_element_size(ac);
}

void mono_config_parse(const char* filename)
{
    return executor_instance()->mono_config_parse(filename);
}

void mono_set_break_policy(MonoBreakPolicyFunc policy_callback)
{
    return executor_instance()->mono_set_break_policy(policy_callback);
}

MonoArray* mono_custom_attrs_construct(MonoCustomAttrInfo* cinfo)
{
    return executor_instance()->mono_custom_attrs_construct(cinfo);
}

MonoCustomAttrInfo* mono_custom_attrs_from_assembly(MonoAssembly* assembly)
{
    return executor_instance()->mono_custom_attrs_from_assembly(assembly);
}

MonoArray* mono_reflection_get_custom_attrs_by_type(MonoObject* obj, MonoClass* attr_klass)
{
    return executor_instance()->mono_reflection_get_custom_attrs_by_type(obj, attr_klass);
}

MonoLoaderError* mono_loader_get_last_error()
{
    return executor_instance()->mono_loader_get_last_error();
}

MonoException* mono_loader_error_prepare_exception(MonoLoaderError* error)
{
    return executor_instance()->mono_loader_error_prepare_exception(error);
}

MonoDlFallbackHandler* mono_dl_fallback_register(MonoDlFallbackLoad load_func, MonoDlFallbackSymbol symbol_func, MonoDlFallbackClose close_func, void* user_data)
{
    return executor_instance()->mono_dl_fallback_register(load_func, symbol_func, close_func, user_data);
}

void mono_dl_fallback_unregister(MonoDlFallbackHandler* handler)
{
    return executor_instance()->mono_dl_fallback_unregister(handler);
}

LivenessState* mono_unity_liveness_allocate_struct(MonoClass* filter, guint max_count, register_object_callback callback, void* callback_userdata)
{
    return executor_instance()->mono_unity_liveness_allocate_struct(filter, max_count, callback, callback_userdata);
}

void mono_unity_liveness_stop_gc_world()
{
    return executor_instance()->mono_unity_liveness_stop_gc_world();
}

void mono_unity_liveness_finalize(LivenessState* state)
{
    return executor_instance()->mono_unity_liveness_finalize(state);
}

void mono_unity_liveness_start_gc_world()
{
    return executor_instance()->mono_unity_liveness_start_gc_world();
}

void mono_unity_liveness_free_struct(LivenessState* state)
{
    return executor_instance()->mono_unity_liveness_free_struct(state);
}

LivenessState* mono_unity_liveness_calculation_begin(MonoClass* filter, guint max_count, register_object_callback callback, void* callback_userdata)
{
    return executor_instance()->mono_unity_liveness_calculation_begin(filter, max_count, callback, callback_userdata);
}

void mono_unity_liveness_calculation_end(LivenessState* state)
{
    return executor_instance()->mono_unity_liveness_calculation_end(state);
}

void mono_unity_liveness_calculation_from_root(MonoObject* root, LivenessState* state)
{
    return executor_instance()->mono_unity_liveness_calculation_from_root(root, state);
}

void mono_unity_liveness_calculation_from_statics(LivenessState* state)
{
    return executor_instance()->mono_unity_liveness_calculation_from_statics(state);
}

void mono_trace_set_level_string(const char* value)
{
    return executor_instance()->mono_trace_set_level_string(value);
}

void mono_trace_set_mask_string(char* value)
{
    return executor_instance()->mono_trace_set_mask_string(value);
}

gint64 mono_gc_get_used_size()
{
    return executor_instance()->mono_gc_get_used_size();
}

gint64 mono_gc_get_heap_size()
{
    return executor_instance()->mono_gc_get_heap_size();
}

MonoMethod* mono_method_desc_search_in_class(MonoMethodDesc* desc, MonoClass* klass)
{
    return executor_instance()->mono_method_desc_search_in_class(desc, klass);
}

void mono_method_desc_free(MonoMethodDesc* desc)
{
    return executor_instance()->mono_method_desc_free(desc);
}

char* mono_type_get_name_full(MonoType* type, MonoTypeNameFormat format)
{
    return executor_instance()->mono_type_get_name_full(type, format);
}

void mono_unity_thread_clear_domain_fields()
{
    return executor_instance()->mono_unity_thread_clear_domain_fields();
}

void mono_unity_set_vprintf_func(vprintf_func func)
{
    return executor_instance()->mono_unity_set_vprintf_func(func);
}

void mono_profiler_install(MonoProfiler* prof, MonoProfileFunc shutdown_callback)
{
    return executor_instance()->mono_profiler_install(prof, shutdown_callback);
}

void mono_profiler_set_events(MonoProfileFlags events)
{
    return executor_instance()->mono_profiler_set_events(events);
}

void mono_profiler_install_enter_leave(MonoProfileMethodFunc enter, MonoProfileMethodFunc fleave)
{
    return executor_instance()->mono_profiler_install_enter_leave(enter, fleave);
}

void mono_profiler_install_gc(MonoProfileGCFunc callback, MonoProfileGCResizeFunc heap_resize_callback)
{
    return executor_instance()->mono_profiler_install_gc(callback, heap_resize_callback);
}

void mono_profiler_install_allocation(MonoProfileAllocFunc callback)
{
    return executor_instance()->mono_profiler_install_allocation(callback);
}

void mono_profiler_install_jit_end(MonoProfileJitResult end)
{
    return executor_instance()->mono_profiler_install_jit_end(end);
}

void mono_profiler_install_exception(MonoProfileExceptionFunc throw_callback, MonoProfileMethodFunc exc_method_leave, MonoProfileExceptionClauseFunc clause_callback)
{
    return executor_instance()->mono_profiler_install_exception(throw_callback, exc_method_leave, clause_callback);
}

void mono_profiler_install_thread(MonoProfileThreadFunc start, MonoProfileThreadFunc end)
{
    return executor_instance()->mono_profiler_install_thread(start, end);
}

