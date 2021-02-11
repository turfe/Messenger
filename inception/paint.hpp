#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//#include <SFML/Mouse.hpp>

#define path_to_melody_one "/home/ravil/chat/data/sounds/sqwoz_woman.wav"
#define path_to_fon "/home/ravil/chat/data/image/fon_memecria3.jpg"
#define path_to_sound "/home/ravil/chat/data/image/icon_sound.jpg"


namespace screen {
    class Background {
        private:
            sf::RenderWindow window;
            void play_sound();
        public:
            Background(int height, int width) : window(sf::VideoMode(height, width), "MEMECRIA") {}
            void draw_on_window(const char path_to_image[]);
            void draw_on_window(const char path_to_image[], int x, int y);
            void draw_on_window(sf::Color colour);
            void handler_button();
            bool is_open() const;
            void display();
            void enter_button(sf::Vector2i vec);
    };
    
    void Background::draw_on_window(const char path_to_image[]) {
        sf::Texture image;
        image.loadFromFile(path_to_image);
        sf::Sprite sprite_image;
        sprite_image.setTexture(image);
        sprite_image.setPosition(0, 0);
        window.draw(sprite_image);
    }
    
    void Background::draw_on_window(const char path_to_image[], int x, int y) {
        sf::Texture image;
        image.loadFromFile(path_to_image);
        sf::Sprite sprite_image;
        sprite_image.setTexture(image);
        sprite_image.setPosition(x, y);
        window.draw(sprite_image);
    }
    
    void Background::draw_on_window(sf::Color colour) {
        window.clear(colour);
    }

    void Background::handler_button() {
        sf::Event event;
        while ( window.pollEvent(event) ) {
            if ( event.type == sf::Event::Closed ) {
                window.close();
            }
            else if ( event.type == sf::Event::KeyPressed ) {
                play_sound();
            }
            else if ( sf::Mouse::isButtonPressed(sf::Mouse::Left) ) {
                std::cout << "LEFT CLICK" << std::endl;
                sf::Vector2i position_mouse = sf::Mouse::getPosition(window);
                //std::cout << position_mouse.x << "= x\n" << position_mouse.y << "= y\n" << std::endl;
                enter_button(position_mouse);
            }
        }
    }

    bool Background::is_open() const {
        return window.isOpen();
    }

    void Background::display() {
        window.display();
    }
    //эти глобальные переменные необходимы для проигрывания саунда
    //issue: add melody in global_variables
    sf::Sound ringthone_one;
    sf::SoundBuffer melody_one;

    void Background::play_sound() {
        if ( !melody_one.loadFromFile(path_to_melody_one) ) {
            std::cout << "ERROR. Melody_one isn't detected" << std::endl;
        }
        ringthone_one.setBuffer(melody_one);
        ringthone_one.play();
    }

    void Background::enter_button(sf::Vector2i position) {
        float X = position.x;
        float Y = position.y;
        if ( (X > 0) & (Y > 0) & (X < 150) & (Y < 150) ) {
            std::cout << "ENTER BUTTON\n";
        }
    }
}


