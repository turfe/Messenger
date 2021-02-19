#include "global_variables.hpp"
//#include "paint.hpp"
#pragma once

#define ps_err_img ""
#define ps_two_img ""
#define ps_three_img ""

void wait_sign(screen::Background& window, int H, int W) {
    std::cout << "First, log in to the messenger\n";
    sf::Font font;
    font.loadFromFile(path_to_font);
    for (int i = 5; i > 0; --i) {
        window.draw_on_window(sf::Color::White);
        std::string str = "FIRST,\nLOG IN TO THE MESSENGER\n\n\n\n             AUTO CLOSE: ";
        str += std::to_string(i);
        str += "sec";
        sf::Text text(str, font);
        text.setFont(font);
        text.setCharacterSize(30);
        text.setStyle(sf::Text::Bold);
        text.setFillColor(sf::Color::Black);
        std::cout << i << std::endl;
        window.Get_window().draw(text);
        window.display();
        window.handler_button();
        std::this_thread::sleep_for (std::chrono::seconds(1));
        window.Get_window().clear();
        //window.display();
    }
    window.my_clear();
}


void change_data(screen::Background& window, int H, int W) {
    //add func: personal_settings
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
        else if ( global_sign == 1 ) {
            change_data(settings_window, H, W);
        }
    }
}

    


