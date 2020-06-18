#include <iostream>
using namespace std;

int main()
{
    cout << "Podaj liczbę:" << endl;
    float x;
    cin >> x;
    float odw;

    
    if (x != 0)
    {
        odw = 1/x;
        cout << "Odwrotność tej liczby: " << odw << endl;
    }

    else
    {
        cout << "Odwrotność zera to zero, co nie" << endl;
    }
    
    return 0;
}
