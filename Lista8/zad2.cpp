#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

class PPMimage
{
public:
    struct Kolor { unsigned char red, green, blue; };
    struct NewColor { unsigned char gray; };

    PPMimage (const char nazwa_pliku[]);           // wczytuje obraz z pliku
    ~PPMimage();
    void zapisz(const char nazwa_pliku[]);         // zapisuje obraz w pliku
    void convert();
private:
    PPMimage(PPMimage const&) { }                  // nie wywołuj tej funkcji!
    void operator= (PPMimage const&) { }           // nie wywołuj tej funkcji!

    int      _szerokosc;    // liczba kolumn w obrazku
    int      _wysokosc;     // liczba wierszy w obrazku
    int      _glebia;       // głębia koloru
    Kolor**  _tab;          // adres dwuwymiarowej tablicy kolorów
    NewColor** _new_tab;    // adres dwuwymiarowej tablicy kolorów
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
    _new_tab = new NewColor* [_wysokosc];
    for (int i = 0; i < _wysokosc; ++i)
    {
        _tab[i] = new Kolor [_szerokosc];            // przydział pamięci dla i-tego wiersza
        _new_tab[i] = new NewColor [_szerokosc];
        char* adres = reinterpret_cast<char*>(_tab[i]);      // zmiana typu wskaźnika
        F.read(adres, sizeof(Kolor) * _szerokosc);           // wczytanie i-tego wiersza
    }
}

void PPMimage::convert()
{
    NewColor* p = new NewColor [_szerokosc];               // bufor na nowy wiersz
    for (int y = 0; y < _wysokosc; ++y)
    {
        for (int x = 0; x < _szerokosc;x++)
        {
            auto srednia = (_tab[y][x].red + _tab[y][x].green + _tab[y][x].blue) / 3;
            p[x].gray = srednia;
        }
        std::swap(_new_tab[y], p);                       // podmiana bufora p
    }
    delete [] p;                                     // usunięcie niepotrzebnego bufora
}

void PPMimage::zapisz(const char nazwa_pliku[])
{
    std::ofstream F(nazwa_pliku, std::ios::binary);
    F << "P5\n" << _szerokosc << " " << _wysokosc << "\n" << _glebia << "\n";
    for (int i = 0; i < _wysokosc; ++i)
        F.write(reinterpret_cast<char*>(_new_tab[i]), _szerokosc);
}

PPMimage::~PPMimage()
{
    for (int i = 0;i < _wysokosc; ++i){
        delete [] _tab[i];
        delete [] _new_tab[i];
    }
    delete [] _tab;
    delete [] _new_tab;
}

int main()
{
    PPMimage image("obrazek.ppm");
    image.convert();
    image.zapisz("nowy.pgm");
}
