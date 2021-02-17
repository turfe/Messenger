#include "global_variables.hpp"
//#include "paint.hpp"
#pragma once

#define ps_err_img ""
#define ps_two_img ""
#define ps_three_img ""

void wait_sign(screen::Background& window, int H, int W) {

}
void personal_settings() {
    int W = 400;
    int H = 400;
    screen::Background settings_window(H, "Personal Settings", W);
    while( settings_window.is_open() ) {
        settings_window.handler_button();
        settings_window.draw_on_window(sf::Color::White);
        settings_window.display();
        if ( global_sign == 0 ) {
            //wait_sign(settings_window, H, W);
        }

    }
}

