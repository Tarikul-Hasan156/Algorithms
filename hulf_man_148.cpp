#include<bits/stdc++.h>
using namespace std;

#define MAX 100
#define MAX_TREE_HT 100

// Node structure to represent each node in the Huffman Tree
class Node {
public:
    char character;   // Character associated with the node
    int frequency;    // Frequency of the character
    int left;         // Index of the left child in the nodes array
    int right;        // Index of the right child in the nodes array
};

// Global array of nodes
Node nodes[MAX];
int nodeCount = 0; // Total number of nodes created

// Create a new node and return its index
int createNode(char character, int frequency, int left, int right) {
    nodes[nodeCount].character = character; // Assign character to the node
    nodes[nodeCount].frequency = frequency; // Assign frequency to the node
    nodes[nodeCount].left = left;           // Assign left child index
    nodes[nodeCount].right = right;         // Assign right child index
    return nodeCount++;                     // Return the index of the newly created node
}

// Sorts an array of node indices by frequency using selection sort
void sort(int index[], int n) {
    for (int i = 0; i < n - 1; i++) {  // Iterate over the array
        int min = i;  // Assume the current element is the smallest
        for (int j = i + 1; j < n; j++) {  // Compare with the rest of the array
            if (nodes[index[j]].frequency < nodes[index[min]].frequency) {  // If a smaller frequency is found
                min = j;  // Update the index of the smallest element
            }
        }
        int temp = index[i];  // Swap the current element with the smallest element
        index[i] = index[min];
        index[min] = temp;
    }
}

// Recursive function to print the Huffman Codes
void printCodes(int rootIndex, int code[], int top) {
    // Check if there is a left child
    if (nodes[rootIndex].left != -1) {
        code[top] = 0;  // Assign 0 for left child
        printCodes(nodes[rootIndex].left, code, top + 1); // Recurse left
    }

    // Check if there is a right child
    if (nodes[rootIndex].right != -1) {
        code[top] = 1;  // Assign 1 for right child
        printCodes(nodes[rootIndex].right, code, top + 1); // Recurse right
    }

    // Leaf node found, print its character and code
    if (nodes[rootIndex].left == -1 && nodes[rootIndex].right == -1) {
        cout << nodes[rootIndex].character << ": ";  // Print the character
        for (int i = 0; i < top; i++) {  // Print the Huffman code for this character
            cout << code[i];
        }
        cout << endl;  // Move to the next line after printing the code
    }
}

// Builds the Huffman Tree and returns root index
int buildHuffmanTree(char characters[], int frequency[], int size) {
    int active[MAX];  // Array to hold active nodes (leaf nodes initially)
    int activeCount = size;  // Initially, the number of active nodes is the size

    // Create leaf nodes and store them in the active array
    for (int i = 0; i < size; i++) {
        active[i] = createNode(characters[i], frequency[i], -1, -1);  // Leaf nodes have no children
    }

    // Build the tree by merging the two nodes with the smallest frequencies
    while (activeCount > 1) {  // While more than one node exists
        sort(active, activeCount);  // Sort the active nodes by frequency

        int left = active[0];  // Get the index of the node with the smallest frequency
        int right = active[1]; // Get the index of the second smallest node

        // Create a new internal node with the combined frequency of the left and right nodes
        int newNodeIndex = createNode('$', nodes[left].frequency + nodes[right].frequency, left, right);

        // Shift the active nodes to make space for the new node
        for (int i = 2; i < activeCount; i++) {
            active[i - 2] = active[i];
        }

        active[activeCount - 2] = newNodeIndex;  // Add the new node to the active array
        activeCount--;  // Decrease the active node count
    }

    return active[0];  // Return the index of the root node (last remaining node)
}

int main() {
    int size;
    cout << "Enter the number of characters: ";  // Ask user for the number of characters
    cin >> size;  // Read the number of characters

    char characters[size];  // Array to store characters
    int frequency[size];    // Array to store corresponding frequencies

    // Input characters and their frequencies
    cout << "Enter the characters and their frequencies:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Character " << i + 1 << ": ";
        cin >> characters[i];  // Read the character
        cout << "Frequency of " << characters[i] << ": ";
        cin >> frequency[i];  // Read the frequency of the character
    }

    int root = buildHuffmanTree(characters, frequency, size);  // Build the Huffman tree and get the root index

    int code[MAX_TREE_HT];  // Array to store the Huffman code
    int top = 0;  // Variable to track the current depth of the code

    cout << "Huffman Codes for the characters are:" << endl;
    printCodes(root, code, top);  // Print the Huffman codes starting from the root

    return 0;
}
