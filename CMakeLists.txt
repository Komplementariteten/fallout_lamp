cmake_minimum_required(VERSION 3.13)

set(NAME fallout_lamp)

include(pico_sdk_import.cmake)

project(${NAME} C CXX ASM)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

pico_sdk_init()

add_executable(${NAME}
src/main.cpp
src/main.h
)

pico_enable_stdio_usb(${NAME} 1)

target_link_libraries(${NAME} pico_stdlib pico_cyw43_arch_none)

# target_include_directories(${NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src/ # For btstack config)
# pico_btstack_make_gatt_header(${NAME} PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src/led_control.gatt")
pico_add_extra_outputs(${NAME})