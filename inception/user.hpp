#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include "global_variables.hpp"
//char secret_path[] = "/inception/data/user/user.txt";

void encoder(std::string &input, std::string &key, std::string &output);
void decoder(std::string &input, std::string &key, std::string &output);
void file_lock(char* s);
void file_unlock(char* s);

class User {
    public:
        User(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6);
        User();
        std::string name;
        std::string information;
        std::string nickname;
        std::string avatar;
        void read(std::string path);
        void write(std::string path);
        void change_password();
        void change_melody();
    private:                                  //to keep this info in encode type
        std::string key = "9PyA[Z]LAq*yimdfUQ0.Fv9o1ykI6C;J(VNyLY7kf3UGj)z0_N7SEqZbZy%s86ROQoxFi3<fgh";
        std::string password;
        std::string unique_nickname;
        std::string melody;
};
