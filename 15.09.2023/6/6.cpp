#include <iostream>

int main(int argc, char *argv[])
{

    int a = 1;
    int b = 1;
    int a1 = 1;
    int b1 = 1;
    int ab = 1;

    std::cin >> a;
    std::cin >> b;

    a1 = a > b;
    b1 = b > a;
    ab = b == a;

    std::cout << a * a1 + b * b1 + a * ab;

    return 0;
}