#include "motor_hal.h"

void motor_control_step(float target_rpm) {
  const float measured_rpm = motor_hal_get_speed_rpm();
  const float error = target_rpm - measured_rpm;
  const float duty = error * 0.01f;
  motor_hal_set_pwm_percent(duty);
}
