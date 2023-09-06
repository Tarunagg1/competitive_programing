// Mother Vertex
// EasyAccuracy: 47.64%Submissions: 39K+Points: 2
// Given a Directed Graph, find a Mother Vertex in the Graph (if present).
// A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.

// Example 1:

// Input:

// Output: 0
// Explanation: According to the given edges, all
// nodes can be reaced from nodes from 0, 1 and 2.
// But, since 0 is minimum among 0,1 and 2, so 0
// is the output.
// Example 2:

// Input:

// Output: -1
// Explanation: According to the given edges,
// no vertices are there from where we can
// reach all vertices. So, output is -1.
// Your Task:
// You don't need to read or print anything. Your task is to complete the function findMotherVertex() which takes V denoting the number of vertices and adjacency list as imput parameter and returns the verticex from through which we can traverse all other vertices of the graph. If there is more than one possible nodes then returns the node with minimum value.If not possible returns -1.

// Expected Time Complexity: O(V + E)
// Expected Space Compelxity: O(V)

// Constraints:
// 1 ≤ V ≤ 500

// Topic Tags

class Solution
{
public:
    // Function to find a Mother Vertex in the Graph.
    void dfs(int s, vector<int> adj[], vector<bool> &visited)
    {
        visited[s] = true;
        for (auto helper : adj[s])
        {
            if (!visited[helper])
                dfs(helper, adj, visited);
        }
    }

    int findMotherVertex(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        int ans;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited);
                ans = i;
            }
        }

        fill(visited.begin(), visited.end(), false);
        dfs(ans, adj, visited);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                return -1;
        }

        return ans;
    }
};
