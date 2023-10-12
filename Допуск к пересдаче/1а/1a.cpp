#include <iostream>

typedef unsigned int uint;

int main(int argc, char* argv[])
{	
	int n = 0;
	const int BITS = sizeof(uint) * 8;
	
	std::cin >> n;
	
	int sum = 0;
	
	for (int i = 0; i < BITS; ++i)
	{
		sum += (n >> i) & 1;
	}
	
	std::cout << sum << std::endl;
	
	return 0;
}