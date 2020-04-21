#include <iostream>
#include <vector>

std::vector<double> operator* (std::vector<double> a, std::vector<double> b){

   std::vector<double> wynik (a.size());

    for (int i = 0; i < a.size(); ++i){
                wynik[i] = a[i]*b[i];
        }
    
    return wynik;

}

int main(){

    std::vector<double> a = {2, 2, 2};
    std::vector<double> b = {2, 2, 2};

    std::vector<double> c = a*b;

    for (int i = 0; i < c.size(); ++i){
        std::cout << c[i] << "\n";
    }

}

