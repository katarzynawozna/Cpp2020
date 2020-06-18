#include <iostream>

using namespace std;

int main()
{
    char haslo[8];
    strcpy(haslo, "Ta.jnE!");
    for( ; ; )
    {
        cout << "podaj haslo: " << endl;
        char tmp[8];
        cin >> tmp;
        cout << endl;
        if (strcmp(tmp,haslo) == 0)
            break;
        cout << "niepoprawne! " << endl;
    }

    cout << "witaj w systemie!" << endl;
}

// hasło zostaje nadpisane z powodu braku pamięciu typu char
