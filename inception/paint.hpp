/*
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iterator>


#define path_to_melody_one "data/sounds/sp-cheers.wav"
#define path_to_background "data/image/fon_memecria3.jpg"
#define path_to_sound "data/image/icon_sound.jpg"

//эти глобальные переменные необходимы для проигрывания саунда
//issue: add melody in global_variables //closed
sf::Sound ringthone_one;
sf::SoundBuffer melody_one;
sf::Vector2u pos;
*/

#pragma once

#include "global_variables.hpp"

namespace screen {
    class Background;
}


namespace screen {       // Everything required for screen operation is stored here 
    class Point {                                                                               // Class for storing information about a single 2D point
    private:
        double x, y;                                                                        // Coordinates
    public:
        Point(double _x, double _y);                                    // Constructor
        Point() : x(0), y(0) {}                                                             // Another constructor
        sf::Vector2u getPoint();

        float getX() const;

        float getY() const;

        ~Point();
    };                                                                                          //

    class Icons {                                                                               // Everything required for operations with images is stored here
    public:
        std::string path_to_image;                                                          // Path to the file containing image
        double height, width;                                                               // Image's height and width in pixels
        Point vertex;                                                                       // This point represents the upper left corner of the image
    public:                                                                                 //
        Icons(std::string path);                                                            // 3 different constructors
        Icons(std::string path, Point _vertex);                                             //
        Icons(std::string path, Point _vertex, double _height, double _width);

        void draw_object(sf::RenderWindow &wind); //add func //added
        bool click(sf::Vector2i position_mouse, Background &wind) const; //
        void display_text(sf::Event &event, sf::String player_input, sf::Text player_text);

        float Get_main_x();

        float Get_main_y();

        ~Icons();
    };

    class Button {                                                                              // Everything required for operations with buttons is stored here
    private:                                                                                //
        std::vector<Icons> Buttons;                                                         // Single vector contains information about all buttons
    public:                                                                                 //
        Button(Icons _icon);                                                                // 2 constructors
        Button();                                                                           //
        void insert(Icons icon);

        void draw_objects(sf::RenderWindow &wind);

        ~Button();
    };                                                                                          //

    class Background {                                                                          // Class used for operations with background
    private:                                                                                //
        sf::RenderWindow window;                                                          // Reference: https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderWindow.php
        void play_sound(); // Different functions used for interaction with the active window
        //void my_clear();
        sf::Vector2u Begin_size;
        float kx;
        float ky;
    public:                                                                                 //
        Background(int height, int width);
        Background(int height, std::string name, int width);
        void draw_on_window(const char path_to_image[]);                                    //
        void draw_on_window(const char path_to_image[], int x, int y);                      //
        void draw_on_window(sf::Color colour);

        void draw_on_window(std::string text, int pixel_size, sf::Vector2f position);//
        void handler_button_start();                                                              //
        void handler_button();

        bool is_open();                                                               //
        void display();                                                                     //
        void enter_button_start(sf::Vector2i vec);                                                //
        void my_clear();

        sf::RenderWindow& Get_window();

        float Get_kx() const;

        float Get_ky() const;

        //void close_window();
        ~Background();
    };

    /*
    //эти глобальные переменные необходимы для проигрывания саунда
    //issue: add melody in global_variables
    sf::Sound ringthone_one;
    sf::SoundBuffer melody_one;
    */

/*
    sf::RenderWindow Background::getWindow() {
        return &window;
    }
*/
}

