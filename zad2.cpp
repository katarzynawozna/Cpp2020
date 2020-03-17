#include <iostream>
#include <math.h>

int main(){

    // wzór a

    float sum_a = 0;
    float sum_b = 1;
    float sum_c = 0;
    float top = 0;

    for (int j = 1; j <= 1000000; ++j){
        if (((j+1) % 2) == 0) {
            top = 1;
        }
        else {
            top = -1;
        }

        sum_a += top/((2*j)-1);
    }

    sum_a = 4*sum_a;

    std::cout << sum_a << std::endl;

    // wzor b

    for (int j = 1; j <= 1000000; ++j){
        float suma = ((4*(pow(j,2)))/((4*(pow(j, 2)))-1));
        sum_b *= suma;
    }

    sum_b = 2*sum_b;
    
    std::cout << sum_b << std::endl;

    // wzor c

    for (int j = 1; j <= 1000000; ++j){
        sum_c += 1/pow((2*j - 1), 2);
    }

    sum_c = pow((sum_c*8), 0.5);

    std::cout << sum_c << std::endl;

    return 0;
}