#include "stdafx.h"

#include "unity_input.h"

float unity_input::GetAxis(MonoString* axisName)
{
    typedef float(__cdecl *func_type)(MonoString* axisName);
    auto f = reinterpret_cast<func_type>(f_.GetAxis);
    return f(axisName);
}

float unity_input::GetAxisRaw(MonoString* axisName)
{
    typedef float(__cdecl *func_type)(MonoString* axisName);
    auto f = reinterpret_cast<func_type>(f_.GetAxisRaw);
    return f(axisName);
}

gboolean unity_input::GetButton(MonoString* buttonName)
{
    typedef gboolean(__cdecl *func_type)(MonoString* buttonName);
    auto f = reinterpret_cast<func_type>(f_.GetButton);
    return f(buttonName);
}

gboolean unity_input::GetButtonUp(MonoString* buttonName)
{
    typedef gboolean(__cdecl *func_type)(MonoString* buttonName);
    auto f = reinterpret_cast<func_type>(f_.GetButtonUp);
    return f(buttonName);
}

gboolean unity_input::GetButtonDown(MonoString* buttonName)
{
    typedef gboolean(__cdecl *func_type)(MonoString* buttonName);
    auto f = reinterpret_cast<func_type>(f_.GetButtonDown);
    return f(buttonName);
}

MonoArray* unity_input::GetJoystickNames()
{
    typedef MonoArray*(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.GetJoystickNames);
    return f();
}

gboolean unity_input::GetKeyDownInt(int32_t key)
{
    typedef gboolean(__cdecl *func_type)(int32_t key);
    auto f = reinterpret_cast<func_type>(f_.GetKeyDownInt);
    return f(key);
}

gboolean unity_input::GetKeyDownString(MonoString* name)
{
    typedef gboolean(__cdecl *func_type)(MonoString* name);
    auto f = reinterpret_cast<func_type>(f_.GetKeyDownString);
    return f(name);
}

gboolean unity_input::GetKeyInt(int32_t key)
{
    typedef gboolean(__cdecl *func_type)(int32_t key);
    auto f = reinterpret_cast<func_type>(f_.GetKeyInt);
    return f(key);
}

gboolean unity_input::GetKeyString(MonoString* name)
{
    typedef gboolean(__cdecl *func_type)(MonoString* name);
    auto f = reinterpret_cast<func_type>(f_.GetKeyString);
    return f(name);
}

gboolean unity_input::GetKeyUpInt(int32_t key)
{
    typedef gboolean(__cdecl *func_type)(int32_t key);
    auto f = reinterpret_cast<func_type>(f_.GetKeyUpInt);
    return f(key);
}

gboolean unity_input::GetKeyUpString(MonoString* name)
{
    typedef gboolean(__cdecl *func_type)(MonoString* name);
    auto f = reinterpret_cast<func_type>(f_.GetKeyUpString);
    return f(name);
}

gboolean unity_input::GetMouseButton(int32_t button)
{
    typedef gboolean(__cdecl *func_type)(int32_t button);
    auto f = reinterpret_cast<func_type>(f_.GetMouseButton);
    return f(button);
}

gboolean unity_input::GetMouseButtonDown(int32_t button)
{
    typedef gboolean(__cdecl *func_type)(int32_t button);
    auto f = reinterpret_cast<func_type>(f_.GetMouseButtonDown);
    return f(button);
}

gboolean unity_input::GetMouseButtonUp(int32_t button)
{
    typedef gboolean(__cdecl *func_type)(int32_t button);
    auto f = reinterpret_cast<func_type>(f_.GetMouseButtonUp);
    return f(button);
}

void unity_input::INTERNAL_CALL_GetAccelerationEvent(int32_t index, MonoStruct_out value)
{
    typedef void(__cdecl *func_type)(int32_t index, MonoStruct_out value);
    auto f = reinterpret_cast<func_type>(f_.INTERNAL_CALL_GetAccelerationEvent);
    return f(index, value);
}

void unity_input::INTERNAL_CALL_GetTouch(int32_t index, MonoStruct_out value)
{
    typedef void(__cdecl *func_type)(int32_t index, MonoStruct_out value);
    auto f = reinterpret_cast<func_type>(f_.INTERNAL_CALL_GetTouch);
    return f(index, value);
}

void unity_input::INTERNAL_get_acceleration(MonoStruct_out value)
{
    typedef void(__cdecl *func_type)(MonoStruct_out value);
    auto f = reinterpret_cast<func_type>(f_.INTERNAL_get_acceleration);
    return f(value);
}

void unity_input::INTERNAL_get_compositionCursorPos(MonoStruct_out value)
{
    typedef void(__cdecl *func_type)(MonoStruct_out value);
    auto f = reinterpret_cast<func_type>(f_.INTERNAL_get_compositionCursorPos);
    return f(value);
}

void unity_input::INTERNAL_get_mousePosition(MonoStruct_out value)
{
    typedef void(__cdecl *func_type)(MonoStruct_out value);
    auto f = reinterpret_cast<func_type>(f_.INTERNAL_get_mousePosition);
    return f(value);
}

void unity_input::INTERNAL_get_mouseScrollDelta(MonoStruct_out value)
{
    typedef void(__cdecl *func_type)(MonoStruct_out value);
    auto f = reinterpret_cast<func_type>(f_.INTERNAL_get_mouseScrollDelta);
    return f(value);
}

void unity_input::INTERNAL_set_compositionCursorPos(MonoStruct value)
{
    typedef void(__cdecl *func_type)(MonoStruct value);
    auto f = reinterpret_cast<func_type>(f_.INTERNAL_set_compositionCursorPos);
    return f(value);
}

void unity_input::ResetInputAxes()
{
    typedef void(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.ResetInputAxes);
    return f();
}

MonoObject* unity_input::get_deviceOrientation()
{
    typedef MonoObject*(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.get_deviceOrientation);
    return f();
}

MonoObject* unity_input::get_imeCompositionMode()
{
    typedef MonoObject*(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.get_imeCompositionMode);
    return f();
}

int32_t unity_input::get_accelerationEventCount()
{
    typedef int32_t(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.get_accelerationEventCount);
    return f();
}

gboolean unity_input::get_anyKey()
{
    typedef gboolean(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.get_anyKey);
    return f();
}

gboolean unity_input::get_anyKeyDown()
{
    typedef gboolean(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.get_anyKeyDown);
    return f();
}

gboolean unity_input::get_backButtonLeavesApp()
{
    typedef gboolean(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.get_backButtonLeavesApp);
    return f();
}

gboolean unity_input::get_compensateSensors()
{
    typedef gboolean(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.get_compensateSensors);
    return f();
}

MonoString* unity_input::get_compositionString()
{
    typedef MonoString*(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.get_compositionString);
    return f();
}

gboolean unity_input::get_eatKeyPressOnTextFieldFocus()
{
    typedef gboolean(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.get_eatKeyPressOnTextFieldFocus);
    return f();
}

gboolean unity_input::get_imeIsSelected()
{
    typedef gboolean(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.get_imeIsSelected);
    return f();
}

MonoString* unity_input::get_inputString()
{
    typedef MonoString*(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.get_inputString);
    return f();
}

gboolean unity_input::get_isGyroAvailable()
{
    typedef gboolean(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.get_isGyroAvailable);
    return f();
}

gboolean unity_input::get_mousePresent()
{
    typedef gboolean(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.get_mousePresent);
    return f();
}

gboolean unity_input::get_multiTouchEnabled()
{
    typedef gboolean(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.get_multiTouchEnabled);
    return f();
}

gboolean unity_input::get_simulateMouseWithTouches()
{
    typedef gboolean(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.get_simulateMouseWithTouches);
    return f();
}

gboolean unity_input::get_stylusTouchSupported()
{
    typedef gboolean(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.get_stylusTouchSupported);
    return f();
}

int32_t unity_input::get_touchCount()
{
    typedef int32_t(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.get_touchCount);
    return f();
}

gboolean unity_input::get_touchPressureSupported()
{
    typedef gboolean(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.get_touchPressureSupported);
    return f();
}

gboolean unity_input::get_touchSupported()
{
    typedef gboolean(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.get_touchSupported);
    return f();
}

int32_t unity_input::mainGyroIndex_Internal()
{
    typedef int32_t(__cdecl *func_type)();
    auto f = reinterpret_cast<func_type>(f_.mainGyroIndex_Internal);
    return f();
}

void unity_input::set_backButtonLeavesApp(gboolean value)
{
    typedef void(__cdecl *func_type)(gboolean value);
    auto f = reinterpret_cast<func_type>(f_.set_backButtonLeavesApp);
    return f(value);
}

void unity_input::set_compensateSensors(gboolean value)
{
    typedef void(__cdecl *func_type)(gboolean value);
    auto f = reinterpret_cast<func_type>(f_.set_compensateSensors);
    return f(value);
}

void unity_input::set_eatKeyPressOnTextFieldFocus(gboolean value)
{
    typedef void(__cdecl *func_type)(gboolean value);
    auto f = reinterpret_cast<func_type>(f_.set_eatKeyPressOnTextFieldFocus);
    return f(value);
}

void unity_input::set_imeCompositionMode(MonoObject* value)
{
    typedef void(__cdecl *func_type)(MonoObject* value);
    auto f = reinterpret_cast<func_type>(f_.set_imeCompositionMode);
    return f(value);
}

void unity_input::set_multiTouchEnabled(gboolean value)
{
    typedef void(__cdecl *func_type)(gboolean value);
    auto f = reinterpret_cast<func_type>(f_.set_multiTouchEnabled);
    return f(value);
}

void unity_input::set_simulateMouseWithTouches(gboolean value)
{
    typedef void(__cdecl *func_type)(gboolean value);
    auto f = reinterpret_cast<func_type>(f_.set_simulateMouseWithTouches);
    return f(value);
}


gconstpointer unity_input::register_fn(char const *name, gconstpointer fn)
{
    if (false) {}
    else if (!strcmp(name, "GetAxis"))
    {
        f_.GetAxis = fn;
        return &unity_input::GetAxis;
    }
    else if (!strcmp(name, "GetAxisRaw"))
    {
        f_.GetAxisRaw = fn;
        return &unity_input::GetAxisRaw;
    }
    else if (!strcmp(name, "GetButton"))
    {
        f_.GetButton = fn;
        return &unity_input::GetButton;
    }
    else if (!strcmp(name, "GetButtonUp"))
    {
        f_.GetButtonUp = fn;
        return &unity_input::GetButtonUp;
    }
    else if (!strcmp(name, "GetButtonDown"))
    {
        f_.GetButtonDown = fn;
        return &unity_input::GetButtonDown;
    }
    else if (!strcmp(name, "GetJoystickNames"))
    {
        f_.GetJoystickNames = fn;
        return &unity_input::GetJoystickNames;
    }
    else if (!strcmp(name, "GetKeyDownInt"))
    {
        f_.GetKeyDownInt = fn;
        return &unity_input::GetKeyDownInt;
    }
    else if (!strcmp(name, "GetKeyDownString"))
    {
        f_.GetKeyDownString = fn;
        return &unity_input::GetKeyDownString;
    }
    else if (!strcmp(name, "GetKeyInt"))
    {
        f_.GetKeyInt = fn;
        return &unity_input::GetKeyInt;
    }
    else if (!strcmp(name, "GetKeyString"))
    {
        f_.GetKeyString = fn;
        return &unity_input::GetKeyString;
    }
    else if (!strcmp(name, "GetKeyUpInt"))
    {
        f_.GetKeyUpInt = fn;
        return &unity_input::GetKeyUpInt;
    }
    else if (!strcmp(name, "GetKeyUpString"))
    {
        f_.GetKeyUpString = fn;
        return &unity_input::GetKeyUpString;
    }
    else if (!strcmp(name, "GetMouseButton"))
    {
        f_.GetMouseButton = fn;
        return &unity_input::GetMouseButton;
    }
    else if (!strcmp(name, "GetMouseButtonDown"))
    {
        f_.GetMouseButtonDown = fn;
        return &unity_input::GetMouseButtonDown;
    }
    else if (!strcmp(name, "GetMouseButtonUp"))
    {
        f_.GetMouseButtonUp = fn;
        return &unity_input::GetMouseButtonUp;
    }
    else if (!strcmp(name, "INTERNAL_CALL_GetAccelerationEvent"))
    {
        f_.INTERNAL_CALL_GetAccelerationEvent = fn;
        return &unity_input::INTERNAL_CALL_GetAccelerationEvent;
    }
    else if (!strcmp(name, "INTERNAL_CALL_GetTouch"))
    {
        f_.INTERNAL_CALL_GetTouch = fn;
        return &unity_input::INTERNAL_CALL_GetTouch;
    }
    else if (!strcmp(name, "INTERNAL_get_acceleration"))
    {
        f_.INTERNAL_get_acceleration = fn;
        return &unity_input::INTERNAL_get_acceleration;
    }
    else if (!strcmp(name, "INTERNAL_get_compositionCursorPos"))
    {
        f_.INTERNAL_get_compositionCursorPos = fn;
        return &unity_input::INTERNAL_get_compositionCursorPos;
    }
    else if (!strcmp(name, "INTERNAL_get_mousePosition"))
    {
        f_.INTERNAL_get_mousePosition = fn;
        return &unity_input::INTERNAL_get_mousePosition;
    }
    else if (!strcmp(name, "INTERNAL_get_mouseScrollDelta"))
    {
        f_.INTERNAL_get_mouseScrollDelta = fn;
        return &unity_input::INTERNAL_get_mouseScrollDelta;
    }
    else if (!strcmp(name, "INTERNAL_set_compositionCursorPos"))
    {
        f_.INTERNAL_set_compositionCursorPos = fn;
        return &unity_input::INTERNAL_set_compositionCursorPos;
    }
    else if (!strcmp(name, "ResetInputAxes"))
    {
        f_.ResetInputAxes = fn;
        return &unity_input::ResetInputAxes;
    }
    else if (!strcmp(name, "get_deviceOrientation"))
    {
        f_.get_deviceOrientation = fn;
        return &unity_input::get_deviceOrientation;
    }
    else if (!strcmp(name, "get_imeCompositionMode"))
    {
        f_.get_imeCompositionMode = fn;
        return &unity_input::get_imeCompositionMode;
    }
    else if (!strcmp(name, "get_accelerationEventCount"))
    {
        f_.get_accelerationEventCount = fn;
        return &unity_input::get_accelerationEventCount;
    }
    else if (!strcmp(name, "get_anyKey"))
    {
        f_.get_anyKey = fn;
        return &unity_input::get_anyKey;
    }
    else if (!strcmp(name, "get_anyKeyDown"))
    {
        f_.get_anyKeyDown = fn;
        return &unity_input::get_anyKeyDown;
    }
    else if (!strcmp(name, "get_backButtonLeavesApp"))
    {
        f_.get_backButtonLeavesApp = fn;
        return &unity_input::get_backButtonLeavesApp;
    }
    else if (!strcmp(name, "get_compensateSensors"))
    {
        f_.get_compensateSensors = fn;
        return &unity_input::get_compensateSensors;
    }
    else if (!strcmp(name, "get_compositionString"))
    {
        f_.get_compositionString = fn;
        return &unity_input::get_compositionString;
    }
    else if (!strcmp(name, "get_eatKeyPressOnTextFieldFocus"))
    {
        f_.get_eatKeyPressOnTextFieldFocus = fn;
        return &unity_input::get_eatKeyPressOnTextFieldFocus;
    }
    else if (!strcmp(name, "get_imeIsSelected"))
    {
        f_.get_imeIsSelected = fn;
        return &unity_input::get_imeIsSelected;
    }
    else if (!strcmp(name, "get_inputString"))
    {
        f_.get_inputString = fn;
        return &unity_input::get_inputString;
    }
    else if (!strcmp(name, "get_isGyroAvailable"))
    {
        f_.get_isGyroAvailable = fn;
        return &unity_input::get_isGyroAvailable;
    }
    else if (!strcmp(name, "get_mousePresent"))
    {
        f_.get_mousePresent = fn;
        return &unity_input::get_mousePresent;
    }
    else if (!strcmp(name, "get_multiTouchEnabled"))
    {
        f_.get_multiTouchEnabled = fn;
        return &unity_input::get_multiTouchEnabled;
    }
    else if (!strcmp(name, "get_simulateMouseWithTouches"))
    {
        f_.get_simulateMouseWithTouches = fn;
        return &unity_input::get_simulateMouseWithTouches;
    }
    else if (!strcmp(name, "get_stylusTouchSupported"))
    {
        f_.get_stylusTouchSupported = fn;
        return &unity_input::get_stylusTouchSupported;
    }
    else if (!strcmp(name, "get_touchCount"))
    {
        f_.get_touchCount = fn;
        return &unity_input::get_touchCount;
    }
    else if (!strcmp(name, "get_touchPressureSupported"))
    {
        f_.get_touchPressureSupported = fn;
        return &unity_input::get_touchPressureSupported;
    }
    else if (!strcmp(name, "get_touchSupported"))
    {
        f_.get_touchSupported = fn;
        return &unity_input::get_touchSupported;
    }
    else if (!strcmp(name, "mainGyroIndex_Internal"))
    {
        f_.mainGyroIndex_Internal = fn;
        return &unity_input::mainGyroIndex_Internal;
    }
    else if (!strcmp(name, "set_backButtonLeavesApp"))
    {
        f_.set_backButtonLeavesApp = fn;
        return &unity_input::set_backButtonLeavesApp;
    }
    else if (!strcmp(name, "set_compensateSensors"))
    {
        f_.set_compensateSensors = fn;
        return &unity_input::set_compensateSensors;
    }
    else if (!strcmp(name, "set_eatKeyPressOnTextFieldFocus"))
    {
        f_.set_eatKeyPressOnTextFieldFocus = fn;
        return &unity_input::set_eatKeyPressOnTextFieldFocus;
    }
    else if (!strcmp(name, "set_imeCompositionMode"))
    {
        f_.set_imeCompositionMode = fn;
        return &unity_input::set_imeCompositionMode;
    }
    else if (!strcmp(name, "set_multiTouchEnabled"))
    {
        f_.set_multiTouchEnabled = fn;
        return &unity_input::set_multiTouchEnabled;
    }
    else if (!strcmp(name, "set_simulateMouseWithTouches"))
    {
        f_.set_simulateMouseWithTouches = fn;
        return &unity_input::set_simulateMouseWithTouches;
    }
    else
    {
        return nullptr;
    }
}
