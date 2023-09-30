#include <iostream>

int main(int argc, char *argv[])
{
    int k = 0;
    int m = 0;
    int n = 0;
    int cnt = 0;
	
	std::cin >> k;
    std::cin >> m;
    std::cin >> n;

    cnt = (n / k) * m * 2;
    
    if (n % k > 0) 
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
    
    if (n <= k) 
	{
        cnt = 2 * m;
    }

    std::cout << cnt;
    
    return 0;
}