#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve Rod Cutting and track the cut lengths
int rodCutting(vector<int>& price, int n, vector<int>& cuts) {
    vector<int> dp(n + 1, 0);       // dp[i] stores max value for rod length i
    vector<int> firstCut(n + 1, 0); // firstCut[i] stores the first cut length that leads to max value

    for (int i = 1; i <= n; i++) // for the rod lenght 1 to n 
    { 
        for (int j = 0; j < i; j++)  // length of the first cut
        {
            if (dp[i] < price[j] + dp[i - j - 1]) {
                dp[i] = price[j] + dp[i - j - 1];
                firstCut[i] = j + 1; // Store cut length (because price[j] is for length j+1)
            }
        }
    }

    // Reconstruct the cuts from firstCut[]
    int length = n;
    while (length > 0) {
        cuts.push_back(firstCut[length]); // Add the cut length
        length -= firstCut[length];       // Reduce rod length
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n; // Total rod length

    vector<int> price(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i]; // price[i] is the price for rod of length i+1
    }

    vector<int> cuts; // to store cut lengths
    int maxValue = rodCutting(price, n, cuts);

    cout << "Maximum Obtainable Value: " << maxValue << endl;
    cout << "Cut lengths to achieve this: ";
    for (int cut : cuts) {
        cout << cut << " ";
    }
    cout << endl;

    return 0;
}
