#include <iostream>
#include <algorithm>
using namespace std;

// Function to calculate the maximum value of knapsack
double fractionalKnapsack(int W, int val[], int wt[], int n) {
    // Calculate value/weight ratio and store them in a new array
    double ratio[100]; // Assuming maximum items are 100

    for (int i = 0; i < n; i++) {
        ratio[i] = (double)val[i] / wt[i]; // value per unit weight
    }

    double totalValue = 0.0;

    // Loop through the items, starting from the highest value/weight ratio
    for (int i = 0; i < n; i++) {
        if (W == 0) break; // No more capacity in knapsack

        int maxIndex = i;
        // Find the item with the maximum value/weight ratio
        for (int j = i + 1; j < n; j++) {
            if (ratio[j] > ratio[maxIndex]) {
                maxIndex = j;
            }
        }

        // Swap the maximum ratio item with the first item in the remaining items
        swap(ratio[i], ratio[maxIndex]);
        swap(val[i], val[maxIndex]);
        swap(wt[i], wt[maxIndex]);

        // Take as much as possible from this item
        if (wt[i] <= W) {
            W -= wt[i]; // Reduce capacity of knapsack
            totalValue += val[i]; // Add full value of item
        } else {
            totalValue += (double)val[i] * ((double)W / wt[i]); // Take fraction of the item
            W = 0; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int val[100], wt[100]; // Arrays for value and weight

    cout << "Enter the value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> val[i] >> wt[i];
    }

    cout << "Enter maximum capacity of knapsack: ";
    cin >> W;

    double result = fractionalKnapsack(W, val, wt, n);
    cout << "Maximum value in knapsack = " << result << endl;

    return 0;
}
