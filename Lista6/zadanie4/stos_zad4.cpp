#include "stos_zad4.h"

Stos::~Stos() {
    while ( !this->empty() )
        this->pop();
}

void Stos::reverse()
{

    assert(!empty());

    Ogniwo* iteration = this->_pSzczyt;
    Ogniwo* last_element = NULL;
    Ogniwo* previus_element = NULL;
    Ogniwo* next_element = NULL;

    while (iteration != NULL) {
        next_element = iteration->_p_nastepny;
        iteration->_p_nastepny = previus_element;
        last_element = iteration;
        previus_element = last_element;
        iteration = next_element;
    }

    this->_pSzczyt = last_element;

}

std::ostream &operator<< (std::ostream &result, Stos const &c){
    result << "(";
    if (!c.empty())
        result << c.top();
    Ogniwo* last = c._pSzczyt->_p_nastepny;
    while(last != NULL){
        result << ", ";
        result << last->_dane;
        last = last->_p_nastepny;
    }
    result << ") \n";
    return result;
}
