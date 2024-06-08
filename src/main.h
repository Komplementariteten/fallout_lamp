//
// Created by me on 12.05.24.
//

#ifndef FALLOUT_LAMP_MAIN_H
#define FALLOUT_LAMP_MAIN_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/cyw43_arch.h"

/*
#include "btstack.h"
#include "server_common.h"
*/

#define RED_GPIO 19
#define GREEN_GPIO 20
#define BLUE_GPIO 21

class main {

};


class rgb
{
private:
    /* data */
public:
    rgb
(bool r, bool g, bool b): red(r), green(g), blue(b){};
bool red;
bool green;
bool blue;
};

void blink_board_led();

void init_gpio(rgb* state);

void toogle_white(rgb* state);

void toogle_red(rgb* state);

void toogle_green(rgb* state);

void toogle_blue(rgb* state);

void report_board_status();


#endif //FALLOUT_LAMP_MAIN_H
