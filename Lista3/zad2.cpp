#include <iostream>
#include <vector>

std::vector<double> all_zeros(std::vector<double> &x){

    for (int i = 0; i < x.size(); ++i){

        x[i] = 0;
    }

    return x;
}

int main(){

    std::vector<double> a = {1, 2, 3, 4};
    all_zeros(a);

    for (int i = 0; i < a.size(); ++i){
        std::cout << a[i] << "\n";
    }

}