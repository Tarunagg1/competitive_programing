// Longest Repeating Subsequence
// MediumAccuracy: 48.54%Submissions: 91K+Points: 4
// POTD July Placement Special : All POTD in the month of July are based on popular interview questions. Solve every day to ace the upcoming Placement Season !
// Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

// The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B.

// Example 1:

// Input:
// str = "axxzxy"
// Output: 2
// Explanation:
// The given array with indexes looks like
// a x x z x y
// 0 1 2 3 4 5

// The longest subsequence is "xx".
// It appears twice as explained below.

// subsequence A
// x x
// 0 1  <-- index of subsequence A
// ------
// 1 2  <-- index of str

// subsequence B
// x x
// 0 1  <-- index of subsequence B
// ------
// 2 4  <-- index of str

// We are able to use character 'x'
// (at index 2 in str) in both subsequences
// as it appears on index 1 in subsequence A
// and index 0 in subsequence B.
// Example 2:

// Input:
// str = "axxxy"
// Output: 2
// Explanation:
// The given array with indexes looks like
// a x x x y
// 0 1 2 3 4

// The longest subsequence is "xx".
// It appears twice as explained below.

// subsequence A
// x x
// 0 1  <-- index of subsequence A
// ------
// 1 2  <-- index of str

// subsequence B
// x x
// 0 1  <-- index of subsequence B
// ------
// 2 3  <-- index of str

// We are able to use character 'x'
// (at index 2 in str) in both subsequences
// as it appears on index 1 in subsequence A
// and index 0 in subsequence B.

// Your Task:
// You don't need to read or print anything. Your task is to complete the LongestRepeatingSubsequence() which takes str as input parameter and returns the length of the longest repeating subsequnece.

// Expected Time Complexity: O(n2)
// Expected Space Complexity: O(n2)

// Constraints:
// 1 <= |str| <= 103

class Solution
{
public:
    int dp[1001][1001];
    int helper(int i, int j, string &str)
    {
        if (i >= str.size() or j >= str.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int res = 0;
        if (str[i] == str[j] and i != j)
        {
            res = max(res, 1 + helper(i + 1, j + 1, str));
        }
        else
            res = max({res, helper(i + 1, j, str), helper(i, j + 1, str)});
        return dp[i][j] = res;
    }
    int LongestRepeatingSubsequence(string str)
    {
        memset(dp, -1, sizeof(dp));
        // Code here
        return helper(0, 0, str);
    }
};
