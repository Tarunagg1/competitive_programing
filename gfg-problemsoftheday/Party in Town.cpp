// Party in Town
// Medium Accuracy: 66.64% Submissions: 896 Points: 4
// Geek town has N Houses numbered from 1 to N. They are connected with each other via N-1 bidirectional roads and an adjacency list is used to represent the connections. Find the house from which the distance to the farthest house is the minimum to host the optimal party.

// Example 1:

// Input:
// N = 4
// Roads = {{1,2},{2,3},{2,4}}
// adj = {{2},{1,3,4},{2},{2}}

// Output: 1

// Explaination: Maximum distance from house number 2 is 1.

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function partyHouse() which takes N and adj as input parameters and returns the minimum possible distance to the farthest house from the house where the party is happening.

// Expected Time Complexity: O(N*N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 1000

// View Bookmarked Problems
// Topic Tags

class Solution
{
public:
    int maxd = 0;
    void dfs(int ind, vector<vector<int>> &adj, vector<int> &vis, int c)
    {
        vis[ind] = 1;
        maxd = max(maxd, c); // max depth to which a node goes
        for (int i : adj[ind])
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, c + 1);
            }
        }
    }
    int partyHouse(int N, vector<vector<int>> &adj)
    {

        int mx = INT_MAX;
        int house = -1;

        for (int i = 1; i <= N; i++)
        {
            vector<int> vis(N + 1, 0);
            maxd = 0;
            dfs(i, adj, vis, 0); // for each find maxdeptht to which it goes and finally find min of it

            if (maxd < mx)
            {
                mx = maxd;
            }
        }
        return mx;
    }
};
