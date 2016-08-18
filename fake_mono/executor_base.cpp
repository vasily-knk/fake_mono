#include "stdafx.h"
#include "executor_base.h"
#include "log.h"

executor_base::executor_base()
{}

mono_wrapper::functions_cptr mono_functions();

mono_wrapper::functions_t const &executor_base::get_f()
{
    return *(::mono_functions());
}

void executor_base::mono_thread_suspend_all_other_threads()
{
    log_function("mono_thread_suspend_all_other_threads");
    return get_f().mono_thread_suspend_all_other_threads();
}

void executor_base::mono_thread_pool_cleanup()
{
    log_function("mono_thread_pool_cleanup");
    return get_f().mono_thread_pool_cleanup();
}

void executor_base::mono_threads_set_shutting_down()
{
    log_function("mono_threads_set_shutting_down");
    return get_f().mono_threads_set_shutting_down();
}

void executor_base::mono_runtime_set_shutting_down()
{
    log_function("mono_runtime_set_shutting_down");
    return get_f().mono_runtime_set_shutting_down();
}

gboolean executor_base::mono_domain_finalize(MonoDomain* domain, int timeout)
{
    log_function("mono_domain_finalize", domain, timeout);
    return get_f().mono_domain_finalize(domain, timeout);
}

void executor_base::mono_runtime_cleanup(MonoDomain* domain)
{
    log_function("mono_runtime_cleanup", domain);
    return get_f().mono_runtime_cleanup(domain);
}

MonoMethodDesc* executor_base::mono_method_desc_new(const char* name, gboolean include_namespace)
{
    log_function("mono_method_desc_new", name, include_namespace);
    return get_f().mono_method_desc_new(name, include_namespace);
}

MonoMethod* executor_base::mono_method_desc_search_in_image(MonoMethodDesc* desc, MonoImage* image)
{
    log_function("mono_method_desc_search_in_image", desc, image);
    return get_f().mono_method_desc_search_in_image(desc, image);
}

void executor_base::mono_verifier_set_mode(MiniVerifierMode m)
{
    log_function("mono_verifier_set_mode", m);
    return get_f().mono_verifier_set_mode(m);
}

void executor_base::mono_security_set_mode(MonoSecurityMode m)
{
    log_function("mono_security_set_mode", m);
    return get_f().mono_security_set_mode(m);
}

void executor_base::mono_add_internal_call(const char* name, gconstpointer method)
{
    log_function("mono_add_internal_call", name, method);
    return get_f().mono_add_internal_call(name, method);
}

void executor_base::mono_jit_cleanup(MonoDomain* domain)
{
    log_function("mono_jit_cleanup", domain);
    return get_f().mono_jit_cleanup(domain);
}

MonoDomain* executor_base::mono_jit_init(const char* file)
{
    log_function("mono_jit_init", file);
    return get_f().mono_jit_init(file);
}

MonoDomain* executor_base::mono_jit_init_version(const char* file, const char* runtime_version)
{
    log_function("mono_jit_init_version", file, runtime_version);
    return get_f().mono_jit_init_version(file, runtime_version);
}

int executor_base::mono_jit_exec(MonoDomain* domain, MonoAssembly* assembly, int argc, char* argv[])
{
    log_function("mono_jit_exec", domain, assembly, argc, argv);
    return get_f().mono_jit_exec(domain, assembly, argc, argv);
}

MonoClass* executor_base::mono_class_from_name(MonoImage* image, const char* name_space, const char* name)
{
    log_function("mono_class_from_name", image, name_space, name);
    return get_f().mono_class_from_name(image, name_space, name);
}

MonoAssembly* executor_base::mono_domain_assembly_open(MonoDomain* domain, const char* name)
{
    log_function("mono_domain_assembly_open", domain, name);
    return get_f().mono_domain_assembly_open(domain, name);
}

MonoDomain* executor_base::mono_domain_create_appdomain(const char* domainname, const char* configfile)
{
    log_function("mono_domain_create_appdomain", domainname, configfile);
    return get_f().mono_domain_create_appdomain(domainname, configfile);
}

void executor_base::mono_domain_unload(MonoDomain* domain)
{
    log_function("mono_domain_unload", domain);
    return get_f().mono_domain_unload(domain);
}

MonoObject* executor_base::mono_object_new(MonoDomain* domain, MonoClass* klass)
{
    log_function("mono_object_new", domain, klass);
    return get_f().mono_object_new(domain, klass);
}

void executor_base::mono_runtime_object_init(MonoObject* this_obj)
{
    log_function("mono_runtime_object_init", this_obj);
    return get_f().mono_runtime_object_init(this_obj);
}

MonoObject* executor_base::mono_runtime_invoke(MonoMethod* method, void* obj, void** params, MonoObject** exc)
{
    log_function("mono_runtime_invoke", method, obj, params, exc);
    return get_f().mono_runtime_invoke(method, obj, params, exc);
}

void executor_base::mono_field_set_value(MonoObject* obj, MonoClassField* field, void* value)
{
    log_function("mono_field_set_value", obj, field, value);
    return get_f().mono_field_set_value(obj, field, value);
}

void executor_base::mono_field_get_value(MonoObject* obj, MonoClassField* field, void* value)
{
    log_function("mono_field_get_value", obj, field, value);
    return get_f().mono_field_get_value(obj, field, value);
}

int executor_base::mono_field_get_offset(MonoClassField* field)
{
    log_function("mono_field_get_offset", field);
    return get_f().mono_field_get_offset(field);
}

MonoClassField* executor_base::mono_class_get_fields(MonoClass* klass, gpointer* iter)
{
    log_function("mono_class_get_fields", klass, iter);
    return get_f().mono_class_get_fields(klass, iter);
}

MonoMethod* executor_base::mono_class_get_methods(MonoClass* klass, gpointer* iter)
{
    log_function("mono_class_get_methods", klass, iter);
    return get_f().mono_class_get_methods(klass, iter);
}

MonoDomain* executor_base::mono_domain_get()
{
    log_function("mono_domain_get");
    return get_f().mono_domain_get();
}

MonoDomain* executor_base::mono_get_root_domain()
{
    log_function("mono_get_root_domain");
    return get_f().mono_get_root_domain();
}

gint32 executor_base::mono_domain_get_id(MonoDomain* domain)
{
    log_function("mono_domain_get_id", domain);
    return get_f().mono_domain_get_id(domain);
}

void executor_base::mono_assembly_foreach(GFunc func, gpointer user_data)
{
    log_function("mono_assembly_foreach", func, user_data);
    return get_f().mono_assembly_foreach(func, user_data);
}

void executor_base::mono_image_close(MonoImage* image)
{
    log_function("mono_image_close", image);
    return get_f().mono_image_close(image);
}

void executor_base::mono_unity_socket_security_enabled_set(gboolean b)
{
    log_function("mono_unity_socket_security_enabled_set", b);
    return get_f().mono_unity_socket_security_enabled_set(b);
}

const char* executor_base::mono_image_get_name(MonoImage* image)
{
    log_function("mono_image_get_name", image);
    return get_f().mono_image_get_name(image);
}

MonoClass* executor_base::mono_get_object_class()
{
    log_function("mono_get_object_class");
    return get_f().mono_get_object_class();
}

void executor_base::mono_set_commandline_arguments(int i, const char* argv[], const char* s)
{
    log_function("mono_set_commandline_arguments", i, argv, s);
    return get_f().mono_set_commandline_arguments(i, argv, s);
}

const char* executor_base::mono_field_get_name(MonoClassField* field)
{
    log_function("mono_field_get_name", field);
    return get_f().mono_field_get_name(field);
}

MonoType* executor_base::mono_field_get_type(MonoClassField* field)
{
    log_function("mono_field_get_type", field);
    return get_f().mono_field_get_type(field);
}

int executor_base::mono_type_get_type(MonoType* type)
{
    log_function("mono_type_get_type", type);
    return get_f().mono_type_get_type(type);
}

const char* executor_base::mono_method_get_name(MonoMethod* method)
{
    log_function("mono_method_get_name", method);
    return get_f().mono_method_get_name(method);
}

MonoImage* executor_base::mono_assembly_get_image(MonoAssembly* assembly)
{
    log_function("mono_assembly_get_image", assembly);
    return get_f().mono_assembly_get_image(assembly);
}

MonoClass* executor_base::mono_method_get_class(MonoMethod* method)
{
    log_function("mono_method_get_class", method);
    return get_f().mono_method_get_class(method);
}

MonoClass* executor_base::mono_object_get_class(MonoObject* obj)
{
    log_function("mono_object_get_class", obj);
    return get_f().mono_object_get_class(obj);
}

gboolean executor_base::mono_class_is_valuetype(MonoClass* klass)
{
    log_function("mono_class_is_valuetype", klass);
    return get_f().mono_class_is_valuetype(klass);
}

guint32 executor_base::mono_signature_get_param_count(MonoMethodSignature* sig)
{
    log_function("mono_signature_get_param_count", sig);
    return get_f().mono_signature_get_param_count(sig);
}

char* executor_base::mono_string_to_utf8(MonoString* string_obj)
{
    log_function("mono_string_to_utf8", string_obj);
    return get_f().mono_string_to_utf8(string_obj);
}

MonoString* executor_base::mono_string_new_wrapper(const char* text)
{
    log_function("mono_string_new_wrapper", text);
    return get_f().mono_string_new_wrapper(text);
}

MonoClass* executor_base::mono_class_get_parent(MonoClass* klass)
{
    log_function("mono_class_get_parent", klass);
    return get_f().mono_class_get_parent(klass);
}

const char* executor_base::mono_class_get_namespace(MonoClass* klass)
{
    log_function("mono_class_get_namespace", klass);
    return get_f().mono_class_get_namespace(klass);
}

gboolean executor_base::mono_class_is_subclass_of(MonoClass* klass, MonoClass* klassc, gboolean check_interfaces)
{
    log_function("mono_class_is_subclass_of", klass, klassc, check_interfaces);
    return get_f().mono_class_is_subclass_of(klass, klassc, check_interfaces);
}

const char* executor_base::mono_class_get_name(MonoClass* klass)
{
    log_function("mono_class_get_name", klass);
    return get_f().mono_class_get_name(klass);
}

char* executor_base::mono_type_get_name(MonoType* type)
{
    log_function("mono_type_get_name", type);
    return get_f().mono_type_get_name(type);
}

MonoClass* executor_base::mono_type_get_class(MonoType* type)
{
    log_function("mono_type_get_class", type);
    return get_f().mono_type_get_class(type);
}

MonoException* executor_base::mono_exception_from_name_msg(MonoImage* image, const char* name_space, const char* name, const char* msg)
{
    log_function("mono_exception_from_name_msg", image, name_space, name, msg);
    return get_f().mono_exception_from_name_msg(image, name_space, name, msg);
}

void executor_base::mono_raise_exception(MonoException* ex)
{
    log_function("mono_raise_exception", ex);
    return get_f().mono_raise_exception(ex);
}

MonoClass* executor_base::mono_get_exception_class()
{
    log_function("mono_get_exception_class");
    return get_f().mono_get_exception_class();
}

MonoClass* executor_base::mono_get_array_class()
{
    log_function("mono_get_array_class");
    return get_f().mono_get_array_class();
}

MonoClass* executor_base::mono_get_string_class()
{
    log_function("mono_get_string_class");
    return get_f().mono_get_string_class();
}

MonoClass* executor_base::mono_get_int32_class()
{
    log_function("mono_get_int32_class");
    return get_f().mono_get_int32_class();
}

MonoArray* executor_base::mono_array_new(MonoDomain* domain, MonoClass* eclass, guint32 n)
{
    log_function("mono_array_new", domain, eclass, n);
    return get_f().mono_array_new(domain, eclass, n);
}

MonoArray* executor_base::mono_array_new_full(MonoDomain* domain, MonoClass* array_class, guint32* lengths, guint32* lower_bounds)
{
    log_function("mono_array_new_full", domain, array_class, lengths, lower_bounds);
    return get_f().mono_array_new_full(domain, array_class, lengths, lower_bounds);
}

MonoClass* executor_base::mono_array_class_get(MonoClass* eclass, guint32 rank)
{
    log_function("mono_array_class_get", eclass, rank);
    return get_f().mono_array_class_get(eclass, rank);
}

gint32 executor_base::mono_class_array_element_size(MonoClass* ac)
{
    log_function("mono_class_array_element_size", ac);
    return get_f().mono_class_array_element_size(ac);
}

MonoObject* executor_base::mono_type_get_object(MonoDomain* domain, MonoType* type)
{
    log_function("mono_type_get_object", domain, type);
    return get_f().mono_type_get_object(domain, type);
}

MonoThread* executor_base::mono_thread_attach(MonoDomain* domain)
{
    log_function("mono_thread_attach", domain);
    return get_f().mono_thread_attach(domain);
}

void executor_base::mono_thread_detach(MonoThread* thread)
{
    log_function("mono_thread_detach", thread);
    return get_f().mono_thread_detach(thread);
}

MonoThread* executor_base::mono_thread_exit()
{
    log_function("mono_thread_exit");
    return get_f().mono_thread_exit();
}

MonoThread* executor_base::mono_thread_current()
{
    log_function("mono_thread_current");
    return get_f().mono_thread_current();
}

void executor_base::mono_thread_set_main(MonoThread* thread)
{
    log_function("mono_thread_set_main", thread);
    return get_f().mono_thread_set_main(thread);
}

void executor_base::mono_set_find_plugin_callback(gconstpointer method)
{
    log_function("mono_set_find_plugin_callback", method);
    return get_f().mono_set_find_plugin_callback(method);
}

void executor_base::mono_security_enable_core_clr()
{
    log_function("mono_security_enable_core_clr");
    return get_f().mono_security_enable_core_clr();
}

bool executor_base::mono_security_set_core_clr_platform_callback(MonoCoreClrPlatformCB a)
{
    log_function("mono_security_set_core_clr_platform_callback", a);
    return get_f().mono_security_set_core_clr_platform_callback(a);
}

MonoRuntimeUnhandledExceptionPolicy executor_base::mono_runtime_unhandled_exception_policy_get()
{
    log_function("mono_runtime_unhandled_exception_policy_get");
    return get_f().mono_runtime_unhandled_exception_policy_get();
}

void executor_base::mono_runtime_unhandled_exception_policy_set(MonoRuntimeUnhandledExceptionPolicy policy)
{
    log_function("mono_runtime_unhandled_exception_policy_set", policy);
    return get_f().mono_runtime_unhandled_exception_policy_set(policy);
}

MonoClass* executor_base::mono_class_get_nesting_type(MonoClass* klass)
{
    log_function("mono_class_get_nesting_type", klass);
    return get_f().mono_class_get_nesting_type(klass);
}

MonoVTable* executor_base::mono_class_vtable(MonoDomain* domain, MonoClass* klass)
{
    log_function("mono_class_vtable", domain, klass);
    return get_f().mono_class_vtable(domain, klass);
}

MonoReflectionMethod* executor_base::mono_method_get_object(MonoDomain* domain, MonoMethod* method, MonoClass* refclass)
{
    log_function("mono_method_get_object", domain, method, refclass);
    return get_f().mono_method_get_object(domain, method, refclass);
}

MonoMethodSignature* executor_base::mono_method_signature(MonoMethod* method)
{
    log_function("mono_method_signature", method);
    return get_f().mono_method_signature(method);
}

MonoType* executor_base::mono_signature_get_params(MonoMethodSignature* sig, gpointer* iter)
{
    log_function("mono_signature_get_params", sig, iter);
    return get_f().mono_signature_get_params(sig, iter);
}

MonoType* executor_base::mono_signature_get_return_type(MonoMethodSignature* sig)
{
    log_function("mono_signature_get_return_type", sig);
    return get_f().mono_signature_get_return_type(sig);
}

MonoType* executor_base::mono_class_get_type(MonoClass* klass)
{
    log_function("mono_class_get_type", klass);
    return get_f().mono_class_get_type(klass);
}

void executor_base::mono_set_ignore_version_and_key_when_finding_assemblies_already_loaded(gboolean value)
{
    log_function("mono_set_ignore_version_and_key_when_finding_assemblies_already_loaded", value);
    return get_f().mono_set_ignore_version_and_key_when_finding_assemblies_already_loaded(value);
}

void executor_base::mono_debug_init(int format)
{
    log_function("mono_debug_init", format);
    return get_f().mono_debug_init(format);
}

void executor_base::mono_debug_open_image_from_memory(MonoImage* image, const char* raw_contents, int size)
{
    log_function("mono_debug_open_image_from_memory", image, raw_contents, size);
    return get_f().mono_debug_open_image_from_memory(image, raw_contents, size);
}

guint32 executor_base::mono_field_get_flags(MonoClassField* field)
{
    log_function("mono_field_get_flags", field);
    return get_f().mono_field_get_flags(field);
}

MonoImage* executor_base::mono_image_open_from_data_full(const void* data, guint32 data_len, gboolean need_copy, int* status, gboolean ref_only)
{
    log_function("mono_image_open_from_data_full", data, data_len, need_copy, status, ref_only);
    return get_f().mono_image_open_from_data_full(data, data_len, need_copy, status, ref_only);
}

MonoImage* executor_base::mono_image_open_from_data_with_name(char* data, guint32 data_len, gboolean need_copy, int* status, gboolean refonly, const char* name)
{
    log_function("mono_image_open_from_data_with_name", data, data_len, need_copy, status, refonly, name);
    return get_f().mono_image_open_from_data_with_name(data, data_len, need_copy, status, refonly, name);
}

MonoAssembly* executor_base::mono_assembly_load_from(MonoImage* image, const char* fname, int* status)
{
    log_function("mono_assembly_load_from", image, fname, status);
    return get_f().mono_assembly_load_from(image, fname, status);
}

MonoObject* executor_base::mono_value_box(MonoDomain* domain, MonoClass* klass, gpointer val)
{
    log_function("mono_value_box", domain, klass, val);
    return get_f().mono_value_box(domain, klass, val);
}

MonoImage* executor_base::mono_class_get_image(MonoClass* klass)
{
    log_function("mono_class_get_image", klass);
    return get_f().mono_class_get_image(klass);
}

char executor_base::mono_signature_is_instance(MonoMethodSignature* signature)
{
    log_function("mono_signature_is_instance", signature);
    return get_f().mono_signature_is_instance(signature);
}

MonoMethod* executor_base::mono_method_get_last_managed()
{
    log_function("mono_method_get_last_managed");
    return get_f().mono_method_get_last_managed();
}

MonoClass* executor_base::mono_get_enum_class()
{
    log_function("mono_get_enum_class");
    return get_f().mono_get_enum_class();
}

MonoType* executor_base::mono_class_get_byref_type(MonoClass* klass)
{
    log_function("mono_class_get_byref_type", klass);
    return get_f().mono_class_get_byref_type(klass);
}

void executor_base::mono_field_static_get_value(MonoVTable* vt, MonoClassField* field, void* value)
{
    log_function("mono_field_static_get_value", vt, field, value);
    return get_f().mono_field_static_get_value(vt, field, value);
}

void executor_base::mono_unity_set_embeddinghostname(const char* name)
{
    log_function("mono_unity_set_embeddinghostname", name);
    return get_f().mono_unity_set_embeddinghostname(name);
}

void executor_base::mono_set_assemblies_path(const char* name)
{
    log_function("mono_set_assemblies_path", name);
    return get_f().mono_set_assemblies_path(name);
}

guint32 executor_base::mono_gchandle_new(MonoObject* obj, gboolean pinned)
{
    log_function("mono_gchandle_new", obj, pinned);
    return get_f().mono_gchandle_new(obj, pinned);
}

MonoObject* executor_base::mono_gchandle_get_target(guint32 gchandle)
{
    log_function("mono_gchandle_get_target", gchandle);
    return get_f().mono_gchandle_get_target(gchandle);
}

guint32 executor_base::mono_gchandle_new_weakref(MonoObject* obj, gboolean track_resurrection)
{
    log_function("mono_gchandle_new_weakref", obj, track_resurrection);
    return get_f().mono_gchandle_new_weakref(obj, track_resurrection);
}

MonoObject* executor_base::mono_assembly_get_object(MonoDomain* domain, MonoAssembly* assembly)
{
    log_function("mono_assembly_get_object", domain, assembly);
    return get_f().mono_assembly_get_object(domain, assembly);
}

void executor_base::mono_gchandle_free(guint32 gchandle)
{
    log_function("mono_gchandle_free", gchandle);
    return get_f().mono_gchandle_free(gchandle);
}

MonoProperty* executor_base::mono_class_get_properties(MonoClass* klass, gpointer* iter)
{
    log_function("mono_class_get_properties", klass, iter);
    return get_f().mono_class_get_properties(klass, iter);
}

MonoMethod* executor_base::mono_property_get_get_method(MonoProperty* prop)
{
    log_function("mono_property_get_get_method", prop);
    return get_f().mono_property_get_get_method(prop);
}

MonoObject* executor_base::mono_object_new_alloc_specific(MonoVTable* vtable)
{
    log_function("mono_object_new_alloc_specific", vtable);
    return get_f().mono_object_new_alloc_specific(vtable);
}

MonoObject* executor_base::mono_object_new_specific(MonoVTable* vtable)
{
    log_function("mono_object_new_specific", vtable);
    return get_f().mono_object_new_specific(vtable);
}

void executor_base::mono_gc_collect(int generation)
{
    log_function("mono_gc_collect", generation);
    return get_f().mono_gc_collect(generation);
}

int executor_base::mono_gc_max_generation()
{
    log_function("mono_gc_max_generation");
    return get_f().mono_gc_max_generation();
}

MonoAssembly* executor_base::mono_image_get_assembly(MonoImage* image)
{
    log_function("mono_image_get_assembly", image);
    return get_f().mono_image_get_assembly(image);
}

MonoAssembly* executor_base::mono_assembly_open(const char* filename, int* status)
{
    log_function("mono_assembly_open", filename, status);
    return get_f().mono_assembly_open(filename, status);
}

gboolean executor_base::mono_class_is_enum(MonoClass* klass)
{
    log_function("mono_class_is_enum", klass);
    return get_f().mono_class_is_enum(klass);
}

gint32 executor_base::mono_class_instance_size(MonoClass* klass)
{
    log_function("mono_class_instance_size", klass);
    return get_f().mono_class_instance_size(klass);
}

guint32 executor_base::mono_object_get_size(MonoObject* obj)
{
    log_function("mono_object_get_size", obj);
    return get_f().mono_object_get_size(obj);
}

const char* executor_base::mono_image_get_filename(MonoImage* image)
{
    log_function("mono_image_get_filename", image);
    return get_f().mono_image_get_filename(image);
}

MonoAssembly* executor_base::mono_assembly_load_from_full(MonoImage* image, const char* fname, int* status, gboolean refonly)
{
    log_function("mono_assembly_load_from_full", image, fname, status, refonly);
    return get_f().mono_assembly_load_from_full(image, fname, status, refonly);
}

MonoClass* executor_base::mono_class_get_interfaces(MonoClass* klass, gpointer* iter)
{
    log_function("mono_class_get_interfaces", klass, iter);
    return get_f().mono_class_get_interfaces(klass, iter);
}

void executor_base::mono_assembly_close(MonoAssembly* assembly)
{
    log_function("mono_assembly_close", assembly);
    return get_f().mono_assembly_close(assembly);
}

MonoProperty* executor_base::mono_class_get_property_from_name(MonoClass* klass, const char* name)
{
    log_function("mono_class_get_property_from_name", klass, name);
    return get_f().mono_class_get_property_from_name(klass, name);
}

MonoMethod* executor_base::mono_class_get_method_from_name(MonoClass* klass, const char* name, int param_count)
{
    log_function("mono_class_get_method_from_name", klass, name, param_count);
    return get_f().mono_class_get_method_from_name(klass, name, param_count);
}

MonoClass* executor_base::mono_class_from_mono_type(MonoType* image)
{
    log_function("mono_class_from_mono_type", image);
    return get_f().mono_class_from_mono_type(image);
}

gboolean executor_base::mono_domain_set(MonoDomain* domain, gboolean force)
{
    log_function("mono_domain_set", domain, force);
    return get_f().mono_domain_set(domain, force);
}

void executor_base::mono_thread_push_appdomain_ref(MonoDomain* domain)
{
    log_function("mono_thread_push_appdomain_ref", domain);
    return get_f().mono_thread_push_appdomain_ref(domain);
}

void executor_base::mono_thread_pop_appdomain_ref()
{
    log_function("mono_thread_pop_appdomain_ref");
    return get_f().mono_thread_pop_appdomain_ref();
}

int executor_base::mono_runtime_exec_main(MonoMethod* method, MonoArray* args, MonoObject** exc)
{
    log_function("mono_runtime_exec_main", method, args, exc);
    return get_f().mono_runtime_exec_main(method, args, exc);
}

MonoImage* executor_base::mono_get_corlib()
{
    log_function("mono_get_corlib");
    return get_f().mono_get_corlib();
}

MonoClassField* executor_base::mono_class_get_field_from_name(MonoClass* klass, const char* name)
{
    log_function("mono_class_get_field_from_name", klass, name);
    return get_f().mono_class_get_field_from_name(klass, name);
}

guint32 executor_base::mono_class_get_flags(MonoClass* klass)
{
    log_function("mono_class_get_flags", klass);
    return get_f().mono_class_get_flags(klass);
}

int executor_base::mono_parse_default_optimizations(const char* p)
{
    log_function("mono_parse_default_optimizations", p);
    return get_f().mono_parse_default_optimizations(p);
}

void executor_base::mono_set_defaults(int verbose_level, guint32 opts)
{
    log_function("mono_set_defaults", verbose_level, opts);
    return get_f().mono_set_defaults(verbose_level, opts);
}

void executor_base::mono_set_dirs(const char* assembly_dir, const char* config_dir)
{
    log_function("mono_set_dirs", assembly_dir, config_dir);
    return get_f().mono_set_dirs(assembly_dir, config_dir);
}

void executor_base::mono_jit_parse_options(int argc, char* argv[])
{
    log_function("mono_jit_parse_options", argc, argv);
    return get_f().mono_jit_parse_options(argc, argv);
}

gpointer executor_base::mono_object_unbox(MonoObject* o)
{
    log_function("mono_object_unbox", o);
    return get_f().mono_object_unbox(o);
}

MonoObject* executor_base::mono_custom_attrs_get_attr(MonoCustomAttrInfo* ainfo, MonoClass* attr_klass)
{
    log_function("mono_custom_attrs_get_attr", ainfo, attr_klass);
    return get_f().mono_custom_attrs_get_attr(ainfo, attr_klass);
}

gboolean executor_base::mono_custom_attrs_has_attr(MonoCustomAttrInfo* ainfo, MonoClass* attr_klass)
{
    log_function("mono_custom_attrs_has_attr", ainfo, attr_klass);
    return get_f().mono_custom_attrs_has_attr(ainfo, attr_klass);
}

MonoCustomAttrInfo* executor_base::mono_custom_attrs_from_field(MonoClass* klass, MonoClassField* field)
{
    log_function("mono_custom_attrs_from_field", klass, field);
    return get_f().mono_custom_attrs_from_field(klass, field);
}

MonoCustomAttrInfo* executor_base::mono_custom_attrs_from_method(MonoMethod* method)
{
    log_function("mono_custom_attrs_from_method", method);
    return get_f().mono_custom_attrs_from_method(method);
}

MonoCustomAttrInfo* executor_base::mono_custom_attrs_from_class(MonoClass* klass)
{
    log_function("mono_custom_attrs_from_class", klass);
    return get_f().mono_custom_attrs_from_class(klass);
}

void executor_base::mono_custom_attrs_free(MonoCustomAttrInfo* attr)
{
    log_function("mono_custom_attrs_free", attr);
    return get_f().mono_custom_attrs_free(attr);
}

void executor_base::g_free(void* p)
{
    log_function("g_free", p);
    return get_f().g_free(p);
}

gboolean executor_base::mono_runtime_is_shutting_down()
{
    log_function("mono_runtime_is_shutting_down");
    return get_f().mono_runtime_is_shutting_down();
}

MonoMethod* executor_base::mono_object_get_virtual_method(MonoObject* obj, MonoMethod* method)
{
    log_function("mono_object_get_virtual_method", obj, method);
    return get_f().mono_object_get_virtual_method(obj, method);
}

gpointer executor_base::mono_jit_info_get_code_start(MonoJitInfo* ji)
{
    log_function("mono_jit_info_get_code_start", ji);
    return get_f().mono_jit_info_get_code_start(ji);
}

int executor_base::mono_jit_info_get_code_size(MonoJitInfo* ji)
{
    log_function("mono_jit_info_get_code_size", ji);
    return get_f().mono_jit_info_get_code_size(ji);
}

MonoClass* executor_base::mono_class_from_name_case(MonoImage* image, const char* name_space, const char* name)
{
    log_function("mono_class_from_name_case", image, name_space, name);
    return get_f().mono_class_from_name_case(image, name_space, name);
}

MonoClass* executor_base::mono_class_get_nested_types(MonoClass* klass, gpointer* iter)
{
    log_function("mono_class_get_nested_types", klass, iter);
    return get_f().mono_class_get_nested_types(klass, iter);
}

int executor_base::mono_class_get_userdata_offset()
{
    log_function("mono_class_get_userdata_offset");
    return get_f().mono_class_get_userdata_offset();
}

void* executor_base::mono_class_get_userdata(MonoClass* klass)
{
    log_function("mono_class_get_userdata", klass);
    return get_f().mono_class_get_userdata(klass);
}

void executor_base::mono_class_set_userdata(MonoClass* klass, void* userdata)
{
    log_function("mono_class_set_userdata", klass, userdata);
    return get_f().mono_class_set_userdata(klass, userdata);
}

void executor_base::mono_set_signal_chaining(gboolean chain_signals)
{
    log_function("mono_set_signal_chaining", chain_signals);
    return get_f().mono_set_signal_chaining(chain_signals);
}

LONG executor_base::mono_unity_seh_handler(EXCEPTION_POINTERS* ep)
{
    log_function("mono_unity_seh_handler", ep);
    return get_f().mono_unity_seh_handler(ep);
}

void executor_base::mono_unity_set_unhandled_exception_handler(void* handler)
{
    log_function("mono_unity_set_unhandled_exception_handler", handler);
    return get_f().mono_unity_set_unhandled_exception_handler(handler);
}

MonoObject* executor_base::mono_runtime_invoke_array(MonoMethod* method, void* obj, MonoArray* params, MonoObject** exc)
{
    log_function("mono_runtime_invoke_array", method, obj, params, exc);
    return get_f().mono_runtime_invoke_array(method, obj, params, exc);
}

char* executor_base::mono_array_addr_with_size(MonoArray* array, int size, uintptr_t idx)
{
    log_function("mono_array_addr_with_size", array, size, idx);
    return get_f().mono_array_addr_with_size(array, size, idx);
}

gunichar2* executor_base::mono_string_to_utf16(MonoString* string_obj)
{
    log_function("mono_string_to_utf16", string_obj);
    return get_f().mono_string_to_utf16(string_obj);
}

MonoClass* executor_base::mono_field_get_parent(MonoClassField* field)
{
    log_function("mono_field_get_parent", field);
    return get_f().mono_field_get_parent(field);
}

char* executor_base::mono_method_full_name(MonoMethod* method, gboolean signature)
{
    log_function("mono_method_full_name", method, signature);
    return get_f().mono_method_full_name(method, signature);
}

MonoObject* executor_base::mono_object_isinst(MonoObject* obj, MonoClass* klass)
{
    log_function("mono_object_isinst", obj, klass);
    return get_f().mono_object_isinst(obj, klass);
}

MonoString* executor_base::mono_string_new_len(MonoDomain* domain, const char* text, guint length)
{
    log_function("mono_string_new_len", domain, text, length);
    return get_f().mono_string_new_len(domain, text, length);
}

MonoString* executor_base::mono_string_from_utf16(gunichar2* data)
{
    log_function("mono_string_from_utf16", data);
    return get_f().mono_string_from_utf16(data);
}

MonoException* executor_base::mono_get_exception_argument_null(const char* arg)
{
    log_function("mono_get_exception_argument_null", arg);
    return get_f().mono_get_exception_argument_null(arg);
}

MonoClass* executor_base::mono_get_boolean_class()
{
    log_function("mono_get_boolean_class");
    return get_f().mono_get_boolean_class();
}

MonoClass* executor_base::mono_get_byte_class()
{
    log_function("mono_get_byte_class");
    return get_f().mono_get_byte_class();
}

MonoClass* executor_base::mono_get_char_class()
{
    log_function("mono_get_char_class");
    return get_f().mono_get_char_class();
}

MonoClass* executor_base::mono_get_int16_class()
{
    log_function("mono_get_int16_class");
    return get_f().mono_get_int16_class();
}

MonoClass* executor_base::mono_get_int64_class()
{
    log_function("mono_get_int64_class");
    return get_f().mono_get_int64_class();
}

MonoClass* executor_base::mono_get_single_class()
{
    log_function("mono_get_single_class");
    return get_f().mono_get_single_class();
}

MonoClass* executor_base::mono_get_double_class()
{
    log_function("mono_get_double_class");
    return get_f().mono_get_double_class();
}

gboolean executor_base::mono_class_is_generic(MonoClass* klass)
{
    log_function("mono_class_is_generic", klass);
    return get_f().mono_class_is_generic(klass);
}

gboolean executor_base::mono_class_is_inflated(MonoClass* klass)
{
    log_function("mono_class_is_inflated", klass);
    return get_f().mono_class_is_inflated(klass);
}

gboolean executor_base::unity_mono_method_is_generic(MonoMethod* method)
{
    log_function("unity_mono_method_is_generic", method);
    return get_f().unity_mono_method_is_generic(method);
}

gboolean executor_base::unity_mono_method_is_inflated(MonoMethod* method)
{
    log_function("unity_mono_method_is_inflated", method);
    return get_f().unity_mono_method_is_inflated(method);
}

gboolean executor_base::mono_is_debugger_attached()
{
    log_function("mono_is_debugger_attached");
    return get_f().mono_is_debugger_attached();
}

gboolean executor_base::mono_assembly_fill_assembly_name(MonoImage* image, MonoAssemblyName* aname)
{
    log_function("mono_assembly_fill_assembly_name", image, aname);
    return get_f().mono_assembly_fill_assembly_name(image, aname);
}

char* executor_base::mono_stringify_assembly_name(MonoAssemblyName* aname)
{
    log_function("mono_stringify_assembly_name", aname);
    return get_f().mono_stringify_assembly_name(aname);
}

gboolean executor_base::mono_assembly_name_parse(const char* name, MonoAssemblyName* aname)
{
    log_function("mono_assembly_name_parse", name, aname);
    return get_f().mono_assembly_name_parse(name, aname);
}

MonoAssembly* executor_base::mono_assembly_loaded(MonoAssemblyName* aname)
{
    log_function("mono_assembly_loaded", aname);
    return get_f().mono_assembly_loaded(aname);
}

int executor_base::mono_image_get_table_rows(MonoImage* image, int table_id)
{
    log_function("mono_image_get_table_rows", image, table_id);
    return get_f().mono_image_get_table_rows(image, table_id);
}

MonoClass* executor_base::mono_class_get(MonoImage* image, guint32 type_token)
{
    log_function("mono_class_get", image, type_token);
    return get_f().mono_class_get(image, type_token);
}

gboolean executor_base::mono_metadata_signature_equal(MonoMethodSignature* sig1, MonoMethodSignature* sig2)
{
    log_function("mono_metadata_signature_equal", sig1, sig2);
    return get_f().mono_metadata_signature_equal(sig1, sig2);
}

gboolean executor_base::mono_gchandle_is_in_domain(guint32 gchandle, MonoDomain* domain)
{
    log_function("mono_gchandle_is_in_domain", gchandle, domain);
    return get_f().mono_gchandle_is_in_domain(gchandle, domain);
}

void executor_base::mono_stack_walk(MonoStackWalk func, gpointer user_data)
{
    log_function("mono_stack_walk", func, user_data);
    return get_f().mono_stack_walk(func, user_data);
}

char* executor_base::mono_pmip(void* ip)
{
    log_function("mono_pmip", ip);
    return get_f().mono_pmip(ip);
}

MonoObject* executor_base::mono_runtime_delegate_invoke(MonoObject* delegate, void** params, MonoObject** exc)
{
    log_function("mono_runtime_delegate_invoke", delegate, params, exc);
    return get_f().mono_runtime_delegate_invoke(delegate, params, exc);
}

MonoJitInfo* executor_base::mono_jit_info_table_find(MonoDomain* domain, char* addr)
{
    log_function("mono_jit_info_table_find", domain, addr);
    return get_f().mono_jit_info_table_find(domain, addr);
}

MonoDebugSourceLocation* executor_base::mono_debug_lookup_source_location(MonoMethod* method, guint32 address, MonoDomain* domain)
{
    log_function("mono_debug_lookup_source_location", method, address, domain);
    return get_f().mono_debug_lookup_source_location(method, address, domain);
}

void executor_base::mono_debug_free_source_location(MonoDebugSourceLocation* location)
{
    log_function("mono_debug_free_source_location", location);
    return get_f().mono_debug_free_source_location(location);
}

void executor_base::mono_gc_wbarrier_generic_store(gpointer ptr, MonoObject* value)
{
    log_function("mono_gc_wbarrier_generic_store", ptr, value);
    return get_f().mono_gc_wbarrier_generic_store(ptr, value);
}

MonoType* executor_base::mono_class_enum_basetype(MonoClass* klass)
{
    log_function("mono_class_enum_basetype", klass);
    return get_f().mono_class_enum_basetype(klass);
}

guint32 executor_base::mono_class_get_type_token(MonoClass* klass)
{
    log_function("mono_class_get_type_token", klass);
    return get_f().mono_class_get_type_token(klass);
}

int executor_base::mono_class_get_rank(MonoClass* klass)
{
    log_function("mono_class_get_rank", klass);
    return get_f().mono_class_get_rank(klass);
}

MonoClass* executor_base::mono_class_get_element_class(MonoClass* klass)
{
    log_function("mono_class_get_element_class", klass);
    return get_f().mono_class_get_element_class(klass);
}

gboolean executor_base::mono_unity_class_is_interface(MonoClass* klass)
{
    log_function("mono_unity_class_is_interface", klass);
    return get_f().mono_unity_class_is_interface(klass);
}

gboolean executor_base::mono_unity_class_is_abstract(MonoClass* klass)
{
    log_function("mono_unity_class_is_abstract", klass);
    return get_f().mono_unity_class_is_abstract(klass);
}

gint32 executor_base::mono_array_element_size(MonoClass* ac)
{
    log_function("mono_array_element_size", ac);
    return get_f().mono_array_element_size(ac);
}

void executor_base::mono_config_parse(const char* filename)
{
    log_function("mono_config_parse", filename);
    return get_f().mono_config_parse(filename);
}

void executor_base::mono_set_break_policy(MonoBreakPolicyFunc policy_callback)
{
    log_function("mono_set_break_policy", policy_callback);
    return get_f().mono_set_break_policy(policy_callback);
}

MonoArray* executor_base::mono_custom_attrs_construct(MonoCustomAttrInfo* cinfo)
{
    log_function("mono_custom_attrs_construct", cinfo);
    return get_f().mono_custom_attrs_construct(cinfo);
}

MonoCustomAttrInfo* executor_base::mono_custom_attrs_from_assembly(MonoAssembly* assembly)
{
    log_function("mono_custom_attrs_from_assembly", assembly);
    return get_f().mono_custom_attrs_from_assembly(assembly);
}

MonoArray* executor_base::mono_reflection_get_custom_attrs_by_type(MonoObject* obj, MonoClass* attr_klass)
{
    log_function("mono_reflection_get_custom_attrs_by_type", obj, attr_klass);
    return get_f().mono_reflection_get_custom_attrs_by_type(obj, attr_klass);
}

MonoLoaderError* executor_base::mono_loader_get_last_error()
{
    log_function("mono_loader_get_last_error");
    return get_f().mono_loader_get_last_error();
}

MonoException* executor_base::mono_loader_error_prepare_exception(MonoLoaderError* error)
{
    log_function("mono_loader_error_prepare_exception", error);
    return get_f().mono_loader_error_prepare_exception(error);
}

MonoDlFallbackHandler* executor_base::mono_dl_fallback_register(MonoDlFallbackLoad load_func, MonoDlFallbackSymbol symbol_func, MonoDlFallbackClose close_func, void* user_data)
{
    log_function("mono_dl_fallback_register", load_func, symbol_func, close_func, user_data);
    return get_f().mono_dl_fallback_register(load_func, symbol_func, close_func, user_data);
}

void executor_base::mono_dl_fallback_unregister(MonoDlFallbackHandler* handler)
{
    log_function("mono_dl_fallback_unregister", handler);
    return get_f().mono_dl_fallback_unregister(handler);
}

LivenessState* executor_base::mono_unity_liveness_allocate_struct(MonoClass* filter, guint max_count, register_object_callback callback, void* callback_userdata)
{
    log_function("mono_unity_liveness_allocate_struct", filter, max_count, callback, callback_userdata);
    return get_f().mono_unity_liveness_allocate_struct(filter, max_count, callback, callback_userdata);
}

void executor_base::mono_unity_liveness_stop_gc_world()
{
    log_function("mono_unity_liveness_stop_gc_world");
    return get_f().mono_unity_liveness_stop_gc_world();
}

void executor_base::mono_unity_liveness_finalize(LivenessState* state)
{
    log_function("mono_unity_liveness_finalize", state);
    return get_f().mono_unity_liveness_finalize(state);
}

void executor_base::mono_unity_liveness_start_gc_world()
{
    log_function("mono_unity_liveness_start_gc_world");
    return get_f().mono_unity_liveness_start_gc_world();
}

void executor_base::mono_unity_liveness_free_struct(LivenessState* state)
{
    log_function("mono_unity_liveness_free_struct", state);
    return get_f().mono_unity_liveness_free_struct(state);
}

LivenessState* executor_base::mono_unity_liveness_calculation_begin(MonoClass* filter, guint max_count, register_object_callback callback, void* callback_userdata)
{
    log_function("mono_unity_liveness_calculation_begin", filter, max_count, callback, callback_userdata);
    return get_f().mono_unity_liveness_calculation_begin(filter, max_count, callback, callback_userdata);
}

void executor_base::mono_unity_liveness_calculation_end(LivenessState* state)
{
    log_function("mono_unity_liveness_calculation_end", state);
    return get_f().mono_unity_liveness_calculation_end(state);
}

void executor_base::mono_unity_liveness_calculation_from_root(MonoObject* root, LivenessState* state)
{                                                                   
    log_function("mono_unity_liveness_calculation_from_root", root, state);
    return get_f().mono_unity_liveness_calculation_from_root(root, state);
}

void executor_base::mono_unity_liveness_calculation_from_statics(LivenessState* state)
{
    log_function("mono_unity_liveness_calculation_from_statics", state);
    return get_f().mono_unity_liveness_calculation_from_statics(state);
}

void executor_base::mono_trace_set_level_string(const char* value)
{
    log_function("mono_trace_set_level_string", value);
    return get_f().mono_trace_set_level_string(value);
}

void executor_base::mono_trace_set_mask_string(char* value)
{
    log_function("mono_trace_set_mask_string", value);
    return get_f().mono_trace_set_mask_string(value);
}

gint64 executor_base::mono_gc_get_used_size()
{
    log_function("mono_gc_get_used_size");
    return get_f().mono_gc_get_used_size();
}

gint64 executor_base::mono_gc_get_heap_size()
{
    log_function("mono_gc_get_heap_size");
    return get_f().mono_gc_get_heap_size();
}

