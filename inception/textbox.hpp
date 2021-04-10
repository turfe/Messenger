#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>

#define DELETE 8
#define ENTER 13
#define ESCAPE 29


class Textbox {
private:
    sf::Text textbox;
    std::ostringstream text;
    bool isSelected = false;
    bool hasLimit = false;
    int limit;

    void input_logic(int symbol);

    void delete_last_symbol();

public:
    Textbox();

    Textbox(const sf::Font &font, int size, bool select, sf::Vector2f position, int input_limit);

    Textbox(const Textbox &copy_textbox);

    void setLimit(bool tof);

    bool check_symbols();

    void setLimit(bool tof, int input_limit);

    void erase_text();

    void setPosition(sf::Vector2f pos);

    void setSelected(bool select);

    std::string getText();

    void draw(sf::RenderWindow &window);

    void type_text(sf::Event event);
};