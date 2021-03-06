#define ARG(tp, nm) { "name": #nm, "type": #tp, "array": false }
#define ARGS(a) a
#define DEF_API(nm, a, ret) { "name": #nm, "return_type": #ret, "args": [ a ] },


DEF_API(GetAxis, ARGS((ARG(MonoString*, axisName))), float)
DEF_API(GetAxisRaw, ARGS((ARG(MonoString*, axisName))), float)
DEF_API(GetButton, ARGS((ARG(MonoString*, buttonName))), MonoBoolean)
DEF_API(GetButtonUp, ARGS((ARG(MonoString*, buttonName))), MonoBoolean)
DEF_API(GetButtonDown, ARGS((ARG(MonoString*, buttonName))), MonoBoolean)
DEF_API(GetJoystickNames, ARGS(()), MonoArray*)
DEF_API(GetKeyDownInt, ARGS((ARG(int32_t, key))), MonoBoolean)
DEF_API(GetKeyDownString, ARGS((ARG(MonoString*, name))), MonoBoolean)
DEF_API(GetKeyInt, ARGS((ARG(int32_t, key))), MonoBoolean)
DEF_API(GetKeyString, ARGS((ARG(MonoString*, name))), MonoBoolean)
DEF_API(GetKeyUpInt, ARGS((ARG(int32_t, key))), MonoBoolean)
DEF_API(GetKeyUpString, ARGS((ARG(MonoString*, name))), MonoBoolean)
DEF_API(GetMouseButton, ARGS((ARG(int32_t, button))), MonoBoolean)
DEF_API(GetMouseButtonDown, ARGS((ARG(int32_t, button))), MonoBoolean)
DEF_API(GetMouseButtonUp, ARGS((ARG(int32_t, button))), MonoBoolean)
DEF_API(INTERNAL_CALL_GetAccelerationEvent, ARGS((ARG(int32_t, index), ARG(MonoStruct_out, value))), void)
DEF_API(INTERNAL_CALL_GetTouch, ARGS((ARG(int32_t, index), ARG(MonoStruct_out, value))), void)
DEF_API(INTERNAL_get_acceleration, ARGS((ARG(MonoStruct_out, value))), void)
DEF_API(INTERNAL_get_compositionCursorPos, ARGS((ARG(MonoStruct_out, value))), void)
DEF_API(INTERNAL_get_mousePosition, ARGS((ARG(MonoStruct_out, value))), void)
DEF_API(INTERNAL_get_mouseScrollDelta, ARGS((ARG(MonoStruct_out, value))), void)
DEF_API(INTERNAL_set_compositionCursorPos, ARGS((ARG(MonoStruct, value))), void)
DEF_API(ResetInputAxes, ARGS(()), void)
DEF_API(get_deviceOrientation, ARGS(()), MonoObject*)
DEF_API(get_imeCompositionMode, ARGS(()), MonoObject*)
DEF_API(get_accelerationEventCount, ARGS(()), int32_t)
DEF_API(get_anyKey, ARGS(()), MonoBoolean)
DEF_API(get_anyKeyDown, ARGS(()), MonoBoolean)
DEF_API(get_backButtonLeavesApp, ARGS(()), MonoBoolean)
DEF_API(get_compensateSensors, ARGS(()), MonoBoolean)
DEF_API(get_compositionString, ARGS(()), MonoString*)
DEF_API(get_eatKeyPressOnTextFieldFocus, ARGS(()), MonoBoolean)
DEF_API(get_imeIsSelected, ARGS(()), MonoBoolean)
DEF_API(get_inputString, ARGS(()), MonoString*)
DEF_API(get_isGyroAvailable, ARGS(()), MonoBoolean)
DEF_API(get_mousePresent, ARGS(()), MonoBoolean)
DEF_API(get_multiTouchEnabled, ARGS(()), MonoBoolean)
DEF_API(get_simulateMouseWithTouches, ARGS(()), MonoBoolean)
DEF_API(get_stylusTouchSupported, ARGS(()), MonoBoolean)
DEF_API(get_touchCount, ARGS(()), int32_t)
DEF_API(get_touchPressureSupported, ARGS(()), MonoBoolean)
DEF_API(get_touchSupported, ARGS(()), MonoBoolean)
DEF_API(mainGyroIndex_Internal, ARGS(()), int32_t)
DEF_API(set_backButtonLeavesApp, ARGS((ARG(MonoBoolean, value))), void)
DEF_API(set_compensateSensors, ARGS((ARG(MonoBoolean, value))), void)
DEF_API(set_eatKeyPressOnTextFieldFocus, ARGS((ARG(MonoBoolean, value))), void)
DEF_API(set_imeCompositionMode, ARGS((ARG(MonoObject*, value))), void)
DEF_API(set_multiTouchEnabled, ARGS((ARG(MonoBoolean, value))), void)
DEF_API(set_simulateMouseWithTouches, ARGS((ARG(MonoBoolean, value))), void)