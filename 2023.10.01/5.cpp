#include <iostream>

int pol(int i) 
{
	int x = 0;
	while (i > 0)
	{
		x = x * 10 + (i % 10);
		i = i / 10;
	}
	return x;
}

int main(int argc, char* argv[])
{
	int k = 0;
	int cnt = 0;
	int i = 1;
	
	std::cin >> k;
	
	while (i <= k)
	{
		if (i == pol(i))
		{
			cnt++;
		}
		i++;
	} 
	
	std::cout << cnt;
	return 0;
}
	

