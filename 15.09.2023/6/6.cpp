#include <iostream>

int main(int argc, char *argv[])
{

    int a = 1;
    int b = 1;
    int a_max = 1;
    int b_max = 1;
    int equal = 1;

    std::cin >> a;
    std::cin >> b;

    a_max = a > b;
    b_max = b > a;
    equal = b == a;

    std::cout << a * a_max + b * b_max + a * equal;

    return 0;
}