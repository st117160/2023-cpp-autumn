#include <iostream>

int main(int argc, char* argv[]) {
	
	int v;
	int t;
	int s;
	
	std::cin >> v;
	std::cin >> t;
	s = v * t;
	
	std::cout << ((109+v*t % 109)%109 + 1);
	
	
}