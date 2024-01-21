// Vertex Cover
// HardAccuracy: 72.12%Submissions: 7K+Points: 8
// Boost your resume to top companies via this Free Hiring Contest!

// banner
// Vertex cover of an undirected graph is a list of vertices such that every vertex not in the vertex cover shares their every edge with the vertices in the vertex cover. In other words, for every edge in the graph, atleast one of the endpoints of the graph should belong to the vertex cover. You will be given an undirected graph G, and your task is to determine the smallest possible size of a vertex cover.

// Example 1:

// Input:
// N=5
// M=6
// edges[][]={{1,2}
//            {4, 1},
//            {2, 4},
//            {3, 4},
//            {5, 2},
//            {1, 3}}
// Output:
// 3
// Explanation:
// {2, 3, 4} forms a vertex cover
// with the smallest size.
// Example 2:

// Input:
// N=2
// M=1
// edges[][]={{1,2}}
// Output:
// 1
// Explanation:
// Include either node 1 or node 2
// in the vertex cover.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function vertexCover() which takes the edge list and an integer n for the number of nodes of the graph as input parameters and returns the size of the smallest possible vertex cover.

// Expected Time Complexity: O(M*N2log(N))
// Expected Auxiliary Space: O(N2)

//  Constraints:
// 1 <= N <= 16
// 1 <= M <= N*(N-1)/2
// 1 <= edges[i][0], edges[i][1] <= N

class Solution
{
public:
    map<pair<int, vector<int>>, int> mp;
    int solve(int n, vector<pair<int, int>> &edges, int i, vector<int> &vis)
    {
        if (i >= edges.size())
        {
            return 0;
        }
        if (mp.find({i, vis}) != mp.end())
        {
            return mp[{i, vis}];
        }
        int a = edges[i].first;
        int b = edges[i].second;
        if (vis[a] == 0 && vis[b] == 0)
        {
            vis[a] = 1;
            int val = solve(n, edges, i + 1, vis) + 1;
            vis[a] = 0;
            vis[b] = 1;
            int val1 = solve(n, edges, i + 1, vis) + 1;
            vis[b] = 0;
            return mp[{i, vis}] = min(val, val1);
        }
        return mp[{i, vis}] = solve(n, edges, i + 1, vis);
    }

    int vertexCover(int n, vector<pair<int, int>> &edges)
    {
        // code here
        vector<int> vis(n + 1, 0);
        return solve(n, edges, 0, vis);
    }
};
