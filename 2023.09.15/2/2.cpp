#include <iostream>

int main(int argc, char *argv[])
{

    int num = 1;
    int n_positive = 1;
    int n_negative = 1;
    int answer = 1;

    std::cin >> num;
    n_positive = num > 0;
    n_negative = num < 0;
    answer = ((n_negative * num + n_positive * 1) + (n_negative * 1 + n_positive * num)) * (n_positive * num + n_negative * (-num + 2)) / 2.0;

    std::cout << answer;

        return 0;
}