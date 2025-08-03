#include <iostream>
#include <algorithm>  // For sort function
using namespace std;
int main() {
    int n;

    // Input: Number of activities
    cout << "Enter number of activities: ";
    cin >> n;

    int start[n], end[n];

    // Input: Start times
    cout << "Enter start times:\n";
    for (int i = 0; i < n; i++) {
        cin >> start[i];
    }

    // Input: End times
    cout << "Enter end times:\n";
    for (int i = 0; i < n; i++) {
        cin >> end[i];
    }

    // Sorting the activities based on end times
    // Create an index array to keep track of the original activity indices
    int index[n];
    for (int i = 0; i < n; i++) {
        index[i] = i;
    }

    // Sort the index array using the comparison function
    sort(index, index + n);

    // Activity selection
    cout << "\nSelected activities:\n";
    int last_end = end[index[0]];  // Store the end time of the first activity
    cout << "(" << start[index[0]] << ", " << end[index[0]] << ")\n";  // Print the first activity

    // Select other activities based on end time and start time
    for (int i = 1; i < n; i++) {
        if (start[index[i]] >= last_end) {  // If start time of the activity >= last selected activity's end time
            cout << "(" << start[index[i]] << ", " << end[index[i]] << ")\n";
            last_end = end[index[i]];  // Update the last end time
        }
    }

    return 0;
}
