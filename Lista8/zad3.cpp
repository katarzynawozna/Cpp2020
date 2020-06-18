#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

class PPMimage
{
public:
    struct Kolor { unsigned char red, green, blue; };

    PPMimage (const char nazwa_pliku[]);           // wczytuje obraz z pliku
    ~PPMimage();
    void zapisz(const char nazwa_pliku[]);         // zapisuje obraz w pliku
    void zmiekcz();
private:
    PPMimage(PPMimage const&) { }                  // nie wywołuj tej funkcji!
    void operator= (PPMimage const&) { }           // nie wywołuj tej funkcji!

    int      _szerokosc;    // liczba kolumn w obrazku
    int      _wysokosc;     // liczba wierszy w obrazku
    int      _glebia;       // głębia koloru
    Kolor**  _tab;
};

PPMimage::PPMimage(const char nazwa_pliku[])
{
    std::ifstream F(nazwa_pliku, std::ios::binary);  // '\n' zajmuje 1 bajt!
    std::string s;                                   // zmienna pomocnicza
    F >> s >> std::ws;                               // teraz s powinno miec wartość "P6"
    while(F.peek() == '#')                           // pominięcie ewentualnych komentarzy
        F.ignore(100000, '\n');
    F >> _szerokosc >> _wysokosc >> _glebia;         // wczytanie parametrów obrazu
    F.ignore(100000,'\n');                           // pominięcie bajtów do znaku '\n' włącznie
    _tab = new Kolor* [_wysokosc];                   // przydział pamięci dla adresów wierszy
    for (int i = 0; i < _wysokosc; ++i)
    {
        _tab[i] = new Kolor [_szerokosc];            // przydział pamięci dla i-tego wiersza
        char* adres = reinterpret_cast<char*>(_tab[i]);      // zmiana typu wskaźnika
        F.read(adres, sizeof(Kolor) * _szerokosc);           // wczytanie i-tego wiersza
    }
}

void PPMimage::zmiekcz()
{
    for (int y = 1; y < _wysokosc-1; ++y)
    {
        for (int x = 0; x < _szerokosc;x++)
        {
            _tab[y][x].red = (_tab[y-1][x].red + _tab[y+1][x].red + _tab[y][x-1].red + _tab[y][x+1].red) / 4;
            _tab[y][x].green = (_tab[y-1][x].green + _tab[y+1][x].green + _tab[y][x-1].green + _tab[y][x+1].green) / 4;
            _tab[y][x].blue = (_tab[y-1][x].blue + _tab[y+1][x].blue + _tab[y][x-1].blue + _tab[y][x+1].blue) / 4;
        }
    }
}

void PPMimage::zapisz(const char nazwa_pliku[])
{
    std::ofstream F(nazwa_pliku, std::ios::binary);
    F << "P6\n" << _szerokosc << " " << _wysokosc << "\n" << _glebia << "\n";
    for (int i = 0; i < _wysokosc; ++i)
        F.write(reinterpret_cast<char*>(_tab[i]), 3*_szerokosc);
}

PPMimage::~PPMimage()
{
    for (int i = 0;i < _wysokosc; ++i){
        delete [] _tab[i];
    }
    delete [] _tab;
}

int main()
{
    PPMimage image("obrazek.ppm");
    image.zmiekcz();
    image.zapisz("nowy.ppm");
}
