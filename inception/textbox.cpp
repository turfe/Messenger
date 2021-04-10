#include "textbox.hpp"

void Textbox::input_logic(int symbol) {
    if (symbol != DELETE && symbol != ENTER && symbol != ESCAPE) {
        text << static_cast<char>(symbol);
    } else if (symbol == DELETE) {
        if (text.str().length() > 0) {
            delete_last_symbol();
        }
    }
    textbox.setString(text.str() + "/");
}

void Textbox::delete_last_symbol() {
    std::string str = text.str();
    std::string new_str;
    for (int i = 0; i < str.length() - 1; i++) {
        new_str += str[i];
    }
    text.str("");
    text << new_str;

    textbox.setString(text.str());
}

Textbox::Textbox(const sf::Font &font, int size, bool select, sf::Vector2f position, int input_limit) {
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

Textbox::Textbox(const Textbox &copy_textbox) {
    textbox = copy_textbox.textbox;
    text << copy_textbox.text.str();
    isSelected = copy_textbox.isSelected;
    hasLimit = copy_textbox.hasLimit;
    limit = copy_textbox.limit;
}

void Textbox::setLimit(bool tof) {
    hasLimit = tof;
}

bool Textbox::check_symbols(){
    bool result = false;
    std::string check_str = text.str();
    for (char i : check_str) {
        if (i < 32 || i > 126){
            result = true;
            return result;
        }
    }
    return result;
}

void Textbox::setLimit(bool tof, int input_limit) {
    hasLimit = tof;
    limit = input_limit - 1;
}

void Textbox::erase_text() {
    text.str("");
}

void Textbox::setPosition(sf::Vector2f pos){
    textbox.setPosition(pos);
}

void Textbox::setSelected(bool select) {
    isSelected = select;
    if (!select) {
        std::string str = text.str();
        std::string new_str = "";
        for (int i = 0; i < str.length(); ++i) {
            new_str += str[i];
        }
        textbox.setString(new_str);
    }
}

std::string Textbox::getText() {
    return text.str();
}

void Textbox::draw(sf::RenderWindow &window) {
    window.draw(textbox);
}

void Textbox::type_text(sf::Event event) {
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