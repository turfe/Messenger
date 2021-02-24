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
        window.handler_button();        //add handler_button
        std::this_thread::sleep_for (std::chrono::seconds(1));
        window.Get_window().clear();    //add method in class Background
        //window.display();
    }
    window.my_clear();
}


void change_data(screen::Background& window, int W, int H) {
    //add func: personal_settings
    screen::Icons ava(path_to_mem2, screen::Point(100, 100));               //Issue: Error in constructor Icons, WTF??  // TO SOLVED
    screen::Icons name(path_to_mem, screen::Point(200, 200));
    screen::Icons password(path_to_sound);
    screen::Icons nickname(path_to_sound);
    screen::Icons info(path_to_sound);
    screen::Icons melody(path_to_dante, screen::Point(0, 0));
    screen::Button public_data(ava);
    std::cout << "WORK\n";
    std::cout << name.path_to_image << std::endl;
    public_data.insert(name);
    public_data.insert(password);
    public_data.insert(nickname);
    public_data.insert(info);
    //std::cout << "WROK\n";
    public_data.insert(melody);
    public_data.draw_objects(window.Get_window());
    window.display();
    while( window.is_open() ) {
        sf::Event event;
        while ( window.Get_window().pollEvent(event) ) {
            if ( event.type == sf::Event::Closed ) {
                window.Get_window().close();            //Issue: add my_CLOSE
            }
            else if ( sf::Mouse::isButtonPressed(sf::Mouse::Left) ) {
                sf::Vector2i position_mouse = sf::Mouse::getPosition(window.Get_window());
                if ( ava.click(position_mouse, window) == true ) {
                        std::cout << "CLICK\n";
                        //change_ava        //ISsue: add funk
                }
            }
        }
        //window.display();
        // ISSUE: Add metod in class Icons of situation Icons and click on          //added
        // Issue: Add all work_background in RGB:6699CC                             //added
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
    std::cout << H << "    " << W << std::endl; ///Issue: add normal full size window           //added
    screen::Background settings_window(W, "Personal Settings", H);
    while( settings_window.is_open() ) {
        settings_window.handler_button();
        settings_window.draw_on_window(Background_test);
        settings_window.display();
        if ( global_sign == 0 ) {
            wait_sign(settings_window, W, H);
        }
        else if ( global_sign == 1 ) {
            change_data(settings_window, W, W);
        }
    }
}

    


