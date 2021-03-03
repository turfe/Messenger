#pragma once

#include "global_variables.hpp"
#include <fstream>
#include <iostream>
#include "textbox.hpp"

void sign() {
    std::ofstream File;
    std::string s1, s2, s3, s4, s5, s6;
    int a = 0;
    sf::Font font;
    font.loadFromFile(path_to_font);
    Textbox textbox_name(font, 30, false, sf::Vector2f(100, 50), 15);

    screen::Background sign(1240, "SIGN", 700);
    while (sign.is_open()) {
        sign.display();
        sign.handler_button();
        sign.draw_on_window(Background_test);
        sign.draw_on_window("Name:asd", 45, sf::Vector2f(50, 50));
        sign.display();
        sf::Event event;
        // TODO
        //  - add click icons
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            textbox_name.setSelected(true);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            textbox_name.setSelected(false);
        }

        while (sign.Get_window().pollEvent(event)) {
            std::cout << textbox_name.getText() << std::endl;
            switch (event.type) {
                case sf::Event::TextEntered:
                    std::cout << "Hey" << std::endl;
                    textbox_name.type_text(event);
            }
        }
        textbox_name.draw(sign.Get_window());
        sign.display();
        /*
        std::cout << "Enter name\n";
        std::cin >> s1;
        std::cout << " Enter information\n";
        std::cin >> s2;
        std::cout << " Enter nickname\n";
        std::cin >> s3;
        std::cout << " Enter avatar\n";
        std::cin >> s4;
        std::cout << " Enter password\n";
        std::cin >> s5;
        std::cout << "Enter melody\n";
        std::cin >> s6;
        a = 1;*/
    }
    User personal(s1, s2, s3, s4, s5, s6);
    personal.write(two_secret_path);
    global_sign = 0;
}


