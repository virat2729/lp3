#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item with weight and value
struct Item {
    double weight;
    double value;

    // Constructor for convenience
    Item(double v, double w) : value(v), weight(w) {}
};

// Comparator function to sort items by their value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = a.value / a.weight;
    double r2 = b.value / b.weight;
    return r1 > r2;
}

// Function to perform the fractional knapsack algorithm
double fractionalKnapsack(double capacity, vector<Item>& items) {
    // Sort items by value-to-weight ratio in descending order
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;  // Variable to store the total value

    // Traverse through the sorted items
    for (auto& item : items) {
        // If the item can be added in full
        if (capacity >= item.weight) {
            capacity -= item.weight;
            totalValue += item.value;
        } 
        // If only a fraction of the item can be added
        else {
            totalValue += item.value * (capacity / item.weight);
            break; // The knapsack is now full
        }
    }

    return totalValue;
}

// Main function
int main() {
    int n;
    double capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items;
    cout << "Enter the value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        double value, weight;
        cin >> value >> weight;
        items.push_back(Item(value, weight));
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "The maximum value in the knapsack is: " << maxValue << endl;

    return 0;
}
