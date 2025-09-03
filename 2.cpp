//2. Write a code to run DFS on a directed weighted graph using Adjacency List.

#include <bits/stdc++.h> // All header file.
using namespace std;

int n, e; // input from users vertiex (n) and edge (e).

vector<pair<int, int>> adj[1001]; // Using vector for adjacency list.
int visit[1001];                  // visited array

// Calling void type DFS recursive funcation.
void DFS_Rec(int start)
{
    // Inatial Step:

    visit[start] = 1;     // Mark the visited node
    cout << start << " "; // Print the visited node.

    // Using loop and travers all current nodes.
    for (int i = 0; i < adj[start].size(); i++)
    {
        int v = adj[start][i].first;  // Neighbor node
        int w = adj[start][i].second; // Weight not used in DFS.

        if (visit[v] == 0) // Use condition and if neighbor is not visited.
        {
            DFS_Rec(v); // recursive called.
        }
    }
}

// Main function.
int main()
{
    cin >> n >> e; // Input from users two variables.
    int u, v, w;   // Define 3 weighted variables.

    // input directed weighted edges.
    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // Store in adjacency list.
    }

    DFS_Rec(1); // Recursion method.

    return 0; // End the program
}
