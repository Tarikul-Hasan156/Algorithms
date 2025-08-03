#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string X, Y;
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();

    // Create a 2D array to store lengths of LCS
    int lcs[m + 1][n + 1];

    // Build the lcs array in bottom-up fashion
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                lcs[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }

    // Print the length of LCS
    cout << "Length of LCS: " << lcs[m][n] << endl;

    // To print the LCS string
    int i = m, j = n;
    string lcs_str = "";
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs_str = X[i - 1] + lcs_str;
            i--;
            j--;
        } else if (lcs[i - 1][j] > lcs[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << "LCS: " << lcs_str << endl;

    return 0;
}
