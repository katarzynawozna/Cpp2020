#include <iostream>
#include <cmath>
int main()
{
    const int n = 1000000;
    double long s1 = 0.0, s2= 1.0, s3= 0.0;
    M_PI;
    for (int j = 1; j <= n; ++j)
    {
        s1+= ((pow(-1,j+1))/(2*j-1));
        s2*= ((4*pow(j,2))/(4*pow(j,2)-1));
        s3+= 8*(1/pow((2*j-1),2));
    }
    std::cout << 4*s1 << " " << 2*s2 << " " << sqrt(s3)<<"\n";
    std::cout << "M_PI: " << M_PI;
    return 0;
}
