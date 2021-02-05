#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(350, 350), "MEMEKRIA");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
    sf::Texture fon;
    std::string path_to_fon = "/home/ravil/chat/image/fon_memecria.jpg";
    fon.loadFromFile(path_to_fon);
    sf::Sprite sprite_fon;
    sprite_fon.setTexture(fon);
    sprite_fon.setPosition(0, 0);

    while ( window.isOpen() ) {
        sf::Event event;
        while ( window.pollEvent(event) ) {
            if ( event.type == sf::Event::Closed )
                window.close();
        }
        window.clear(sf::Color::Green);
        window.draw(sprite_fon);
        //window.draw(shape);
        window.display();
    }
    return 0;
}
