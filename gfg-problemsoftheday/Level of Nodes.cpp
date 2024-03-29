// Level of Nodes
// MediumAccuracy: 50.95%Submissions: 26K+Points: 4
// Full stack, Backend development, Data Science & other trending courses at upto 35% Off

// banner
// Given an integer X and an undirected acyclic graph with V nodes, labeled from 0 to V-1, and E edges, find the level of node labeled as X.

// Level is the minimum number of edges you must travel from the node 0 to some target.

// If there doesn't exists such a node that is labeled as X, return -1.

// Example 1:

// Input:

// X = 4
// Output:
// 2
// Explanation:

// We can clearly see that Node 4 lies at Level 2.
// Example 2:

// Input:

// X = 1
// Output:
// 1
// Explanation:
// Node 1 lies at level 1, immediate after Node 0.
// Your task:
// You dont need to read input or print anything. Your task is to complete the function nodeLevel() which takes two integers V and X denoting the number of vertices and the node, and another adjacency list adj as input parameters and returns the level of Node X. If node X isn't present it returns -1.

// Expected Time Complexity: O(V)
// Expected Auxiliary Space: O(V)

// Constraints:
// 2 ≤ V ≤ 104
// 1 ≤ E ≤ 104
// 0 ≤ adji, j < V
// 1 ≤ X < V
// Graph doesn't contain multiple edges and self loops.

class Solution
{
public:
    // Function to find the level of node X.
    int nodeLevel(int V, vector<int> adj[], int X)
    {
        // code here

        queue<int> q;
        q.push(0);
        vector<int> vis(V, 0);
        int l = 0;

        while (!q.empty())
        {
            int s = q.size();

            while (s--)
            {
                int front = q.front();
                q.pop();

                if (front == X)
                    return l;

                for (auto i : adj[front])
                {
                    if (vis[i] == 0)
                    {
                        q.push(i);
                        vis[i] = 1;
                    }
                }
            }
            l++;
        }
        return -1;
    }
};
