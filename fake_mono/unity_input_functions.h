#pragma once

#include "mono_wrapper/types.h"

struct unity_input_functions
{
    gconstpointer GetAxis = nullptr;
    gconstpointer GetAxisRaw = nullptr;
    gconstpointer GetButton = nullptr;
    gconstpointer GetButtonUp = nullptr;
    gconstpointer GetButtonDown = nullptr;
    gconstpointer GetJoystickNames = nullptr;
    gconstpointer GetKeyDownInt = nullptr;
    gconstpointer GetKeyDownString = nullptr;
    gconstpointer GetKeyInt = nullptr;
    gconstpointer GetKeyString = nullptr;
    gconstpointer GetKeyUpInt = nullptr;
    gconstpointer GetKeyUpString = nullptr;
    gconstpointer GetMouseButton = nullptr;
    gconstpointer GetMouseButtonDown = nullptr;
    gconstpointer GetMouseButtonUp = nullptr;
    gconstpointer INTERNAL_CALL_GetAccelerationEvent = nullptr;
    gconstpointer INTERNAL_CALL_GetTouch = nullptr;
    gconstpointer INTERNAL_get_acceleration = nullptr;
    gconstpointer INTERNAL_get_compositionCursorPos = nullptr;
    gconstpointer INTERNAL_get_mousePosition = nullptr;
    gconstpointer INTERNAL_get_mouseScrollDelta = nullptr;
    gconstpointer INTERNAL_set_compositionCursorPos = nullptr;
    gconstpointer ResetInputAxes = nullptr;
    gconstpointer get_deviceOrientation = nullptr;
    gconstpointer get_imeCompositionMode = nullptr;
    gconstpointer get_accelerationEventCount = nullptr;
    gconstpointer get_anyKey = nullptr;
    gconstpointer get_anyKeyDown = nullptr;
    gconstpointer get_backButtonLeavesApp = nullptr;
    gconstpointer get_compensateSensors = nullptr;
    gconstpointer get_compositionString = nullptr;
    gconstpointer get_eatKeyPressOnTextFieldFocus = nullptr;
    gconstpointer get_imeIsSelected = nullptr;
    gconstpointer get_inputString = nullptr;
    gconstpointer get_isGyroAvailable = nullptr;
    gconstpointer get_mousePresent = nullptr;
    gconstpointer get_multiTouchEnabled = nullptr;
    gconstpointer get_simulateMouseWithTouches = nullptr;
    gconstpointer get_stylusTouchSupported = nullptr;
    gconstpointer get_touchCount = nullptr;
    gconstpointer get_touchPressureSupported = nullptr;
    gconstpointer get_touchSupported = nullptr;
    gconstpointer mainGyroIndex_Internal = nullptr;
    gconstpointer set_backButtonLeavesApp = nullptr;
    gconstpointer set_compensateSensors = nullptr;
    gconstpointer set_eatKeyPressOnTextFieldFocus = nullptr;
    gconstpointer set_imeCompositionMode = nullptr;
    gconstpointer set_multiTouchEnabled = nullptr;
    gconstpointer set_simulateMouseWithTouches = nullptr;
};
