#include "paint.hpp"
#include "personal_settings.hpp"
#include "sign.hpp"

void check_personal(screen::Background &window) {
    if ( global_personal == 1 )  {
        std::cout << "global_personal" << std::endl;
        //window.my_clear();
        personal_settings();
        global_personal = 0;
    }
    if ( ( global_sign == 1 ) && ( global_have == 0 ) ) {
        std::cout << "global_sign\n";
        window.my_clear();
        sign_reg();
    }
    if ( ( global_sign == 1 ) && ( global_have == 1 ) ) {
        window.my_clear();
        sign_enter();
    }
}

int main() {
    global_have = 0;
    std::ofstream check(secret_path);
    if ( !check ) {
        global_have = 1;
    }
    screen::Background window(1240, 740);
    while (window.is_open()) {
        check_personal(window);
        window.handler_button_start();
        window.draw_on_window(Background_test);
        window.draw_on_window(path_to_new_background); //change_logo
        window.display();
    }
    return 0;
}
