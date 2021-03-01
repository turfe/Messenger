#include <fstream>
#include <string>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>


void encoder(std::string &input, std::string &key, std::string &output) {
    int n = std::min(input.length(), key.length());
    int test;
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

int main() {
    char pathname[] = "encoded_data/encoded_data.txt";
    int status;
    status = unlink(pathname);
    if(status != 0) {
    	std::cout << "unlink ERROR" << '\n';
    }
    file_unlock(pathname);
    std::ifstream fin("data.txt");
    std::ofstream fout("encoded_data/encoded_data.txt");
    if(!fin) return 1;
    if(!fout) return 1;
    std::string buffer, key, password, unique_nickname, number_phone, melody;
    for(int i = 0; i < 4; i++) {
        std::getline(fin, buffer);
    }
    std::getline(fin, key);
    std::getline(fin, buffer);
    encoder(buffer, key, password);
    std::getline(fin, buffer);
    encoder(buffer, key, unique_nickname);
    std::getline(fin, buffer);
    encoder(buffer, key, number_phone);
    std::getline(fin, buffer);
    encoder(buffer, key, melody);
    fout << key << "\n"<< password << "\n" << unique_nickname << "\n" << number_phone << "\n" << melody << "\n";
    
    fout.close();
    fin.close();
    file_lock(pathname);
}
