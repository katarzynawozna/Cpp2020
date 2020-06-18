#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float x;
    float y;
    float r;
    float alfa;
    float sinus;

    cout << "Podaj wspolrzedna x:" << endl;
    cin >> x;
    cout << "Podaj wspolrzedna y:" << endl;
    cin >> y;

    r = pow((x*x)+(y*y),(0.5));

    cout << "Odleglosc od punktu (0,0): " << r << endl;

    sinus = y/r;

    alfa = asin(sinus) * 180 / M_PI ;

    cout << "Kąt miedzy osią x a ramieniem wynosi " << alfa << " stopni." << endl;
   
    return 0;
}
