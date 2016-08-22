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
    return functions_->GetAxis(axisName);
}

float executor_base::GetAxisRaw(MonoString* axisName)
{
    return functions_->GetAxisRaw(axisName);
}

gboolean executor_base::GetButton(MonoString* buttonName)
{
    return functions_->GetButton(buttonName);
}

gboolean executor_base::GetButtonUp(MonoString* buttonName)
{
    return functions_->GetButtonUp(buttonName);
}

gboolean executor_base::GetButtonDown(MonoString* buttonName)
{
    return functions_->GetButtonDown(buttonName);
}

MonoArray* executor_base::GetJoystickNames()
{
    return functions_->GetJoystickNames();
}

gboolean executor_base::GetKeyDownInt(int32_t key)
{
    return functions_->GetKeyDownInt(key);
}

gboolean executor_base::GetKeyDownString(MonoString* name)
{
    return functions_->GetKeyDownString(name);
}

gboolean executor_base::GetKeyInt(int32_t key)
{
    return functions_->GetKeyInt(key);
}

gboolean executor_base::GetKeyString(MonoString* name)
{
    return functions_->GetKeyString(name);
}

gboolean executor_base::GetKeyUpInt(int32_t key)
{
    return functions_->GetKeyUpInt(key);
}

gboolean executor_base::GetKeyUpString(MonoString* name)
{
    return functions_->GetKeyUpString(name);
}

gboolean executor_base::GetMouseButton(int32_t button)
{
    return functions_->GetMouseButton(button);
}

gboolean executor_base::GetMouseButtonDown(int32_t button)
{
    return functions_->GetMouseButtonDown(button);
}

gboolean executor_base::GetMouseButtonUp(int32_t button)
{
    return functions_->GetMouseButtonUp(button);
}

void executor_base::INTERNAL_CALL_GetAccelerationEvent(int32_t index, MonoStruct_out value)
{
    return functions_->INTERNAL_CALL_GetAccelerationEvent(index, value);
}

void executor_base::INTERNAL_CALL_GetTouch(int32_t index, MonoStruct_out value)
{
    return functions_->INTERNAL_CALL_GetTouch(index, value);
}

void executor_base::INTERNAL_get_acceleration(MonoStruct_out value)
{
    return functions_->INTERNAL_get_acceleration(value);
}

void executor_base::INTERNAL_get_compositionCursorPos(MonoStruct_out value)
{
    return functions_->INTERNAL_get_compositionCursorPos(value);
}

void executor_base::INTERNAL_get_mousePosition(MonoStruct_out value)
{
    return functions_->INTERNAL_get_mousePosition(value);
}

void executor_base::INTERNAL_get_mouseScrollDelta(MonoStruct_out value)
{
    return functions_->INTERNAL_get_mouseScrollDelta(value);
}

void executor_base::INTERNAL_set_compositionCursorPos(MonoStruct value)
{
    return functions_->INTERNAL_set_compositionCursorPos(value);
}

void executor_base::ResetInputAxes()
{
    return functions_->ResetInputAxes();
}

MonoObject* executor_base::get_deviceOrientation()
{
    return functions_->get_deviceOrientation();
}

MonoObject* executor_base::get_imeCompositionMode()
{
    return functions_->get_imeCompositionMode();
}

int32_t executor_base::get_accelerationEventCount()
{
    return functions_->get_accelerationEventCount();
}

gboolean executor_base::get_anyKey()
{
    return functions_->get_anyKey();
}

gboolean executor_base::get_anyKeyDown()
{
    return functions_->get_anyKeyDown();
}

gboolean executor_base::get_backButtonLeavesApp()
{
    return functions_->get_backButtonLeavesApp();
}

gboolean executor_base::get_compensateSensors()
{
    return functions_->get_compensateSensors();
}

MonoString* executor_base::get_compositionString()
{
    return functions_->get_compositionString();
}

gboolean executor_base::get_eatKeyPressOnTextFieldFocus()
{
    return functions_->get_eatKeyPressOnTextFieldFocus();
}

gboolean executor_base::get_imeIsSelected()
{
    return functions_->get_imeIsSelected();
}

MonoString* executor_base::get_inputString()
{
    return functions_->get_inputString();
}

gboolean executor_base::get_isGyroAvailable()
{
    return functions_->get_isGyroAvailable();
}

gboolean executor_base::get_mousePresent()
{
    return functions_->get_mousePresent();
}

gboolean executor_base::get_multiTouchEnabled()
{
    return functions_->get_multiTouchEnabled();
}

gboolean executor_base::get_simulateMouseWithTouches()
{
    return functions_->get_simulateMouseWithTouches();
}

gboolean executor_base::get_stylusTouchSupported()
{
    return functions_->get_stylusTouchSupported();
}

int32_t executor_base::get_touchCount()
{
    return functions_->get_touchCount();
}

gboolean executor_base::get_touchPressureSupported()
{
    return functions_->get_touchPressureSupported();
}

gboolean executor_base::get_touchSupported()
{
    return functions_->get_touchSupported();
}

int32_t executor_base::mainGyroIndex_Internal()
{
    return functions_->mainGyroIndex_Internal();
}

void executor_base::set_backButtonLeavesApp(gboolean value)
{
    return functions_->set_backButtonLeavesApp(value);
}

void executor_base::set_compensateSensors(gboolean value)
{
    return functions_->set_compensateSensors(value);
}

void executor_base::set_eatKeyPressOnTextFieldFocus(gboolean value)
{
    return functions_->set_eatKeyPressOnTextFieldFocus(value);
}

void executor_base::set_imeCompositionMode(MonoObject* value)
{
    return functions_->set_imeCompositionMode(value);
}

void executor_base::set_multiTouchEnabled(gboolean value)
{
    return functions_->set_multiTouchEnabled(value);
}

void executor_base::set_simulateMouseWithTouches(gboolean value)
{
    return functions_->set_simulateMouseWithTouches(value);
}

} // namespace unity_input