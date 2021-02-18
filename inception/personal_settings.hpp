#include "global_variables.hpp"
//#include "paint.hpp"
#pragma once

#define ps_err_img ""
#define ps_two_img ""
#define ps_three_img ""

void wait_sign(screen::Background& window, int H, int W) {
    std::cout << "First, log in to the messenger\n";
    for (int i = 5; i > 0; --i) {
        std::cout << i << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
    window.my_clear();
}


void personal_settings() {
    int W = 500;
    int H = 500;
    screen::Background settings_window(H, "Personal Settings", W);
    while( settings_window.is_open() ) {
        settings_window.handler_button();
        settings_window.draw_on_window(sf::Color::White);
        settings_window.display();
        if ( global_sign == 0 ) {
            wait_sign(settings_window, H, W);
        }

    }
}

