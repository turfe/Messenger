#pragma once
#include <SFML/Graphics.hpp>

#define path_to_fon "/home/ravil/chat/image/fon_memecria.jpg"

namespace screen {
    class Background {
        private:
            sf::RenderWindow window;
        public:
            Background(int height, int width) : window(sf::VideoMode(height, width), "MEMECRIA") {}
            //sf::RenderWindow create(int height, int width);
            void draw_on_window(const char path_to_image[]);
            void draw_on_window(const char path_to_image[], int x, int y);
            void draw_on_window(sf::Color colour);
            void handler_exit();
            bool is_open() const;

    };
    /*
    sf::RenderWindow Background::create(int height, int width) {
        return sf::RenderWindow(sf::VideoMode(height, width), "MEMECRIA");
    }
    */
    void Background::draw_on_window(const char path_to_image[]) {
        sf::Texture image;
        image.loadFromFile(path_to_image);
        sf::Sprite sprite_image;
        sprite_image.setTexture(image);
        sprite_image.setPosition(0, 0);
        window.draw(sprite_image);
        window.display();
    }
    
    void Background::draw_on_window(const char path_to_image[], int x, int y) {
        sf::Texture image;
        image.loadFromFile(path_to_image);
        sf::Sprite sprite_image;
        sprite_image.setTexture(image);
        sprite_image.setPosition(x, y);
        window.draw(sprite_image);
        window.display();
    }
    
    void Background::draw_on_window(sf::Color colour) {
        window.clear(colour);
    }

    void Background::handler_exit() {
        sf::Event event;
        while ( window.pollEvent(event) ) {
            if ( event.type == sf::Event::Closed )
                window.close();
        }
    }

    bool Background::is_open() const {
        return window.isOpen();
    }
}


