// Negative weight cycle
// Medium Accuracy: 50.77% Submissions: 20293 Points: 4
// Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
// Note: edges[i] is defined as u, v and weight.

// Example 1:

// Input: n = 3, edges = {{0,1,-1},{1,2,-2},
// {2,0,-3}}
// Output: 1
// Explanation: The graph contains negative weight
// cycle as 0->1->2->0 with weight -1,-2,-3.
// Example 2:

// Input: n = 3, edges = {{0,1,-1},{1,2,-2},
// {2,0,3}}
// Output: 0
// Explanation: The graph does not contain any
// negative weight cycle.

// Your Task:
// You don't need to read or print anyhting. Your task is to complete the function isNegativeWeightCycle() which takes n and edges as input paramater and returns 1 if graph contains negative weight cycle otherwise returns 0.

// Expected Time Complexity: O(n*m)
// Expected Space Compelxity: O(n)

// Constraints:
// 1 <= n <= 100
// 1 <= m <= n*(n-1), where m is the total number of Edges in the directed graph.

// View Bookmarked Problems
// Company Tags
// Topic Tags

class Solution
{
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        // Code here

        vector<int> store(n, INT_MAX);
        store[0] = 0;
        for (int v = 0; v < (n - 1); v++)
        {
            for (int i = 0; i < edges.size(); i++)
            {
                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];
                if (store[u] != INT_MAX && store[v] > store[u] + w)
                    store[v] = store[u] + w;
            }
        }

        // detection for negative weight cycle
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if (store[u] != INT_MAX && store[v] > store[u] + w)
                return 1;
        }
        return 0;
    }
}
