#pragma once

#include "unity_input_executor.h"
#include "unity_input_functions.h"

namespace unity_input
{
struct executor_base
    : executor
{
    executor_base(functions_cptr functions);

    float GetAxis(MonoString* axisName) override;
    float GetAxisRaw(MonoString* axisName) override;
    gboolean GetButton(MonoString* buttonName) override;
    gboolean GetButtonUp(MonoString* buttonName) override;
    gboolean GetButtonDown(MonoString* buttonName) override;
    MonoArray* GetJoystickNames() override;
    gboolean GetKeyDownInt(int32_t key) override;
    gboolean GetKeyDownString(MonoString* name) override;
    gboolean GetKeyInt(int32_t key) override;
    gboolean GetKeyString(MonoString* name) override;
    gboolean GetKeyUpInt(int32_t key) override;
    gboolean GetKeyUpString(MonoString* name) override;
    gboolean GetMouseButton(int32_t button) override;
    gboolean GetMouseButtonDown(int32_t button) override;
    gboolean GetMouseButtonUp(int32_t button) override;
    void INTERNAL_CALL_GetAccelerationEvent(int32_t index, MonoStruct_out value) override;
    void INTERNAL_CALL_GetTouch(int32_t index, MonoStruct_out value) override;
    void INTERNAL_get_acceleration(MonoStruct_out value) override;
    void INTERNAL_get_compositionCursorPos(MonoStruct_out value) override;
    void INTERNAL_get_mousePosition(MonoStruct_out value) override;
    void INTERNAL_get_mouseScrollDelta(MonoStruct_out value) override;
    void INTERNAL_set_compositionCursorPos(MonoStruct value) override;
    void ResetInputAxes() override;
    MonoObject* get_deviceOrientation() override;
    MonoObject* get_imeCompositionMode() override;
    int32_t get_accelerationEventCount() override;
    gboolean get_anyKey() override;
    gboolean get_anyKeyDown() override;
    gboolean get_backButtonLeavesApp() override;
    gboolean get_compensateSensors() override;
    MonoString* get_compositionString() override;
    gboolean get_eatKeyPressOnTextFieldFocus() override;
    gboolean get_imeIsSelected() override;
    MonoString* get_inputString() override;
    gboolean get_isGyroAvailable() override;
    gboolean get_mousePresent() override;
    gboolean get_multiTouchEnabled() override;
    gboolean get_simulateMouseWithTouches() override;
    gboolean get_stylusTouchSupported() override;
    int32_t get_touchCount() override;
    gboolean get_touchPressureSupported() override;
    gboolean get_touchSupported() override;
    int32_t mainGyroIndex_Internal() override;
    void set_backButtonLeavesApp(gboolean value) override;
    void set_compensateSensors(gboolean value) override;
    void set_eatKeyPressOnTextFieldFocus(gboolean value) override;
    void set_imeCompositionMode(MonoObject* value) override;
    void set_multiTouchEnabled(gboolean value) override;
    void set_simulateMouseWithTouches(gboolean value) override;
    
protected:
    functions_cptr functions() const;

public:
    functions_cptr functions_;
};
} // namespace unity_input