#include <iostream>
using namespace std;

int fibonacci(int n, int &stepCount) {
    if (n <= 1) {
        stepCount = 1;  // One step if n is 0 or 1
        return n;
    }

    int a = 0, b = 1, c;
    stepCount = 2;  // Initial steps for setting a and b

    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
        stepCount++;  // Increment step count for each iteration
    }
    return b;
}

int main() {
    int n;
    char choice;

    do {
        int stepCount = 0;
        cout << "Enter the position of Fibonacci number: ";
        cin >> n;

        int result = fibonacci(n, stepCount);
        cout << "Fibonacci number at position " << n << " is: " << result << endl;
        cout << "Step count: " << stepCount << endl;

        cout << "Do you want to calculate another Fibonacci number? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
