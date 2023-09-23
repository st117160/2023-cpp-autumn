#include <iostream>

int main(int argc, char *argv[])
{
    int x = 0;

    std::cin >> x;

	if (x == 100)
	{
		std::cout << "C";
	}
	
	if (90 <= x && x < 100)
	{
		std::cout << "XC";
		x -= 90;
	}
	
	if (80 <= x && x < 90)
	{
		std::cout << "LXXX";
		x -= 80;
	}
	
	if (70 <= x && x < 80)
	{
		std::cout << "LXX";
		x -= 70;
	}
	
	if (60 <= x && x < 70)
	{
		std::cout << "LX";
		x -= 60;
	}
	
	if (50 <= x && x < 60)
	{
		std::cout << "L";
		x -= 50;
	}
	
	if (40 <= x && x < 50)
	{
		std::cout << "XL";
		x -= 40;
	}
	
	if (30 <= x && x < 40)
	{
		std::cout << "XXX";
		x -= 30;
	}
	
	if (20 <= x && x < 30)
	{
		std::cout << "XX";
		x -= 20;
	}
	
	if (10 <= x && x < 20)
	{
		std::cout << "X";
		x -= 10;
	}
	
	if (x == 9)
	{
		std::cout << "IX";
		x -= 9;
	}
	
	if (x == 8)
	{
		std::cout << "VIII";
		x -= 8;
	}
	
	if (x == 7)
	{
		std::cout << "VII";
		x -= 7;
	}
	
	if (x == 6)
	{
		std::cout << "VI";
		x -= 6;
	}
	
	if (x == 5)
	{
		std::cout << "V";
		x -= 5;
	}
	
	if (x == 4)
	{
		std::cout << "IV";
		x -= 4;
	}
	
	if (x == 3)
	{
		std::cout << "III";
		x -= 3;
	}
	
	if (x == 2)
	{
		std::cout << "II";
		x -= 2;
	}
	
	if (x == 1)
	{
		std::cout << "I";
		x -= 1;
	}
	
	return 0;
}