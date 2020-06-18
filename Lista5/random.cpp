#include "random.h"

random::random(int f1)
    : _fn(f1)
{
    assert( f1 > 0 && f1 < max);

}

double random::operator()()
{
    long long x = _fn;
    x *= 16807;
    x %= max;
    _fn = static_cast<int>(x);
    return x/max;
}
