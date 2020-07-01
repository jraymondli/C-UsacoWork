#include <iostream>

int main()
{
    int a[1], b[1];
    b[0]=1;
    a[0]=b[0];
    b[0]=2;
    std::cout << a[0] << b[0];
}