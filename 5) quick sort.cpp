#include <iostream>
#include <vector>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

using namespace std;

// Function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function for deterministic quick sort (pivot as last element)
int deterministicPartition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // pivot
    int i = low - 1;        // index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Deterministic Quick Sort
void deterministicQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = deterministicPartition(arr, low, high);
        deterministicQuickSort(arr, low, pi - 1);
        deterministicQuickSort(arr, pi + 1, high);
    }
}

// Partition function for randomized quick sort
int randomizedPartition(vector<int>& arr, int low, int high) {
    // Generate a random index between low and high
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);  // swap pivot with last element
    return deterministicPartition(arr, low, high);
}

// Randomized Quick Sort
void randomizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));  // Seed for random number generation

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> arrDeterministic = arr;  // Copy of the array for deterministic quick sort
    vector<int> arrRandomized = arr;     // Copy of the array for randomized quick sort

    // Deterministic Quick Sort
    cout << "\nDeterministic Quick Sort:\n";
    deterministicQuickSort(arrDeterministic, 0, n - 1);
    printArray(arrDeterministic);

    // Randomized Quick Sort
    cout << "\nRandomized Quick Sort:\n";
    randomizedQuickSort(arrRandomized, 0, n - 1);
    printArray(arrRandomized);

    return 0;
}
