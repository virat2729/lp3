#include <iostream>
using namespace std;

int fibonacci(int n, int &stepCount) {
    stepCount++; // Increment the step count with each function call
    if (n <= 1)
        return n;
    return fibonacci(n - 1, stepCount) + fibonacci(n - 2, stepCount);
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
