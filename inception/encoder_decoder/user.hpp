#pragma once

class User {
    public:
        std::string name;
        std::string family;
        std::string informaion;
        std::string nickname;
        std::string avatar;
    private:                                //to keep this info in encode type
        std::string password;
        std::string unique_nickame;
        std::string number_phone;
}
