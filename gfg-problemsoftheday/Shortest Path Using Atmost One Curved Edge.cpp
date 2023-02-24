// Shortest Path Using Atmost One Curved Edge
// HardAccuracy: 80.79%Submissions: 2K+Points: 8
// Lamp
// Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!

// Given an undirected connected graph of n vertices and list of m edges in a graph and for each pair of vertices that are connected by an edge.

// There are two edges between them, one curved edge and one straight edge i.e. the tuple (x, y, w1, w2) means that between vertices x and y, there is a straight edge with weight w1 and a curved edge with weight w2.

// You are given two vertices a and b and you have to go from a to b through a series of edges such that in the entire path you can use at most 1 curved edge. Your task is to find the shortest path from a to b satisfying the above condition. If there is no path from a to b, return -1.

// Example 1:

// Input:
// n = 4, m = 4
// a = 2, b = 4
// edges = {{1, 2, 1, 4}, {1, 3, 2, 4},
//          {1, 4, 3, 1}, {2, 4, 6, 5}}
// Output:
// 2

// Explanation:
// We can follow the path 2 -> 1 -> 4.
// This gives a distance of 1+3 = 4 if we follow
// all straight paths. But we can take the curved
// path  from 1 -> 4, which costs 1. This
// will result in a cost of 1+1 = 2
// Example 2:
// Input:
// n = 2, m = 1
// a = 1, b = 2
// edges = {{1, 2, 4, 1}}
// Output :
// 1

// Explanation:
// Take the curved path from 1 to 2 which costs 1.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function shortestPath() which takes 4 integers n, m, a, and b, and a list of lists named edges of size m as input and returns the cost of shortest path from a to b.

// Expected Time Complexity: O((m+n)log(n))
// Expected Auxiliary Space: O(n+m)

// Constraints:
// 1 ≤ n,m ≤ 105
// 1 ≤ a,b ≤ n
// weight of edges ≤ 104

// View Bookmarked Problems

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dis(V + 5, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // store distance and node
    dis[S] = 0;
    pq.push({0, S});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis_curr = pq.top().first;
        pq.pop();
        for (auto &it : adj[node])
        {
            int nxt_dis = dis_curr + it[1];
            if (dis[it[0]] > nxt_dis)
            {
                dis[it[0]] = nxt_dis;
                pq.push({nxt_dis, it[0]});
            }
        }
    }
    return dis;
}
int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges)
{
    vector<vector<int>> adj[n + 5];
    for (auto &x : edges)
    {
        adj[x[0]].push_back({x[1], x[2]});
        adj[x[1]].push_back({x[0], x[2]});
    }
    vector<int> disa = dijkstra(n, adj, a);
    vector<int> disb = dijkstra(n, adj, b);
    int ans = disa[b];
    for (auto x : edges)
    {
        if (disa[x[0]] != INT_MAX && disb[x[1]] != INT_MAX)
        {
            int now = disa[x[0]] + disb[x[1]] + x[3];
            ans = min(ans, now);
        }
        swap(x[0], x[1]);
        if (disa[x[0]] != INT_MAX && disb[x[1]] != INT_MAX)
        {
            int now = disa[x[0]] + disb[x[1]] + x[3];
            ans = min(ans, now);
        }
    }
    return ans == INT_MAX ? -1 : ans;
}
