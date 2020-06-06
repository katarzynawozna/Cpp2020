#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    //new and delete

    auto t_indicators1 = chrono::high_resolution_clock::now();

    for(unsigned n = 1; n <= 4000000; ++n)
    {
        int *p = new int[n];
        delete [] p;
    }

    auto t_indicators2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(t_indicators2 - t_indicators1).count();
    
    //addition

    int x = 0;
    auto t_addition1 = chrono::high_resolution_clock::now();

    for (unsigned n = 1; n < 4000000; ++n)
    {
        x = x + 50;
    }

    auto t_addition2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(t_addition2 - t_addition1).count();

    cout << "Time using new and delete: " << duration << "\n";
    cout << "Time using additon: " << duration2 << "\n";

    //Program używający dodawania wykonuje się zdecydowanie szybciej, niż ten z new i delete.

    return 0;
}
