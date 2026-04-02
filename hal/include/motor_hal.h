#ifndef MOTOR_HAL_H
#define MOTOR_HAL_H

#include <stdint.h>

void motor_hal_init(void);
void motor_hal_set_pwm_percent(float duty_percent);
float motor_hal_get_speed_rpm(void);
float motor_hal_get_bus_voltage(void);
float motor_hal_get_phase_current(void);
uint8_t motor_hal_fault_active(void);

#endif
