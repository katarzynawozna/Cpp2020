#include <iostream>
#include <fstream>
#include <string>

int main(){
    
    std::cout << "Podaj nazwę pliku:" << std::endl;
    std::string file_name;
    std::cin >> file_name;    
    std::ifstream File(file_name);
    std::string text;
    std::string coded_text;
    getline(File, text);
    
    for (int i = 0; i <= text.size()-1; ++i){
        char z = text[i];
        z += 13;
        coded_text += z;
    }

    std::ofstream Coded_File("bezpiecznysekret.txt");
    Coded_File << coded_text;

}