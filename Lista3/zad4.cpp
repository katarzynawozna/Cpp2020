#include <iostream>

unsigned silnia(unsigned n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n * silnia(n-1);
    }
}

int main()
{
    for(int i = 0; i < 5; ++i)
    {
        std::cout << i << "! = " << silnia(i) << "\n";
    }
    silnia(-1);
    
//Oczekiwany wynik po wywołania powyższego programu to błąd, związany z przeciążeniem pamięci Segmetation fault (core dumped) w funkcji silnia spowodowany zastosowaniem typu unsigned (wynik nie może być liczba ujemną).

}
