#include <iostream>
#include <climits>
#include <vector>

int smallest_value(std::vector<int> x){

    int smallest_value = x[0];

    if (!x.empty()){
        for (int i = 0; i < x.size()-1; ++i){
            if (smallest_value > x[i+1]){
                smallest_value = x[i+1];
            }
        }
        return smallest_value; 
        }

    else {
        return INT_MIN;
    }

}

int main(){
    std::vector<int> x = {892, 234, 3, -123, 5};
    std::cout << smallest_value(x) << "\n";

}