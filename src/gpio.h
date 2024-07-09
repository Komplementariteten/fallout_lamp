//
// Created by me on 06.07.24.
//

#ifndef FALLOUT_LAMP_GPIO_H
#define FALLOUT_LAMP_GPIO_H

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/cyw43_arch.h"

#define RED_GPIO 22
#define GREEN_GPIO 21
#define BLUE_GPIO 20

class rgb
{
private:
    /* data */
public:
    rgb(bool r, bool g, bool b): red(r), green(g), blue(b){};
    bool red;
    bool green;
    bool blue;
};

void set_board_led(bool value);

void blink_board_led();

void init_outputs(rgb* state);

void handle_state(rgb* state);

void error_board_led_blink();

bool lamp_is_on();

#endif //FALLOUT_LAMP_GPIO_H
