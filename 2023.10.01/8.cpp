#include <iostream>

int main(int argc, char *argv[])
{
	int a = 0;
	int b = 0;
	int n = 0;
	int x = 0;
	int gcd = 0;
	
	std::cin >> a;
	std::cin >> b;
	std::cin >> n;
	
	if (b > a)
	{
		x = b;
		b = a;
		a = x;	
	}

	
	while (a != 0 && b != 0)
	{
		if (a > b)
		{
			a = a % b;
		}
		else
		{
			b = b % a;
		}
		gcd = a + b;
	}
	
	std::cout << gcd;
	
	return 0;
}