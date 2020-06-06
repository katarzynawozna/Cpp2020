#include <assert.h>
class Stos
{
public:
	Stos();
	Stos(Stos const&);
	~Stos();

	void push(int i);
	void pop();
	int top()const;
	int& top();
	bool empty() const;
	size_t size() const;
	Stos& operator = (Stos const&);

private:
	enum { initial_capacity = 1 };
	void _grow();
	void _shrink();

	size_t _capacity;
	size_t _size;
	int* _tab;
};
        Stos::Stos() : _capacity(initial_capacity), _size(0), _tab(new int[initial_capacity])
{
	assert(initial_capacity > 0);
}

        Stos::~Stos() { delete [] _tab; }
       
        void Stos::push(int n)
{
	if (_size == _capacity)
		_grow();

	_tab[_size] = n;
	_size++;
}

        void Stos::pop()
{
	assert(!empty());
        _size--;
        if(_capacity > 4 * _size) 
        { _shrink(); std::cout << "Nie wolno wywolywac jesli capacity < 4"; }
}

        int Stos::top()  const
{
	assert(!empty());
	return _tab[_size - 1];
}

        int& Stos::top()
{
	assert(!empty());
	return _tab[_size - 1];
}

        bool Stos::empty()const { return _size == 0; }
        size_t Stos::size() const { return _size; }
