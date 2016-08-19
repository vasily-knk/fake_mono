#include "stdafx.h"
#include "unity_input_base.h"
#include "log.h"

unity_input_base::unity_input_base(unity_input_functions_cptr f)
    : f_(f)
{}

unity_input_functions_cptr unity_input_base::get_f() const
{
    return f_;
}

float unity_input_base::GetAxis(MonoString* axisName)
{
    return get_f()->GetAxis(axisName);
}

float unity_input_base::GetAxisRaw(MonoString* axisName)
{
    return get_f()->GetAxisRaw(axisName);
}

gboolean unity_input_base::GetButton(MonoString* buttonName)
{
    return get_f()->GetButton(buttonName);
}

gboolean unity_input_base::GetButtonUp(MonoString* buttonName)
{
    return get_f()->GetButtonUp(buttonName);
}

gboolean unity_input_base::GetButtonDown(MonoString* buttonName)
{
    return get_f()->GetButtonDown(buttonName);
}

MonoArray* unity_input_base::GetJoystickNames()
{
    return get_f()->GetJoystickNames();
}

gboolean unity_input_base::GetKeyDownInt(int32_t key)
{
    return get_f()->GetKeyDownInt(key);
}

gboolean unity_input_base::GetKeyDownString(MonoString* name)
{
    return get_f()->GetKeyDownString(name);
}

gboolean unity_input_base::GetKeyInt(int32_t key)
{
    return get_f()->GetKeyInt(key);
}

gboolean unity_input_base::GetKeyString(MonoString* name)
{
    return get_f()->GetKeyString(name);
}

gboolean unity_input_base::GetKeyUpInt(int32_t key)
{
    return get_f()->GetKeyUpInt(key);
}

gboolean unity_input_base::GetKeyUpString(MonoString* name)
{
    return get_f()->GetKeyUpString(name);
}

gboolean unity_input_base::GetMouseButton(int32_t button)
{
    return get_f()->GetMouseButton(button);
}

gboolean unity_input_base::GetMouseButtonDown(int32_t button)
{
    return get_f()->GetMouseButtonDown(button);
}

gboolean unity_input_base::GetMouseButtonUp(int32_t button)
{
    return get_f()->GetMouseButtonUp(button);
}

void unity_input_base::INTERNAL_CALL_GetAccelerationEvent(int32_t index, MonoStruct_out value)
{
    return get_f()->INTERNAL_CALL_GetAccelerationEvent(index, value);
}

void unity_input_base::INTERNAL_CALL_GetTouch(int32_t index, MonoStruct_out value)
{
    return get_f()->INTERNAL_CALL_GetTouch(index, value);
}

void unity_input_base::INTERNAL_get_acceleration(MonoStruct_out value)
{
    return get_f()->INTERNAL_get_acceleration(value);
}

void unity_input_base::INTERNAL_get_compositionCursorPos(MonoStruct_out value)
{
    return get_f()->INTERNAL_get_compositionCursorPos(value);
}

void unity_input_base::INTERNAL_get_mousePosition(MonoStruct_out value)
{
    return get_f()->INTERNAL_get_mousePosition(value);
}

void unity_input_base::INTERNAL_get_mouseScrollDelta(MonoStruct_out value)
{
    return get_f()->INTERNAL_get_mouseScrollDelta(value);
}

void unity_input_base::INTERNAL_set_compositionCursorPos(MonoStruct value)
{
    return get_f()->INTERNAL_set_compositionCursorPos(value);
}

void unity_input_base::ResetInputAxes()
{
    return get_f()->ResetInputAxes();
}

MonoObject* unity_input_base::get_deviceOrientation()
{
    return get_f()->get_deviceOrientation();
}

MonoObject* unity_input_base::get_imeCompositionMode()
{
    return get_f()->get_imeCompositionMode();
}

int32_t unity_input_base::get_accelerationEventCount()
{
    return get_f()->get_accelerationEventCount();
}

gboolean unity_input_base::get_anyKey()
{
    return get_f()->get_anyKey();
}

gboolean unity_input_base::get_anyKeyDown()
{
    return get_f()->get_anyKeyDown();
}

gboolean unity_input_base::get_backButtonLeavesApp()
{
    return get_f()->get_backButtonLeavesApp();
}

gboolean unity_input_base::get_compensateSensors()
{
    return get_f()->get_compensateSensors();
}

MonoString* unity_input_base::get_compositionString()
{
    return get_f()->get_compositionString();
}

gboolean unity_input_base::get_eatKeyPressOnTextFieldFocus()
{
    return get_f()->get_eatKeyPressOnTextFieldFocus();
}

gboolean unity_input_base::get_imeIsSelected()
{
    return get_f()->get_imeIsSelected();
}

MonoString* unity_input_base::get_inputString()
{
    return get_f()->get_inputString();
}

gboolean unity_input_base::get_isGyroAvailable()
{
    return get_f()->get_isGyroAvailable();
}

gboolean unity_input_base::get_mousePresent()
{
    return get_f()->get_mousePresent();
}

gboolean unity_input_base::get_multiTouchEnabled()
{
    return get_f()->get_multiTouchEnabled();
}

gboolean unity_input_base::get_simulateMouseWithTouches()
{
    return get_f()->get_simulateMouseWithTouches();
}

gboolean unity_input_base::get_stylusTouchSupported()
{
    return get_f()->get_stylusTouchSupported();
}

int32_t unity_input_base::get_touchCount()
{
    return get_f()->get_touchCount();
}

gboolean unity_input_base::get_touchPressureSupported()
{
    return get_f()->get_touchPressureSupported();
}

gboolean unity_input_base::get_touchSupported()
{
    return get_f()->get_touchSupported();
}

int32_t unity_input_base::mainGyroIndex_Internal()
{
    return get_f()->mainGyroIndex_Internal();
}

void unity_input_base::set_backButtonLeavesApp(gboolean value)
{
    return get_f()->set_backButtonLeavesApp(value);
}

void unity_input_base::set_compensateSensors(gboolean value)
{
    return get_f()->set_compensateSensors(value);
}

void unity_input_base::set_eatKeyPressOnTextFieldFocus(gboolean value)
{
    return get_f()->set_eatKeyPressOnTextFieldFocus(value);
}

void unity_input_base::set_imeCompositionMode(MonoObject* value)
{
    return get_f()->set_imeCompositionMode(value);
}

void unity_input_base::set_multiTouchEnabled(gboolean value)
{
    return get_f()->set_multiTouchEnabled(value);
}

void unity_input_base::set_simulateMouseWithTouches(gboolean value)
{
    return get_f()->set_simulateMouseWithTouches(value);
}

