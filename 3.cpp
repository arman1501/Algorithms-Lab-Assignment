// 3. Write a code to run BFS on a bidirectional weighted graph using an Adjacency Matrix.

#include <bits/stdc++.h>
using namespace std;

int graph[1001][1001]; // adjacency matrix (weight stored)
int visit[1001];       // visited array
int n, e;              // number of nodes and edges

// Calling BFS void type function.
void BFS(int start)
{
    // Initial Step: mark start node as visited and push into queue
    visit[start] = 1;
    cout << start << " ";
    queue<int> Q;
    Q.push(start);

    // Repeat until queue is empty
    while (!Q.empty())
    {
        int x = Q.front(); // get front node
        Q.pop();

        // traverse all nodes
        for (int j = 1; j <= n; j++)
        {
            // If there is an edge (weight != 0) and node j is not visited
            if (graph[x][j] != 0 && visit[j] == 0)
            {
                visit[j] = 1;     // mark visited
                cout << j << " "; // print node
                Q.push(j);        // add to queue
            }
        }
    }
}

int main()
{
    cin >> n >> e; // input number of nodes and edges
    int u, v, w;

    // input bidirectional weighted edges
    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v >> w; // edge u <-> v with weight w
        graph[u][v] = w;    // directed weight
        graph[v][u] = w;    // because bidirectional
    }

    BFS(1); // start BFS from node 1

    return 0;
}
