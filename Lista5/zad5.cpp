#include <iostream>

using namespace std;

class Samochod
{

public:
    Samochod (int n)
    : _kola (n), _sruby (4*n)
    {
      std::cout << "Samochód z " << _kola << " kolami i " << _sruby << " srubami \n";
    }

private:

    int _sruby;
    int _kola;

  
};

int main()
{
    //Błędem (jedyny jaki udało mi się znaleźć) w klasie Samochod.h było to, że argument _sruby(4*_kola) przyjmował zły arugment - zamiast (4*_kola) - powinno byc _sruby(4*n).
    
    Samochod s4 (4);
    Samochod s12(12);
    
    return 0;
}
