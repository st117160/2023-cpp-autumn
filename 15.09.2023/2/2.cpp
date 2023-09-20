#include <iostream>

int main(int argc, char *argv[])
{

    int N = 1;
    int n_positive = 1;
    int n_negative = 1;
    int answer = 1;

    std::cin >> N;
    n_positive = N > 0;
    n_negative = N < 0;
    answer = ((n_negative * N + n_positive * 1) + (n_negative * 1 + n_positive * N)) * (n_positive * N + n_negative * (-N + 2)) / 2.0;

    std::cout << answer;

        return 0;
}