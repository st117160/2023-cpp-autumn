#include <iostream>

int main(int argc, char *argv[])
{
    int n = 0;
    int i = 0;
    int cnt = 0;

    std::cin >> n;

    for (i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt += 1;

            if (i != n / i)
            {
                cnt += 1;
            }
        }
    }

    std::cout << cnt;

    return 0;
}