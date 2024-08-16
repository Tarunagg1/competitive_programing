// Maximize The Cut Segments
// Difficulty: MediumAccuracy: 24.29%Submissions: 214K+Points: 4
// Given an integer n denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
// After performing all the cut operations, your total number of cut segments must be maximum.

// Note: if no segment can be cut then return 0.

// Examples:

// Input: n = 4, x = 2, y = 1, z = 1
// Output: 4
// Explanation: Total length is 4, and the cut
// lengths are 2, 1 and 1.  We can make
// maximum 4 segments each of length 1.
// Input: n = 5, x = 5, y = 3, z = 2
// Output: 2
// Explanation: Here total length is 5, and
// the cut lengths are 5, 3 and 2. We can
// make two segments of lengths 3 and 2.
// Expected Time Complexity : O(n)
// Expected Auxiliary Space: O(n)

// Constraints
// 1 <= n, x, y, z <= 104

class Solution
{
public:
    // Function to find the maximum number of cuts.
    int dp[10001];
    int solve(int x, int y, int z, int n)
    {
        // base case
        if (n < 0)
        {
            return INT_MIN;
        }
        if (n == 0)
        {
            return 0;
        }

        if (dp[n] != -1)
            return dp[n];

        int op1 = 1 + solve(x, y, z, n - x);
        int op2 = 1 + solve(x, y, z, n - y);
        int op3 = 1 + solve(x, y, z, n - z);

        return dp[n] = max({op1, op2, op3});
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Your code here
        memset(dp, -1, sizeof(dp));
        int ans = solve(x, y, z, n);
        if (ans <= 0)
            return 0;

        return ans;
    }
};
