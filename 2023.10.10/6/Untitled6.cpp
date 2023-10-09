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
	
	int mx = 0;
	int cnt_mx = 0;
	
	for (int i = 0; i < n; ++i)
	{
		if (*(m + i) >= mx)
		{
			mx = *(m + i);
			cnt_mx = i;
		}
	}
	
	int mn = mx;
	int cnt_mn = 0;
	for (int i = 0; i < n; ++i)
	{
		if (*(m + i) < mn)
		{
			mn = *(m + i);
			cnt_mn = i;
		}
	}
	
	*(m + (cnt_mx)) = mn;
	*(m + (cnt_mn)) = mx;	
	
	for (int i = 0; i < n; ++i)
	{
		std::cout << *(m + i) << " ";
	}

	free(m);
	
	return 0;
}