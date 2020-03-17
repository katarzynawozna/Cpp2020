#include <iostream>
#include <math.h>

float pi_a = 0;
float pi_b = 0;
float ti;


float ta(int i){
    if (i == 0){
            ti = 1/(pow(3, 0.5));
        }
    else {
            ti = (pow(pow(ta(i-1), 2)+1, 0.5)-1)/ta(i-1);
        }

    return ti;
}

float tb(int i){
    if (i == 0){
        ti = 1/(pow(3, 0.5));
    }
    else {
        ti = tb(i-1)/(pow(pow(tb(i-1), 2)+1, 0.5)+1);
    }

    return ti;
}

int main(){

    

    for (int i = 0; i <= 30; ++i){
        pi_a = 6*pow(2, i)*ta(i);
        pi_b = 6*pow(2, i)*tb(i);
        std::cout << i << "a. " << pi_a << std::endl;
        std::cout << i << "b. " << pi_b << std::endl;
    }


}