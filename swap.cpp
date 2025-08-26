#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a = 5, b = 3;
    std::cout << a << ' ' << b << '\n';
    std::swap(a, b);
    std::cout << a << ' ' << b << '\n';

    string c = "pablo", d = "david";
    std::cout << c << ' ' << d << '\n';
    std::swap(c, d);
    std::cout << c << ' ' << d << '\n';
}