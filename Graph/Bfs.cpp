#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 0 - 1 - 2
// 1 - 0 - 2 - 3
// 2 - 3 - 1 - 0 - 4
// 3 - 1 - 2 - 4
// 4 - 3 - 2

void BFS(vector<int> adj[], int v, int s)
{
    vector<bool> visited(v + 1, false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u])
        {
            if (adj[v] == false)
            {
                visited[v] = false;
                q.push(v);
            }
        }
    }
}
