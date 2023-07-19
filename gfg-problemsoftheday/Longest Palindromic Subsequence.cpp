// Longest Palindromic Subsequence
// MediumAccuracy: 56.57%Submissions: 58K+Points: 4
// POTD July Placement Special : All POTD in the month of July are based on popular interview questions. Solve every day to ace the upcoming Placement Season !
// Given a String, find the longest palindromic subsequence.

// Example 1:

// Input:
// S = "bbabcbcab"
// Output: 7
// Explanation: Subsequence "babcbab" is the
// longest subsequence which is also a palindrome.
// Example 2:

// Input:
// S = "abcd"
// Output: 1
// Explanation: "a", "b", "c" and "d" are
// palindromic and all have a length 1.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function longestPalinSubseq() which takes the string S as input and returns an integer denoting the length of the longest palindromic subsequence of S.

// Expected Time Complexity: O(|S|*|S|).
// Expected Auxiliary Space: O(|S|*|S|).

// Constraints:
// 1 ≤ |S| ≤ 1000

class Solution
{
public:
    int dp[1001][1001];
    int helper(string &A, int left, int right)
    {
        if (left > right)
            return 0;
        if (left == right)
            return 1;

        if (dp[left][right] != -1)
            return dp[left][right];

        if (A[left] == A[right])
            return dp[left][right] = 2 + helper(A, left + 1, right - 1);

        else
        {
            return dp[left][right] = max(helper(A, left + 1, right), helper(A, left, right - 1));
        }
    }

    int longestPalinSubseq(string A)
    {
        int n = A.size();
        memset(dp, -1, sizeof(dp));
        return helper(A, 0, n - 1);
    }
};
