//
// Created by me on 06.07.24.
//

#include "gpio.h"


void blink_board_led() {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, true);
    sleep_ms(250);
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, false);
    sleep_ms(250);
}

bool lamp_is_on(){
    auto red = gpio_get(RED_GPIO);
    auto green = gpio_get(GREEN_GPIO);
    auto blue = gpio_get(BLUE_GPIO);

    return red && green && blue;
}

void error_board_led_blink() {
    auto current = cyw43_arch_gpio_get(CYW43_WL_GPIO_LED_PIN);
    if(current) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, true);
        sleep_ms(250);
    }
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, true);
    sleep_ms(150);
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, false);
    sleep_ms(150);
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, true);
    sleep_ms(150);
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, false);
    sleep_ms(150);
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, true);
    sleep_ms(150);
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, false);
    sleep_ms(150);
}

void set_board_led(bool value) {
    auto current = cyw43_arch_gpio_get(CYW43_WL_GPIO_LED_PIN);
    if(current != value) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, true);
        sleep_ms(250);
    }
}

void init_outputs(rgb* state){

    // Init GPIO
    gpio_init(RED_GPIO);
    gpio_set_dir(RED_GPIO, GPIO_OUT);
    gpio_init(GREEN_GPIO);
    gpio_set_dir(GREEN_GPIO, GPIO_OUT);
    gpio_init(BLUE_GPIO);
    gpio_set_dir(BLUE_GPIO, GPIO_OUT);
    blink_board_led();

    // Initialize Outputs
    handle_state(state);
    blink_board_led();
}

void handle_state(rgb* state){
    gpio_put(RED_GPIO, state->red);
    gpio_put(GREEN_GPIO, state->green);
    gpio_put(BLUE_GPIO, state->blue);
    sleep_ms(250);
}
