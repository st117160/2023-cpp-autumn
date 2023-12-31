#include <iostream>

void hanoi(int n, int from, int to);

void hanoi(int n, int from, int to)
{
	if (n > 0)
	{
		int res = 6 - from - to;
		hanoi(n - 1, from, res);
		std::cout << 0 << " " << from << " " << to << std::endl;
		hanoi(n - 1, res, to);
		std::cout << n << " " << 6 - from - to << " " << 3 << std::endl;
	}
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int a = 0;
	int temp = 0;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a;
		if (a > temp)
		{
			hanoi(1, 1, 3);
		}
		else
		{
			hanoi(1, 1, 2);
		}
		temp = a;
	}

	return 0;
}