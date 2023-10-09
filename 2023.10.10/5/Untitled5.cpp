#include <iostream>
#include <cstdlib>

int main(int, char**)
{
	int n = 0;
	
	std::cin >> n;
	
	int* m = 0;
	
	m = (int*)malloc(sizeof(int) * n);
	
	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(m + i);
	}
		
	for (int i = 0; i < n; ++i)
	{
		std::cout << *(m + (n - i - 1)) << " ";
	}

	free(m);
	
	return 0;
}