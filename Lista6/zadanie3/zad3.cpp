#include <iostream>
#include "stos_lista.h"

int main()
{
    Stos stos;

    for(int i = 25; i > 0; i -= 5)
    {
        stos.push(i);
    }

    std::cout << stos << "\n";

}
