// Shortest Path in Weighted undirected graph
// Difficulty: MediumAccuracy: 50.0%Submissions: 45K+Points: 4
// You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights. Find the shortest path between the vertex 1 and the vertex n,  if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element -1.

// The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the weight of that edge.

// Note: The driver code here will first check if the weight of the path returned is equal to the sum of the weights along the nodes on that path, if equal it will output the weight of the path, else -2. In case the list contains only a single element (-1) it will simply output -1.

// Examples :

// Input: n = 5, m= 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
// Output: 5
// Explanation: Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5.
// Input: n = 2, m= 1, edges = [[1, 2, 2]]
// Output: 2
// Explanation: Shortest path from 1 to 2 is by the path 1 2 whose weight is 2.
// Input: n = 2, m= 0, edges = [ ]
// Output: -1
// Explanation: Since there are no edges, so no answer is possible.
// Expected Time Complexity: O(m* log(n))
// Expected Space Complexity: O(n+m)

// Constraint:
// 2 <= n <= 106
// 0 <= m <= 106
// 1 <= a, b <= n
// 1 <= w <= 105

class Solution
{
public:
    vector<int> shortestPath(int V, int m, vector<vector<int>> &edges)
    {
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto &it : edges)
        {
            int u = it[0];
            int v = it[1];
            int weight = it[2];
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }

        vector<int> visited(V + 1, 0);
        vector<int> dist(V + 1, INT_MAX);
        dist[1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        vector<int> parent(V + 1, -1);

        while (!pq.empty())
        {
            int node = pq.top().second;
            pq.pop();

            if (!visited[node])
            {
                visited[node] = true;
                for (auto v : adj[node])
                {
                    int nbr = v.first;
                    int weight = v.second;
                    if (dist[nbr] > dist[node] + weight)
                    {
                        dist[nbr] = dist[node] + weight;
                        pq.push({dist[nbr], nbr});
                        parent[nbr] = node;
                    }
                }
            }
        }

        if (parent[V] == -1)
            return {-1};
        vector<int> path;
        int t = V;
        while (t != -1)
        {
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(dist[V]);
        reverse(path.begin(), path.end());
        return path;
    }
};
