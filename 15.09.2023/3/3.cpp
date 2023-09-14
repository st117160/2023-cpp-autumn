#include <iostream>

int main(int argc, char* argv[]) {
	
    int long long n;
	
    std::cin >> n;
    
    n = 100*(n/10)*((n/10)+1)+25;
    
    std::cout << n;
    return 0;
}