#include <iostream>

typedef unsigned int uint;
typedef unsigned short ush;

int main(int argc, char* argv[])
{
	const int BITS = sizeof(uint) * 8;
	
	ush a = 0;
	ush b = 0;
	ush c = 0;
	
	std::cin >> a;
	std::cin >> b;

	bool up = 0;
	
	for (int i = 0; i < BITS; ++i)
	{
		bool bitA = ((a >> i) & 1);
		bool bitB = ((b >> i) & 1);
		bool current = bitA ^ bitB ^ up;
		up = (bitA & bitB) | (bitA & up) | (bitB & up);
		c = c | ((int)current << i);
	}
	
	std::cout << a << " + " << b << " = " << c << std::endl;
	
	return 0;
}