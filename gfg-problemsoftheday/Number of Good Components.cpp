// Number of Good Components
// MediumAccuracy: 73.67%Submissions: 2K+Points: 4
// Lamp
// Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!

// Given an undirected graph with V vertices(numbered from 1 to V) and E edges. Find the number of good components in the graph.
// A component of the graph is good if and only if the component is a fully connected component.
// Note: A fully connected component is a subgraph of a given graph such that there's an edge between every pair of vertices in a component, the given graph can be a disconnected graph. Consider the adjacency list from index 1.

// Example 1:

// Input:

// Output: 1
// Explanation: We can see that there is only one
// component in the graph and in this component
// there is a edge between any two vertces.
// Example 2:

// Input:

// Output: 2
// Explanation: We can see that there are 3 components
// in the graph. For 1-2-7 there is no edge between
// 1 to 7, so it is not a fully connected component.
// Rest 2 are individually fully connected component.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function
// findNumberOfGoodComponent() which takes an integer V and an adjacency list adj as input parameters and returns an integer denoting the number of good components.

// Expected Time Complexity: O(V+E)
// Expected Auxiliary Space: O(depth of the graph)

// Constraints:
// 1 ≤ V, E ≤ 104

// View Bookmarked Problems

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, int size, bool &flag, int &cv, vector<int> &vis)
    {
        vis[node] = 1;
        cv++;
        if (size != adj[node].size())
            flag = true;
        for (auto i : adj[node])
        {
            if (!vis[i])
                dfs(i, adj, size, flag, cv, vis);
        }
    }
    int findNumberOfGoodComponent(int V, vector<vector<int>> &adj)
    {
        vector<int> vis(V + 1);
        int count = 0;

        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                bool flag = false; // to test wether all the vertices have same indegree
                int cv = 0;        // to count vertices in a component

                dfs(i, adj, adj[i].size(), flag, cv, vis);

                if (!flag and cv == adj[i].size() + 1)
                    count++;
            }
        }

        return count;
    }
};
