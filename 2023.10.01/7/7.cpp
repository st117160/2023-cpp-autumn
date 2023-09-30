#include <iostream>

int main(int argc, char *argv[])
{
	int k = 0;
	int n = 0;
	int ans = 1;
	
	std::cin >> n;
	
	while (ans < n)
	{
		ans *= 2;
		k += 1;
	}
	
	std::cout << k;
	
	return 0;
}