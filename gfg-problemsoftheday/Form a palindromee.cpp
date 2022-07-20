// Form a palindrome
// MediumAccuracy: 53.0%Submissions: 21227Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.

// Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
// For Example:
// ab: Number of insertions required is 1. bab or aba
// aa: Number of insertions required is 0. aa
// abcd: Number of insertions required is 3. dcbabcd

// Example 1:

// Input: str = "abcd"
// Output: 3
// Explanation: Inserted character marked
// with bold characters in dcbabcd
// Example 2:

// Input: str = "aa"
// Output: 0
// Explanation:"aa" is already a palindrome.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function countMin() which takes the string str as inputs and returns the answer.

// Expected Time Complexity: O(N2), N = |str|
// Expected Auxiliary Space: O(N2)

// Constraints:
// 1 ≤ |str| ≤ 103

class Solution
{
public:
    int solve(string &str, int i, int j, vector<vector<int>> &dp)
    {
        // Base Case
        if (i >= j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (str[i] == str[j])
        {
            return dp[i][j] = solve(str, i + 1, j - 1, dp); // ignoring when palindrome condition is satisfied
        }
        else
        {
            int ans1 = 1 + solve(str, i + 1, j, dp); // inserting at the back
            int ans2 = 1 + solve(str, i, j - 1, dp); // inserting at the front
            return dp[i][j] = min(ans1, ans2);       // taking minimum of all possibilities
        }
    }
    int countMin(string str)
    {
        vector<vector<int>> dp(str.size(), vector<int>(str.size(), -1));
        return solve(str, 0, str.size() - 1, dp);
    }
};
