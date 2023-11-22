#include <iostream>

void hanoi(int n, int from, int to)
{
	if (n <= 0)
	{
		return;
	}
	else {
		int res = 6 - from - to;
		if ((from == 2 && to == 1) || (from == 3 && to == 2) || (from == 1 && to == 3))
		{
			hanoi(n - 1, from, to);
			printf("%d %d %d\n", n, from, res);
			hanoi(n - 1, to, from);
			printf("%d %d %d\n", n, res, to);
			hanoi(n - 1, from, to);
		}
		else
		{
			hanoi(n - 1, from, res);
			printf("%d %d %d\n", n, from, to);
			hanoi(n - 1, res, to);

		}
	}
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	hanoi(n, 1, 3);
	return 0;
}