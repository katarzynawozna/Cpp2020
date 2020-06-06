#include <assert.h>

struct Ogniwo
{
	Ogniwo(int n, Ogniwo* p) : _dane(n), _p_nastepny(p)
	{}
	int _dane;
	Ogniwo* _p_nastepny; 
};

class Stos
{
public:
	Stos(); 
	Stos(Stos const&); // konstruktor kopiujący
	~Stos();

	void push(int i); 
	void pop(); 
	int top()const; 
	int& top(); 
	bool empty() const; 
	size_t size() const;
	Stos& operator = (Stos const&); // operator przypisania

private:
	Ogniwo* _pSzczyt; 
	size_t _size;
};

	Stos::Stos() : _pSzczyt(0), _size(0){}

	bool Stos::empty() const { return _pSzczyt == 0; }

	void Stos::push(int n)
{
	_pSzczyt = new Ogniwo(n, _pSzczyt);
	_size++;
}

	void Stos::pop()
{
	assert(!empty());
	Ogniwo* temp = _pSzczyt;
	_pSzczyt = _pSzczyt->_p_nastepny;
	delete temp;
	_size--;
}

	Stos::~Stos()
{
	while (!this->empty())
		this->pop();
}

	int Stos::top() const
{
	assert(!empty());
	return _pSzczyt->_dane;
}

	int& Stos::top()
{
	assert(!empty());
	return _pSzczyt->_dane;
}
