#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>

#define DELETE 8
#define ENTER 13
#define ESCAPE 27


class Textbox {
private:
    sf::Text textbox;
    std::ostringstream text;
    bool isSelected = false;
    bool hasLimit = false;
    int limit;

    void input_logic(int symbol) {
        if (symbol != DELETE && symbol != ENTER && symbol != ESCAPE) {
            text << static_cast<char>(symbol);
        } else if (symbol == DELETE) {
            if (text.str().length() > 0) {
                delete_last_symbol();
            }
        }
        textbox.setString(text.str() + "/");
    }

    void delete_last_symbol() {
        std::string str = text.str();
        std::string new_str;
        for (int i = 0; i < str.length() - 1; i++) {
            new_str += str[i];
        }
        text.str("");
        text << new_str;

        textbox.setString(text.str());
    }

public:
    Textbox() {}

    Textbox(const sf::Font &font, int size, bool select, sf::Vector2f position, int input_limit) {
        textbox.setFont(font);
        textbox.setCharacterSize(size);
        textbox.setFillColor(sf::Color::Black);
        textbox.setPosition(position);
        isSelected = select;
        limit = input_limit;
        if (select) {
            textbox.setString("_");
        } else {
            textbox.setString("");
        }
    }

    Textbox(const Textbox &copy_textbox) {
        textbox = copy_textbox.textbox;
        text << copy_textbox.text.str();
        isSelected = copy_textbox.isSelected;
        hasLimit = copy_textbox.hasLimit;
        limit = copy_textbox.limit;
    }

    void setLimit(bool tof) {
        hasLimit = tof;
    }

    void setLimit(bool tof, int input_limit) {
        hasLimit = tof;
        limit = input_limit - 1;
    }

    void erase_text() {
        text.str("");
    }

    void setPosition(sf::Vector2f pos){
        textbox.setPosition(pos);
    }

    void setSelected(bool select) {
        isSelected = select;
        if (!select) {
            std::string str = text.str();
            std::string new_str = "";
            for (int i = 0; i < str.length() - 1; ++i) {
                new_str += str[i];
            }
            textbox.setString(new_str);
        }
    }

    std::string getText() {
        return text.str();
    }

    void draw(sf::RenderWindow &window) {
        window.draw(textbox);
    }

    void type_text(sf::Event event) {
        if (isSelected) {
            int typed_symbol = event.text.unicode;
            if (typed_symbol < 128) {
                if (hasLimit) {
                    if (text.str().length() <= limit) {
                        input_logic(typed_symbol);
                    } else if (text.str().length() > limit && typed_symbol == DELETE) {
                        delete_last_symbol();
                    }
                } else {
                    input_logic(typed_symbol);
                }
            }
        }
    }
};