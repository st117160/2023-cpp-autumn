#include <iostream>

using namespace std;

int main() {
    
    int a;
    int b;
    int a1;
    int b1;
    
    cin >> a;
    cin >> b;
    
    a1 = a > b;
    b1 = b > a;
    
    cout << a * a1 + b * b1;

    return 0;
}