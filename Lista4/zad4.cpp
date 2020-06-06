#include <iostream>

using namespace std;

int main()
{
    double tab[10];
    double x;

    cout << &x << "\t" << &tab[-1] << "\n";
    return 0;
}

    //Dostajemy adres komórki w pamięci zmiennej x, który w moim przypadku jest taki sam, jak zmyślony adres tab[-1]. Dzieję się tak dlatego, że dostajemy lokalizację pierwszego elementu i pierwszego elementu tablicy rzeczywistej [0] minus rozmiar jednego elementu. W zależności od kompiltora, może do doprowadzić do nadpisania danych w pamięci.
