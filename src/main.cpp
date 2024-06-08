//
// Created by me on 12.05.24.
//

#include "main.h"


int main() {
    stdio_init_all();
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed");
        return -1;
    }

    while (true) {
        blink_board_led();
    }
    // report_board_status();
    // auto state = new rgb(false, false, false);
}

void blink_board_led() {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    sleep_ms(250);
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    sleep_ms(250);
}


void toogle_white(rgb* state){
    toogle_red(state);
    toogle_green(state);
    toogle_blue(state);
}

void report_board_status() {

    const uint BOARD_LED = 25;
    gpio_init(BOARD_LED);
    gpio_set_dir(BOARD_LED, GPIO_OUT);
    gpio_put(BOARD_LED, true);

}

void toogle_red(rgb* state){
    state->red = !state->red;
}

void toogle_green(rgb* state){
    state->green = !state->green;
}
void toogle_blue(rgb* state){
    state->blue = !state->blue;
}


void init_gpio(rgb* state) {
    gpio_init(RED_GPIO);
    gpio_set_dir(RED_GPIO, GPIO_OUT);
    gpio_put(RED_GPIO, state->red);

    gpio_init(BLUE_GPIO);
    gpio_set_dir(BLUE_GPIO, GPIO_OUT);
    gpio_put(BLUE_GPIO, state->blue);

    gpio_init(GREEN_GPIO);
    gpio_set_dir(GREEN_GPIO, GPIO_OUT);
    gpio_put(GREEN_GPIO, state->green);
}