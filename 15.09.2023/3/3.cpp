#include <iostream>

using namespace std;

int main() {
    
    int n;
    int n0;
    int n1;
    int n5;
    
    cin >> n;
    
    n0 = n / 10;
    n5 = n > 5;
    n1 = n < 6;
    
    cout << n5*n0*(n0+1) + n1*"";
	cout << "25";
    
    return 0;
}