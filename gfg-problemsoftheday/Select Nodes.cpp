// Select Nodes
// HardAccuracy: 80.96%Submissions: 1K+Points: 8
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// Given N nodes of a tree and a list of edges. Find the minimum number of nodes to be selected to light up all the edges of the tree.
// An edge lights up when at least one node at the end of the edge is selected.

// Example 1:

// Input:
// N = 6
// edges[] = {(1,2), (1,3), (2,4), (3,5), (3,6)}
// Output: 2
// Explanation: Selecting nodes 2 and 3 lights
// up all the edges.
// Example 2:

// Input:
// N = 3
// arr[] = {(1,2), (1,3)}
// Output: 1
// Explanation: Selecting Node 1
// lights up all the edges.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function countVertex() which takes the number of nodes N, and the list of edges as input parameters and returns the minimum number of nodes selected.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ edges ≤ N
// Given graph is a valid tree.

// View Bookmarked Problems

class Solution
{
public:
    void dfs(const vector<vector<int>> &nodes, const int src, const int act, vector<pair<int, int>> &dp)
    {
        for (const auto &i : nodes[src])
            if (i != act)
                dfs(nodes, i, src, dp);
        for (const auto &i : nodes[src])
            if (i != act)
            {
                dp[src].first += dp[i].second;
                dp[src].second += min(dp[i].first, dp[i].second);
            }
    }

    int countVertex(int N, vector<vector<int>> edges)
    {
        vector<vector<int>> nodes(N);
        for (const auto &e : edges)
        {
            nodes[e[0] - 1].push_back(e[1] - 1);
            nodes[e[1] - 1].push_back(e[0] - 1);
        }
        vector<pair<int, int>> dp(N, {0, 1});
        dfs(nodes, 0, 0, dp);
        return min(dp[0].first, dp[0].second);
    }
};
