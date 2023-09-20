#include <iostream>

int main(int argc, char *argv[])
{

    int long long A = 1;

    std::cin >> A;

    A = 100 * (A / 10) * ((A / 10) + 1) + 25;

    std::cout << A;
    return 0;
}