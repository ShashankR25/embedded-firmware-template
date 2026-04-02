#include "motor_hal.h"

void motor_hal_init(void) {}
void motor_hal_set_pwm_percent(float duty_percent) {(void)duty_percent;}
float motor_hal_get_speed_rpm(void) { return 0.0f; }
float motor_hal_get_bus_voltage(void) { return 0.0f; }
float motor_hal_get_phase_current(void) { return 0.0f; }
uint8_t motor_hal_fault_active(void) { return 0U; }
