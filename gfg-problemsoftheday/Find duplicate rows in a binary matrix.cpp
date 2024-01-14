// Find duplicate rows in a binary matrix
// MediumAccuracy: 62.55%Submissions: 11K+Points: 4
// You've won Geekbits by solving daily. Now win 90% of your money-back by learning daily!

// banner
// Given a boolean matrix of size RxC where each cell contains either 0 or 1, find the row numbers (0-based) of row which already exists or are repeated.

// Example 1:

// Input:
// R = 2, C = 2
// matrix[][] = {{1, 0},
//             {1, 0}}
// Output:
// 1
// Explanation:
// Row 1 is duplicate of Row 0.
// Example 2:

// Input:
// R = 4, C = 3
// matrix[][] = {{ 1, 0, 0},
//             { 1, 0, 0},
//             { 0, 0, 0},
//             { 0, 0, 0}}
// Output:
// 1 3
// Explanation:
// Row 1 and Row 3 are duplicates of Row 0 and 2 respectively.
// Your Task:
// You dont need to read input or print anything. Complete the function repeatedRows() that takes the matrix as input parameter and returns a list of row numbers which are duplicate rows.

// Expected Time Complexity: O(R * C)
// Expected Auxiliary Space: O(R * C)

// Constraints:
// 1 ≤ R, C ≤ 103
// 0 ≤ matrix[i][j] ≤ 1

// Company Tags

class Solution
{
public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N)
    {
        // Your code here
        vector<int> ans;

        map<vector<int>, vector<int>> m;
        for (int i = 0; i < M; i++)
        {
            m[matrix[i]].push_back(i);
        }

        for (auto it : m)
        {

            if (it.second.size() > 1)
            {
                for (int i = 1; i < it.second.size(); i++)
                {
                    ans.push_back(it.second[i]);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
