#include "paint.hpp"


int main() {
    /*
    //sf::RenderWindow window(sf::VideoMode(350, 350), "MEMEKRIA");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
    sf::Texture fon;
    fon.loadFromFile(path_to_fon);
    sf::Sprite sprite_fon;
    sprite_fon.setTexture(fon);
    sprite_fon.setPosition(0, 0);
    */
    //sf::RenderWindow window = screen::Background::create(350, 350); 
    screen::Background window(1240, 800);
    while ( window.is_open() ) {
        /*sf::Event event;
        while ( window.pollEvent(event) ) {
            if ( event.type == sf::Event::Closed )
                window.close();
        }
        */
        window.handler_button();
        window.draw_on_window(sf::Color::Green);
        window.draw_on_window(path_to_fon);
        //window.draw_on_window(path_to_sound, 200, 200);
        //window.draw(sprite_fon);
        //window.draw(shape);
        window.display();
    }
    return 0;
}
