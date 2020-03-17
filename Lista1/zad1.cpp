#include <iostream>

int main(){

    int k;

    for (int n = 0; n < 40; ++n){
        if (n == 0){
            k = 1;
        }
        else {
            k *= n;
            }
    
    std::cout << n << "! = " << k << std::endl; 
    }

    return 0;
}