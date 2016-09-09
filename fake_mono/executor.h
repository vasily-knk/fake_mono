#pragma once

#include "mono_wrapper/types.h"
#include "mono_wrapper/mono_wrapper_fwd.h"
#include "fake_mono_fwd.h"

struct executor
{
    virtual ~executor() {}

    virtual void mono_thread_suspend_all_other_threads() = 0;
    virtual void mono_thread_pool_cleanup() = 0;
    virtual void mono_threads_set_shutting_down() = 0;
    virtual void mono_runtime_set_shutting_down() = 0;
    virtual gboolean mono_domain_finalize(MonoDomain* domain, int timeout) = 0;
    virtual void mono_runtime_cleanup(MonoDomain* domain) = 0;
    virtual MonoMethodDesc* mono_method_desc_new(const char* name, gboolean include_namespace) = 0;
    virtual MonoMethod* mono_method_desc_search_in_image(MonoMethodDesc* desc, MonoImage* image) = 0;
    virtual void mono_verifier_set_mode(MiniVerifierMode m) = 0;
    virtual void mono_security_set_mode(MonoSecurityMode m) = 0;
    virtual void mono_add_internal_call(const char* name, gconstpointer method) = 0;
    virtual void mono_jit_cleanup(MonoDomain* domain) = 0;
    virtual MonoDomain* mono_jit_init(const char* file) = 0;
    virtual MonoDomain* mono_jit_init_version(const char* file, const char* runtime_version) = 0;
    virtual int mono_jit_exec(MonoDomain* domain, MonoAssembly* assembly, int argc, char* argv[]) = 0;
    virtual MonoClass* mono_class_from_name(MonoImage* image, const char* name_space, const char* name) = 0;
    virtual MonoAssembly* mono_domain_assembly_open(MonoDomain* domain, const char* name) = 0;
    virtual MonoDomain* mono_domain_create_appdomain(const char* domainname, const char* configfile) = 0;
    virtual void mono_domain_unload(MonoDomain* domain) = 0;
    virtual MonoObject* mono_object_new(MonoDomain* domain, MonoClass* klass) = 0;
    virtual void mono_runtime_object_init(MonoObject* this_obj) = 0;
    virtual MonoObject* mono_runtime_invoke(MonoMethod* method, void* obj, void** params, MonoObject** exc) = 0;
    virtual void mono_field_set_value(MonoObject* obj, MonoClassField* field, void* value) = 0;
    virtual void mono_field_get_value(MonoObject* obj, MonoClassField* field, void* value) = 0;
    virtual int mono_field_get_offset(MonoClassField* field) = 0;
    virtual MonoClassField* mono_class_get_fields(MonoClass* klass, gpointer* iter) = 0;
    virtual MonoMethod* mono_class_get_methods(MonoClass* klass, gpointer* iter) = 0;
    virtual MonoDomain* mono_domain_get() = 0;
    virtual MonoDomain* mono_get_root_domain() = 0;
    virtual gint32 mono_domain_get_id(MonoDomain* domain) = 0;
    virtual void mono_assembly_foreach(GFunc func, gpointer user_data) = 0;
    virtual void mono_image_close(MonoImage* image) = 0;
    virtual void mono_unity_socket_security_enabled_set(gboolean b) = 0;
    virtual const char* mono_image_get_name(MonoImage* image) = 0;
    virtual MonoClass* mono_get_object_class() = 0;
    virtual void mono_set_commandline_arguments(int i, const char* argv[], const char* s) = 0;
    virtual const char* mono_field_get_name(MonoClassField* field) = 0;
    virtual MonoType* mono_field_get_type(MonoClassField* field) = 0;
    virtual int mono_type_get_type(MonoType* type) = 0;
    virtual const char* mono_method_get_name(MonoMethod* method) = 0;
    virtual MonoImage* mono_assembly_get_image(MonoAssembly* assembly) = 0;
    virtual MonoClass* mono_method_get_class(MonoMethod* method) = 0;
    virtual MonoClass* mono_object_get_class(MonoObject* obj) = 0;
    virtual gboolean mono_class_is_valuetype(MonoClass* klass) = 0;
    virtual guint32 mono_signature_get_param_count(MonoMethodSignature* sig) = 0;
    virtual char* mono_string_to_utf8(MonoString* string_obj) = 0;
    virtual MonoString* mono_string_new_wrapper(const char* text) = 0;
    virtual MonoClass* mono_class_get_parent(MonoClass* klass) = 0;
    virtual const char* mono_class_get_namespace(MonoClass* klass) = 0;
    virtual gboolean mono_class_is_subclass_of(MonoClass* klass, MonoClass* klassc, gboolean check_interfaces) = 0;
    virtual const char* mono_class_get_name(MonoClass* klass) = 0;
    virtual char* mono_type_get_name(MonoType* type) = 0;
    virtual MonoClass* mono_type_get_class(MonoType* type) = 0;
    virtual MonoException* mono_exception_from_name_msg(MonoImage* image, const char* name_space, const char* name, const char* msg) = 0;
    virtual void mono_raise_exception(MonoException* ex) = 0;
    virtual MonoClass* mono_get_exception_class() = 0;
    virtual MonoClass* mono_get_array_class() = 0;
    virtual MonoClass* mono_get_string_class() = 0;
    virtual MonoClass* mono_get_int32_class() = 0;
    virtual MonoArray* mono_array_new(MonoDomain* domain, MonoClass* eclass, guint32 n) = 0;
    virtual MonoArray* mono_array_new_full(MonoDomain* domain, MonoClass* array_class, guint32* lengths, guint32* lower_bounds) = 0;
    virtual MonoClass* mono_array_class_get(MonoClass* eclass, guint32 rank) = 0;
    virtual gint32 mono_class_array_element_size(MonoClass* ac) = 0;
    virtual MonoObject* mono_type_get_object(MonoDomain* domain, MonoType* type) = 0;
    virtual MonoThread* mono_thread_attach(MonoDomain* domain) = 0;
    virtual void mono_thread_detach(MonoThread* thread) = 0;
    virtual MonoThread* mono_thread_exit() = 0;
    virtual MonoThread* mono_thread_current() = 0;
    virtual void mono_thread_set_main(MonoThread* thread) = 0;
    virtual void mono_set_find_plugin_callback(gconstpointer method) = 0;
    virtual void mono_security_enable_core_clr() = 0;
    virtual bool mono_security_set_core_clr_platform_callback(MonoCoreClrPlatformCB a) = 0;
    virtual MonoRuntimeUnhandledExceptionPolicy mono_runtime_unhandled_exception_policy_get() = 0;
    virtual void mono_runtime_unhandled_exception_policy_set(MonoRuntimeUnhandledExceptionPolicy policy) = 0;
    virtual MonoClass* mono_class_get_nesting_type(MonoClass* klass) = 0;
    virtual MonoVTable* mono_class_vtable(MonoDomain* domain, MonoClass* klass) = 0;
    virtual MonoReflectionMethod* mono_method_get_object(MonoDomain* domain, MonoMethod* method, MonoClass* refclass) = 0;
    virtual MonoMethodSignature* mono_method_signature(MonoMethod* method) = 0;
    virtual MonoType* mono_signature_get_params(MonoMethodSignature* sig, gpointer* iter) = 0;
    virtual MonoType* mono_signature_get_return_type(MonoMethodSignature* sig) = 0;
    virtual MonoType* mono_class_get_type(MonoClass* klass) = 0;
    virtual void mono_set_ignore_version_and_key_when_finding_assemblies_already_loaded(gboolean value) = 0;
    virtual void mono_debug_init(int format) = 0;
    virtual void mono_debug_open_image_from_memory(MonoImage* image, const char* raw_contents, int size) = 0;
    virtual guint32 mono_field_get_flags(MonoClassField* field) = 0;
    virtual MonoImage* mono_image_open_from_data_full(const void* data, guint32 data_len, gboolean need_copy, int* status, gboolean ref_only) = 0;
    virtual MonoImage* mono_image_open_from_data_with_name(char* data, guint32 data_len, gboolean need_copy, int* status, gboolean refonly, const char* name) = 0;
    virtual MonoAssembly* mono_assembly_load_from(MonoImage* image, const char* fname, int* status) = 0;
    virtual MonoObject* mono_value_box(MonoDomain* domain, MonoClass* klass, gpointer val) = 0;
    virtual MonoImage* mono_class_get_image(MonoClass* klass) = 0;
    virtual char mono_signature_is_instance(MonoMethodSignature* signature) = 0;
    virtual MonoMethod* mono_method_get_last_managed() = 0;
    virtual MonoClass* mono_get_enum_class() = 0;
    virtual MonoType* mono_class_get_byref_type(MonoClass* klass) = 0;
    virtual void mono_field_static_get_value(MonoVTable* vt, MonoClassField* field, void* value) = 0;
    virtual void mono_unity_set_embeddinghostname(const char* name) = 0;
    virtual void mono_set_assemblies_path(const char* name) = 0;
    virtual guint32 mono_gchandle_new(MonoObject* obj, gboolean pinned) = 0;
    virtual MonoObject* mono_gchandle_get_target(guint32 gchandle) = 0;
    virtual guint32 mono_gchandle_new_weakref(MonoObject* obj, gboolean track_resurrection) = 0;
    virtual MonoObject* mono_assembly_get_object(MonoDomain* domain, MonoAssembly* assembly) = 0;
    virtual void mono_gchandle_free(guint32 gchandle) = 0;
    virtual MonoProperty* mono_class_get_properties(MonoClass* klass, gpointer* iter) = 0;
    virtual MonoMethod* mono_property_get_get_method(MonoProperty* prop) = 0;
    virtual MonoObject* mono_object_new_alloc_specific(MonoVTable* vtable) = 0;
    virtual MonoObject* mono_object_new_specific(MonoVTable* vtable) = 0;
    virtual void mono_gc_collect(int generation) = 0;
    virtual int mono_gc_max_generation() = 0;
    virtual MonoAssembly* mono_image_get_assembly(MonoImage* image) = 0;
    virtual MonoAssembly* mono_assembly_open(const char* filename, int* status) = 0;
    virtual gboolean mono_class_is_enum(MonoClass* klass) = 0;
    virtual gint32 mono_class_instance_size(MonoClass* klass) = 0;
    virtual guint32 mono_object_get_size(MonoObject* obj) = 0;
    virtual const char* mono_image_get_filename(MonoImage* image) = 0;
    virtual MonoAssembly* mono_assembly_load_from_full(MonoImage* image, const char* fname, int* status, gboolean refonly) = 0;
    virtual MonoClass* mono_class_get_interfaces(MonoClass* klass, gpointer* iter) = 0;
    virtual void mono_assembly_close(MonoAssembly* assembly) = 0;
    virtual MonoProperty* mono_class_get_property_from_name(MonoClass* klass, const char* name) = 0;
    virtual MonoMethod* mono_class_get_method_from_name(MonoClass* klass, const char* name, int param_count) = 0;
    virtual MonoClass* mono_class_from_mono_type(MonoType* image) = 0;
    virtual gboolean mono_domain_set(MonoDomain* domain, gboolean force) = 0;
    virtual void mono_thread_push_appdomain_ref(MonoDomain* domain) = 0;
    virtual void mono_thread_pop_appdomain_ref() = 0;
    virtual int mono_runtime_exec_main(MonoMethod* method, MonoArray* args, MonoObject** exc) = 0;
    virtual MonoImage* mono_get_corlib() = 0;
    virtual MonoClassField* mono_class_get_field_from_name(MonoClass* klass, const char* name) = 0;
    virtual guint32 mono_class_get_flags(MonoClass* klass) = 0;
    virtual int mono_parse_default_optimizations(const char* p) = 0;
    virtual void mono_set_defaults(int verbose_level, guint32 opts) = 0;
    virtual void mono_set_dirs(const char* assembly_dir, const char* config_dir) = 0;
    virtual void mono_jit_parse_options(int argc, char* argv[]) = 0;
    virtual gpointer mono_object_unbox(MonoObject* o) = 0;
    virtual MonoObject* mono_custom_attrs_get_attr(MonoCustomAttrInfo* ainfo, MonoClass* attr_klass) = 0;
    virtual gboolean mono_custom_attrs_has_attr(MonoCustomAttrInfo* ainfo, MonoClass* attr_klass) = 0;
    virtual MonoCustomAttrInfo* mono_custom_attrs_from_field(MonoClass* klass, MonoClassField* field) = 0;
    virtual MonoCustomAttrInfo* mono_custom_attrs_from_method(MonoMethod* method) = 0;
    virtual MonoCustomAttrInfo* mono_custom_attrs_from_class(MonoClass* klass) = 0;
    virtual void mono_custom_attrs_free(MonoCustomAttrInfo* attr) = 0;
    virtual void g_free(void* p) = 0;
    virtual gboolean mono_runtime_is_shutting_down() = 0;
    virtual MonoMethod* mono_object_get_virtual_method(MonoObject* obj, MonoMethod* method) = 0;
    virtual gpointer mono_jit_info_get_code_start(MonoJitInfo* ji) = 0;
    virtual int mono_jit_info_get_code_size(MonoJitInfo* ji) = 0;
    virtual MonoClass* mono_class_from_name_case(MonoImage* image, const char* name_space, const char* name) = 0;
    virtual MonoClass* mono_class_get_nested_types(MonoClass* klass, gpointer* iter) = 0;
    virtual int mono_class_get_userdata_offset() = 0;
    virtual void* mono_class_get_userdata(MonoClass* klass) = 0;
    virtual void mono_class_set_userdata(MonoClass* klass, void* userdata) = 0;
    virtual void mono_set_signal_chaining(gboolean chain_signals) = 0;
    virtual LONG mono_unity_seh_handler(EXCEPTION_POINTERS* ep) = 0;
    virtual void mono_unity_set_unhandled_exception_handler(void* handler) = 0;
    virtual MonoObject* mono_runtime_invoke_array(MonoMethod* method, void* obj, MonoArray* params, MonoObject** exc) = 0;
    virtual char* mono_array_addr_with_size(MonoArray* array, int size, uintptr_t idx) = 0;
    virtual gunichar2* mono_string_to_utf16(MonoString* string_obj) = 0;
    virtual MonoClass* mono_field_get_parent(MonoClassField* field) = 0;
    virtual char* mono_method_full_name(MonoMethod* method, gboolean signature) = 0;
    virtual MonoObject* mono_object_isinst(MonoObject* obj, MonoClass* klass) = 0;
    virtual MonoString* mono_string_new_len(MonoDomain* domain, const char* text, guint length) = 0;
    virtual MonoString* mono_string_from_utf16(gunichar2* data) = 0;
    virtual MonoException* mono_get_exception_argument_null(const char* arg) = 0;
    virtual MonoClass* mono_get_boolean_class() = 0;
    virtual MonoClass* mono_get_byte_class() = 0;
    virtual MonoClass* mono_get_char_class() = 0;
    virtual MonoClass* mono_get_int16_class() = 0;
    virtual MonoClass* mono_get_int64_class() = 0;
    virtual MonoClass* mono_get_single_class() = 0;
    virtual MonoClass* mono_get_double_class() = 0;
    virtual gboolean mono_class_is_generic(MonoClass* klass) = 0;
    virtual gboolean mono_class_is_inflated(MonoClass* klass) = 0;
    virtual gboolean unity_mono_method_is_generic(MonoMethod* method) = 0;
    virtual gboolean unity_mono_method_is_inflated(MonoMethod* method) = 0;
    virtual gboolean mono_is_debugger_attached() = 0;
    virtual gboolean mono_assembly_fill_assembly_name(MonoImage* image, MonoAssemblyName* aname) = 0;
    virtual char* mono_stringify_assembly_name(MonoAssemblyName* aname) = 0;
    virtual gboolean mono_assembly_name_parse(const char* name, MonoAssemblyName* aname) = 0;
    virtual MonoAssembly* mono_assembly_loaded(MonoAssemblyName* aname) = 0;
    virtual int mono_image_get_table_rows(MonoImage* image, int table_id) = 0;
    virtual MonoClass* mono_class_get(MonoImage* image, guint32 type_token) = 0;
    virtual gboolean mono_metadata_signature_equal(MonoMethodSignature* sig1, MonoMethodSignature* sig2) = 0;
    virtual gboolean mono_gchandle_is_in_domain(guint32 gchandle, MonoDomain* domain) = 0;
    virtual void mono_stack_walk(MonoStackWalk func, gpointer user_data) = 0;
    virtual char* mono_pmip(void* ip) = 0;
    virtual MonoObject* mono_runtime_delegate_invoke(MonoObject* delegate, void** params, MonoObject** exc) = 0;
    virtual MonoJitInfo* mono_jit_info_table_find(MonoDomain* domain, char* addr) = 0;
    virtual MonoDebugSourceLocation* mono_debug_lookup_source_location(MonoMethod* method, guint32 address, MonoDomain* domain) = 0;
    virtual void mono_debug_free_source_location(MonoDebugSourceLocation* location) = 0;
    virtual void mono_gc_wbarrier_generic_store(gpointer ptr, MonoObject* value) = 0;
    virtual MonoType* mono_class_enum_basetype(MonoClass* klass) = 0;
    virtual guint32 mono_class_get_type_token(MonoClass* klass) = 0;
    virtual int mono_class_get_rank(MonoClass* klass) = 0;
    virtual MonoClass* mono_class_get_element_class(MonoClass* klass) = 0;
    virtual gboolean mono_unity_class_is_interface(MonoClass* klass) = 0;
    virtual gboolean mono_unity_class_is_abstract(MonoClass* klass) = 0;
    virtual gint32 mono_array_element_size(MonoClass* ac) = 0;
    virtual void mono_config_parse(const char* filename) = 0;
    virtual void mono_set_break_policy(MonoBreakPolicyFunc policy_callback) = 0;
    virtual MonoArray* mono_custom_attrs_construct(MonoCustomAttrInfo* cinfo) = 0;
    virtual MonoCustomAttrInfo* mono_custom_attrs_from_assembly(MonoAssembly* assembly) = 0;
    virtual MonoArray* mono_reflection_get_custom_attrs_by_type(MonoObject* obj, MonoClass* attr_klass) = 0;
    virtual MonoLoaderError* mono_loader_get_last_error() = 0;
    virtual MonoException* mono_loader_error_prepare_exception(MonoLoaderError* error) = 0;
    virtual MonoDlFallbackHandler* mono_dl_fallback_register(MonoDlFallbackLoad load_func, MonoDlFallbackSymbol symbol_func, MonoDlFallbackClose close_func, void* user_data) = 0;
    virtual void mono_dl_fallback_unregister(MonoDlFallbackHandler* handler) = 0;
    virtual LivenessState* mono_unity_liveness_allocate_struct(MonoClass* filter, guint max_count, register_object_callback callback, void* callback_userdata) = 0;
    virtual void mono_unity_liveness_stop_gc_world() = 0;
    virtual void mono_unity_liveness_finalize(LivenessState* state) = 0;
    virtual void mono_unity_liveness_start_gc_world() = 0;
    virtual void mono_unity_liveness_free_struct(LivenessState* state) = 0;
    virtual LivenessState* mono_unity_liveness_calculation_begin(MonoClass* filter, guint max_count, register_object_callback callback, void* callback_userdata) = 0;
    virtual void mono_unity_liveness_calculation_end(LivenessState* state) = 0;
    virtual void mono_unity_liveness_calculation_from_root(MonoObject* root, LivenessState* state) = 0;
    virtual void mono_unity_liveness_calculation_from_statics(LivenessState* state) = 0;
    virtual void mono_trace_set_level_string(const char* value) = 0;
    virtual void mono_trace_set_mask_string(char* value) = 0;
    virtual gint64 mono_gc_get_used_size() = 0;
    virtual gint64 mono_gc_get_heap_size() = 0;
    virtual MonoMethod* mono_method_desc_search_in_class(MonoMethodDesc* desc, MonoClass* klass) = 0;
    virtual void mono_method_desc_free(MonoMethodDesc* desc) = 0;
    virtual char* mono_type_get_name_full(MonoType* type, MonoTypeNameFormat format) = 0;
    virtual void mono_unity_thread_clear_domain_fields() = 0;
    virtual void mono_unity_set_vprintf_func(vprintf_func func) = 0;
    virtual void mono_profiler_install(MonoProfiler* prof, MonoProfileFunc shutdown_callback) = 0;
    virtual void mono_profiler_set_events(MonoProfileFlags events) = 0;
    virtual void mono_profiler_install_enter_leave(MonoProfileMethodFunc enter, MonoProfileMethodFunc fleave) = 0;
    virtual void mono_profiler_install_gc(MonoProfileGCFunc callback, MonoProfileGCResizeFunc heap_resize_callback) = 0;
    virtual void mono_profiler_install_allocation(MonoProfileAllocFunc callback) = 0;
    virtual void mono_profiler_install_jit_end(MonoProfileJitResult end) = 0;
    virtual void mono_profiler_install_exception(MonoProfileExceptionFunc throw_callback, MonoProfileMethodFunc exc_method_leave, MonoProfileExceptionClauseFunc clause_callback) = 0;
};

executor_ptr create_executor();
