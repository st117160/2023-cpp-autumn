#include <iostream>

int main(int argc, char *argv[])
{
    int a = 1;
    int b = 1;
    int c = 1;

    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    if (a <= b)
    {
        if (b <= c)
        {
            std::cout << a << " ";
            std::cout << b << " ";
            std::cout << c;
        }
        else if (a <= c)
        {
            std::cout << a << " ";
            std::cout << c << " ";
            std::cout << b;
        }
        else
        {
            std::cout << c << " ";
            std::cout << a << " ";
            std::cout << b;
        }
    }
    else
    {
        if (a <= c)
        {
            std::cout << b << " ";
            std::cout << a << " ";
            std::cout << c;
        }
        else if (b <= c)
        {
            std::cout << b << " ";
            std::cout << c << " ";
            std::cout << a;
        }
        else
        {
            std::cout << c << " ";
            std::cout << b << " ";
            std::cout << a;
        }
    }

    return 0;
}