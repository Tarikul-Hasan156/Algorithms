#include <iostream>
using namespace std;

// Function to get max of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    int val[100], wt[100]; // Arrays for values and weights

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << "Enter maximum capacity of knapsack: ";
    cin >> W;

    // dp[i][w] = max value for first i items and capacity w
    int dp[100][100]; // Assuming n and W are <= 100

    // Fill the dp table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0; // Base case: no item or no capacity
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Final answer
    cout << "Maximum value in knapsack = " << dp[n][W] << endl;

    return 0;
}
