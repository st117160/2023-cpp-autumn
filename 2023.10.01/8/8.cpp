#include <iostream>

int main(int argc, char *argv[])
{
	int a = 0;
	int b = 0;
	int n = 0;
	int gcd = 0;
	int x = 0;
	int y = 0;
	char lit = 'A';
	char big = 'B';
	int ost = 0;
	
	std::cin >> a;
	std::cin >> b;
	std::cin >> n;
	
	x = a;
	y = b;
	
	if (a > b)
    {
        gcd = a;
        a = b;
        b = gcd;
        lit = 'B';
        big = 'A';
    }

    if (n == b)
    {
        std::cout << ">" << big;
        std::cout << std::endl;
    }
    
    while (y != 0) 
    {
        gcd = x % y;
        x = y;
        y = gcd;
    }
	
	if ((n % x != 0) || ((n > a) && (n > b)))
    {
        std::cout << "Impossible";
        std::cout << std::endl;
    }
    else
    {
        while ('True')
        {
            ost += a;
            std::cout << ">" << lit;
            std::cout << std::endl;
            std::cout << lit << ">" << big;
            std::cout << std::endl;
            if (ost >= b)
            {
                std::cout << big << ">" ;
				std::cout << std::endl;
                std::cout << lit << ">" << big;
                std::cout << std::endl;
                ost %= b;
            }
            
            if ((ost == n) || (ost == 0))
            {
                break;
            }
        }
    }
    return 0;
}