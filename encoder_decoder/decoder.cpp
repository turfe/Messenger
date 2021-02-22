#include <fstream>
#include <string>
#include <iostream>

void decoder(std::string &input, std::string &key, std::string &output) {
    int n = input.length();
    for(int i = 0; i < n; i++) {
        output.push_back((-input[i]) ^ key[i]);
    }
}

int main() {
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
}
