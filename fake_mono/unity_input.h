#pragma once

#include "mono_wrapper/types.h"

struct unity_input
{
   static float GetAxis(MonoString* axisName);
   static float GetAxisRaw(MonoString* axisName);
   static gboolean GetButton(MonoString* buttonName);
   static gboolean GetButtonUp(MonoString* buttonName);
   static gboolean GetButtonDown(MonoString* buttonName);
   static MonoArray* GetJoystickNames();
   static gboolean GetKeyDownInt(int32_t key);
   static gboolean GetKeyDownString(MonoString* name);
   static gboolean GetKeyInt(int32_t key);
   static gboolean GetKeyString(MonoString* name);
   static gboolean GetKeyUpInt(int32_t key);
   static gboolean GetKeyUpString(MonoString* name);
   static gboolean GetMouseButton(int32_t button);
   static gboolean GetMouseButtonDown(int32_t button);
   static gboolean GetMouseButtonUp(int32_t button);
   static void INTERNAL_CALL_GetAccelerationEvent(int32_t index, MonoStruct_out value);
   static void INTERNAL_CALL_GetTouch(int32_t index, MonoStruct_out value);
   static void INTERNAL_get_acceleration(MonoStruct_out value);
   static void INTERNAL_get_compositionCursorPos(MonoStruct_out value);
   static void INTERNAL_get_mousePosition(MonoStruct_out value);
   static void INTERNAL_get_mouseScrollDelta(MonoStruct_out value);
   static void INTERNAL_set_compositionCursorPos(MonoStruct value);
   static void ResetInputAxes();
   static MonoObject* get_deviceOrientation();
   static MonoObject* get_imeCompositionMode();
   static int32_t get_accelerationEventCount();
   static gboolean get_anyKey();
   static gboolean get_anyKeyDown();
   static gboolean get_backButtonLeavesApp();
   static gboolean get_compensateSensors();
   static MonoString* get_compositionString();
   static gboolean get_eatKeyPressOnTextFieldFocus();
   static gboolean get_imeIsSelected();
   static MonoString* get_inputString();
   static gboolean get_isGyroAvailable();
   static gboolean get_mousePresent();
   static gboolean get_multiTouchEnabled();
   static gboolean get_simulateMouseWithTouches();
   static gboolean get_stylusTouchSupported();
   static int32_t get_touchCount();
   static gboolean get_touchPressureSupported();
   static gboolean get_touchSupported();
   static int32_t mainGyroIndex_Internal();
   static void set_backButtonLeavesApp(gboolean value);
   static void set_compensateSensors(gboolean value);
   static void set_eatKeyPressOnTextFieldFocus(gboolean value);
   static void set_imeCompositionMode(MonoObject* value);
   static void set_multiTouchEnabled(gboolean value);
   static void set_simulateMouseWithTouches(gboolean value);
};
