#pragma once

#include "mono_wrapper/types.h"
#include "unity_input_fwd.h"

namespace unity_input
{
struct executor
{
    virtual ~executor() {}

    virtual float GetAxis(MonoString* axisName) = 0;
    virtual float GetAxisRaw(MonoString* axisName) = 0;
    virtual gboolean GetButton(MonoString* buttonName) = 0;
    virtual gboolean GetButtonUp(MonoString* buttonName) = 0;
    virtual gboolean GetButtonDown(MonoString* buttonName) = 0;
    virtual MonoArray* GetJoystickNames() = 0;
    virtual gboolean GetKeyDownInt(int32_t key) = 0;
    virtual gboolean GetKeyDownString(MonoString* name) = 0;
    virtual gboolean GetKeyInt(int32_t key) = 0;
    virtual gboolean GetKeyString(MonoString* name) = 0;
    virtual gboolean GetKeyUpInt(int32_t key) = 0;
    virtual gboolean GetKeyUpString(MonoString* name) = 0;
    virtual gboolean GetMouseButton(int32_t button) = 0;
    virtual gboolean GetMouseButtonDown(int32_t button) = 0;
    virtual gboolean GetMouseButtonUp(int32_t button) = 0;
    virtual void INTERNAL_CALL_GetAccelerationEvent(int32_t index, MonoStruct_out value) = 0;
    virtual void INTERNAL_CALL_GetTouch(int32_t index, MonoStruct_out value) = 0;
    virtual void INTERNAL_get_acceleration(MonoStruct_out value) = 0;
    virtual void INTERNAL_get_compositionCursorPos(MonoStruct_out value) = 0;
    virtual void INTERNAL_get_mousePosition(MonoStruct_out value) = 0;
    virtual void INTERNAL_get_mouseScrollDelta(MonoStruct_out value) = 0;
    virtual void INTERNAL_set_compositionCursorPos(MonoStruct value) = 0;
    virtual void ResetInputAxes() = 0;
    virtual MonoObject* get_deviceOrientation() = 0;
    virtual MonoObject* get_imeCompositionMode() = 0;
    virtual int32_t get_accelerationEventCount() = 0;
    virtual gboolean get_anyKey() = 0;
    virtual gboolean get_anyKeyDown() = 0;
    virtual gboolean get_backButtonLeavesApp() = 0;
    virtual gboolean get_compensateSensors() = 0;
    virtual MonoString* get_compositionString() = 0;
    virtual gboolean get_eatKeyPressOnTextFieldFocus() = 0;
    virtual gboolean get_imeIsSelected() = 0;
    virtual MonoString* get_inputString() = 0;
    virtual gboolean get_isGyroAvailable() = 0;
    virtual gboolean get_mousePresent() = 0;
    virtual gboolean get_multiTouchEnabled() = 0;
    virtual gboolean get_simulateMouseWithTouches() = 0;
    virtual gboolean get_stylusTouchSupported() = 0;
    virtual int32_t get_touchCount() = 0;
    virtual gboolean get_touchPressureSupported() = 0;
    virtual gboolean get_touchSupported() = 0;
    virtual int32_t mainGyroIndex_Internal() = 0;
    virtual void set_backButtonLeavesApp(gboolean value) = 0;
    virtual void set_compensateSensors(gboolean value) = 0;
    virtual void set_eatKeyPressOnTextFieldFocus(gboolean value) = 0;
    virtual void set_imeCompositionMode(MonoObject* value) = 0;
    virtual void set_multiTouchEnabled(gboolean value) = 0;
    virtual void set_simulateMouseWithTouches(gboolean value) = 0;
};

executor_ptr create_executor(functions_cptr);
} // namespace unity_input
