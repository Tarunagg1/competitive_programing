// Unit Area of largest region of 1's
// MediumAccuracy: 49.82%Submissions: 30919Points: 4
// Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
// Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).

// Example 1:

// Input: grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}}
// Output: 5
// Explanation: The grid is-
// 1 1 1 0
// 0 0 1 0
// 0 0 0 1
// The largest region of 1's is colored
// in orange.
// Example 2:

// Input: grid = {{0,1}}
// Output: 1
// Explanation: The grid is-
// 0 1
// The largest region of 1's is colored in
// orange.

// Your Task:
// You don't need to read or print anyhting. Your task is to complete the function findMaxArea() which takes grid as input parameter and returns the area of the largest region of 1's.

// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n*m)

// Constraints:
// 1 ≤ n, m ≤ 500

class Solution
{
public:
    // Function to find unit area of the largest region of 1s.

    void recursion(int i, int j, vector<vector<int>> &grid, int n, int m, int &count)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
        {
            return;
        }

        grid[i][j] = 0;
        count++;
        recursion(i - 1, j, grid, n, m, count);
        recursion(i + 1, j, grid, n, m, count);
        recursion(i, j + 1, grid, n, m, count);
        recursion(i, j - 1, grid, n, m, count);
        recursion(i + 1, j + 1, grid, n, m, count);
        recursion(i + 1, j - 1, grid, n, m, count);
        recursion(i - 1, j - 1, grid, n, m, count);
        recursion(i - 1, j + 1, grid, n, m, count);
    }
    int findMaxArea(vector<vector<int>> &grid)
    {
        // Code here

        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int count = 0;
                if (grid[i][j] == 1)
                {
                    recursion(i, j, grid, n, m, count);
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
