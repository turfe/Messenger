#include <fstream>
#include <string>
#include <iostream>
#include <sys/stat.h>


void decoder(std::string &input, std::string &key, std::string &output) {
    int n = std::min(input.length(), key.length());
    int shift = key[0] - '0';
    for(int i = 0; i < n; i++) {
        if(input[i] - shift < -128) {
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
    status = chmod(pathname, 770);
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

int main() {
    char pathname[] = "encoded_data/encoded_data.txt";
    file_unlock(pathname);
    std::ifstream fin("encoded_data/encoded_data.txt");
    std::ofstream fout("decoded_data.txt");
    if(!fin) return 1;
    if(!fout) return 1;
    std::string buffer, key, password, unique_nickname, number_phone, melody;
    std::getline(fin, key);
    std::getline(fin, buffer);
    decoder(buffer, key, password);
    std::getline(fin, buffer);
    decoder(buffer, key, unique_nickname);
    std::getline(fin, buffer);
    decoder(buffer, key, number_phone);
    std::getline(fin, buffer);
    decoder(buffer, key, melody);
    fout << key << "\n"<< password << "\n" << unique_nickname << "\n" << number_phone << "\n" << melody << "\n";
    
    fout.close();
    fin.close();
    file_lock(pathname);
}
