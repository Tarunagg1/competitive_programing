// Possible Paths in a Tree
// HardAccuracy: 81.17%Submissions: 6K+Points: 8
// Share your experience with the world! Submit your admission, interview, campus or any other experience and reach an audience of millions today!

// banner
// Given a weighted tree with n nodes and (n-1) edges. You are given q queries. Each query contains a number x. For each query, find the number of paths in which the maximum edge weight is less than or equal to x.

// Note: Path from A to B and B to A are considered to be the same.

// Example 1:

// Input:
// n = 3
// edges {start, end, weight} = {{1, 2, 1}, {2, 3, 4}}
// q = 1
// queries[] = {3}
// Output:
// 1
// Explanation:
// Query 1: Path from 1 to 2
// Example 2:

// Input:
// n = 7
// edges {start, end, weight} = {{1, 2, 3}, {2, 3, 1}, {2, 4, 9}, {3, 6, 7}, {3, 5, 8}, {5, 7, 4}}
// q = 3
// queries[] = {1, 3, 5}
// Output:
// 1 3 4
// Explanation:
// Query 1: Path from 2 to 3
// Query 2: Path from 1 to 2, 1 to 3, and 2 to 3
// Query 3: Path from 1 to 2, 1 to 3, 2 to 3, and 5 to 7
// Your Task:
// You don't need to read input or print anything. Complete the function maximumWeight()which takes integers n, list of edges where each edge is given by {start,end,weight}, an integer q and a list of q queries as input parameters and returns a list of integers denoting the number of possible paths for each query.

// Expected Time Complexity: O(nlogn + qlogn)
// Expected Auxiliary Space: O(n)

// Constraints:
// 2 ≤ n ≤ 104
// 1 ≤ q ≤ 104
// 1 ≤ edges[i][0], edges[i][1] ≤ n
// edges[i][0] != edges[i][1]
// 0 ≤ edges[i][2] ≤ 105
// 0 ≤ queries[i] ≤ 105

// Topic Tags

class Solution
{
public:
    int dsu(vector<pair<int, int>> &parent, int x)
    {
        if (parent[x].first == x)
        {
            return x;
        }
        return parent[x].first = dsu(parent, parent[x].first);
    }
    vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
    {
        // code here
        vector<pair<int, int>> Q(q);
        for (int i = 0; i < q; i++)
        {
            Q[i].first = queries[i];
            Q[i].second = i;
        }
        sort(Q.begin(), Q.end());
        for (int i = 0; i < n - 1; i++)
        {
            swap(edges[i][0], edges[i][2]);
        }
        sort(edges.begin(), edges.end());
        vector<pair<int, int>> parent(n);
        for (int i = 0; i < n; i++)
        {
            parent[i].first = i;
            parent[i].second = 1;
        }
        vector<int> ans(q);
        int i = 0, last = 0;
        for (int j = 0; j < q; j++)
        {
            while (i < n - 1 && edges[i][0] <= Q[j].first)
            {
                int u = edges[i][1] - 1, v = edges[i][2] - 1;
                int paru = dsu(parent, u), parv = dsu(parent, v);
                int cu = parent[paru].second, cv = parent[parv].second;
                last -= (cu * (cu - 1)) / 2;
                last -= (cv * (cv - 1)) / 2;
                parent[parv].first = paru;
                parent[paru].second += parent[parv].second;
                dsu(parent, parv);
                cu += cv;
                last += (cu * (cu - 1)) / 2;
                i++;
            }
            ans[Q[j].second] = last;
        }
        return ans;
    }
};
