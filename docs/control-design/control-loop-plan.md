# Control Loop Plan

## Initial Scope
- Open-loop PWM drive
- Closed-loop speed control with PID
- Optional current limiting
- Fault handling for overcurrent, undervoltage, and sensor loss

## Suggested Scheduling
- PWM update ISR: fast loop
- Speed estimation: periodic timer task
- Control update: fixed sample time
- Telemetry: slower background task

## Tuning Path
1. Verify motor direction and deadband
2. Validate encoder scaling
3. Add speed measurement filtering
4. Tune P only
5. Add I carefully
6. Add saturation and anti-windup
