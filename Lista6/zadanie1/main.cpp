#include "stos.h"

void Stos::_grow()
{
	assert(_size == _capacity);
	_capacity *= 2;
	int* p = new int[_capacity];
	for (size_t i = 0; i < _size; i++)
		p[i] = _tab[i];
	delete[] _tab;
	_tab = p;
}

void Stos::_shrink()
{
	assert(_capacity >= 4);
	_capacity /= 2;
	int* p = new int[_capacity];
	for (size_t i = 0; i < _size; i++)
		p[i] = _tab[i];
	delete[] _tab;
	_tab = p;
}

Stos::Stos(Stos const& rhs)
	:_capacity(rhs._capacity), _size(rhs._size), _tab(new int[_capacity])
{
	for (size_t i = 0; i < _size; i++)
		_tab[i] = rhs._tab[i];
}

Stos& Stos::operator= (Stos const& rhs)
{
	if (this == &rhs)
		return *this;
	if (_capacity < rhs._size)
	{
		delete[] _tab;
		_capacity = rhs._size;
		_tab = new int[_capacity];
	}
	_size = rhs._size;
	for (size_t i = 0; i < _size; i++)
		_tab[i] = rhs._tab[i];
	return *this;
}
