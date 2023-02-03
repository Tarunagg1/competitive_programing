// Coordinates of the last cell in a Matrix on which performing given operations exits from the Matrix
// EasyAccuracy: 72.04%Submissions: 3K+Points: 2
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// Given a binary matrix of dimensions N * M. One can perform the given operation into the matrix.

// If the value of matrix[i][j] is 0, then traverse in the same direction and check the next value.
// If the value of matrix[i][j] is 1, then update matrix[i][j] to 0 and change the current direction from up, right, down, or left to the directions right, down, left, and up respectively.
// Initially you start from cell(0, 0), moving in right direction.

// The task is to find the indices of the matrix  which leads to outside the matrix from the traversal of the given matrix from the cell (0, 0) by performing the operations.

// Example 1:

// Input:
// matrix[][] = {{0,1},
//               {1,0}}

// Output: (1,1)
// Explanation:

// Example 2:

// Input:
// matrix[][] = {{0, 1, 1, 1, 0},
//                    {1, 0, 1, 0, 1},
//               {1, 1, 1, 0, 0}}

// Output: (2,0)
// Explanation: We will leave the grid after visiting the index (2,0).

// Your Task:
// You don't need to read input or print anything. Complete the function endPoints() that take the matrix as input parameter and output the last cell before the pointer gets outside of the matrix.

// Expected Time Complexity: O(N)
// Expected Space Complexity: O(1)

// Constrains:
// 1<= N, M <=1000
// 0<= matrix[i][j] <=1

// View Bookmarked Problems
// Company Tags

class Solution
{
public:
    bool check(int x, int y, int n, int m)
    {
        if (x >= n || y >= m || x < 0 || y < 0)
            return true;
        return false;
    }
    pair<int, int> endPoints(vector<vector<int>> &a)
    {
        int n = a.size();
        int m = a[0].size();
        pair<int, int> ans{-1, -1};
        int x = 0, y = 0;
        map<pair<int, int>, pair<int, int>> mp;
        mp[{-1, 0}] = {0, 1};  // up ---> right
        mp[{0, 1}] = {1, 0};   // right ->> down
        mp[{1, 0}] = {0, -1};  // down ---> left
        mp[{0, -1}] = {-1, 0}; // left ----> up
        int dx = 0, dy = 1;
        while (true)
        {
            int nxtx, nxty;
            nxtx = x + dx;
            nxty = y + dy;
            if (a[x][y] == 0)
            {
                if (check(nxtx, nxty, n, m))
                {
                    ans = {x, y};
                    break;
                }
                x = nxtx;
                y = nxty;
            }
            if (a[x][y])
            {
                a[x][y] = 0;
                pair<int, int> p = mp[{dx, dy}];
                dx = p.first;
                dy = p.second;
            }
        }
        return ans;
    }
};
