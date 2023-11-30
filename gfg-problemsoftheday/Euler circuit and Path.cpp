// Euler circuit and Path
// MediumAccuracy: 50.89%Submissions: 15K+Points: 4
// GfG Weekly + You = Perfect Sunday Evenings!
// Register for free now

// banner
// An Eulerian Path is a path in graph that visits every edge exactly once and it starts and ends up at different indexes. An Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex. Given an undirected acyclic graph with V nodes, and E edges, with adjacency list adj, return 2 if the graph contains an eulerian circuit, else if the graph contains an eulerian path, return 1, otherwise, return 0.

// Example 1:

// Input:

// Output: 2
// Explanation:
// Following is an eulerian circuit in the mentioned graph
// 1 -> 2 -> 0 -> 1
// Example 2:

// Input:

// Output: 1
// Explanation:
// Following is an eulerian circuit in the mentioned graph
// 1 -> 0 -> 2
// Your Task:
// You don't need to read or print anything. Your task is to complete the function isEulerCircuilt() which takes number of vertices in the graph denoted as V and an adjacency list of graph denoted as adj and returns 2 if the graph contains an eulerian circuit, else if the graph contains an eulerian path, it returns 1, otherwise, it will return 0.

// Expected Time Complexity: O(V+E) where E is the number of edges in graph.
// Expected Space Complexity: O(V)

// Constraints:
// 1 ≤ V, E ≤ 104
// 1 ≤ adj[i][j] ≤ V-1

class Solution
{
public:
    int isEulerCircuit(int V, vector<int> adj[])
    {
        // Code here
        int odd = 0, even = 0;
        // counting degree of all nodes, odd and even degree nodes
        for (int i = 0; i < V; i++)
        {
            if (adj[i].size() % 2 == 0)
                even++;
            else
                odd++;
        }

        // for undirected graph
        // euler circuit must have all node with even degree
        // euler circuit must have all even degree node with almost 2 odd degree nodes
        if (even == V)
            return 2;
        else if (odd > 0 and odd == 2)
            return 1;

        return 0;
    }
};
