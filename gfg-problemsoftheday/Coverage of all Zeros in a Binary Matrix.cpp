// Coverage of all Zeros in a Binary Matrix
// Difficulty: EasyAccuracy: 68.85%Submissions: 6K+Points: 2
// Given a binary matrix contains 0s and 1s only, we need to find the sum of coverage of all zeros of the matrix where coverage for a particular 0 is defined as a total number of ones around a zero in left, right, up and bottom directions.

// Examples:

// Input:
// matrix = [[0, 1, 0],
//           [0, 1, 1],
//           [0, 0, 0]]
// Output: 6
// Explanation: There are a total of 6 coverage are there

// Input:
// matrix = [[0, 1]]
// Output: 1
// Explanation: There are only 1 coverage.
// Expected Time Complexity: O(n * m)
// Expected Space Complexity: O(1)

// Constraints:
// 1 <= matrix.size, matrix[0].size <= 100

// Seen this question in a real interview before ?

class Solution
{
public:
    int findCoverage(vector<vector<int>> &matrix)
    {
        // Code here
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int new_x = i + dx[k];
                        int new_y = j + dy[k];
                        if (new_x >= 0 && new_x < matrix.size() && new_y >= 0 && new_y < matrix[0].size())
                        {
                            if (matrix[new_x][new_y] == 1)
                            {
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
