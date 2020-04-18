#include <iostream>
#include <string>
#include <fstream>

int main() {

   std::string coded_text;
   std::ifstream File("bezpiecznysekret.txt");
   getline(File, coded_text);
   
   std::string decoded_text;
   for (int i = 0; i <= coded_text.size()-1; ++i){
       char z = coded_text[i];
       z -= 13;
       decoded_text += z;
   }

   std::ofstream Decoded_File("zhakowanysekret.txt");
   Decoded_File << decoded_text;

}