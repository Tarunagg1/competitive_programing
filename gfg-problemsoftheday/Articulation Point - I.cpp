// Articulation Point - I
// HardAccuracy: 39.26%Submissions: 12K+Points: 8
// Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components.
// Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

// Example 1:

// Input:

// Output:{1,4}
// Explanation: Removing the vertex 1 will
// discconect the graph as-

// Removing the vertex 4 will disconnect the
// graph as-

// Your Task:
// You don't need to read or print anything. Your task is to complete the function articulationPoints() which takes V and adj as input parameters and returns a list containing all the vertices removing which turn the graph into two or more disconnected components in sorted order. If there are no such vertices then returns a list containing -1.

// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)

// Constraints:
// 1 ≤ V ≤ 105

// View Bookmarked Problems

void solve(int node, vector<int> &dis, vector<int> &low, vector<bool> &vis, int par, vector<int> adj[], int &timer, vector<int> &art)
{
    vis[node] = true;
    dis[node] = low[node] = timer++;
    int child = 0;
    for (auto &x : adj[node])
    {
        if (x == par)
            continue;
        if (vis[x] == false)
        {
            solve(x, dis, low, vis, node, adj, timer, art);
            low[node] = min(low[node], low[x]);
            if (low[x] >= dis[node] && par != -1)
            {
                art[node] = 1;
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], dis[x]);
        }
    }
    if (par == -1 && child > 1)
    {
        art[node] = 1;
    }
}
vector<int> articulationPoints(int V, vector<int> adj[])
{
    vector<int> dis(V, -1);
    vector<int> low(V, -1);
    vector<bool> vis(V, 0);
    int timer = 0;
    vector<int> art(V, 0);
    solve(0, dis, low, vis, -1, adj, timer, art);
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (art[i] == 1)
        {
            ans.push_back(i);
        }
    }
    if (ans.size() == 0)
        ans.push_back(-1);
    return ans;
}
