#pragma once
#include <ctime>

class Random
{
	unsigned int _fn;
public:
	Random(int f1 = time(0));

	double operator()();
};
