# Software Architecture

## Layering
- `drivers/`: vendor and startup support
- `platform/`: low-level peripheral drivers at register level
- `hal/`: stable interfaces abstracting hardware services
- `bsp/`: board-specific mapping and initialization
- `app/`: control logic and state handling
- `lib/`: reusable algorithms and helpers

## Design Rules
- No direct register access in `app/`
- No board-specific constants in generic modules
- Every hardware capability exposed through a clear interface
- Safety logic remains independent from telemetry and CLI

## Example Flow
Speed setpoint -> trajectory ramp -> PID -> PWM abstraction -> timer compare register
Encoder feedback -> platform encoder driver -> HAL -> speed estimator -> PID
