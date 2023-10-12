#include <iostream>

int main(int argc, char* argv[])
{	
	int n = 0;
	
	std::cin >> n;
	
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int i = 1; i <= n; ++i)
			{
				std::cout << i;
			}
			std::cout << std::endl;
		}
	}
	
	std::cout << std::endl;
	
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int cnt = 1; cnt <= n; ++cnt)
			{
				std::cout << i;
			}
			std::cout << std::endl;
		}	
	}
	
	std::cout << std::endl;

	{
		for (int i = 0; i < n; ++i)
		{
			for (int cnt = 0; cnt < n; ++cnt)
			{
				std::cout << (i + cnt) % n + 1;
			}
			std::cout << std::endl;
		}	
	}
	
	std::cout << std::endl;

	{
		for (int i = 0; i < n; ++i)
		{
			for (int cnt = 0; cnt < n; ++cnt)
			{
				std::cout << 2 * n - i - cnt - 1;
			}
			std::cout << std::endl;
		}
	}
	
	std::cout << std::endl;
	
	{
		for (int i = 0; i < n; ++i)
		{
			for (int cnt = 0; cnt < n; ++cnt)
			{
				std::cout << std::max(std::min(i + 1, n - i), std::min(cnt + 1, n - cnt));
			}
			std::cout << std::endl;
		}
	}
	
	std::cout << std::endl;
	
	{
		for (int i = 0; i < n; ++i)
		{
			for (int cnt = 0; cnt < n; ++cnt)
			{
				std::cout << (i + 1) % 2 * (cnt + 1) + i % 2 * (n - cnt);
			}
			std::cout << std::endl;
		}
	}
	
	return 0;
}

