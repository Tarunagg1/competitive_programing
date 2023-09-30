// Boolean Matrix
// MediumAccuracy: 40.05%Submissions: 80K+Points: 4
// Win 2X Geekbits, Get on the Leaderboard & Top the Coding Charts! Register for GFG Weekly Coding Contest

// banner
// Given a boolean matrix of size RxC where each cell contains either 0 or 1, modify it such that if a matrix cell matrix[i][j] is 1 then all the cells in its ith row and jth column will become 1.

// Example 1:

// Input:
// R = 2, C = 2
// matrix[][] = {{1, 0},
//               {0, 0}}
// Output:
// 1 1
// 1 0
// Explanation:
// Only cell that has 1 is at (0,0) so all
// cells in row 0 are modified to 1 and all
// cells in column 0 are modified to 1.

// Example 2:

// Input:
// R = 4, C = 3
// matrix[][] = {{ 1, 0, 0},
//               { 1, 0, 0},
//               { 1, 0, 0},
//               { 0, 0, 0}}
// Output:
// 1 1 1
// 1 1 1
// 1 1 1
// 1 0 0
// Explanation:
// The position of cells that have 1 in
// the original matrix are (0,0), (1,0)
// and (2,0). Therefore, all cells in row
// 0,1,2 are and column 0 are modified to 1.
// Your Task:
// You dont need to read input or print anything. Complete the function booleanMatrix() that takes the matrix as input parameter and modifies it in-place.

// Expected Time Complexity: O(R * C)
// Expected Auxiliary Space: O(R + C)

// Constraints:
// 1 ≤ R, C ≤ 1000
// 0 ≤ matrix[i][j] ≤ 1

class Solution
{
public:
    // Function to modify the matrix such that if a matrix cell matrix[i][j]
    // is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int>> &matrix)
    {
        // code here

        int row = matrix.size();
        int col = matrix[0].size();
        int rowCol = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 1)
                {
                    if (j != 0)
                        matrix[0][j] = 1;
                    else
                        rowCol = 1;

                    matrix[i][0] = 1;
                }
            }
        }
        // cout<<rowCol<<endl;

        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (matrix[i][0] == 1 || matrix[0][j] == 1)
                        matrix[i][j] = 1;
                }
            }
        }

        if (matrix[0][0] == 1)
        {
            for (int i = 0; i < col; i++)
            {
                matrix[0][i] = 1;
            }
        }

        if (rowCol == 1)
        {
            for (int i = 0; i < row; i++)
            {
                matrix[i][0] = 1;
            }
        }
    }
};
