#include <iostream>

int main(int argc, char *argv[])
{

    int a = 1;

    std::cin >> a;

    a = 100 * (a / 10) * ((a / 10) + 1) + 25;

    std::cout << a;
    return 0;
}