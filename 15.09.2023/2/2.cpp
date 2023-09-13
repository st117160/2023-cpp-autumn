#include <iostream>

int main(int argc, char* argv[]) {
    
    int n;
    int n_positive;
    int n_negative;
    
    std::cin >> n;
    n_positive = n > 0;
    n_negative = n < 0;
    std::cout << ((n_negative*n + n_positive*1) + (n_negative*1 + n_positive*n))*(n_positive*n+n_negative*(-n+2))/2.0;
    
    return 0;
}