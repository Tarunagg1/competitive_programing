// Painting the Fence
// MediumAccuracy: 32.89%Submissions: 66K+Points: 4
// For the first time ever: GATE 2024 introduces DS & AI in its renowned exam. Take its first ever All India Mock Test

// banner
// Given a fence with n posts and k colors, find out the number of ways of painting the fence so that not more than two consecutive posts have the same colors. Since the answer can be large return it modulo 109 + 7.

// Example 1:

// Input:
// n = 3
// k = 2
// Output: 6
// Explanation:
// We have following possible combinations:

// Example 2:

// Input:
// n = 2
// k = 4
// Output: 16
// Explanation:
// After coloring first post with
// 4 possible combinations, you can still color
// next posts with all 4 colors. Total possible
// combinations will be 4x4=16
// Your Task:
// Since, this is a function problem. You don't need to take any input or print anything, as it is already accomplished by the driver code. You just need to complete the function countWays() that takes n and k as parameters and returns the number of ways in which the fence can be painted (modulo 109 + 7).

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 ≤ N ≤ 5000
// 1 ≤ K ≤ 100

// Topic Tags

class Solution
{
public:
    long long countWays(int n, int k)
    {
        // code here
        if (n == 1)
            return k;

        vector<vector<long long>> dp(n + 1, vector<long long>(2, 1));
        const long long mod = 1e9 + 7;

        for (int i = n - 1; i > 0; i--)
        {
            dp[i][0] = (((k - 1) * dp[i + 1][0]) % mod + dp[i + 1][1]) % mod;

            dp[i][1] = ((k - 1) * dp[i + 1][0]) % mod;
        }

        return dp[0][0] = (k * dp[1][0]) % mod;
    }
};
