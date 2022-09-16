// Number of Ways to Arrive at Destination
// MediumAccuracy: 48.81%Submissions: 127Points: 4
// You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

// You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

// Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

// Example:
// Input:
// n=7, m=10
// edges= [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]

// Output:
// 4
// Explaination:

// The four ways to get there in 7 minutes are:
// - 0  6
// - 0  4  6
// - 0  1  2  5  6
// - 0  1  3  5  6

// Constraints:
// 1 <= n <= 200
// n - 1 <= roads.length <= n * (n - 1) / 2
// roads[i].length == 3
// 0 <= ui, vi <= n - 1
// 1 <= timei <= 109
// ui != vi
// There is at most one road connecting any two intersections.
// You can reach any intersection from any other intersection.

// Expected Time Complexity: O(M * logN + N)
// Expected Space Complexity: O(M+N)

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        // code here
        long long mod = 1e9 + 7;
        long long ans = 0;
        vector<vector<pair<int, int>>> adj(n);
        vector<long long> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < roads.size(); ++i)
        {
            adj[roads[i][0]].push_back({roads[i][2], roads[i][1]});
            adj[roads[i][1]].push_back({roads[i][2], roads[i][0]});
        }

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto a = pq.top();
            pq.pop();

            int wtillnow = a.first;
            int curr = a.second;
            for (auto it : adj[curr])
            {
                int wtwithadj = it.first + wtillnow;
                int u = it.second;

                if (u == (n - 1))
                {
                    if (dist[u] > wtwithadj)
                    {
                        dist[u] = wtwithadj;
                        ans = 0;
                    }
                    if (dist[u] == wtwithadj)
                        ans = (ans + 1) % mod;
                    continue;
                }
                if (dist[u] >= wtwithadj)
                {
                    dist[u] = wtwithadj;
                    pq.push({dist[u], u});
                }
            }
        }
        return ans;
    }
};
