#pragma once

namespace mono_wrapper
{

namespace types
{


typedef signed long SInt32;
typedef unsigned long UInt32;
typedef signed short SInt16;
typedef unsigned short UInt16;
typedef unsigned char UInt8;
typedef signed char SInt8;
typedef unsigned long long UInt64;
typedef signed long long SInt64;

struct MonoException;
struct MonoAssembly;
struct MonoObject;
struct MonoClassField;
struct MonoClass;
struct MonoDomain;
struct MonoImage;
struct MonoType;
struct MonoMethodSignature;
struct MonoArray;
struct MonoThread;
struct MonoVTable;
struct MonoProperty;
struct MonoReflectionAssembly;
struct MonoReflectionMethod;
struct MonoAppDomain;
struct MonoCustomAttrInfo;

struct MonoReflectionType { UInt32 offset[2]; MonoType* type;};

typedef void* gconstpointer;
typedef void* gpointer;
typedef int gboolean;
typedef unsigned int guint32;
typedef int gint32;
typedef long gint64;
typedef unsigned char   guchar;
typedef UInt16 gunichar2;

typedef MonoObject* MonoStruct;
typedef MonoObject** MonoStruct_out;

// struct MonoString 
// {
// 	gint32 monoObjectPart1;
// 	gint32 monoObjectPart2;
// 	gint32 length;
// 	gunichar2 firstCharacter;
// };

typedef MonoObject MonoString;

struct MonoMethod {
	UInt16 flags;
	UInt16 iflags;
};

typedef enum
{
	MONO_VERIFIER_MODE_OFF,
	MONO_VERIFIER_MODE_VALID,
	MONO_VERIFIER_MODE_VERIFIABLE,
	MONO_VERIFIER_MODE_STRICT
} MiniVerifierMode;

typedef enum {
	MONO_SECURITY_MODE_NONE,
	MONO_SECURITY_MODE_CORE_CLR,
	MONO_SECURITY_MODE_CAS,
	MONO_SECURITY_MODE_SMCS_HACK
} MonoSecurityMode;

typedef void GFuncRef (void*, void*);
typedef GFuncRef* GFunc;

typedef enum {
	MONO_UNHANDLED_POLICY_LEGACY,
	MONO_UNHANDLED_POLICY_CURRENT
} MonoRuntimeUnhandledExceptionPolicy;

struct MonoMethodDesc {
	char *namespace2;
	char *klass;
	char *name;
	char *args1;
	UInt32 num_args;
	gboolean include_namespace, klass_glob, name_glob;
};


struct MonoJitInfo;
struct MonoAssemblyName;
struct MonoDebugSourceLocation;
struct MonoLoaderError;
struct MonoDlFallbackHandler;
struct LivenessState;

struct MonoBreakPolicy;

typedef bool (*MonoCoreClrPlatformCB) (const char *image_name);

typedef unsigned int guint;
typedef void (*register_object_callback)(gpointer* arr, int size, void* callback_userdata);
typedef gboolean (*MonoStackWalk)     (MonoMethod *method, gint32 native_offset, gint32 il_offset, gboolean managed, gpointer data);
typedef MonoBreakPolicy (*MonoBreakPolicyFunc) (MonoMethod *method);
typedef void* (*MonoDlFallbackLoad) (const char *name, int flags, char **err, void *user_data);
typedef void* (*MonoDlFallbackSymbol) (void *handle, const char *name, char **err, void *user_data);
typedef void* (*MonoDlFallbackClose) (void *handle, void *user_data);

typedef enum {
	MONO_TYPE_NAME_FORMAT_IL,
	MONO_TYPE_NAME_FORMAT_REFLECTION,
	MONO_TYPE_NAME_FORMAT_FULL_NAME,
	MONO_TYPE_NAME_FORMAT_ASSEMBLY_QUALIFIED
} MonoTypeNameFormat;

typedef void (*vprintf_func)(const char* msg, va_list args);

struct MonoProfiler;
typedef void (*MonoProfileFunc) (MonoProfiler *prof);

typedef enum {
	MONO_PROFILE_NONE = 0,
	MONO_PROFILE_APPDOMAIN_EVENTS = 1 << 0,
	MONO_PROFILE_ASSEMBLY_EVENTS  = 1 << 1,
	MONO_PROFILE_MODULE_EVENTS    = 1 << 2,
	MONO_PROFILE_CLASS_EVENTS     = 1 << 3,
	MONO_PROFILE_JIT_COMPILATION  = 1 << 4,
	MONO_PROFILE_INLINING         = 1 << 5,
	MONO_PROFILE_EXCEPTIONS       = 1 << 6,
	MONO_PROFILE_ALLOCATIONS      = 1 << 7,
	MONO_PROFILE_GC               = 1 << 8,
	MONO_PROFILE_THREADS          = 1 << 9,
	MONO_PROFILE_REMOTING         = 1 << 10,
	MONO_PROFILE_TRANSITIONS      = 1 << 11,
	MONO_PROFILE_ENTER_LEAVE      = 1 << 12,
	MONO_PROFILE_COVERAGE         = 1 << 13,
	MONO_PROFILE_INS_COVERAGE     = 1 << 14,
	MONO_PROFILE_STATISTICAL      = 1 << 15,
	MONO_PROFILE_METHOD_EVENTS    = 1 << 16,
	MONO_PROFILE_MONITOR_EVENTS   = 1 << 17,
	MONO_PROFILE_IOMAP_EVENTS = 1 << 18, /* this should likely be removed, too */
	MONO_PROFILE_GC_MOVES = 1 << 19
} MonoProfileFlags;

typedef enum {
	MONO_GC_EVENT_START,
	MONO_GC_EVENT_MARK_START,
	MONO_GC_EVENT_MARK_END,
	MONO_GC_EVENT_RECLAIM_START,
	MONO_GC_EVENT_RECLAIM_END,
	MONO_GC_EVENT_END,
	MONO_GC_EVENT_PRE_STOP_WORLD,
	MONO_GC_EVENT_POST_STOP_WORLD,
	MONO_GC_EVENT_PRE_START_WORLD,
	MONO_GC_EVENT_POST_START_WORLD
} MonoGCEvent;

typedef void (*MonoProfileMethodFunc)   (MonoProfiler *prof, MonoMethod   *method);
typedef void (*MonoProfileGCFunc)         (MonoProfiler *prof, MonoGCEvent event, int generation);
typedef void (*MonoProfileGCMoveFunc) (MonoProfiler *prof, void **objects, int num);
typedef void (*MonoProfileGCResizeFunc)   (MonoProfiler *prof, gint64 new_size);
typedef void (*MonoProfileAllocFunc)      (MonoProfiler *prof, MonoObject *obj, MonoClass *klass);
typedef void (*MonoProfileJitResult)      (MonoProfiler *prof, MonoMethod   *method,   MonoJitInfo* jinfo,   int result);
typedef void (*MonoProfileExceptionFunc) (MonoProfiler *prof, MonoObject *object);
typedef void (*MonoProfileExceptionClauseFunc) (MonoProfiler *prof, MonoMethod *method, int clause_type, int clause_num);


} // namespace types
} // namespace mono_wrapper

using namespace mono_wrapper::types;


