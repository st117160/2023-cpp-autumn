#include <iostream>

int main(int argc, char *argv[])
{
	int n = 0;
	int k_2 = 0;
	int k_1 = 1;
	int k = 1;
	int c = 2;
	
	std::cin >> n;

	while (c < n)
	{
		k_2 = k_1;
		k_1 = k;
		k = k_2 + k_1;
		c++;
	}
	std::cout << k;

}