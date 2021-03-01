#pragma once

#include "global_variables.hpp"
#include <fstream>
#include <iostream>

void sign() {
    std::ofstream File;
    std::string s1, s2, s3, s4, s5, s6;
    int a = 0;
    screen::Background sign(1240, "SIGN", 700);
    while ( sign.is_open() & ( a != 1 ) ) {
        sign.handler_button();
        sign.draw_on_window(Background_test);
        sign.display();
        std::cout << "Enter name\n";
        std::cin >> s1;
        std::cout << " Enter information\n";
        std::cin >> s2;
        std::cout << " Enter nickname\n";
        std::cin >> s3;
        std::cout << " Enter avatar\n";
        std::cin >> s4;
        std::cout << " Enter password\n";
        std::cin >> s5;
        std::cout << "Enter melody\n";
        std::cin >> s6;
        a = 1;
    }
    User personal(s1, s2, s3, s4, s5, s6);
    personal.write(secret_path);
    global_sign = 0;
}


