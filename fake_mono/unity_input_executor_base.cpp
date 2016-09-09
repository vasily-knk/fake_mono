#include "stdafx.h"
#include "unity_input_executor_base.h"

namespace unity_input
{
executor_base::executor_base(functions_cptr functions)
    : functions_(functions)
{}

functions_cptr executor_base::functions() const
{
    return functions_;
}


float executor_base::GetAxis(MonoString* axisName)
{
    return functions()->GetAxis(axisName);
}


float executor_base::GetAxisRaw(MonoString* axisName)
{
    return functions()->GetAxisRaw(axisName);
}


gboolean executor_base::GetButton(MonoString* buttonName)
{
    return functions()->GetButton(buttonName);
}


gboolean executor_base::GetButtonUp(MonoString* buttonName)
{
    return functions()->GetButtonUp(buttonName);
}


gboolean executor_base::GetButtonDown(MonoString* buttonName)
{
    return functions()->GetButtonDown(buttonName);
}


MonoArray* executor_base::GetJoystickNames()
{
    return functions()->GetJoystickNames();
}


gboolean executor_base::GetKeyDownInt(int32_t key)
{
    return functions()->GetKeyDownInt(key);
}


gboolean executor_base::GetKeyDownString(MonoString* name)
{
    return functions()->GetKeyDownString(name);
}


gboolean executor_base::GetKeyInt(int32_t key)
{
    return functions()->GetKeyInt(key);
}


gboolean executor_base::GetKeyString(MonoString* name)
{
    return functions()->GetKeyString(name);
}


gboolean executor_base::GetKeyUpInt(int32_t key)
{
    return functions()->GetKeyUpInt(key);
}


gboolean executor_base::GetKeyUpString(MonoString* name)
{
    return functions()->GetKeyUpString(name);
}


gboolean executor_base::GetMouseButton(int32_t button)
{
    return functions()->GetMouseButton(button);
}


gboolean executor_base::GetMouseButtonDown(int32_t button)
{
    return functions()->GetMouseButtonDown(button);
}


gboolean executor_base::GetMouseButtonUp(int32_t button)
{
    return functions()->GetMouseButtonUp(button);
}


void executor_base::INTERNAL_CALL_GetAccelerationEvent(int32_t index, MonoStruct_out value)
{
    return functions()->INTERNAL_CALL_GetAccelerationEvent(index, value);
}


void executor_base::INTERNAL_CALL_GetTouch(int32_t index, MonoStruct_out value)
{
    return functions()->INTERNAL_CALL_GetTouch(index, value);
}


void executor_base::INTERNAL_get_acceleration(MonoStruct_out value)
{
    return functions()->INTERNAL_get_acceleration(value);
}


void executor_base::INTERNAL_get_compositionCursorPos(MonoStruct_out value)
{
    return functions()->INTERNAL_get_compositionCursorPos(value);
}


void executor_base::INTERNAL_get_mousePosition(MonoStruct_out value)
{
    return functions()->INTERNAL_get_mousePosition(value);
}


void executor_base::INTERNAL_get_mouseScrollDelta(MonoStruct_out value)
{
    return functions()->INTERNAL_get_mouseScrollDelta(value);
}


void executor_base::INTERNAL_set_compositionCursorPos(MonoStruct value)
{
    return functions()->INTERNAL_set_compositionCursorPos(value);
}


void executor_base::ResetInputAxes()
{
    return functions()->ResetInputAxes();
}


MonoObject* executor_base::get_deviceOrientation()
{
    return functions()->get_deviceOrientation();
}


MonoObject* executor_base::get_imeCompositionMode()
{
    return functions()->get_imeCompositionMode();
}


int32_t executor_base::get_accelerationEventCount()
{
    return functions()->get_accelerationEventCount();
}


gboolean executor_base::get_anyKey()
{
    return functions()->get_anyKey();
}


gboolean executor_base::get_anyKeyDown()
{
    return functions()->get_anyKeyDown();
}


gboolean executor_base::get_backButtonLeavesApp()
{
    return functions()->get_backButtonLeavesApp();
}


gboolean executor_base::get_compensateSensors()
{
    return functions()->get_compensateSensors();
}


MonoString* executor_base::get_compositionString()
{
    return functions()->get_compositionString();
}


gboolean executor_base::get_eatKeyPressOnTextFieldFocus()
{
    return functions()->get_eatKeyPressOnTextFieldFocus();
}


gboolean executor_base::get_imeIsSelected()
{
    return functions()->get_imeIsSelected();
}


MonoString* executor_base::get_inputString()
{
    return functions()->get_inputString();
}


gboolean executor_base::get_isGyroAvailable()
{
    return functions()->get_isGyroAvailable();
}


gboolean executor_base::get_mousePresent()
{
    return functions()->get_mousePresent();
}


gboolean executor_base::get_multiTouchEnabled()
{
    return functions()->get_multiTouchEnabled();
}


gboolean executor_base::get_simulateMouseWithTouches()
{
    return functions()->get_simulateMouseWithTouches();
}


gboolean executor_base::get_stylusTouchSupported()
{
    return functions()->get_stylusTouchSupported();
}


int32_t executor_base::get_touchCount()
{
    return functions()->get_touchCount();
}


gboolean executor_base::get_touchPressureSupported()
{
    return functions()->get_touchPressureSupported();
}


gboolean executor_base::get_touchSupported()
{
    return functions()->get_touchSupported();
}


int32_t executor_base::mainGyroIndex_Internal()
{
    return functions()->mainGyroIndex_Internal();
}


void executor_base::set_backButtonLeavesApp(gboolean value)
{
    return functions()->set_backButtonLeavesApp(value);
}


void executor_base::set_compensateSensors(gboolean value)
{
    return functions()->set_compensateSensors(value);
}


void executor_base::set_eatKeyPressOnTextFieldFocus(gboolean value)
{
    return functions()->set_eatKeyPressOnTextFieldFocus(value);
}


void executor_base::set_imeCompositionMode(MonoObject* value)
{
    return functions()->set_imeCompositionMode(value);
}


void executor_base::set_multiTouchEnabled(gboolean value)
{
    return functions()->set_multiTouchEnabled(value);
}


void executor_base::set_simulateMouseWithTouches(gboolean value)
{
    return functions()->set_simulateMouseWithTouches(value);
}


} // namespace unity_input
