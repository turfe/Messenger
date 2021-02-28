#include "paint.hpp"
#include "personal_settings.hpp"

void check_personal() {
    if (global_personal == 1) {
        personal_settings();
        global_personal = 0;
    }
    /*
    else if ( global_personal >= 2 ) {
        std::cout << "ERROR IN OPEN PERSONAL_SETTINGS\n";
    }
    */
}

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
    screen::Background window(1240, 740);
    //window.draw_on_window(sf::Color::Green);
    //window.draw_on_window(path_to_background);
    while (window.is_open()) {
        check_personal();
        /*sf::Event event;
        while ( window.pollEvent(event) ) {
            if ( event.type == sf::Event::Closed )
                window.close();
        }
        */
        window.handler_button_start();
        window.draw_on_window(Background_test);
        window.draw_on_window(path_to_new_background); //change_logo
        //window.draw_on_window(path_to_sound, 200, 200);
        //window.draw(sprite_fon);
        //window.draw(shape);
        window.display();
    }
    return 0;
}
