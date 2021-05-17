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

User::User(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6) : 
    name(s1), information(s2), nickname(s3), avatar(s4), password(s5), unique_nickname(s1 + s2), melody(s6) {}

User::User() : 
    name(""), information(""), nickname(""), avatar(""), password(""), unique_nickname(""), melody("") {}

void User::write(std::string path) {
    std::ofstream fout(path);
    std::cout << "PATH "<< path << "\n";
    if ( !fout ) {
        std::cout << "ERROR write user.hpp\n";
    }
    std::cout << key << " KEYS\n";
    std::string buffer;
    fout << name << "\n" << information << "\n" <<  nickname << "\n" << avatar << "\n" << key << "\n";
    encoder(buffer, key, password);
    encoder(buffer, key, unique_nickname);
    encoder(buffer, key, melody);
    fout << key << "\n"<< password << "\n" << unique_nickname << "\n" << "\n" << melody << "\n";
    fout.close();
    file_lock(secret_path);
}

void User::read(std::string path) {
    std::ifstream fin(secret_path);
    if( !fin ) {
        std::cout << "ERROR\n";
    }
    std::string buffer, _key, _password,  _melody, _name, _information, _avatar, _nickname;
    std::getline(fin, _name);
    name = _name;
    std::getline(fin, _information);
    information = _information;
    std::getline(fin, _nickname);
    nickname = _nickname;
    std::getline(fin, _avatar);
    avatar = _avatar;
    std::getline(fin, key);
    std::getline(fin, buffer);
    decoder(buffer, key, password);
    std::getline(fin, buffer);
    decoder(buffer, key, unique_nickname);
    std::getline(fin, buffer);
    decoder(buffer, key, melody);
    fin.close();
    unlink(secret_path);
}

void User::change_password() {
    std::cout << "ENTER NEW PASSWORD\n";
    std::string s;
    std::cin >> s;
    password = s;
}

void User::change_melody() {
    std::cout << "Enter New melody\n";
    std::string s;
    std::cin >> s;
    information = s;
}

void encoder(std::string &input, std::string &key, std::string &output) {
    int n = std::min(input.length(), key.length());
    for(int i = 0; i < n; i++) {
        output.push_back(-(input[i] ^ key[i]));
    }
    for(int i = 0; i <= (n / 2) - 1; i++) {
        char temp;
        temp = output[i];
        output[i] = output[n - i - 1];
        output[n - i - 1] = temp;
    }

    int shift = key[0] - '0';
    for(int i = 0; i < n; i++) {
        if(output[i] + shift > -1) {
            output[i] = output[i] + shift - 128;
        }
        else {
            output[i] = output[i] + shift;
        }
    }
}

void decoder(std::string &input, std::string &key, std::string &output) {
    int n = std::min(input.length(), key.length());
    int shift = key[0] - '0';
    for(int i = 0; i < n; i++) {
        if(input[i] - shift < -127) {
            input[i] = input[i] + 128 - shift;
        }
        else {
            input[i] = input[i] - shift;
        }
    }
    for(int i = 0; i <= (n / 2) - 1; i++) {
        char temp;
        temp = input[i];
        input[i] = input[n - i - 1];
        input[n - i - 1] = temp;
    }
    for(int i = 0; i < n; i++) {
        output.push_back((-input[i]) ^ key[i]);
    }
}


void file_unlock(char* pathname) {
    int status;
    status = chmod(pathname, 777);
//    if(status != 0) {
//        std::cout << "folder_unlock ERROR" << '\n';
//    }
}

void file_lock(char* pathname) {
    int status;
    status = chmod(pathname, 000);
//    if(status != 0) {
//        std::cout << "folder_lock ERROR" << '\n';
//    }
}


