#include <iostream>
#include <sstream>
#include <typeinfo>


auto char_to_int(char *in) {
    int out;
    std::stringstream str(in);
    str >> out;
    return out;
}

int main() {
    char znak[] = "5";
    std::cout << char_to_int(znak) << "\n";
    std::cout << typeid(char_to_int(znak)).name() << "\n";
}
