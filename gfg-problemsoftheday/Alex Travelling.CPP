// Alex Travelling
// MediumAccuracy: 57.7%Submissions: 402+Points: 4
// Alex is very fond of traveling. There are n cities, labeled from 1 to n.  You are also given flights, a list of travel flights as directed weighted edges flights[i] = (ui,vi,wi) where ui is the source node, vi is the target node, and wi is the price it takes for a person to travel from source to target.
// Currently, Alex is in k'th city and wants to visit one city of his choice. Return the minimum money Alex should have so that he can visit any city of his choice from k'th city. If there is a city that has no path from k'th city, which means Alex can't visit that city, return -1.
// Alex always takes the optimal path. He can any city via another city by taking multiple flights.

// Example 1:

// Input:
// n: 4
// k: 2
// flights size: 3
// flights: [[2,1,1],[2,3,1],[3,4,1]]
// Output:
// 2
// Explanation:
// to visit 1 from 2 takes cost 1
// to visit 2 from 2 takes cost 0
// to visit 3 from 2 takes cost 1
// to visit 4 from 2 takes cost 2,
// 2->3->4
// So if Alex wants to visit city 4
// from 2, he needs 2 units of money

// Example 2:

// Input:
// n: 4
// k: 3
// flights size: 3
// flights: [[2,1,1],[2,3,1],[3,4,1]]
// Output: -1
// Explanation:
// There is no direct or indirect path
// to visit city 2 and 1 from city 3

// Your Task:

// You don't need to print or input anything. Complete the function minimumCost() which takes a  flights array, an integer n and an integer k as the input parameters and returns an integer, denoting the minimum money Alex should have so that he can visit any city of his choice from k'th city.

// Expected Time Complexity: O((V+E) log V), here V is number of cities and E is number of flights.
// Expected Auxiliary Space: O(V+E), here V is number of cities and E is number of flights.

// Constraints:

// 2 <= n <= 500
// 1 <= flights.length <= 100000
// flights[i].length == 3
// 1 <= ui, vi, k<= n
// ui != vi
// 1 <= wi <= 100
// All the pairs (ui, vi) are unique. (i.e., no multiple edges)
// View Bookmarked Problems

Class Solution{
    public :
        int minimumCost(vector<vector<int>> & flights, int n, int k){
            // code here
            vector<vector<vector<int>>> graph(n + 1);

for (int i = 0; i < flights.size(); ++i)
{

    int u = flights[i][0];
    int v = flights[i][1];
    int w = flights[i][2];

    graph[u].push_back({v, w});
}

vector<int> dist(n + 1, -1);
queue<vector<int>> q;
dist[k] = 0;
q.push({k, dist[k]}); /* Node | cost */
int ans = INT_MIN;

while (!q.empty())
{
    vector<int> frontNode = q.front();
    q.pop();

    int node = frontNode[0];
    int cost = frontNode[1];

    for (auto x : graph[node])
    {
        int node_x = x[0];
        int cost_x = x[1];

        if (dist[node_x] == -1)
        {
            dist[node_x] = cost + cost_x;
            q.push({node_x, dist[node_x]});
        }

        else if (dist[node_x] > cost + cost_x)
        {
            dist[node_x] = cost + cost_x;
            q.push({node_x, dist[node_x]});
        }
    }
}

for (int i = 1; i < dist.size(); ++i)
{
    if (dist[i] != -1)
    {
        ans = max(ans, dist[i]);
    }
    else
        return -1;
}
return ans;
}
}
;
