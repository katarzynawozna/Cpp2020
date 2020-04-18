#include <iostream>
#include <string>

int main()
{
    std::string s;
    getline(std::cin, s);

    for (int i = s.size()-1; i >= 0; --i)
    {
        std::cout << s[i];
    };
}