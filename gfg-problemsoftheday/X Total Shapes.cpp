// X Total Shapes
// MediumAccuracy: 59.4%Submissions: 15113Points: 4
// Given  a grid of n*m consisting of O's and X's. The task is to find the number of 'X' total shapes.
// Note: 'X' shape consists of one or more adjacent X's (diagonals not included).

// Example 1:

// Input: grid = {{X,O,X},{O,X,O},{X,X,X}}
// Output: 3
// Explanation:
// The grid is-
// X O X
// O X O
// X X X
// So, X with same colour are adjacent to each
// other vertically for horizontally (diagonals
// not included). So, there are 3 different groups
// in the given grid.

// Example 2:

// Input: grid = {{X,X},{X,X}}
// Output: 1
// Expanation:
// The grid is-
// X X
// X X
// So, X with same colour are adjacent to each
// other vertically for horizontally (diagonals
// not included). So, there is only 1 group
// in the given grid.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function xShape() which takes grid as input parameter and returns the count of total X shapes.

// Expected Time Compelxity: O(n*m)
// Expected Space Compelxity: O(n*m)

// Constraints:
// 1 ≤ n, m ≤ 100

// View Bookmarked Problems

class Solution{
    public :
        // Function to find the number of 'X' total shapes.

        void dfs(vector<vector<char>> & grid, vector<vector<int>> &vis, int i, int j, int n, int m){
            if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] == 1 || grid[i][j] == 'O'){
                return;
}

vis[i][j] = 1;

dfs(grid, vis, i + 1, j, n, m);
dfs(grid, vis, i, j + 1, n, m);
dfs(grid, vis, i, j - 1, n, m);
dfs(grid, vis, i - 1, j, n, m);
}

int xShape(vector<vector<char>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && grid[i][j] == 'X')
            {
                cnt += 1;
                dfs(grid, vis, i, j, n, m);
            }
        }
    }
    return cnt;
}
}
;
