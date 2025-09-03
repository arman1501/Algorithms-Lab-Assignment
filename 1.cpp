//1. Write a code to implement topological sort in a weighted graph.

#include <bits/stdc++.h> // All header file.
using namespace std;

int graph[1001][1001]; // Adjency metrix for 1000 nodes.
int visit[1001];       // visited array.
vector<int> ans;       // Using vector for store topological order results.

int n, e; // Define two varibale in global.

// Calling DFS function (recursive)
void DFS(int start)
{
    visit[start] = 1; // Current node e visited hole mark korbe.

    // Using for loop and traverse all possible adjency metrix.
    for (int j = 1; j <= n; j++)
    {
        if (visit[j] == 0 && graph[start][j] != 0) // Using condition.
        {
            DFS(j); // Recursive DFS call.
        }
    }

    ans.push_back(start); // Node added hbe jkn all children processed hbe.
}



int main() // Main function.
{
    cin >> n >> e; // Input n and e.

    int u, v, w;

    // Use for loop and input each edge.
    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v >> w;
        graph[u][v] = w; // adjacency matrix e weight rakha holo.
    }

    // Run DFS all nodes.
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == 0)
        {
            DFS(i);
        }
    }

    // Reverse the DFS finishing order to get Topological Order
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " "; // print output.
    }
    cout << endl; // print new line.

    return 0; // Program end.
}
