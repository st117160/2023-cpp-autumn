#include <iostream>

int main(int argc, char *argv[])
{
    int n = 0;

    std::cin >> n;

    if (n % 10 == 1 && n % 100 != 11)
    {
        std::cout << n;
        std::cout << " ";
        std::cout << "bochka";
    }
	else if ((n % 10 == 2 && n % 100 != 12) || (n % 10 == 3 && n % 100 != 13) || (n % 10 == 4 && n % 100 != 14))
    {
        std::cout << n;
        std::cout << " ";
        std::cout << "bochki";
    }
	else
    {
        std::cout << n;
        std::cout << " ";
        std::cout << "bochek";
    }

    return 0;
}