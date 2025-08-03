#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;            // Defines the maximum number of nodes or queue size
class Queue                          // Define a Queue named class
{
    int arr[MAX];                // Array to store queue elements
    int front, rear;               // Indices for front and rear of queue

public:                              //Constructor
    Queue()
    {
        front = rear = -1;                  // Queue is empty at first
    }
    bool isEmpty()
    {
        return front == -1;                   // If front is -1, queue is empty
    }

    bool isFull()
    {
        return (rear + 1) % MAX == front;                // If front is -1, queue is empty
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is full\n";               // Cannot insert if the queue is full
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;                    // First element inserted
        }
        else
        {
            rear = (rear + 1) % MAX;              // Move rear forward circularly
        }
        arr[rear] = val;                 // Insert value at rear
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;                // Return -1 if the queue is empty
        }
        int val = arr[front];                // Get front value
        if (front == rear)
        {
            front = rear = -1;                // Reset if only one element was present
        }
        else
        {
            front = (front + 1) % MAX;               // Move front forward
        }
        return val;                    // Return dequeued value
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";                     //check if the queue is empty
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";             // Print current element
            if (i == rear) break;                // Stop if rear reached
            i = (i + 1) % MAX;                    // Move circularly
        }
        cout << endl;
    }
};

void inputEdgesToAdjMatrix(int adj[MAX][MAX], int n, int e)
{
    for (int i = 0; i < n; i++)                //use here two for loop for 2D array representation
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;                  // Initialize matrix to 0 (no edges)

    cout << "Enter edges (source destination):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;                         // Read edge from user
        if (u >= 0 && u < n && v >= 0 && v < n)
        {
            adj[u][v] = 1;                       // Set edge u → v
            adj[v][u] = 1;                      // For undirected graph, also set v → u
        }
        else
        {
            cout << "Invalid nodes. Try again.\n";
                     // Retry if invalid
        }
    }
}
void printAdjMatrix(int adj[MAX][MAX], int n)
{
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++)                       //two loop for row and column
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";               // Print each row
        }
        cout << endl;
    }
}

void bfs(int adj[MAX][MAX], int n, int start)
{
    bool visited[MAX] = {false};                // Track visited nodes
    Queue q;

    visited[start] = true;                  // Mark start as visited
    q.enqueue(start);                     // Enqueue start node

    cout << "\nBFS Traversal " << start << ": ";

    while (!q.isEmpty())
    {
        int node = q.dequeue();                     // Dequeue a node
        cout << node << " ";                        // Print the visited node

        for (int i = 0; i < n; i++)
        {
            if (adj[node][i] == 1 && !visited[i])
            {
                visited[i] = true;                     // Mark neighbor as visited
                q.enqueue(i);                       // Enqueue neighbor
            }
        }
    }
    cout << endl;
}
int main()
{
    int n, e;
    int adj[MAX][MAX];

    cout << "Enter number of nodes: ";
    cin >> n;                                     // Input number of nodes

    cout << "Enter number of edges: ";
    cin >> e;                                    // Input number of edges

    inputEdgesToAdjMatrix(adj, n, e);                     // Read and store graph
    printAdjMatrix(adj, n);                    // Print adjacency matrix

    int startNode;
    cout << "Enter the start node for BFS: ";
    cin >> startNode;                // Input start node for BFS

    if (startNode < 0 || startNode >= n)
    {
cout << "Invalid start node.\n";
// Validate input
return 1;
}
bfs(adj, n, startNode);
return 0;
}

