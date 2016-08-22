#include "stdafx.h"
#include "unity_input_context.h"
#include "unity_input_functions.h"
#include "unity_input_executor.h"

namespace unity_input
{
functions_ptr context::functions_ = make_shared<functions_t>();
executor_ptr context::executor_ = create_executor(context::functions_);

float context::GetAxis(MonoString* axisName)
{
    return executor_->GetAxis(axisName);
}

float context::GetAxisRaw(MonoString* axisName)
{
    return executor_->GetAxisRaw(axisName);
}

gboolean context::GetButton(MonoString* buttonName)
{
    return executor_->GetButton(buttonName);
}

gboolean context::GetButtonUp(MonoString* buttonName)
{
    return executor_->GetButtonUp(buttonName);
}

gboolean context::GetButtonDown(MonoString* buttonName)
{
    return executor_->GetButtonDown(buttonName);
}

MonoArray* context::GetJoystickNames()
{
    return executor_->GetJoystickNames();
}

gboolean context::GetKeyDownInt(int32_t key)
{
    return executor_->GetKeyDownInt(key);
}

gboolean context::GetKeyDownString(MonoString* name)
{
    return executor_->GetKeyDownString(name);
}

gboolean context::GetKeyInt(int32_t key)
{
    return executor_->GetKeyInt(key);
}

gboolean context::GetKeyString(MonoString* name)
{
    return executor_->GetKeyString(name);
}

gboolean context::GetKeyUpInt(int32_t key)
{
    return executor_->GetKeyUpInt(key);
}

gboolean context::GetKeyUpString(MonoString* name)
{
    return executor_->GetKeyUpString(name);
}

gboolean context::GetMouseButton(int32_t button)
{
    return executor_->GetMouseButton(button);
}

gboolean context::GetMouseButtonDown(int32_t button)
{
    return executor_->GetMouseButtonDown(button);
}

gboolean context::GetMouseButtonUp(int32_t button)
{
    return executor_->GetMouseButtonUp(button);
}

void context::INTERNAL_CALL_GetAccelerationEvent(int32_t index, MonoStruct_out value)
{
    return executor_->INTERNAL_CALL_GetAccelerationEvent(index, value);
}

void context::INTERNAL_CALL_GetTouch(int32_t index, MonoStruct_out value)
{
    return executor_->INTERNAL_CALL_GetTouch(index, value);
}

void context::INTERNAL_get_acceleration(MonoStruct_out value)
{
    return executor_->INTERNAL_get_acceleration(value);
}

void context::INTERNAL_get_compositionCursorPos(MonoStruct_out value)
{
    return executor_->INTERNAL_get_compositionCursorPos(value);
}

void context::INTERNAL_get_mousePosition(MonoStruct_out value)
{
    return executor_->INTERNAL_get_mousePosition(value);
}

void context::INTERNAL_get_mouseScrollDelta(MonoStruct_out value)
{
    return executor_->INTERNAL_get_mouseScrollDelta(value);
}

void context::INTERNAL_set_compositionCursorPos(MonoStruct value)
{
    return executor_->INTERNAL_set_compositionCursorPos(value);
}

void context::ResetInputAxes()
{
    return executor_->ResetInputAxes();
}

MonoObject* context::get_deviceOrientation()
{
    return executor_->get_deviceOrientation();
}

MonoObject* context::get_imeCompositionMode()
{
    return executor_->get_imeCompositionMode();
}

int32_t context::get_accelerationEventCount()
{
    return executor_->get_accelerationEventCount();
}

gboolean context::get_anyKey()
{
    return executor_->get_anyKey();
}

gboolean context::get_anyKeyDown()
{
    return executor_->get_anyKeyDown();
}

gboolean context::get_backButtonLeavesApp()
{
    return executor_->get_backButtonLeavesApp();
}

gboolean context::get_compensateSensors()
{
    return executor_->get_compensateSensors();
}

MonoString* context::get_compositionString()
{
    return executor_->get_compositionString();
}

gboolean context::get_eatKeyPressOnTextFieldFocus()
{
    return executor_->get_eatKeyPressOnTextFieldFocus();
}

gboolean context::get_imeIsSelected()
{
    return executor_->get_imeIsSelected();
}

MonoString* context::get_inputString()
{
    return executor_->get_inputString();
}

gboolean context::get_isGyroAvailable()
{
    return executor_->get_isGyroAvailable();
}

gboolean context::get_mousePresent()
{
    return executor_->get_mousePresent();
}

gboolean context::get_multiTouchEnabled()
{
    return executor_->get_multiTouchEnabled();
}

gboolean context::get_simulateMouseWithTouches()
{
    return executor_->get_simulateMouseWithTouches();
}

gboolean context::get_stylusTouchSupported()
{
    return executor_->get_stylusTouchSupported();
}

int32_t context::get_touchCount()
{
    return executor_->get_touchCount();
}

gboolean context::get_touchPressureSupported()
{
    return executor_->get_touchPressureSupported();
}

gboolean context::get_touchSupported()
{
    return executor_->get_touchSupported();
}

int32_t context::mainGyroIndex_Internal()
{
    return executor_->mainGyroIndex_Internal();
}

void context::set_backButtonLeavesApp(gboolean value)
{
    return executor_->set_backButtonLeavesApp(value);
}

void context::set_compensateSensors(gboolean value)
{
    return executor_->set_compensateSensors(value);
}

void context::set_eatKeyPressOnTextFieldFocus(gboolean value)
{
    return executor_->set_eatKeyPressOnTextFieldFocus(value);
}

void context::set_imeCompositionMode(MonoObject* value)
{
    return executor_->set_imeCompositionMode(value);
}

void context::set_multiTouchEnabled(gboolean value)
{
    return executor_->set_multiTouchEnabled(value);
}

void context::set_simulateMouseWithTouches(gboolean value)
{
    return executor_->set_simulateMouseWithTouches(value);
}

gconstpointer context::register_function(char const *name, gconstpointer fn)
{
    if (!strcmp(name, "UnityEngine.Input::GetAxis"))
    {
        functions_->GetAxis = reinterpret_cast<functions_t::GetAxis_t>(fn);
        return &GetAxis;
    }

    if (!strcmp(name, "UnityEngine.Input::GetAxisRaw"))
    {
        functions_->GetAxisRaw = reinterpret_cast<functions_t::GetAxisRaw_t>(fn);
        return &GetAxisRaw;
    }

    if (!strcmp(name, "UnityEngine.Input::GetButton"))
    {
        functions_->GetButton = reinterpret_cast<functions_t::GetButton_t>(fn);
        return &GetButton;
    }

    if (!strcmp(name, "UnityEngine.Input::GetButtonUp"))
    {
        functions_->GetButtonUp = reinterpret_cast<functions_t::GetButtonUp_t>(fn);
        return &GetButtonUp;
    }

    if (!strcmp(name, "UnityEngine.Input::GetButtonDown"))
    {
        functions_->GetButtonDown = reinterpret_cast<functions_t::GetButtonDown_t>(fn);
        return &GetButtonDown;
    }

    if (!strcmp(name, "UnityEngine.Input::GetJoystickNames"))
    {
        functions_->GetJoystickNames = reinterpret_cast<functions_t::GetJoystickNames_t>(fn);
        return &GetJoystickNames;
    }

    if (!strcmp(name, "UnityEngine.Input::GetKeyDownInt"))
    {
        functions_->GetKeyDownInt = reinterpret_cast<functions_t::GetKeyDownInt_t>(fn);
        return &GetKeyDownInt;
    }

    if (!strcmp(name, "UnityEngine.Input::GetKeyDownString"))
    {
        functions_->GetKeyDownString = reinterpret_cast<functions_t::GetKeyDownString_t>(fn);
        return &GetKeyDownString;
    }

    if (!strcmp(name, "UnityEngine.Input::GetKeyInt"))
    {
        functions_->GetKeyInt = reinterpret_cast<functions_t::GetKeyInt_t>(fn);
        return &GetKeyInt;
    }

    if (!strcmp(name, "UnityEngine.Input::GetKeyString"))
    {
        functions_->GetKeyString = reinterpret_cast<functions_t::GetKeyString_t>(fn);
        return &GetKeyString;
    }

    if (!strcmp(name, "UnityEngine.Input::GetKeyUpInt"))
    {
        functions_->GetKeyUpInt = reinterpret_cast<functions_t::GetKeyUpInt_t>(fn);
        return &GetKeyUpInt;
    }

    if (!strcmp(name, "UnityEngine.Input::GetKeyUpString"))
    {
        functions_->GetKeyUpString = reinterpret_cast<functions_t::GetKeyUpString_t>(fn);
        return &GetKeyUpString;
    }

    if (!strcmp(name, "UnityEngine.Input::GetMouseButton"))
    {
        functions_->GetMouseButton = reinterpret_cast<functions_t::GetMouseButton_t>(fn);
        return &GetMouseButton;
    }

    if (!strcmp(name, "UnityEngine.Input::GetMouseButtonDown"))
    {
        functions_->GetMouseButtonDown = reinterpret_cast<functions_t::GetMouseButtonDown_t>(fn);
        return &GetMouseButtonDown;
    }

    if (!strcmp(name, "UnityEngine.Input::GetMouseButtonUp"))
    {
        functions_->GetMouseButtonUp = reinterpret_cast<functions_t::GetMouseButtonUp_t>(fn);
        return &GetMouseButtonUp;
    }

    if (!strcmp(name, "UnityEngine.Input::INTERNAL_CALL_GetAccelerationEvent"))
    {
        functions_->INTERNAL_CALL_GetAccelerationEvent = reinterpret_cast<functions_t::INTERNAL_CALL_GetAccelerationEvent_t>(fn);
        return &INTERNAL_CALL_GetAccelerationEvent;
    }

    if (!strcmp(name, "UnityEngine.Input::INTERNAL_CALL_GetTouch"))
    {
        functions_->INTERNAL_CALL_GetTouch = reinterpret_cast<functions_t::INTERNAL_CALL_GetTouch_t>(fn);
        return &INTERNAL_CALL_GetTouch;
    }

    if (!strcmp(name, "UnityEngine.Input::INTERNAL_get_acceleration"))
    {
        functions_->INTERNAL_get_acceleration = reinterpret_cast<functions_t::INTERNAL_get_acceleration_t>(fn);
        return &INTERNAL_get_acceleration;
    }

    if (!strcmp(name, "UnityEngine.Input::INTERNAL_get_compositionCursorPos"))
    {
        functions_->INTERNAL_get_compositionCursorPos = reinterpret_cast<functions_t::INTERNAL_get_compositionCursorPos_t>(fn);
        return &INTERNAL_get_compositionCursorPos;
    }

    if (!strcmp(name, "UnityEngine.Input::INTERNAL_get_mousePosition"))
    {
        functions_->INTERNAL_get_mousePosition = reinterpret_cast<functions_t::INTERNAL_get_mousePosition_t>(fn);
        return &INTERNAL_get_mousePosition;
    }

    if (!strcmp(name, "UnityEngine.Input::INTERNAL_get_mouseScrollDelta"))
    {
        functions_->INTERNAL_get_mouseScrollDelta = reinterpret_cast<functions_t::INTERNAL_get_mouseScrollDelta_t>(fn);
        return &INTERNAL_get_mouseScrollDelta;
    }

    if (!strcmp(name, "UnityEngine.Input::INTERNAL_set_compositionCursorPos"))
    {
        functions_->INTERNAL_set_compositionCursorPos = reinterpret_cast<functions_t::INTERNAL_set_compositionCursorPos_t>(fn);
        return &INTERNAL_set_compositionCursorPos;
    }

    if (!strcmp(name, "UnityEngine.Input::ResetInputAxes"))
    {
        functions_->ResetInputAxes = reinterpret_cast<functions_t::ResetInputAxes_t>(fn);
        return &ResetInputAxes;
    }

    if (!strcmp(name, "UnityEngine.Input::get_deviceOrientation"))
    {
        functions_->get_deviceOrientation = reinterpret_cast<functions_t::get_deviceOrientation_t>(fn);
        return &get_deviceOrientation;
    }

    if (!strcmp(name, "UnityEngine.Input::get_imeCompositionMode"))
    {
        functions_->get_imeCompositionMode = reinterpret_cast<functions_t::get_imeCompositionMode_t>(fn);
        return &get_imeCompositionMode;
    }

    if (!strcmp(name, "UnityEngine.Input::get_accelerationEventCount"))
    {
        functions_->get_accelerationEventCount = reinterpret_cast<functions_t::get_accelerationEventCount_t>(fn);
        return &get_accelerationEventCount;
    }

    if (!strcmp(name, "UnityEngine.Input::get_anyKey"))
    {
        functions_->get_anyKey = reinterpret_cast<functions_t::get_anyKey_t>(fn);
        return &get_anyKey;
    }

    if (!strcmp(name, "UnityEngine.Input::get_anyKeyDown"))
    {
        functions_->get_anyKeyDown = reinterpret_cast<functions_t::get_anyKeyDown_t>(fn);
        return &get_anyKeyDown;
    }

    if (!strcmp(name, "UnityEngine.Input::get_backButtonLeavesApp"))
    {
        functions_->get_backButtonLeavesApp = reinterpret_cast<functions_t::get_backButtonLeavesApp_t>(fn);
        return &get_backButtonLeavesApp;
    }

    if (!strcmp(name, "UnityEngine.Input::get_compensateSensors"))
    {
        functions_->get_compensateSensors = reinterpret_cast<functions_t::get_compensateSensors_t>(fn);
        return &get_compensateSensors;
    }

    if (!strcmp(name, "UnityEngine.Input::get_compositionString"))
    {
        functions_->get_compositionString = reinterpret_cast<functions_t::get_compositionString_t>(fn);
        return &get_compositionString;
    }

    if (!strcmp(name, "UnityEngine.Input::get_eatKeyPressOnTextFieldFocus"))
    {
        functions_->get_eatKeyPressOnTextFieldFocus = reinterpret_cast<functions_t::get_eatKeyPressOnTextFieldFocus_t>(fn);
        return &get_eatKeyPressOnTextFieldFocus;
    }

    if (!strcmp(name, "UnityEngine.Input::get_imeIsSelected"))
    {
        functions_->get_imeIsSelected = reinterpret_cast<functions_t::get_imeIsSelected_t>(fn);
        return &get_imeIsSelected;
    }

    if (!strcmp(name, "UnityEngine.Input::get_inputString"))
    {
        functions_->get_inputString = reinterpret_cast<functions_t::get_inputString_t>(fn);
        return &get_inputString;
    }

    if (!strcmp(name, "UnityEngine.Input::get_isGyroAvailable"))
    {
        functions_->get_isGyroAvailable = reinterpret_cast<functions_t::get_isGyroAvailable_t>(fn);
        return &get_isGyroAvailable;
    }

    if (!strcmp(name, "UnityEngine.Input::get_mousePresent"))
    {
        functions_->get_mousePresent = reinterpret_cast<functions_t::get_mousePresent_t>(fn);
        return &get_mousePresent;
    }

    if (!strcmp(name, "UnityEngine.Input::get_multiTouchEnabled"))
    {
        functions_->get_multiTouchEnabled = reinterpret_cast<functions_t::get_multiTouchEnabled_t>(fn);
        return &get_multiTouchEnabled;
    }

    if (!strcmp(name, "UnityEngine.Input::get_simulateMouseWithTouches"))
    {
        functions_->get_simulateMouseWithTouches = reinterpret_cast<functions_t::get_simulateMouseWithTouches_t>(fn);
        return &get_simulateMouseWithTouches;
    }

    if (!strcmp(name, "UnityEngine.Input::get_stylusTouchSupported"))
    {
        functions_->get_stylusTouchSupported = reinterpret_cast<functions_t::get_stylusTouchSupported_t>(fn);
        return &get_stylusTouchSupported;
    }

    if (!strcmp(name, "UnityEngine.Input::get_touchCount"))
    {
        functions_->get_touchCount = reinterpret_cast<functions_t::get_touchCount_t>(fn);
        return &get_touchCount;
    }

    if (!strcmp(name, "UnityEngine.Input::get_touchPressureSupported"))
    {
        functions_->get_touchPressureSupported = reinterpret_cast<functions_t::get_touchPressureSupported_t>(fn);
        return &get_touchPressureSupported;
    }

    if (!strcmp(name, "UnityEngine.Input::get_touchSupported"))
    {
        functions_->get_touchSupported = reinterpret_cast<functions_t::get_touchSupported_t>(fn);
        return &get_touchSupported;
    }

    if (!strcmp(name, "UnityEngine.Input::mainGyroIndex_Internal"))
    {
        functions_->mainGyroIndex_Internal = reinterpret_cast<functions_t::mainGyroIndex_Internal_t>(fn);
        return &mainGyroIndex_Internal;
    }

    if (!strcmp(name, "UnityEngine.Input::set_backButtonLeavesApp"))
    {
        functions_->set_backButtonLeavesApp = reinterpret_cast<functions_t::set_backButtonLeavesApp_t>(fn);
        return &set_backButtonLeavesApp;
    }

    if (!strcmp(name, "UnityEngine.Input::set_compensateSensors"))
    {
        functions_->set_compensateSensors = reinterpret_cast<functions_t::set_compensateSensors_t>(fn);
        return &set_compensateSensors;
    }

    if (!strcmp(name, "UnityEngine.Input::set_eatKeyPressOnTextFieldFocus"))
    {
        functions_->set_eatKeyPressOnTextFieldFocus = reinterpret_cast<functions_t::set_eatKeyPressOnTextFieldFocus_t>(fn);
        return &set_eatKeyPressOnTextFieldFocus;
    }

    if (!strcmp(name, "UnityEngine.Input::set_imeCompositionMode"))
    {
        functions_->set_imeCompositionMode = reinterpret_cast<functions_t::set_imeCompositionMode_t>(fn);
        return &set_imeCompositionMode;
    }

    if (!strcmp(name, "UnityEngine.Input::set_multiTouchEnabled"))
    {
        functions_->set_multiTouchEnabled = reinterpret_cast<functions_t::set_multiTouchEnabled_t>(fn);
        return &set_multiTouchEnabled;
    }

    if (!strcmp(name, "UnityEngine.Input::set_simulateMouseWithTouches"))
    {
        functions_->set_simulateMouseWithTouches = reinterpret_cast<functions_t::set_simulateMouseWithTouches_t>(fn);
        return &set_simulateMouseWithTouches;
    }

    return nullptr;
}

} // namespace unity_input
