// Number Of Enclaves
// MediumAccuracy: 50.93%Submissions: 33K+Points: 4
// Learn Google Cloud with Curated Lab Assignments. Register, Earn Rewards, Get noticed by experts at Google & Land your Dream Job!

// banner
// You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

// Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

// Example 1:

// Input:
// grid[][] = {{0, 0, 0, 0},
//             {1, 0, 1, 0},
//             {0, 1, 1, 0},
//             {0, 0, 0, 0}}
// Output:
// 3
// Explanation:
// 0 0 0 0
// 1 0 1 0
// 0 1 1 0
// 0 0 0 0
// The highlighted cells represents the land cells.
// Example 2:

// Input:
// grid[][] = {{0, 0, 0, 1},
//             {0, 1, 1, 0},
//             {0, 1, 1, 0},
//             {0, 0, 0, 1},
//             {0, 1, 1, 0}}
// Output:
// 4
// Explanation:
// 0 0 0 1
// 0 1 1 0
// 0 1 1 0
// 0 0 0 1
// 0 1 1 0
// The highlighted cells represents the land cells.
// Your Task:

// You don't need to print or input anything. Complete the function numberOfEnclaves() which takes a 2D integer matrix grid as the input parameter and returns an integer, denoting the number of land cells.

// Expected Time Complexity: O(n * m)

// Expected Space Complexity: O(n * m)

// Constraints:

// 1 <= n, m <= 500
// grid[i][j] == 0 or 1

class Solution
{
    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i + 1, j, grid);
        dfs(i, j - 1, grid);
    }

public:
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size() - 1, n = grid[0].size() - 1, ans = 0;
        for (int i = 0; i <= m; i++)
        {
            if (grid[i][0] == 1)
                dfs(i, 0, grid);
            if (grid[i][n] == 1)
                dfs(i, n, grid);
        }
        for (int j = 0; j <= n; j++)
        {
            if (grid[0][j] == 1)
                dfs(0, j, grid);
            if (grid[m][j] == 1)
                dfs(m, j, grid);
        }

        for (auto row : grid)
        {
            for (auto val : row)
            {
                ans += val;
            }
        }
        return ans;
    }
};
