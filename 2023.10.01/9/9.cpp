#include <iostream>

int main(int argc, char *argv[])
{
	int a = 0;
	int b = 0;
	
	std::cin >> a;
	std::cin >> b;
	
	while (a > b)
	{
		if (a % 2 == 0 && a / 2 >= b)
		{
			std::cout << ":2" << std::endl;
			a /= 2;
		}
		else if ((a % 2 != 0 || a / 2 < b) && a - 1 >= b)
		{
			std::cout << "-1" << std::endl;
			a -= 1;	
		}
    }
    
	return 0;
} 