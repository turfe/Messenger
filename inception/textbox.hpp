#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include "global_variables.hpp"

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

    void delete_last_symbol() {                                                 //Issue: to fix this O(n) function
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

    bool check_symbols(){
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
            for (int i = 0; i < str.length(); ++i) {
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

namespace sfC {
class Text_t final {
    public:
        Text_t(const std::string &file, unsigned int size, const sf::Vector2f &pos, const std::string &str = "");
        std::string get_text() const { return text_.getString(); }
        void set_text(const std::string &text) { text_.setString(text); }
        void push_back(const char cur_sym) { text_.setString(text_.getString() + cur_sym); }
        void update(sf::Event& event);
        void pop_back();
        void set_style(const sf::Uint32 &new_style) { text_.setStyle(new_style); }
        void set_color(const sf::Color &new_color) { text_.setFillColor(new_color); }
        const sf::Text &for_draw() const { return text_; }
        explicit operator bool () const noexcept { return !text_.getString().isEmpty(); }
        sf::Font font_;
        sf::Text text_;
    };
}

sfC::Text_t::Text_t(const std::string& file , unsigned int size , const sf::Vector2f& pos , const std::string& str /*= ""*/)
    : font_ () , text_ () {
        if (!font_.loadFromFile (file)) {
            std::cout << "Can't load text!\n";
    }
    text_.setCharacterSize (size);
    text_.setFont (font_);
    text_.setString (str);
    text_.setPosition (pos);
}

void sfC::Text_t::pop_back () {
    std::string temp = text_.getString ();
    if (!temp.empty ()) {
        temp.pop_back ();
        text_.setString (temp);
    }
}

bool IS_ASKII (const sf::Uint32& symbol) noexcept {
    return (symbol > 47 && symbol < 58) ||
            (symbol > 64 && symbol < 91) ||
            (symbol > 96 && symbol < 123) ||
            symbol == 95;
}

bool AnalyseWait_Text_User (sf::Window& window , std::string& text , sfC::Text_t& user_text) {
    sf::Event event;
    while (window.pollEvent (event)) {
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Escape:
                    text.clear ();
                    return false;
                    break;
                case sf::Keyboard::BackSpace:
                case sf::Keyboard::Delete:
                    text.pop_back ();
                    user_text.pop_back ();
                    break;
                default:
                    break;
                }
        }

        if (event.type == sf::Event::TextEntered) {
            if ( IS_ASKII (event.text.unicode)) {
                char cur_symbol = static_cast<char>(event.text.unicode);
                text.push_back (cur_symbol);
                user_text.push_back (cur_symbol);
            }
        }
    }
    return true;
}
