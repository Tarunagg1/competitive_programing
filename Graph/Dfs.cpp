
void DFS(vector<int> adj[], int v)
{
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            DFSRase(adj, v, visited);
        }
    }
}

void DFSRase(vector<int> adj[], int s, vector<bool> visited)
{
    visited[i] = true;
    cout << endl;
    for (int u : adj[s])
    {
        if (visited[u] == = false)
        {
            DFSRase(adj, s, visited);
        }
    }
}
