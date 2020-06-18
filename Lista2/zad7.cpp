#include <iostream>
#include <string>
#include <cctype>
#include <vector>

int main()
{
    std::vector<int> v(256);
    std::string s;
    char c;
    getline(std::cin, s);
    std::cin >> c;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]==c)
            v[c]++;
    }
    for (int i = 0; i < 256;i++)
    {
        if (v[i]!=0 and isgraph(i))
            {
                char c = i;
                std::cout << c << ": " << v[c] << "\t";
            }
    }
        return 0;
}
