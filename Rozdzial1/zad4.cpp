#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float a,b,c, delta, x1,x2;

    cout << "Wspolczynnik a funkcji kwadratowej:" << endl;
    cin >> a;

    cout << "Wspolczynnik b funkcji kwadratowej:" << endl;
    cin >> b;

    cout << "Wspolczynnik c funkcji kwadratowej:" << endl;
    cin >> c;

    if (a == 0)
    {
        cout << "To nie jest funkcja kwadratowa!" << endl;
    }

    else
    {
        delta = b*b - (4*a*c);

        if (delta < 0)
        {
            cout << "Brak miejsc zerowych" << endl;
        }

        if (delta == 0)
        {
            x1 = -1 * b / (2*a);
            cout << "Jedno miejsce zerowe: " << x1 << endl;
        }

        if (delta > 0)
        {
            x1 = (-1*b - pow(delta,0.5)) / (2*a);
            x2 = (-1*b + pow(delta,0.5)) / (2*a);
            cout << "Dwa miejsca zerowe: " << x1 << ", " << x2 << endl;

        }
        
        
    }
    
    
    return 0;
}
