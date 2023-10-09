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
	
	int l = 0;
	
	for (int i = 0; i < n; ++i)
	{
		if (*(m + i) > 0)
		{
			++l;
		}
	}
	
	std::cout << l;
	
	free(m);
	
	return 0;
}