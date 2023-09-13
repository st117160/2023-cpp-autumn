#include <iostream>

int main(int argc, char* argv[]) {
    
    int a;
    int b;
    int a1;
    int b1;
    int ab;
    
    std::cin >> a;
    std::cin >> b;
    
    a1 = a > b;
    b1 = b > a;
    ab = b == a;
    
    std::cout << a * a1 + b * b1 + a * ab;

    return 0;
}