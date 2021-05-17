#pragma once

#include "global_variables.hpp"
#include "user.hpp"
#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>


#define ps_err_img ""
#define ps_two_img ""
#define ps_three_img ""

std::string countdown(int count) {
    std::string str = "FIRST,\nLOG IN TO THE MESSENGER\n\n\n\n             AUTO CLOSE: ";
    str += std::to_string(count);
    str += "sec";
    return str;
}


void wait_sign(screen::Background &window, int H, int W) {
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
        std::this_thread::sleep_for(std::chrono::seconds(1));
        window.Get_window().clear();    //add method in class Background
        //window.display();
    }
    window.my_clear();
}

void change_password() {
    User personal;
    file_unlock(secret_path);
    personal.read(secret_path);         //add 
    personal.change_password();          //add
    personal.write(secret_path);        //add
}

void change_info() {
    User personal;
    file_unlock(secret_path);
    personal.read(secret_path);
    std::string str;
    std::cout << "Enter new info\n";
    std::cin >> str;
    personal.information = str;
    personal.write(secret_path);
}

void change_ava() {
    User personal;
    file_unlock(secret_path);
    personal.read(secret_path);
    std::string str;
    std::cout << "Enter new path_ava\n";
    std::cin >> str;
    personal.avatar = str;
    personal.write(secret_path);
}

void change_melody() {
    User personal;
    file_unlock(secret_path);
    personal.read(secret_path);
    personal.change_melody();           //add 
    personal.write(secret_path);
}

void change_nickname() {
    User personal;
    file_unlock(secret_path);
    personal.read(secret_path);
    std::string str;
    std::cout << "Enter new nickname\n";
    std::cin >> str;
    personal.nickname = str;
    personal.write(secret_path);

}

void change_name() {
    User personal;
    file_unlock(secret_path);
    personal.read(secret_path);
    std::string str;
    std::cout << "Enter new name\n";
    std::cin >> str;
    personal.name = str;
    personal.write(secret_path);
}

void change_data(screen::Background& window, int W, int H) {
    sf::Font font;
    std::string str, s1, s2, s3, s4, s5, s6;
    User personal;
    file_unlock(secret_path);
    personal.read(secret_path);
    s1 = "Name: " + personal.name + "\n";
    s2 = "Information: " + personal.information + "\n";
    s3 = "Nickname: " + personal.nickname + "\n";
    s4 = personal.avatar;
    screen::Point vert(300, 0);
    screen::Icons ava(s4, vert);
    str = s1 + s2 + s3;
    sf::Text text(str, font);
    text.setFont(font);
    text.setCharacterSize(30);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::Black);
    font.loadFromFile(path_to_font);
    while( window.is_open() ) {
        window.draw_on_window(Background_test);
        window.handler_button();
        ava.draw_object(window.Get_window());
        window.Get_window().draw(text);
        window.display();
    }
    window.my_clear();
}

        




/*
void change_data(screen::Background &window, int W, int H) {
    //add func read in encoded_data
    window.draw_on_window(pers_settings_joke1, 0, 390);
    window.draw_on_window(pers_settings_joke2, 450, 200);
    screen::Icons ava(pers_settings_ava, screen::Point(10, 10));
    screen::Icons name_box(pers_settings_name_box, screen::Point(10, 400));
    window.draw_on_window("Name", 45, sf::Vector2f(137, 400));                      //draw text
    screen::Icons password(pers_settings_password, screen::Point(10, 500));
    screen::Icons nickname(pers_settings_nickname, screen::Point(450, 10));
    screen::Icons info(pers_settings_info, screen::Point(450, 130));
    screen::Icons melody_box(pers_settings_melody_box, screen::Point(10, 600));
    window.draw_on_window("", 45, sf::Vector2f(128, 600));                          //draw text
    screen::Button public_data(ava);
    std::cout << "WORK\n";
    std::cout << name_box.path_to_image << std::endl;
    public_data.insert(name_box);
    public_data.insert(password);
    public_data.insert(nickname);
    public_data.insert(info);
    public_data.insert(melody_box);
    public_data.draw_objects(window.Get_window());
    window.display();
    while (window.is_open()) {
        sf::Event event;
        std::string player_input;
        sf::Text player_text;
        while (window.Get_window().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.Get_window().close();            //Issue: add my_CLOSE
            } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i position_mouse = sf::Mouse::getPosition(window.Get_window());
                if (ava.click(position_mouse, window) == true) {
                    std::cout << "ava\n";
                    change_ava();
                    //change_ava        //ISsue: add funk
                } else if (name_box.click(position_mouse, window) == true) {
                    std::cout << "name\n";
                    change_name();

                } else if (info.click(position_mouse, window) == true) {
                    std::cout << "info\n";
                    change_info();
                } else if (nickname.click(position_mouse, window) == true) {
                    std::cout << "nickname\n";
                    change_nickname();
                } else if (password.click(position_mouse, window) == true) {
                    std::cout << "password\n";
                    change_password();
                } else if (melody_box.click(position_mouse, window) == true) {
                    std::cout << "melody box\n";
                    change_melody();
                }
            }
        }
        //window.display();
        // ISSUE: Add metod in class Icons of situation Icons and click on          //added
        // Issue: Add all work_background in RGB:6699CC                             //added
        // add in here: handler
    }
}
*/
void check(int &H, int &W) {
    if (global_sign == 0) {
        H = 500;
        W = 500;
    } else {
        W = 1240;
        H = 700;
    }
    W = 1240;
    H = 700;
}

void personal_settings() {
    int H, W;
    check(H, W);
    std::cout << H << "    " << W << std::endl; ///Issue: add normal full size window           //added
    screen::Background settings_window(W, "Personal Settings", H);
    while (settings_window.is_open()) {
        settings_window.handler_button();
        settings_window.draw_on_window(Background_test);
        settings_window.display();
        if (global_have == 0) {
            wait_sign(settings_window, W, H);
        } else if (global_have == 1) {
            change_data(settings_window, W, W);
        }
    }
}
