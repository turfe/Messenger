#pragma once

#include "global_variables.hpp"
#include <fstream>
#include <iostream>
#include "textbox.hpp"

void sign() {
    std::ofstream File;
    std::string s1, s2, s3, s4, s5, s6;
    sf::Font font;
    font.loadFromFile(path_to_font);

    int i = 0;
    //std::vector<Textbox> input_data;

    std::vector<sf::Vector2f> positions;
    for (int j = 1; j < 7; ++j) {
        positions.emplace_back(sf::Vector2f(280, 63+45*i));
    }
    Textbox textbox_input(font, 30, false, sf::Vector2f(195, 63), 15);

    screen::Background sign(1240, "SIGN", 700);
    while (sign.is_open()) {
        sign.display();
        sign.handler_button();
        sign.draw_on_window(Background_test);
        sign.draw_on_window("Name:", 45, sf::Vector2f(50, 50));
        sign.draw_on_window("Information:", 45, sf::Vector2f(50, 95));
        sign.draw_on_window("Nickname:", 45, sf::Vector2f(50, 130));
        sign.draw_on_window("Avatar:", 45, sf::Vector2f(50, 175));
        sign.draw_on_window("Password:", 45, sf::Vector2f(50, 220));
        sign.draw_on_window("Melody:", 45, sf::Vector2f(50, 265));

        sf::Event event;

         // TODO: add click icons
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            textbox_input.setSelected(true);
            std::cout << i << std::endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            s1 = textbox_input.getText();
            textbox_input.setSelected(false);
            std::cout << i << std::endl;
            i += 1;
            std::cout << i << std::endl;
        }
        while (sign.Get_window().pollEvent(event)) {
            switch (event.type) {
                case sf::Event::TextEntered:
                    std::cout << "Hey" << std::endl;
                    textbox_input.type_text(event);
                    std::cout << textbox_input.getText() << std::endl;
            }
        }
        for (int j = 0; j < 6; ++j) {
            textbox_input.draw(sign.Get_window());
        }
        sign.Get_window().display();

        //}
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
    //User personal(s1, s2, s3, s4, s5, s6);
    //personal.write(two_secret_path);
    global_sign = 0;
}


