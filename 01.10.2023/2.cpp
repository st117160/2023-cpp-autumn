#include <iostream>

int main(int argc, char *argv[])
{
    int x = 0;

    std::cin >> x;

    for (x = x; x % 10 == 0; x = x / 10)
    {
        x = x;
    }

    for (x = x; x > 0; x = (x - x % 10) / 10)
    {
        std::cout << x % 10;
    }

    return 0;
}