// Find shortest safe route in a matrix
// MediumAccuracy: 50.58%Submissions: 12K+Points: 4
// Given a matrix mat[][] with r rows and c columns, where some cells are landmines (marked as 0) and others are safe to traverse. Your task is to find the shortest safe route from any cell in the leftmost column to any cell in the rightmost column of the mat. You cannot move diagonally, and you must avoid both the landmines and their adjacent cells (up, down, left, right), as they are also unsafe.

// Example 1:

// Input:
// mat = [1, 0, 1, 1, 1],
//       [1, 1, 1, 1, 1],
//       [1, 1, 1, 1, 1],
//       [1, 1, 1, 0, 1],
//       [1, 1, 1, 1, 0]
// Output:
// 6
// Explanation:
// We can see that length of shortest
// safe route is 6 (Highlighted in Bold).
// [1 0 1 1 1]
// [1 1 1 1 1]
// [1 1 1 1 1]
// [1 1 1 0 1]
// [1 1 1 1 0]
// Example 2:

// Input:
// mat = [1, 1, 1, 1, 1],
//       [1, 1, 0, 1, 1],
//       [1, 1, 1, 1, 1]
// Output:
// -1
// Explanation: There is no possible path from
// first column to last column.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findShortestPath() which takes matrix as input parameter and return an integer denoting the shortest safe path form any cell in leftmost column to any cell in rightmost column of mat. If there is no possible path, return -1.

// Expected Time Complexity: O(r * c)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= r, c <= 103
// 0 <= mat[][] <= 1

class Solution
{
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 and ny >= 0 and nx < n and ny < m and mat[nx][ny] == 1)
                            mat[nx][ny] = -1;
                    }
                }
            }
        }

        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] == 1)
            {
                q.push({0, {i, 0}});
                vis[i][0] = 1;
            }
        }

        int ans = INT_MAX;
        while (!q.empty())
        {
            int dist = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            if (c == m - 1)
                ans = min(ans, dist + 1);

            for (int k = 0; k < 4; k++)
            {
                int nx = r + dx[k];
                int ny = c + dy[k];

                if (nx >= 0 and ny >= 0 and nx < n and ny < m and mat[nx][ny] == 1 and !vis[nx][ny])
                {
                    vis[nx][ny] = 1;
                    q.push({dist + 1, {nx, ny}});
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
