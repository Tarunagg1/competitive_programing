// Spirally traversing a matrix
// Difficulty: MediumAccuracy: 35.2%Submissions: 289K+Points: 4
// You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array while traversing the matrix in spiral form.

// Examples:

// Input: mat[][] = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
// Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
// Explanation:

// Input: mat[][] = [[1, 2, 3, 4, 5, 6], [7, 8, 9, 10, 11, 12], [13, 14, 15, 16, 17, 18]]
// Output: [1, 2, 3, 4, 5, 6, 12, 18, 17, 16, 15, 14, 13, 7, 8, 9, 10, 11]
// Explanation: Applying same technique as shown above.
// Input: mat[][] = [[32, 44, 27, 23], [54, 28, 50, 62]]
// Output: [32, 44, 27, 23, 62, 50, 28, 54]
// Explanation: Applying same technique as shown above, output will be [32, 44, 27, 23, 62, 50, 28, 54].
// Constraints:
// 1 <= n, m <= 1000
// 0 <= mat[i][j]<= 100

// Company T

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat)
    {
        // code here

        vector<int> ans;
        int row = mat.size();
        int col = mat[0].size();

        int count = 0;
        int total = row * col;

        // index initialization
        int startingRow = 0;
        int endingRow = row - 1;
        int startingCol = 0;
        int endingCol = col - 1;

        while (count < total)
        {
            // print starting row
            for (int i = startingCol; count < total && i <= endingCol; i++)
            {
                ans.push_back(mat[startingRow][i]);
                count++;
            }
            startingRow++;

            // print ending column
            for (int i = startingRow; count < total && i <= endingRow; i++)
            {
                ans.push_back(mat[i][endingCol]);
                count++;
            }
            endingCol--;

            // print ending row
            for (int i = endingCol; count < total && i >= startingCol; i--)
            {
                ans.push_back(mat[endingRow][i]);
                count++;
            }
            endingRow--;

            // print starting column
            for (int i = endingRow; count < total && i >= startingRow; i--)
            {
                ans.push_back(mat[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};
