#include <cassert>
#include "stos_zad3.h"

Stos::~Stos()
{
    while ( !this->empty() )
        this->pop();
}

std::ostream& operator <<(std::ostream &F, Stos const& c)
{
    F << "(";
    if(!c.empty())
    {
        F << c.top();
    }

    Ogniwo* last = c._pSzczyt ->_p_nastepny;

    while(last != NULL)
    {
        F << ",";
        F << last->_dane;
        last = last->_p_nastepny;

    }
    F << ")";
    return F;

}
