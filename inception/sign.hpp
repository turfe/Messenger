#pragma once

#include "global_variables.hpp"
#include <fstream>
#include <iostream>
#include "textbox.hpp"

void sign() {
    std::ofstream File;
    std::vector<std::string> info_user;
    sf::Font font;
    font.loadFromFile(path_to_font);

    int i = 0, counter = 0;
    //std::vector<Textbox> input_data;

    std::vector<sf::Vector2f> positions;
    positions.reserve(6);
    for (int j = 0; j < 6; ++j) {
        positions.emplace_back(sf::Vector2f(325, 63 + 45 * i));
        info_user.emplace_back("");
    }
    Textbox textbox_input(font, 30, false, positions[0], 15);
    bool flag = false;

    screen::Background sign(1240, "SIGN", 700);
    while (sign.is_open()) {
        sign.display();
        sign.handler_button();
        sign.draw_on_window(Background_test);
        sign.draw_on_window("Name:", 45, sf::Vector2f(50, 50));
        sign.draw_on_window("Information:", 45, sf::Vector2f(50, 100));
        sign.draw_on_window("Nickname:", 45, sf::Vector2f(50, 150));
        sign.draw_on_window("Avatar:", 45, sf::Vector2f(50, 200));
        sign.draw_on_window("Password:", 45, sf::Vector2f(50, 250));
        sign.draw_on_window("Melody:", 45, sf::Vector2f(50, 300));

        sf::Event event;

        // TODO: add click icons
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            std::cout << counter << std::endl;
            textbox_input.setSelected(true);
        } /*else if (counter > 1 && counter != 7) {
                std::cout << counter << std::endl;
                i++;
                s1 = textbox_input.getText();
                textbox_input.erase_text();
                textbox_input.setPosition(positions[i]);
            } else if (counter == 7) {
                std::cout << counter << std::endl;
                s6 = textbox_input.getText();
                flag = true;
            }*/

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            counter++;
            if (counter < 6) {
                textbox_input.setSelected(false);
                info_user[i] = textbox_input.getText();
                textbox_input.erase_text();
                i++;
                textbox_input.setPosition(positions[i]);
                textbox_input.setSelected(true);
                continue;
            } else if (counter == 6) {
                textbox_input.setSelected(false);
                flag = true;
            }
        }

        while (sign.Get_window().pollEvent(event)) {
            switch (event.type) {
                case sf::Event::TextEntered:
                    std::cout << "Hey" << std::endl;
                    textbox_input.type_text(event);
                    std::cout << textbox_input.getText() << std::endl;
            }
        }
        textbox_input.draw(sign.Get_window());
        /*sign.draw_on_window(info_user[0], 45, sf::Vector2f(250, 50));
        sign.draw_on_window(info_user[1], 45, sf::Vector2f(250, 100));
        sign.draw_on_window(info_user[2], 45, sf::Vector2f(250, 150));
        sign.draw_on_window(info_user[3], 45, sf::Vector2f(250, 200));
        sign.draw_on_window(info_user[4], 45, sf::Vector2f(250, 250));
        sign.draw_on_window(info_user[5], 45, sf::Vector2f(250, 300));
         */
        sign.Get_window().display();
        if (flag)
            break;
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

    User personal(info_user[0], info_user[1], info_user[2], info_user[3], info_user[4], info_user[5]);
    personal.
            write(two_secret_path);
    global_sign = 0;
}


