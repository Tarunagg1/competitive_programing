// Mobile numeric keypad
// MediumAccuracy: 32.6%Submissions: 44K+Points: 4
// Solve today's problem-> Be the comment of the day-> Win a GfG T-Shirt!
// Daily rewards up for grabs!

// banner
// There is a standard numeric keypad on a mobile phone. You can only press the current button or buttons that are directly up, left, right, or down from it (for ex if you press 5, then pressing 2, 4, 6 & 8 are allowed). Diagonal movements and pressing the bottom row corner buttons (* and #) are prohibited.

// Given a number n, find the number of possible unique sequences of length n that you can create by pressing buttons. You can start from any digit.

// Examples

// Input: n = 1
// Output: 10
// Explanation: Number of possible numbers are 10 (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
// Input: n = 2
// Output: 36
// Explanation: Possible numbers: 00, 08, 11, 12, 14, 22, 21, 23, 25 and so on. If we start with 0, valid numbers will be 00, 08 (count: 2). If we start with 1, valid numbers will be 11, 12, 14 (count: 3). If we start with 2, valid numbers  will be 22, 21, 23,25 (count: 4). If we start with 3, valid numbers will be 33, 32, 36 (count: 3). If we start with 4, valid numbers will be 44,41,45,47 (count: 4). If we start with 5, valid numbers will be 55,54,52,56,58 (count: 5) and so on.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 ≤ n ≤ 25

class Solution
{
public:
    unordered_map<int, vector<int>> mp;
    long long dp[11][26];
    long long solve(int n, int last, int i)
    {
        if (i == n - 1)
            return 1; // base case

        if (dp[last][i] != -1)
            return dp[last][i];

        long long ans = 0;
        for (auto itr : mp[last])
        {
            ans += solve(n, itr, i + 1);
        }

        return dp[last][i] = ans;
    }
    long long getCount(int n)
    {
        // Your code goes here
        long long ans = 0;
        memset(dp, -1, sizeof(dp));

        mp[0] = {0, 8};
        mp[1] = {1, 2, 4};
        mp[2] = {1, 2, 3, 5};
        mp[3] = {6, 2, 3};
        mp[4] = {1, 4, 5, 7};
        mp[5] = {2, 4, 5, 6, 8};
        mp[6] = {3, 5, 6, 9};
        mp[7] = {7, 4, 8};
        mp[8] = {8, 7, 9, 0, 5};
        mp[9] = {9, 6, 8};
        for (int i = 0; i <= 9; i++)
        {
            ans += solve(n, i, 0);
            // cout<<solve(n, i, 0)<<" ";
        }
        return ans;
    }
};
