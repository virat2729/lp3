#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve 0-1 Knapsack problem using dynamic programming
int knapsack(int capacity, vector<int>& weights, vector<int>& values, int n) {
    // Create a DP table where dp[i][w] represents the maximum value that can be achieved
    // with the first i items and a maximum weight limit of w
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the table dp[][] in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                // Take the maximum of either including the item or excluding it
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                // Exclude the item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value that can be achieved with n items and capacity weight
    return dp[n][capacity];
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> values(n), weights(n);

    cout << "Enter the values and weights of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> values[i] >> weights[i];
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int maxValue = knapsack(capacity, weights, values, n);

    cout << "The maximum value that can be achieved in the knapsack is: " << maxValue << endl;

    return 0;
}
