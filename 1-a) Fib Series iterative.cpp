#include <iostream>
using namespace std;

int fibonacciIterative(int n) {
    if (n <= 1)
        return n;
    
    int a = 0, b = 1, result = 0;
    for (int i = 2; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the Fibonacci term to calculate: ";
    cin >> n;
    cout << "Fibonacci (Iterative) of " << n << " is: " << fibonacciIterative(n) << endl;
    return 0;
}
