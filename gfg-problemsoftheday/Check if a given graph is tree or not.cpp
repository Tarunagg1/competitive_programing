// Check if a given graph is tree or not
// MediumAccuracy: 56.02%Submissions: 10K+Points: 4
// Got your Geekbits? Now Get 90% Of Your Course Fee Refund!

// banner
// You are given an undirected graph of N nodes and M edges. Return 1 if the graph is a tree, else return 0.

// Note: The input graph can have self-loops and multiple edges.

// Example 1:

// Input:
// N = 4, M = 3
// G = [[0, 1], [1, 2], [1, 3]]
// Output:
// 1
// Explanation:
// Every node is reachable and the graph has no loops, so it is a tree
// Example 2:

// Input:
// N = 4, M = 3
// G = [[0, 1], [1, 2], [2, 0]]
// Output:
// 0
// Explanation:
// 3 is not connected to any node and there is a loop 0->1->2->0, so it is not a tree.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isTree() which takes the integer N (the number nodes in the input graph) and the edges representing the graph as input parameters and returns 1 if the input graph is a tree, else 0.

// Expected Time Complexity: O(N+M)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <= 2*105
// 0 <= M <= 2*105

// Topic Tags

class Solution
{
public:
    bool dfs(int node, vector<int> adjList[], int vis[], int parent)
    {
        vis[node] = 1;
        for (auto it : adjList[node])
        {
            if (!vis[it])
            {
                if (dfs(it, adjList, vis, node) == true)
                {
                    return true;
                }
            }
            else if (it != parent)
            {
                return true;
            }
        }
        return false;
    }
    int isTree(int n, int m, vector<vector<int>> &adj)
    {
        // code here
        vector<int> adjList[n];
        for (auto it : adj)
        {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        int vis[n] = {0};
        if (dfs(0, adjList, vis, -1) == true)
        {
            return false;
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                return false;
            }
        }
        return true;
    }
};
