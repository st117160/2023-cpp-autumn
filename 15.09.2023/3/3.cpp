#include <iostream>

int main(int argc, char* argv[]) {
	
    int n;
	int n1;
	
    std::cin >> n;
    
    n1 = n / 10;
    n = 100*n1*(n1+1) + 25;
    
    std::cout << n;
    return 0;
}