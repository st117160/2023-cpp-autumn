#include <iostream>

int main(int argc, char *argv[])
{
	int n = 0;
	int flag = 1;
	int ans = 0;
	
	std::cin >> n;
	
	for (int cnt = 1; cnt <= n; cnt++)
	{
		std::cout << flag << " ";
		ans++;
		
		if (flag == ans)
		{
			flag++;
			ans = 0;
		}
	}
		
	return 0;
}