#include <iostream>

int main(int argc, char *argv[])
{
    int n;
    int a1 = 0;
    int a5 = 0;
    int a10 = 0;
    int a20 = 0;
    int a60 = 0;
    int cnt1 = 0;
    int cnt5 = 0;
    int cnt10 = 0;
    int cnt20 = 0;

    std::cin >> n;

    if (n >= 60)
    {
        a60 = n / 60;
        n = n % 60;
    }
    
    if (n > 20 && n < 60)
    {
        cnt20 = n / 20;
        cnt10 = (n - cnt20 * 20) / 10;
        cnt5 = (n - cnt20 * 20 - cnt10 * 10) / 5;
        cnt1 = n % 5;
        if (cnt20 * 230 + cnt10 * 125 + cnt5 * 70 + cnt1 * 15 < 440)
        {
            a20 = cnt20;
            if (125 * cnt10 + 70 * cnt5 + 15 * cnt1 < 230)
            {
                a10 = cnt10;
                if (70 * cnt5 + 15 * cnt1 < 125)
                {
                    a5 = cnt5;
                    a1 = cnt1;
                }
                else
                {
                    a10 += 1;
                }
            }
            else
            {
                a20 += 1;
            }
        }
        else
        {
            a60 += 1;
        }
    }

    if (n <= 20)
    {
        cnt10 = n / 10;
        cnt5 = (n - cnt10 * 10) / 5;
        cnt1 = n % 5;
        if ((125 * cnt10 + 70 * cnt5 + 15 * cnt1) < 230)
        {
            a10 = cnt10;
            a5 = cnt5;
            a1 = cnt1;
        }
        else
        {
            a20 += 1;
        }
    }

    if (n <= 10)
    {
        if ((70 * (n / 5) + 15 * n % 5) < 125)
        {
            a5 += 1;
            a1 += n % 5;
        }
        else
        {
            a10 += 1;
        }
    }

    if (n <= 5)
    {
        if (15 * n < 70)
        {
            a1 = n;
        }
        else
        {
            a5 += 1;
        }
    }

    std::cout << a1;
    std::cout << " ";
    std::cout << a5;
    std::cout << " "; 
	std::cout << a10;
	std::cout << " ";
	std::cout << a20; 
	std::cout << " "; 
	std::cout << a60;
	std::cout << " ";

    return 0;
}
