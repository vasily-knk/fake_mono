#include "stdafx.h"

#include "unity_input_context.h"

unity_input_functions_ptr unity_input_context::f_ = make_shared<unity_input_functions_t>();
unity_input_ptr unity_input_context::unity_input_ = create_unity_input(unity_input_context::f_);

float unity_input_context::GetAxis(MonoString* axisName)
{
    return unity_input_->GetAxis(axisName);
}

float unity_input_context::GetAxisRaw(MonoString* axisName)
{
    return unity_input_->GetAxisRaw(axisName);
}

gboolean unity_input_context::GetButton(MonoString* buttonName)
{
    return unity_input_->GetButton(buttonName);
}

gboolean unity_input_context::GetButtonUp(MonoString* buttonName)
{
    return unity_input_->GetButtonUp(buttonName);
}

gboolean unity_input_context::GetButtonDown(MonoString* buttonName)
{
    return unity_input_->GetButtonDown(buttonName);
}

MonoArray* unity_input_context::GetJoystickNames()
{
    return unity_input_->GetJoystickNames();
}

gboolean unity_input_context::GetKeyDownInt(int32_t key)
{
    return unity_input_->GetKeyDownInt(key);
}

gboolean unity_input_context::GetKeyDownString(MonoString* name)
{
    return unity_input_->GetKeyDownString(name);
}

gboolean unity_input_context::GetKeyInt(int32_t key)
{
    return unity_input_->GetKeyInt(key);
}

gboolean unity_input_context::GetKeyString(MonoString* name)
{
    return unity_input_->GetKeyString(name);
}

gboolean unity_input_context::GetKeyUpInt(int32_t key)
{
    return unity_input_->GetKeyUpInt(key);
}

gboolean unity_input_context::GetKeyUpString(MonoString* name)
{
    return unity_input_->GetKeyUpString(name);
}

gboolean unity_input_context::GetMouseButton(int32_t button)
{
    return unity_input_->GetMouseButton(button);
}

gboolean unity_input_context::GetMouseButtonDown(int32_t button)
{
    return unity_input_->GetMouseButtonDown(button);
}

gboolean unity_input_context::GetMouseButtonUp(int32_t button)
{
    return unity_input_->GetMouseButtonUp(button);
}

void unity_input_context::INTERNAL_CALL_GetAccelerationEvent(int32_t index, MonoStruct_out value)
{
    return unity_input_->INTERNAL_CALL_GetAccelerationEvent(index, value);
}

void unity_input_context::INTERNAL_CALL_GetTouch(int32_t index, MonoStruct_out value)
{
    return unity_input_->INTERNAL_CALL_GetTouch(index, value);
}

void unity_input_context::INTERNAL_get_acceleration(MonoStruct_out value)
{
    return unity_input_->INTERNAL_get_acceleration(value);
}

void unity_input_context::INTERNAL_get_compositionCursorPos(MonoStruct_out value)
{
    return unity_input_->INTERNAL_get_compositionCursorPos(value);
}

void unity_input_context::INTERNAL_get_mousePosition(MonoStruct_out value)
{
    return unity_input_->INTERNAL_get_mousePosition(value);
}

void unity_input_context::INTERNAL_get_mouseScrollDelta(MonoStruct_out value)
{
    return unity_input_->INTERNAL_get_mouseScrollDelta(value);
}

void unity_input_context::INTERNAL_set_compositionCursorPos(MonoStruct value)
{
    return unity_input_->INTERNAL_set_compositionCursorPos(value);
}

void unity_input_context::ResetInputAxes()
{
    return unity_input_->ResetInputAxes();
}

MonoObject* unity_input_context::get_deviceOrientation()
{
    return unity_input_->get_deviceOrientation();
}

MonoObject* unity_input_context::get_imeCompositionMode()
{
    return unity_input_->get_imeCompositionMode();
}

int32_t unity_input_context::get_accelerationEventCount()
{
    return unity_input_->get_accelerationEventCount();
}

gboolean unity_input_context::get_anyKey()
{
    return unity_input_->get_anyKey();
}

gboolean unity_input_context::get_anyKeyDown()
{
    return unity_input_->get_anyKeyDown();
}

gboolean unity_input_context::get_backButtonLeavesApp()
{
    return unity_input_->get_backButtonLeavesApp();
}

gboolean unity_input_context::get_compensateSensors()
{
    return unity_input_->get_compensateSensors();
}

MonoString* unity_input_context::get_compositionString()
{
    return unity_input_->get_compositionString();
}

gboolean unity_input_context::get_eatKeyPressOnTextFieldFocus()
{
    return unity_input_->get_eatKeyPressOnTextFieldFocus();
}

gboolean unity_input_context::get_imeIsSelected()
{
    return unity_input_->get_imeIsSelected();
}

MonoString* unity_input_context::get_inputString()
{
    return unity_input_->get_inputString();
}

gboolean unity_input_context::get_isGyroAvailable()
{
    return unity_input_->get_isGyroAvailable();
}

gboolean unity_input_context::get_mousePresent()
{
    return unity_input_->get_mousePresent();
}

gboolean unity_input_context::get_multiTouchEnabled()
{
    return unity_input_->get_multiTouchEnabled();
}

gboolean unity_input_context::get_simulateMouseWithTouches()
{
    return unity_input_->get_simulateMouseWithTouches();
}

gboolean unity_input_context::get_stylusTouchSupported()
{
    return unity_input_->get_stylusTouchSupported();
}

int32_t unity_input_context::get_touchCount()
{
    return unity_input_->get_touchCount();
}

gboolean unity_input_context::get_touchPressureSupported()
{
    return unity_input_->get_touchPressureSupported();
}

gboolean unity_input_context::get_touchSupported()
{
    return unity_input_->get_touchSupported();
}

int32_t unity_input_context::mainGyroIndex_Internal()
{
    return unity_input_->mainGyroIndex_Internal();
}

void unity_input_context::set_backButtonLeavesApp(gboolean value)
{
    return unity_input_->set_backButtonLeavesApp(value);
}

void unity_input_context::set_compensateSensors(gboolean value)
{
    return unity_input_->set_compensateSensors(value);
}

void unity_input_context::set_eatKeyPressOnTextFieldFocus(gboolean value)
{
    return unity_input_->set_eatKeyPressOnTextFieldFocus(value);
}

void unity_input_context::set_imeCompositionMode(MonoObject* value)
{
    return unity_input_->set_imeCompositionMode(value);
}

void unity_input_context::set_multiTouchEnabled(gboolean value)
{
    return unity_input_->set_multiTouchEnabled(value);
}

void unity_input_context::set_simulateMouseWithTouches(gboolean value)
{
    return unity_input_->set_simulateMouseWithTouches(value);
}


gconstpointer unity_input_context::register_fn(char const *name, gconstpointer fn)
{
    if (false) {}
    else if (!strcmp(name, "UnityEngine.Input::GetAxis"))
    {
        f_->GetAxis = reinterpret_cast<unity_input_functions_t::GetAxis_t>(fn);
        return &unity_input_context::GetAxis;
    }
    else if (!strcmp(name, "UnityEngine.Input::GetAxisRaw"))
    {
        f_->GetAxisRaw = reinterpret_cast<unity_input_functions_t::GetAxisRaw_t>(fn);
        return &unity_input_context::GetAxisRaw;
    }
    else if (!strcmp(name, "UnityEngine.Input::GetButton"))
    {
        f_->GetButton = reinterpret_cast<unity_input_functions_t::GetButton_t>(fn);
        return &unity_input_context::GetButton;
    }
    else if (!strcmp(name, "UnityEngine.Input::GetButtonUp"))
    {
        f_->GetButtonUp = reinterpret_cast<unity_input_functions_t::GetButtonUp_t>(fn);
        return &unity_input_context::GetButtonUp;
    }
    else if (!strcmp(name, "UnityEngine.Input::GetButtonDown"))
    {
        f_->GetButtonDown = reinterpret_cast<unity_input_functions_t::GetButtonDown_t>(fn);
        return &unity_input_context::GetButtonDown;
    }
    else if (!strcmp(name, "UnityEngine.Input::GetJoystickNames"))
    {
        f_->GetJoystickNames = reinterpret_cast<unity_input_functions_t::GetJoystickNames_t>(fn);
        return &unity_input_context::GetJoystickNames;
    }
    else if (!strcmp(name, "UnityEngine.Input::GetKeyDownInt"))
    {
        f_->GetKeyDownInt = reinterpret_cast<unity_input_functions_t::GetKeyDownInt_t>(fn);
        return &unity_input_context::GetKeyDownInt;
    }
    else if (!strcmp(name, "UnityEngine.Input::GetKeyDownString"))
    {
        f_->GetKeyDownString = reinterpret_cast<unity_input_functions_t::GetKeyDownString_t>(fn);
        return &unity_input_context::GetKeyDownString;
    }
    else if (!strcmp(name, "UnityEngine.Input::GetKeyInt"))
    {
        f_->GetKeyInt = reinterpret_cast<unity_input_functions_t::GetKeyInt_t>(fn);
        return &unity_input_context::GetKeyInt;
    }
    else if (!strcmp(name, "UnityEngine.Input::GetKeyString"))
    {
        f_->GetKeyString = reinterpret_cast<unity_input_functions_t::GetKeyString_t>(fn);
        return &unity_input_context::GetKeyString;
    }
    else if (!strcmp(name, "UnityEngine.Input::GetKeyUpInt"))
    {
        f_->GetKeyUpInt = reinterpret_cast<unity_input_functions_t::GetKeyUpInt_t>(fn);
        return &unity_input_context::GetKeyUpInt;
    }
    else if (!strcmp(name, "UnityEngine.Input::GetKeyUpString"))
    {
        f_->GetKeyUpString = reinterpret_cast<unity_input_functions_t::GetKeyUpString_t>(fn);
        return &unity_input_context::GetKeyUpString;
    }
    else if (!strcmp(name, "UnityEngine.Input::GetMouseButton"))
    {
        f_->GetMouseButton = reinterpret_cast<unity_input_functions_t::GetMouseButton_t>(fn);
        return &unity_input_context::GetMouseButton;
    }
    else if (!strcmp(name, "UnityEngine.Input::GetMouseButtonDown"))
    {
        f_->GetMouseButtonDown = reinterpret_cast<unity_input_functions_t::GetMouseButtonDown_t>(fn);
        return &unity_input_context::GetMouseButtonDown;
    }
    else if (!strcmp(name, "UnityEngine.Input::GetMouseButtonUp"))
    {
        f_->GetMouseButtonUp = reinterpret_cast<unity_input_functions_t::GetMouseButtonUp_t>(fn);
        return &unity_input_context::GetMouseButtonUp;
    }
    else if (!strcmp(name, "UnityEngine.Input::INTERNAL_CALL_GetAccelerationEvent"))
    {
        f_->INTERNAL_CALL_GetAccelerationEvent = reinterpret_cast<unity_input_functions_t::INTERNAL_CALL_GetAccelerationEvent_t>(fn);
        return &unity_input_context::INTERNAL_CALL_GetAccelerationEvent;
    }
    else if (!strcmp(name, "UnityEngine.Input::INTERNAL_CALL_GetTouch"))
    {
        f_->INTERNAL_CALL_GetTouch = reinterpret_cast<unity_input_functions_t::INTERNAL_CALL_GetTouch_t>(fn);
        return &unity_input_context::INTERNAL_CALL_GetTouch;
    }
    else if (!strcmp(name, "UnityEngine.Input::INTERNAL_get_acceleration"))
    {
        f_->INTERNAL_get_acceleration = reinterpret_cast<unity_input_functions_t::INTERNAL_get_acceleration_t>(fn);
        return &unity_input_context::INTERNAL_get_acceleration;
    }
    else if (!strcmp(name, "UnityEngine.Input::INTERNAL_get_compositionCursorPos"))
    {
        f_->INTERNAL_get_compositionCursorPos = reinterpret_cast<unity_input_functions_t::INTERNAL_get_compositionCursorPos_t>(fn);
        return &unity_input_context::INTERNAL_get_compositionCursorPos;
    }
    else if (!strcmp(name, "UnityEngine.Input::INTERNAL_get_mousePosition"))
    {
        f_->INTERNAL_get_mousePosition = reinterpret_cast<unity_input_functions_t::INTERNAL_get_mousePosition_t>(fn);
        return &unity_input_context::INTERNAL_get_mousePosition;
    }
    else if (!strcmp(name, "UnityEngine.Input::INTERNAL_get_mouseScrollDelta"))
    {
        f_->INTERNAL_get_mouseScrollDelta = reinterpret_cast<unity_input_functions_t::INTERNAL_get_mouseScrollDelta_t>(fn);
        return &unity_input_context::INTERNAL_get_mouseScrollDelta;
    }
    else if (!strcmp(name, "UnityEngine.Input::INTERNAL_set_compositionCursorPos"))
    {
        f_->INTERNAL_set_compositionCursorPos = reinterpret_cast<unity_input_functions_t::INTERNAL_set_compositionCursorPos_t>(fn);
        return &unity_input_context::INTERNAL_set_compositionCursorPos;
    }
    else if (!strcmp(name, "UnityEngine.Input::ResetInputAxes"))
    {
        f_->ResetInputAxes = reinterpret_cast<unity_input_functions_t::ResetInputAxes_t>(fn);
        return &unity_input_context::ResetInputAxes;
    }
    else if (!strcmp(name, "UnityEngine.Input::get_deviceOrientation"))
    {
        f_->get_deviceOrientation = reinterpret_cast<unity_input_functions_t::get_deviceOrientation_t>(fn);
        return &unity_input_context::get_deviceOrientation;
    }
    else if (!strcmp(name, "UnityEngine.Input::get_imeCompositionMode"))
    {
        f_->get_imeCompositionMode = reinterpret_cast<unity_input_functions_t::get_imeCompositionMode_t>(fn);
        return &unity_input_context::get_imeCompositionMode;
    }
    else if (!strcmp(name, "UnityEngine.Input::get_accelerationEventCount"))
    {
        f_->get_accelerationEventCount = reinterpret_cast<unity_input_functions_t::get_accelerationEventCount_t>(fn);
        return &unity_input_context::get_accelerationEventCount;
    }
    else if (!strcmp(name, "UnityEngine.Input::get_anyKey"))
    {
        f_->get_anyKey = reinterpret_cast<unity_input_functions_t::get_anyKey_t>(fn);
        return &unity_input_context::get_anyKey;
    }
    else if (!strcmp(name, "UnityEngine.Input::get_anyKeyDown"))
    {
        f_->get_anyKeyDown = reinterpret_cast<unity_input_functions_t::get_anyKeyDown_t>(fn);
        return &unity_input_context::get_anyKeyDown;
    }
    else if (!strcmp(name, "UnityEngine.Input::get_backButtonLeavesApp"))
    {
        f_->get_backButtonLeavesApp = reinterpret_cast<unity_input_functions_t::get_backButtonLeavesApp_t>(fn);
        return &unity_input_context::get_backButtonLeavesApp;
    }
    else if (!strcmp(name, "UnityEngine.Input::get_compensateSensors"))
    {
        f_->get_compensateSensors = reinterpret_cast<unity_input_functions_t::get_compensateSensors_t>(fn);
        return &unity_input_context::get_compensateSensors;
    }
    else if (!strcmp(name, "UnityEngine.Input::get_compositionString"))
    {
        f_->get_compositionString = reinterpret_cast<unity_input_functions_t::get_compositionString_t>(fn);
        return &unity_input_context::get_compositionString;
    }
    else if (!strcmp(name, "UnityEngine.Input::get_eatKeyPressOnTextFieldFocus"))
    {
        f_->get_eatKeyPressOnTextFieldFocus = reinterpret_cast<unity_input_functions_t::get_eatKeyPressOnTextFieldFocus_t>(fn);
        return &unity_input_context::get_eatKeyPressOnTextFieldFocus;
    }
    else if (!strcmp(name, "UnityEngine.Input::get_imeIsSelected"))
    {
        f_->get_imeIsSelected = reinterpret_cast<unity_input_functions_t::get_imeIsSelected_t>(fn);
        return &unity_input_context::get_imeIsSelected;
    }
    else if (!strcmp(name, "UnityEngine.Input::get_inputString"))
    {
        f_->get_inputString = reinterpret_cast<unity_input_functions_t::get_inputString_t>(fn);
        return &unity_input_context::get_inputString;
    }
    else if (!strcmp(name, "UnityEngine.Input::get_isGyroAvailable"))
    {
        f_->get_isGyroAvailable = reinterpret_cast<unity_input_functions_t::get_isGyroAvailable_t>(fn);
        return &unity_input_context::get_isGyroAvailable;
    }
    else if (!strcmp(name, "UnityEngine.Input::get_mousePresent"))
    {
        f_->get_mousePresent = reinterpret_cast<unity_input_functions_t::get_mousePresent_t>(fn);
        return &unity_input_context::get_mousePresent;
    }
    else if (!strcmp(name, "UnityEngine.Input::get_multiTouchEnabled"))
    {
        f_->get_multiTouchEnabled = reinterpret_cast<unity_input_functions_t::get_multiTouchEnabled_t>(fn);
        return &unity_input_context::get_multiTouchEnabled;
    }
    else if (!strcmp(name, "UnityEngine.Input::get_simulateMouseWithTouches"))
    {
        f_->get_simulateMouseWithTouches = reinterpret_cast<unity_input_functions_t::get_simulateMouseWithTouches_t>(fn);
        return &unity_input_context::get_simulateMouseWithTouches;
    }
    else if (!strcmp(name, "UnityEngine.Input::get_stylusTouchSupported"))
    {
        f_->get_stylusTouchSupported = reinterpret_cast<unity_input_functions_t::get_stylusTouchSupported_t>(fn);
        return &unity_input_context::get_stylusTouchSupported;
    }
    else if (!strcmp(name, "UnityEngine.Input::get_touchCount"))
    {
        f_->get_touchCount = reinterpret_cast<unity_input_functions_t::get_touchCount_t>(fn);
        return &unity_input_context::get_touchCount;
    }
    else if (!strcmp(name, "UnityEngine.Input::get_touchPressureSupported"))
    {
        f_->get_touchPressureSupported = reinterpret_cast<unity_input_functions_t::get_touchPressureSupported_t>(fn);
        return &unity_input_context::get_touchPressureSupported;
    }
    else if (!strcmp(name, "UnityEngine.Input::get_touchSupported"))
    {
        f_->get_touchSupported = reinterpret_cast<unity_input_functions_t::get_touchSupported_t>(fn);
        return &unity_input_context::get_touchSupported;
    }
    else if (!strcmp(name, "UnityEngine.Input::mainGyroIndex_Internal"))
    {
        f_->mainGyroIndex_Internal = reinterpret_cast<unity_input_functions_t::mainGyroIndex_Internal_t>(fn);
        return &unity_input_context::mainGyroIndex_Internal;
    }
    else if (!strcmp(name, "UnityEngine.Input::set_backButtonLeavesApp"))
    {
        f_->set_backButtonLeavesApp = reinterpret_cast<unity_input_functions_t::set_backButtonLeavesApp_t>(fn);
        return &unity_input_context::set_backButtonLeavesApp;
    }
    else if (!strcmp(name, "UnityEngine.Input::set_compensateSensors"))
    {
        f_->set_compensateSensors = reinterpret_cast<unity_input_functions_t::set_compensateSensors_t>(fn);
        return &unity_input_context::set_compensateSensors;
    }
    else if (!strcmp(name, "UnityEngine.Input::set_eatKeyPressOnTextFieldFocus"))
    {
        f_->set_eatKeyPressOnTextFieldFocus = reinterpret_cast<unity_input_functions_t::set_eatKeyPressOnTextFieldFocus_t>(fn);
        return &unity_input_context::set_eatKeyPressOnTextFieldFocus;
    }
    else if (!strcmp(name, "UnityEngine.Input::set_imeCompositionMode"))
    {
        f_->set_imeCompositionMode = reinterpret_cast<unity_input_functions_t::set_imeCompositionMode_t>(fn);
        return &unity_input_context::set_imeCompositionMode;
    }
    else if (!strcmp(name, "UnityEngine.Input::set_multiTouchEnabled"))
    {
        f_->set_multiTouchEnabled = reinterpret_cast<unity_input_functions_t::set_multiTouchEnabled_t>(fn);
        return &unity_input_context::set_multiTouchEnabled;
    }
    else if (!strcmp(name, "UnityEngine.Input::set_simulateMouseWithTouches"))
    {
        f_->set_simulateMouseWithTouches = reinterpret_cast<unity_input_functions_t::set_simulateMouseWithTouches_t>(fn);
        return &unity_input_context::set_simulateMouseWithTouches;
    }
    else
    {
        return nullptr;
    }
}
