// Number of paths in a matrix with k coins
// MediumAccuracy: 16.96%Submissions: 27K+Points: 4
// Internship Alert!
// Become an SDE Intern by topping this monthly leaderboard!

// banner
// Given a n x n matrix such that each of its cells contains some coins. Count the number of ways to collect exactly k coins while moving from top left corner of the matrix to the bottom right. From a cell (i, j), you can only move to (i+1, j) or (i, j+1).

// Example 1:

// Input:
// k = 12, n = 3
// arr[] = [[1, 2, 3],
//        [4, 6, 5],
//        [3, 2, 1]]
// Output:
// 2
// Explanation:
// There are 2 possible paths with exactly 12 coins, (1 + 2 + 6 + 2 + 1) and (1 + 2 + 3 + 5 + 1).
// Example 2:

// Input:
// k = 16, n = 3
// arr[] = [[1, 2, 3],
//        [4, 6, 5],
//        [9, 8, 7]]
// Output:
// 0
// Explanation:
// There are no possible paths that lead to sum=16
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function numberOfPath() which takes n, k and 2D matrix arr[][] as input parameters and returns the number of possible paths.

// Expected Time Complexity: O(n*n*k)
// Expected Auxiliary Space: O(n*n*k)

// Constraints:

// 1 <= k < 100
// 1 <= n < 100
// 0 <= arrij <= 200

class Solution
{
public:
    long long dp[101][101][101];
    long long check(vector<vector<int>> &arr, int i, int j, int tar, int n)
    {
        if (i >= n || j >= n || tar <= 0)
            return 0;
        if (i == n - 1 && j == n - 1)
        {
            if (tar == arr[i][j])
                return 1;
            return 0;
        }

        if (dp[i][j][tar] != -1)
            return dp[i][j][tar];
        long long take = check(arr, i + 1, j, tar - arr[i][j], n) + check(arr, i, j + 1, tar - arr[i][j], n);
        return dp[i][j][tar] = take;
    }
    long long numberOfPath(int n, int k, vector<vector<int>> arr)
    {
        memset(dp, -1, sizeof(dp));
        return check(arr, 0, 0, k, n);
        // Code Here
    }
};
