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
    blink_board_led();
    auto state = new rgb(false, false, false);
    init_outputs(state);
    auto result = run_server();
    if(result != 0){
        blink_board_led();
    } else{
        blink_board_led();
        blink_board_led();
        blink_board_led();
    }
}



