// Missing number in matrix
// EasyAccuracy: 8.59%Submissions: 2K+Points: 2
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// Given a matrix of size n x n such that it has only one 0, Find the positive number (greater than zero) to be placed in place of the 0 such that sum of the numbers in every row, column and two diagonals become equal. If no such number exists, return -1.

// Note: Diagonals should be only of the form matrix[i][i] and matrix[i][n-i-1]. n is always greater than 1.

// Example 1:

// Input: matrix = {{5, 5}, {5, 0}}
// Output: 5
// Explanation: The matrix is
// 5 5
// 5 0
// Therefore If we place 5 instead of 0, all
// the element of matrix will become 5.
// Therefore row 5+5=10, column 5+5=10 and
// diagonal 5+5=10, all are equal.
// Example 2:

// Input: matrix = {{1, 2, 0}, {3, 1, 2},
// {2, 3, 1}}
// Output: -1
// Explanation: It is not possible to insert
// an element in place of 0 so that the
// condition is satisfied.thus result is -1.

// Your Task:
// You don't need to read or print anyhting. Your task is to complete the function MissingNo() which takes the matrix as input parameter and returns the number which should be placed in place of 0 such that the condition gets satisfied. If not possible return -1.

// Expected Time Complexity: O(n * n)
// Expected Space Complexity: O(2 * n)

// Constraints:
// 2 <= n <= 1000
// 1 <= elements in the matrix <= 10^9

// View Bookmarked Problems

class Solution
{
public:
    long long int MissingNo(vector<vector<int>> &matrix)
    {
        // Code here
        int n = matrix.size();

        long long int sum = 0;

        long long int prev_sum = -1;

        int r = -1;

        int c = -1;

        for (int i = 0; i < n; ++i)

        {

            long long int row_sum = 0;

            int f = 0;

            for (int j = 0; j < n; ++j)

            {

                if (matrix[i][j] == 0)

                {

                    f = 1;

                    r = i;

                    c = j;
                }

                else

                {

                    row_sum += matrix[i][j];
                }
            }

            if (f == 0)

            {

                if (prev_sum == -1)

                {

                    prev_sum = row_sum;
                }

                else if (prev_sum != row_sum)

                    return -1;
            }

            else

            {

                sum = row_sum;
            }
        }

        long long int val = prev_sum - sum;

        prev_sum = -1;

        for (int j = 0; j < n; ++j)

        {

            long long int col_sum = 0;

            for (int i = 0; i < n; ++i)

            {

                if (i == r && j == c)

                    col_sum += val;

                else

                    col_sum += matrix[i][j];
            }

            if (prev_sum != -1)

            {

                if (col_sum != prev_sum)

                    return -1;
            }

            else
            {

                prev_sum = col_sum;
            }
        }

        long long int sum1 = 0;

        for (int i = 0; i < n; ++i)

        {

            if (i == r && i == c)

                sum1 += val;

            else

                sum1 += matrix[i][i];
        }

        long long int sum2 = 0;

        for (int i = 0; i < n; ++i)

        {

            if (i == r && n - i - 1 == c)

                sum2 += val;

            else

                sum2 += matrix[i][n - i - 1];
        }

        if (sum1 != sum2 || val <= 0)

            return -1;

        return val;
    }
};
