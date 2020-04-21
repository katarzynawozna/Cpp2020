#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>
using namespace std::chrono;

int fibo1 (int n){

    int nth;

    if (n == 0){
        return 0;
    }
    else if (n == 1){
        return 1;
    }
    else
    {
        return fibo1(n-1) + fibo1(n-2);
    }
    
}

int fibo2 (int n){

    int nth = 1/sqrt(5) * ( pow( (1+sqrt(5.0))/2, n) - pow( (1.0-sqrt(5))/2, n) );
    
    return nth;

}

int fibo3 (int n) {
    
    const int size = 48;
    static bool first = true;
    static std::vector<int> fn(size);
    if (first)
    {
        first =  false;
        for(int i = 0; i < size; i++)
        {
            fn[i] = 1/sqrt(5) * ( pow( (1+sqrt(5.0))/2, n) - pow( (1.0-sqrt(5))/2, n) );
        }
    }
    return fn[n];

}

int main(){

    auto start1 = high_resolution_clock::now();
    fibo1(48);
    auto stop1 = high_resolution_clock::now();

    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    auto start2 = high_resolution_clock::now();
    fibo2(48);
    auto stop2 = high_resolution_clock::now();

    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    
    auto start3 = high_resolution_clock::now();
    fibo3(48);
    auto stop3 = high_resolution_clock::now();

    auto duration3 = duration_cast<microseconds>(stop3 - start3);

    std::cout << "Fibo1 duration time: " << duration1.count() << " microseconds." << "\n";
    std::cout << "Fibo2 duration time: " << duration2.count() << " microseconds." << "\n";
    std::cout << "Fibo3 duration time: " << duration3.count() << " microseconds." << "\n";
}