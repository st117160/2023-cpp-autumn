#include <iostream>

int main(int argc, char *argv[])
{

    int n;

    std::cin >> n;
    std::cout << "The next number for the number ";
    std::cout << n;
    std::cout << " is ";
    std::cout << n + 1;
    std::cout << "." << std::endl;

    std::cout << "The previous number for the number ";
    std::cout << n;
    std::cout << " is ";
    std::cout << n - 1;
    std::cout << ".";

    return 0;
}