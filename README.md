# DC Motor Control Template

Enterprise-grade starter repository for a brushed DC motor control system using bare-metal firmware on STM32-class MCUs.

## Goals
- Reusable repository template for future embedded projects
- Bare-metal firmware without vendor HAL dependency in application code
- Modular architecture with clear separation between drivers, platform, HAL, BSP, and application
- CI/CD, code quality gates, contribution guidance, and release flow from day one

## Architecture
```text
app -> hal -> platform -> drivers
app -> lib
bsp -> hal + platform
test -> app + mocked hal
```

## Directory Map
- `drivers/`: CMSIS, startup files, linker scripts, device headers
- `platform/`: Register-level peripheral implementations
- `hal/`: Stable hardware abstraction interfaces used by application code
- `bsp/`: Board-specific mappings and initialization
- `app/`: Motor control logic, state machines, safety, CLI
- `lib/`: Reusable algorithms such as PID, filters, fixed-point helpers
- `test/`: Host, unit, and integration tests
- `docs/`: Architecture, control design, hardware, and verification notes

## Quick Start
1. Install CMake 3.24+, Ninja, Python 3.11+, and Arm GNU Toolchain.
2. Create or update the board config under `config/boards/`.
3. Add startup files, linker script, and CMSIS/device headers under `drivers/`.
4. Implement platform drivers in `platform/` and wire them via `bsp/`.
5. Build:
   ```bash
   cmake -S . -B build -G Ninja -DBOARD=nucleo_f103rb
   cmake --build build
   ```
6. Run host tests:
   ```bash
   ctest --test-dir build-host --output-on-failure
   ```

## Branch Strategy
- `main`: protected, releasable
- `feat/*`: feature development
- `fix/*`: bug fixes
- `docs/*`: documentation-only changes
- `chore/*`: maintenance changes

## Release Artifacts
Tagging `vX.Y.Z` triggers firmware packaging for `.elf`, `.bin`, and `.map` outputs.

## Next Steps
- Add your target MCU startup files and linker script
- Add encoder, PWM, ADC, and current-sense drivers
- Implement motor speed loop and safety monitoring
- Extend host-side tests with mocked HAL interfaces
