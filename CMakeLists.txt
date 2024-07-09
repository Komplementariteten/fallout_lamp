cmake_minimum_required(VERSION 3.13)

set(NAME fallout_lamp)

include(pico_sdk_import.cmake)

project(${NAME} C CXX ASM)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

pico_sdk_init()

add_executable(${NAME}
        src/main.cpp
        src/dhcpd/dhcpserver.cpp
        src/dnsd/dnsserver.cpp
        src/gpio.cpp
        src/tcp_server.cpp
)

target_include_directories(${NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src/dhcpd
        ${CMAKE_CURRENT_LIST_DIR}/src/dnsd
        ${CMAKE_CURRENT_LIST_DIR}/src/opts
        ${CMAKE_CURRENT_LIST_DIR}/src
       )

pico_enable_stdio_usb(${NAME} 1)

target_link_libraries(${NAME}
        pico_cyw43_arch_lwip_poll pico_stdlib)

# target_include_directories(${NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src/ # For btstack config)
# pico_btstack_make_gatt_header(${NAME} PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src/led_control.gatt")
pico_add_extra_outputs(${NAME})