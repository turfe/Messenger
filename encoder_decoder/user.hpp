#pragma once
#include <string>
#define secret_path "../inception/data/user/.user.txt"

class User {
    public:
        std::string name;
        std::string information;
        std::string nickname;
        std::string avatar;
    private:                                  //to keep this info in encode type
        std::string key;
        std::string password;
        std::string unique_nickame;
        std::string melody;
};
