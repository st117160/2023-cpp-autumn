#include <iostream>

typedef unsigned int uint;

int main(int argc, char* argv[])
{
	const int BITS = sizeof(uint) * 8;
	
	uint a = 0;
	uint b = 0;
	uint c = 0;
	
	std::cin >> a;
	std::cin >> b;

	bool up = 0;
	
	for (int i = 0; i < BITS; ++i)
	{
		bool bitA = ((a >> i) & 1);
		
		if (bitA == 1)
		{
			uint d = b;
			for (int j = 0; j < i; ++j)
			{
				d = d << 1;
			}
			c += d;
		}
	}
	
	std::cout << a << " * " << b << " = " << c << std::endl;
	
	return 0;
}
