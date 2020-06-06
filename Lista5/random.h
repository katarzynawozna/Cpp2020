#include <ctime>

class Random {
    private:
        int _fn;

    public:
        Random(int f1 = time(0));
        double operator()();
};
