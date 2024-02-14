// Find all Critical Connections in the Graph
// HardAccuracy: 50.25%Submissions: 11K+Points: 8
// Internship Alert!
// Become an SDE Intern by topping this monthly leaderboard!

// banner
// A critical connection refers to an edge that, upon removal, will make it impossible for certain nodes to reach each other through any path. You are given an undirected connected graph with v vertices and e edges and each vertex distinct and ranges from 0 to v-1, and you have to find all critical connections in the graph. It is ensured that there is at least one such edge present.

// Note: The answers may be presented in various potential orders. Each edge should be displayed in sorted order. For instance, if there's an edge between node 1 and node 2, it should be stored as (1,2) rather than (2,1). Additionally, it is expected that you store the edges in sorted order.

// Example 1:

// Input:

// Output:
// 0 1
// 0 2
// Explanation:
// On removing edge (0, 1), you will not be able to
// reach node 0 and 2 from node 1. Also, on removing
// edge (0, 2), you will not be able to reach node 0
// and 1 from node 2.
// Example 2:

// Input:

// Output:
// 2 3
// Explanation:
// The edge between nodes 2 and 3 is the only
// Critical connection in the given graph.
// Your task:
// You dont need to read input or print anything. Your task is to complete the function criticalConnections() which takes the integer v denoting the number of vertices and an adjacency list adj as input parameters and returns  a list of lists containing the Critical connections in the sorted order.

// Expected Time Complexity: O(v + e)
// Expected Auxiliary Space: O(v)

// Constraints:
// 1 ≤ v, e ≤ 104

class Solution
{
public:
    int dfs(vector<int> graph[], int i, vector<int> &rank, vector<vector<int>> &res, int prev_rank, int n)
    {
        // increment the current node's rank
        rank[i] = prev_rank + 1;
        int t = INT_MAX;
        // traverse the neibours
        for (const auto &nbr : graph[i])
        {
            if (rank[nbr] == -1)
            {
                // not visited
                int k = dfs(graph, nbr, rank, res, prev_rank + 1, n);
                if (k > rank[i])
                    // problem statement to store edges in order
                    res.push_back({min(i, nbr), max(i, nbr)});
                t = min(t, k);
            }
            else if (rank[nbr] == n + 1)
                continue;
            else if (rank[nbr] != prev_rank)
                t = min(t, rank[nbr]);
        }
        rank[i] = n + 1;
        return t;
    }
    vector<vector<int>> criticalConnections(int v, vector<int> adj[])
    {
        // Tarzan's Algorithm
        vector<vector<int>> res;
        vector<int> rank(v, -1);

        int k = dfs(adj, 0, rank, res, 0, v);
        sort(res.begin(), res.end());
        return res;
    }
};