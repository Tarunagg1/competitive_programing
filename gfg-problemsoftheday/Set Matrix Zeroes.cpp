// Set Matrix Zeroes
// Difficulty: MediumAccuracy: 55.89%Submissions: 10K+Points: 4
// You are given a 2D matrix mat[][] of size n×m. The task is to modify the matrix such that if mat[i][j] is 0, all the elements in the i-th row and j-th column are set to 0 and do it in constant space complexity.

// Examples:

// Input: mat[][] = [[1, -1, 1],
//                 [-1, 0, 1],
//                 [1, -1, 1]]
// Output: [[1, 0, 1],
//         [0, 0, 0],
//         [1, 0, 1]]
// Explanation: mat[1][1] = 0, so all elements in row 1 and column 1 are updated to zeroes.
// Input: mat[][] = [[0, 1, 2, 0],
//                 [3, 4, 5, 2],
//                 [1, 3, 1, 5]]
// Output: [[0, 0, 0, 0],
//         [0, 4, 5, 0],
//         [0, 3, 1, 0]]
// Explanation: mat[0][0] and mat[0][3] are 0s, so all elements in row 0, column 0 and column 3 are updated to zeroes.
// Constraints:
// 1 ≤ n, m ≤ 500
// - 231 ≤ mat[i][j] ≤ 231 - 1

class Solution
{
public:
    void setMatrixZeroes(vector<vector<int>> &mat)
    {
        // code here
        unordered_set<int> rw, cols;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 0)
                {
                    rw.insert(i);
                    cols.insert(j);
                }
            }
        }

        for (auto it : rw)
        {
            for (int i = 0; i < mat[0].size(); i++)
            {
                mat[it][i] = 0;
            }
        }

        for (auto it : cols)
        {
            for (int i = 0; i < mat.size(); i++)
            {
                mat[i][it] = 0;
            }
        }
    }
};
