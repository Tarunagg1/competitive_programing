// Given a grid of size n*m (n is number of rows and m is number of columns grid has) consisting of '0's(Water) and '1's(Land). Find the number of islands.
// Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

// Example 1:

// Input:
// grid = {{0,1},{1,0},{1,1},{1,0}}
// Output:
// 1
// Explanation:
// The grid is-
// 0 1
// 1 0
// 1 1
// 1 0
// All lands are connected.
// Example 2:

// Input:
// grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
// Output:
// 2
// Expanation:
// The grid is-
// 0 1 1 1 0 0 0
// 0 0 1 1 0 1 0
// There are two islands one is colored in blue
// and other in orange.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function numIslands() which takes grid as input parameter and returns the total number of islands.

// Expected Time Compelxity: O(n*m)
// Expected Space Compelxity: O(n*m)

// Constraints:
// 1 ≤ n, m ≤ 500

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int i, int j, int n, int m)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return;

        if (grid[i][j] == '0')
            return;

        if (vis[i][j] == 1)
            return;

        if (vis[i][j] == 0)
        {
            vis[i][j] = 1;

            dfs(grid, vis, i + 1, j, n, m);

            dfs(grid, vis, i - 1, j, n, m);

            dfs(grid, vis, i, j + 1, n, m);

            dfs(grid, vis, i, j - 1, n, m);

            dfs(grid, vis, i + 1, j + 1, n, m);

            dfs(grid, vis, i + 1, j - 1, n, m);

            dfs(grid, vis, i - 1, j + 1, n, m);

            dfs(grid, vis, i - 1, j - 1, n, m);
        }
    }

    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        int n = grid.size();

        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 0 and grid[i][j] == '1')
                {
                    dfs(grid, vis, i, j, n, m);

                    count++;
                }
            }
        }

        return count;
    }
}
