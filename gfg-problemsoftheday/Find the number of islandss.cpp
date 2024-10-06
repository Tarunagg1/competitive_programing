// Find the number of islands
// Difficulty: MediumAccuracy: 42.12%Submissions: 200K+Points: 4
// Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

// Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

// Examples:

// Input: grid = [[0,1],[1,0],[1,1],[1,0]]
// Output: 1
// Explanation:
// The grid is-
// 0 1
// 1 0
// 1 1
// 1 0
// All lands are connected.
// Input: grid = [[0,1,1,1,0,0,0],[0,0,1,1,0,1,0]]
// Output: 2
// Expanation:
// The grid is-
// 0 1 1 1 0 0 0
// 0 0 1 1 0 2 0
// There are two islands in the grid. One island is marked by '1' and the other by '2'.
// Expected Time Complexity: O(n*m)
// Expected Space Complexity: O(n*m)

// Constraints:
// 1 ≤ n, m ≤ 500
// 0 ≤ grid[i][j] ≤ 1Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

// Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

// Examples:

// Input: grid = [[0,1],[1,0],[1,1],[1,0]]
// Output: 1
// Explanation:
// The grid is-
// 0 1
// 1 0
// 1 1
// 1 0
// All lands are connected.
// Input: grid = [[0,1,1,1,0,0,0],[0,0,1,1,0,1,0]]
// Output: 2
// Expanation:
// The grid is-
// 0 1 1 1 0 0 0
// 0 0 1 1 0 2 0
// There are two islands in the grid. One island is marked by '1' and the other by '2'.
// Expected Time Complexity: O(n*m)
// Expected Space Complexity: O(n*m)

// Constraints:
// 1 ≤ n, m ≤ 500
// grid[i][j] = {'0', '1'}

class Solution
{
public:
    // Function to find the number of islands.
    int n, m;
    int row[8] = {0, -1, -1, -1, 0, 1, 1, 1}, col[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

public:
    // Function to find the number of islands.
    bool expand(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &vis)
    {
        return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] == '1');
    }
    void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &vis)
    {
        vis[i][j] = true;
        for (int k = 0; k < 8; k++)
        {
            int x = i + row[k], y = j + col[k];
            if (expand(x, y, grid, vis))
            {
                dfs(grid, x, y, vis);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        n = grid.size(), m = grid[0].size();
        int res = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    dfs(grid, i, j, vis);
                    res++;
                }
            }
        }
        return res;
    }
};
