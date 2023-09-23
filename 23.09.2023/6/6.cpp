#include <iostream>

int main(int argc, char *argv[])
{
    int k = 1;
    int m = 1;
    int n = 1;
    int cnt = 0;
	
	std::cin >> k;
    std::cin >> m;
    std::cin >> n;

    cnt = n / m * k * 2;
    
    if (n > k) 
	{
        if (k / 2 < n % k) 
		{
            cnt += (m * 2);
        } 
		else 
		{
            cnt += m;
        }
    }
    if (n <= k) {
        cnt = 2 * m;
    }

    std::cout << cnt;
    
    return 0;
}