#include <iostream>

int main(int argc, char *argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int x = 0;
	
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;
	
	while (x <= 1000)
	{
		if ((a * x * x * x + b * x * x + c * x + d) == 0)
		{
			std::cout << x << " ";
		}
		x++;
	}
	
	return 0;
}