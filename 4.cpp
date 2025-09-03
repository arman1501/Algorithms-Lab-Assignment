#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e; // n = number of nodes, e = number of edges
    cin >> n >> e;

    // Adjacency Matrix
    int adjMatrix[1001][1001];               // declare matrix
    memset(adjMatrix, 0, sizeof(adjMatrix)); // initialize all to 0


    int u, v, w;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;  // input edge u->v with weight w
        adjMatrix[u][v] = w; // set weight
        adjMatrix[v][u] = w; // bidirectional
    }

    // Print adjacency matrix
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }

    // Adjacency list.
    vector<pair<int, int>> adjList[1001]; // each node stores pair {neighbor, weight}

    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        adjList[u].push_back({v, w}); // add neighbor with weight
        adjList[v].push_back({u, w}); // bidirectional
    }

    // Print adjacency list
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for (auto edge : adjList[i])
        {
            cout << "(" << edge.first << "," << edge.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
