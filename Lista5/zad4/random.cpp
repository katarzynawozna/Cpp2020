#include "random.h"
#include <cassert>
#include <cmath>
#include <iostream>

Random::Random(int f1)
{
	assert(f1 > 0 && f1 < pow(2, 31) - 1);
	_fn = f1;
}

double Random::operator()()
{
	int mod = pow(2, 31) - 1;
	long long fn = _fn;
	long long fn1 = (16807 * fn) % mod;
	_fn = fn1;
	//std::cout << _fn / (pow(2, 31) - 2) << "\n";
	return _fn/(pow(2,31)-2);
}
