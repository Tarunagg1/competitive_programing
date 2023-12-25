// Determinant of a Matrix
// EasyAccuracy: 56.66%Submissions: 15K+Points: 2
// Money can’t buy you happiness. But Geekbits can buy you GfG goodies and it’s the same thing. Earn 2X Geekbits Now

// banner
// Given a square matrix of size n*n. The task is to find the determinant of this matrix.

// Example 1:

// Input:
// n = 4
// matrix[][] = {{1, 0, 2, -1},
//               {3, 0, 0, 5},
//               {2, 1, 4, -3},
//               {1, 0, 5, 0}}
// Output: 30
// Explanation:
// Determinant of the given matrix is 30.
// Example 2:

// Input:
// n = 3
// matrix[][] = {{1, 2, 3},
//               {4, 5, 6},
//               {7, 10, 9}}
// Output: 12
// Explanation:
// Determinant of the given matrix is 12.
// Your Task:
// You don't need to read input or print anything. Complete the function determinantOfMatrix() that takes matrix and its size n as input parameters and returns the determinant of the matrix.

// Expected Time Complexity: O(N4)
// Expected Auxiliary Space: O(N2)

// Constraints:
// 1 <= N <= 10
// -10 <= mat[i][j] <= 10

// Topic Tags

class Solution
{
public:
    // Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int>> matrix, int n)
    {
        // code here
        if (n == 1)
            return matrix[0][0];
        vector<vector<int>> submat(n - 1, vector<int>(n - 1));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                int x = 0;
                for (int k = 0; k < n; k++)
                {
                    if (k == i)
                        continue;
                    submat[j - 1][x++] = matrix[j][k];
                }
            }
            ans += (matrix[0][i] * determinantOfMatrix(submat, n - 1) * ((i & 1) == 1 ? -1 : 1));
        }
        return ans;
    }
};
