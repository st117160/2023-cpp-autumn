#include <iostream>

int main(int argc, char *argv[])
{
	int a = 0;
	int b = 0;
	int n = 0;
	int mx = 0;
	
	std::cin >> a;
	std::cin >> b;
	std::cin >> n;
	
	if (a > b)
	{
	}
	else
	{
		mx = b;
		b = a;
		a = mx;
	}
	
	std::cout << a << b;
	return 0;
}