// Anti Diagonal Traversal of Matrix
// MediumAccuracy: 77.52%Submissions: 9K+Points: 4
// Win from a cash prize pool of INR 15,000
// Check out Hack-For-Health Hackathon Now!

// banner
// Give a N*N square matrix, return an array of its anti-diagonals in top-leftmost to bottom-rightmost order. In an element of a anti-diagonal (i, j), surrounding elements will be (i+1, j-1) and (i-1, j+1). Look at the examples for more clarity.

// Example 1:

// Input:
// N = 2
// matrix[][] = 1 2
//             3 4
// Output:
// 1 2 3 4
// Explanation:
// List of anti-diagnoals in order is
// {1}, {2, 3}, {4}
// Example 2:

// Input:
// N = 3
// matrix[][] = 3 2 3
//             4 5 1
//             7 8 9
// Output:
// 3 2 4 3 5 7 1 8 9
// Explanation:
// List of anti-diagnoals in order is
// {3}, {2, 4}, {3, 5, 7}, {1, 8}, {9}
// Your Task:
// You dont need to read input or print anything. Complete the function antiDiagonalPattern() that takes matrix as input parameter and returns a list of integers in order of the values visited in the anti-Diagonal pattern.

// Expected Time Complexity: O(N * N)
// Expected Auxiliary Space: O(N * N)

// Constraints:
// 1 <= N <= 100
// 0 <= mat[i][j] <= 100

class Solution
{
public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix)
    {
        // Code here
        vector<int> result;
        int N = matrix.size();

        // Traverse the top-left part of the matrix
        for (int i = 0; i < N; ++i)
        {
            int row = 0, col = i;
            while (col >= 0)
            {
                result.push_back(matrix[row][col]);
                ++row;
                --col;
            }
        }

        // Traverse the bottom-right part of the matrix
        for (int i = 1; i < N; ++i)
        {
            int row = i, col = N - 1;
            while (row < N)
            {
                result.push_back(matrix[row][col]);
                ++row;
                --col;
            }
        }

        return result;
    }
};
