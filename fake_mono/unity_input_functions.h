#pragma once

#include "mono_wrapper/types.h"
#include "unity_input_fwd.h"

namespace unity_input
{
struct functions_t
{
    typedef float(__cdecl *GetAxis_t)(MonoString* axisName);
    typedef float(__cdecl *GetAxisRaw_t)(MonoString* axisName);
    typedef gboolean(__cdecl *GetButton_t)(MonoString* buttonName);
    typedef gboolean(__cdecl *GetButtonUp_t)(MonoString* buttonName);
    typedef gboolean(__cdecl *GetButtonDown_t)(MonoString* buttonName);
    typedef MonoArray*(__cdecl *GetJoystickNames_t)();
    typedef gboolean(__cdecl *GetKeyDownInt_t)(int32_t key);
    typedef gboolean(__cdecl *GetKeyDownString_t)(MonoString* name);
    typedef gboolean(__cdecl *GetKeyInt_t)(int32_t key);
    typedef gboolean(__cdecl *GetKeyString_t)(MonoString* name);
    typedef gboolean(__cdecl *GetKeyUpInt_t)(int32_t key);
    typedef gboolean(__cdecl *GetKeyUpString_t)(MonoString* name);
    typedef gboolean(__cdecl *GetMouseButton_t)(int32_t button);
    typedef gboolean(__cdecl *GetMouseButtonDown_t)(int32_t button);
    typedef gboolean(__cdecl *GetMouseButtonUp_t)(int32_t button);
    typedef void(__cdecl *INTERNAL_CALL_GetAccelerationEvent_t)(int32_t index, MonoStruct_out value);
    typedef void(__cdecl *INTERNAL_CALL_GetTouch_t)(int32_t index, MonoStruct_out value);
    typedef void(__cdecl *INTERNAL_get_acceleration_t)(MonoStruct_out value);
    typedef void(__cdecl *INTERNAL_get_compositionCursorPos_t)(MonoStruct_out value);
    typedef void(__cdecl *INTERNAL_get_mousePosition_t)(MonoStruct_out value);
    typedef void(__cdecl *INTERNAL_get_mouseScrollDelta_t)(MonoStruct_out value);
    typedef void(__cdecl *INTERNAL_set_compositionCursorPos_t)(MonoStruct value);
    typedef void(__cdecl *ResetInputAxes_t)();
    typedef MonoObject*(__cdecl *get_deviceOrientation_t)();
    typedef MonoObject*(__cdecl *get_imeCompositionMode_t)();
    typedef int32_t(__cdecl *get_accelerationEventCount_t)();
    typedef gboolean(__cdecl *get_anyKey_t)();
    typedef gboolean(__cdecl *get_anyKeyDown_t)();
    typedef gboolean(__cdecl *get_backButtonLeavesApp_t)();
    typedef gboolean(__cdecl *get_compensateSensors_t)();
    typedef MonoString*(__cdecl *get_compositionString_t)();
    typedef gboolean(__cdecl *get_eatKeyPressOnTextFieldFocus_t)();
    typedef gboolean(__cdecl *get_imeIsSelected_t)();
    typedef MonoString*(__cdecl *get_inputString_t)();
    typedef gboolean(__cdecl *get_isGyroAvailable_t)();
    typedef gboolean(__cdecl *get_mousePresent_t)();
    typedef gboolean(__cdecl *get_multiTouchEnabled_t)();
    typedef gboolean(__cdecl *get_simulateMouseWithTouches_t)();
    typedef gboolean(__cdecl *get_stylusTouchSupported_t)();
    typedef int32_t(__cdecl *get_touchCount_t)();
    typedef gboolean(__cdecl *get_touchPressureSupported_t)();
    typedef gboolean(__cdecl *get_touchSupported_t)();
    typedef int32_t(__cdecl *mainGyroIndex_Internal_t)();
    typedef void(__cdecl *set_backButtonLeavesApp_t)(gboolean value);
    typedef void(__cdecl *set_compensateSensors_t)(gboolean value);
    typedef void(__cdecl *set_eatKeyPressOnTextFieldFocus_t)(gboolean value);
    typedef void(__cdecl *set_imeCompositionMode_t)(MonoObject* value);
    typedef void(__cdecl *set_multiTouchEnabled_t)(gboolean value);
    typedef void(__cdecl *set_simulateMouseWithTouches_t)(gboolean value);
    
    GetAxis_t GetAxis = nullptr;
    GetAxisRaw_t GetAxisRaw = nullptr;
    GetButton_t GetButton = nullptr;
    GetButtonUp_t GetButtonUp = nullptr;
    GetButtonDown_t GetButtonDown = nullptr;
    GetJoystickNames_t GetJoystickNames = nullptr;
    GetKeyDownInt_t GetKeyDownInt = nullptr;
    GetKeyDownString_t GetKeyDownString = nullptr;
    GetKeyInt_t GetKeyInt = nullptr;
    GetKeyString_t GetKeyString = nullptr;
    GetKeyUpInt_t GetKeyUpInt = nullptr;
    GetKeyUpString_t GetKeyUpString = nullptr;
    GetMouseButton_t GetMouseButton = nullptr;
    GetMouseButtonDown_t GetMouseButtonDown = nullptr;
    GetMouseButtonUp_t GetMouseButtonUp = nullptr;
    INTERNAL_CALL_GetAccelerationEvent_t INTERNAL_CALL_GetAccelerationEvent = nullptr;
    INTERNAL_CALL_GetTouch_t INTERNAL_CALL_GetTouch = nullptr;
    INTERNAL_get_acceleration_t INTERNAL_get_acceleration = nullptr;
    INTERNAL_get_compositionCursorPos_t INTERNAL_get_compositionCursorPos = nullptr;
    INTERNAL_get_mousePosition_t INTERNAL_get_mousePosition = nullptr;
    INTERNAL_get_mouseScrollDelta_t INTERNAL_get_mouseScrollDelta = nullptr;
    INTERNAL_set_compositionCursorPos_t INTERNAL_set_compositionCursorPos = nullptr;
    ResetInputAxes_t ResetInputAxes = nullptr;
    get_deviceOrientation_t get_deviceOrientation = nullptr;
    get_imeCompositionMode_t get_imeCompositionMode = nullptr;
    get_accelerationEventCount_t get_accelerationEventCount = nullptr;
    get_anyKey_t get_anyKey = nullptr;
    get_anyKeyDown_t get_anyKeyDown = nullptr;
    get_backButtonLeavesApp_t get_backButtonLeavesApp = nullptr;
    get_compensateSensors_t get_compensateSensors = nullptr;
    get_compositionString_t get_compositionString = nullptr;
    get_eatKeyPressOnTextFieldFocus_t get_eatKeyPressOnTextFieldFocus = nullptr;
    get_imeIsSelected_t get_imeIsSelected = nullptr;
    get_inputString_t get_inputString = nullptr;
    get_isGyroAvailable_t get_isGyroAvailable = nullptr;
    get_mousePresent_t get_mousePresent = nullptr;
    get_multiTouchEnabled_t get_multiTouchEnabled = nullptr;
    get_simulateMouseWithTouches_t get_simulateMouseWithTouches = nullptr;
    get_stylusTouchSupported_t get_stylusTouchSupported = nullptr;
    get_touchCount_t get_touchCount = nullptr;
    get_touchPressureSupported_t get_touchPressureSupported = nullptr;
    get_touchSupported_t get_touchSupported = nullptr;
    mainGyroIndex_Internal_t mainGyroIndex_Internal = nullptr;
    set_backButtonLeavesApp_t set_backButtonLeavesApp = nullptr;
    set_compensateSensors_t set_compensateSensors = nullptr;
    set_eatKeyPressOnTextFieldFocus_t set_eatKeyPressOnTextFieldFocus = nullptr;
    set_imeCompositionMode_t set_imeCompositionMode = nullptr;
    set_multiTouchEnabled_t set_multiTouchEnabled = nullptr;
    set_simulateMouseWithTouches_t set_simulateMouseWithTouches = nullptr;
};
} // namespace unity_input
