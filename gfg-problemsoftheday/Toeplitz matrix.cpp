// Toeplitz matrix
// Difficulty: MediumAccuracy: 49.05%Submissions: 13K+Points: 4
// A Toeplitz (or diagonal-constant) matrix is a matrix in which each descending diagonal from left to right is constant, i.e., all elements in a diagonal are the same. Given a rectangular matrix mat, your task is to complete the function isToeplitz which returns 1 if the matrix is Toeplitz otherwise, it returns 0.

// Examples:

// Input:
// mat = [[6, 7, 8],
//        [4, 6, 7],
//        [1, 4, 6]]
// Output: 1
// Explanation: The test case represents a 3x3 matrix
//  6 7 8
//  4 6 7
//  1 4 6
// Output: 1(True) as values in all downward diagonals from left to right contain the same elements.

// Input:
// mat = [[1,2,3],
//        [4,5,6]]
// Output: 0
// Explanation: Matrix of order 2x3 will be 1 2 3 4 5 6 Output: 0(False) as values in all diagonals are not the same.

// Constraints:
// 1<=mat.size,mat[0].size<=40
// 1<=mat[i][j]<=100

// Expected time complexity: O(n*m)
// Expected space complexity: O(1)

bool isToepliz(vector<vector<int>> &mat)
{
    // code here
    int n = mat.size();
    int m = mat[0].size();

    int dia = mat[0][0];
    for (int i = 1, j = 1; i < n and j < m; i++ and j++)
    {
        if (mat[i][j] != dia)
        {
            return false;
        }
    }
    return true;
}
