#include "global_variables.hpp"
//#include "paint.hpp"
#pragma once

#define ps_err_img ""
#define ps_two_img ""
#define ps_three_img ""

std::string countdown(int count) {
        std::string str = "FIRST,\nLOG IN TO THE MESSENGER\n\n\n\n             AUTO CLOSE: ";
        str += std::to_string(count);
        str += "sec";
        return str;
}


void wait_sign(screen::Background& window, int H, int W) {
    std::cout << "First, log in to the messenger\n";
    sf::Font font;
    font.loadFromFile(path_to_font);
    for (int i = 5; i > 0; --i) {
        window.draw_on_window(Background_test);
        //std::string str = "FIRST,\nLOG IN TO THE MESSENGER\n\n\n\n             AUTO CLOSE: ";
        //str += std::to_string(i);
        //str += "sec";
        std::string str = countdown(i);
        sf::Text text(str, font);
        text.setFont(font);
        text.setCharacterSize(30);
        text.setStyle(sf::Text::Bold);
        text.setFillColor(sf::Color::Black);
        std::cout << i << std::endl;
        window.Get_window().draw(text); //add method in class Background
        window.display();
        window.handler_button();
        std::this_thread::sleep_for (std::chrono::seconds(1));
        window.Get_window().clear();    //add method in class Background
        //window.display();
    }
    window.my_clear();
}


void change_data(screen::Background& window, int W, int H) {
    //add func: personal_settings
    screen::Icons ava(path_to_sound);
    screen::Icons name(path_to_sound);
    screen::Icons password(path_to_sound);
    screen::Icons nickname(path_to_sound);
    screen::Icons info(path_to_sound);
    screen::Icons melody(path_to_sound);
    screen::Button public_data(ava);
    public_data.insert(name);
    public_data.insert(password);
    public_data.insert(nickname);
    public_data.insert(info);
    public_data.insert(melody);
    while( window.is_open() ) {
        window.handler_button();
        // ISSUE: Add metod in class Icons of situation Icons and click on
        // Issue: Add all work_background in RGB:6699CC
        // add in here: handler
    }
}

void check(int& H, int& W) {
    if ( global_sign == 0 ) {
        H = 500;
        W = 500;
    }
    else {
        W = 1240;
        H = 800;
    }
}

void personal_settings() {
    int H, W;
    check(H, W);
    screen::Background settings_window(H, "Personal Settings", W);
    while( settings_window.is_open() ) {
        settings_window.handler_button();
        settings_window.draw_on_window(Background_test);
        settings_window.display();
        if ( global_sign == 0 ) {
            wait_sign(settings_window, W, H);
        }
        else if ( global_sign == 1 ) {
            change_data(settings_window, W, H);
        }
    }
}

    


