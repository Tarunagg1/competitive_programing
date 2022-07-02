// Count the paths
// Easy Accuracy: 60.65% Submissions: 8668 Points: 2
// Given a directed acyclic graph(DAG) with n nodes labeled from 0 to n-1. Given edges, s and d ,count the number of ways to reach from s to d.There is a directed Edge from vertex edges[i][0] to the vertex edges[i][1].

// Example:

// Input: edges = {{0,1},{0,3},{1,2},{3,2}},
// n = 4, s = 0, d = 2
// Output: 2
// Explanation: There are two ways to reach at
// 2 from 0. These are-
// 1. 0->1->2
// 2. 0->3->2

// Your Task:
// You don't need to read or print anything. Your task is to complete the function possible_paths() which takes edges, n, s and d as input parameter and returns the number of ways to reach from s to d.

// Expected Time Compelxity: O(2n)
// Expected Space Complexity: O(n+e)

// where e is the number of edges in the graph.

// Constraints:
// 1 <= n <= 15
// 0 <= s, d <= n-1

// View Bookmarked Problems

class Solution
{
public:
    void dfs(vector<vector<int>> graph, int &cnt, vector<bool> &visited, int s, int d)
    {
        if (s == d)
        {
            cnt++;
            return;
        }
        visited[s] = 1;
        // int ans=0;
        for (auto it : graph[s])
        {
            if (!visited[it])
                dfs(graph, cnt, visited, it, d);
        }
        visited[s] = 0;

        return;
    }
    int possible_paths(vector<vector<int>> edges, int n, int s, int d)
    {
        // Code here
        vector<bool> visited(n, 0);
        int cnt = 0;
        vector<vector<int>> graph(n);
        for (auto i : edges)
            graph[i[0]].push_back(i[1]);
        dfs(graph, cnt, visited, s, d);
        return cnt;
    }
};
