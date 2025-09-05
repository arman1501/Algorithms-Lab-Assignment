// 4. Write a code to take a graph as input using a matrix and a list.
#include <bits/stdc++.h> // All header file.
using namespace std;

int main() // Main function use.
{
    int node, edge;      // Define two variables.
    cin >> node >> edge; // Input from users of two variables.

    // Adjacency Matrix.
    int graph[node + 1][node + 1];
    memset(graph, 0, sizeof(graph)); // Full matrix k 0 diye initialize korci.

    // Adjacency list.
    vector<int> adjList[node + 1]; // Using vector for store neighbor node.

    int u, v, w;                    // Define 3 variables.
    for (int i = 1; i <= edge; i++) // Using for loop for input from users.
    {
        cin >> u >> v >> w;

        // Matrix update. Undirected weighted tai two side e weight bosate hbe.
        graph[u][v] = w; // u -> v er weight.
        graph[v][u] = w; // v -> u er weight

        // List e sudhu neighbor node rakhci.
        adjList[u].push_back(v); // u er neighbor v.
        adjList[v].push_back(u); // v er neighbor u.
    }

    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            cout << graph[i][j] << " "; // Print adjacency metrix.
        }
        cout << endl; // New line.
    }

    cout << endl;   // More space that's why use another new line for better output.

    for (int i = 1; i <= node; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < (int)adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " "; // Print adjacency list.
        }
        cout << endl; // New line.
    }

    return 0; // Program end.
}
