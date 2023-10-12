#include <iostream>

typedef unsigned int uint;

int main(int argc, char* argv[])
{
	const int BITS = sizeof(uint) * 8;
	
	uint n = 0;
	
	std::cin >> n;
	std::cout << "0b ";
	
	for (int i = BITS - 1; i >= 0; --i)
	{
		std::cout << ((n >> i) & 1) << (i % 4 == 0 ? " " : "");
	}
	
	std::cout << std::endl;
	
	if (n = 0)
	{
		n = ~n;
	}
	else
	{
		int start = BITS - 1;
		
	}
}
