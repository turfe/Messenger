#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define path_to_melody_one "/home/ravil/chat/data/sounds/sqwoz_woman.wav"
#define path_to_fon "/home/ravil/chat/data/image/fon_memecria.jpg"
#define path_to_sound "/home/ravil/chat/data/image/icon_sound.jpg"


namespace screen {
    class Background {
        private:
            sf::RenderWindow window;
            void play_sound();
        public:
            Background(int height, int width) : window(sf::VideoMode(height, width), "MEMECRIA") {}
            //sf::RenderWindow create(int height, int width);
            void draw_on_window(const char path_to_image[]);
            void draw_on_window(const char path_to_image[], int x, int y);
            void draw_on_window(sf::Color colour);
            void handler_button();
            bool is_open() const;
            void display();
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
        }
    }

    bool Background::is_open() const {
        return window.isOpen();
    }

    void Background::display() {
        window.display();
    }
    
    sf::Sound ringthone_one;
    sf::SoundBuffer melody_one;

    void Background::play_sound() {
        //sf::SoundBuffer melody_one;
        if ( !melody_one.loadFromFile(path_to_melody_one) ) {
            std::cout << "ERROR. Melody_one isn't detected" << std::endl;
        }
        //saf::Sound ringthone_one;
        ringthone_one.setBuffer(melody_one);
        ringthone_one.play();
    }
}


