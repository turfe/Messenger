#include <fstream>
#include <string>
#include <iostream>
#include <sys/stat.h>

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
