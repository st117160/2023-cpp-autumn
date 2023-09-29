#include <iostream>

int main(int argc, char *argv[])
{

    int v = 1;
    int t = 1;
    int s = 1;

    std::cin >> v;
    std::cin >> t;
    s = v * t;

    std::cout << ((109 + v * t % 109) % 109 + 1);

    return 0;
}