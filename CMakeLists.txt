cmake_minimum_required(VERSION 3.24)
project(dc_motor_control C ASM)

enable_language(C ASM)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT DEFINED BOARD)
  set(BOARD nucleo_f103rb)
endif()

add_library(project_warnings INTERFACE)
target_compile_options(project_warnings INTERFACE
  -Wall
  -Wextra
  -Wpedantic
  -Wshadow
  -Wconversion
  -Wdouble-promotion
)

add_library(hal STATIC
  hal/src/motor_hal.c
)
target_include_directories(hal PUBLIC hal/include)
target_link_libraries(hal PUBLIC project_warnings)

add_library(app STATIC
  app/motor_control/motor_control.c
  app/state_machine/motor_fsm.c
  app/safety/safety_monitor.c
)
target_include_directories(app PUBLIC app)
target_link_libraries(app PUBLIC hal project_warnings)

add_executable(${PROJECT_NAME}.elf
  drivers/startup/startup_placeholder.s
  bsp/${BOARD}/board_init.c
  platform/gpio/gpio.c
  platform/pwm/pwm.c
  platform/adc/adc.c
  platform/timer/timer.c
  platform/uart/uart.c
  platform/encoder/encoder.c
)
target_link_libraries(${PROJECT_NAME}.elf PRIVATE app hal project_warnings)

target_include_directories(${PROJECT_NAME}.elf PRIVATE
  drivers/cmsis
  drivers/device
  platform
  bsp/${BOARD}
)
