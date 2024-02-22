// Distinct occurrences
// MediumAccuracy: 27.37%Submissions: 45K+Points: 4
// Internship Alert!
// Become an SDE Intern by topping this monthly leaderboard!

// banner
// Given two strings s and t of length n and m respectively. Find the count of distinct occurrences of t in s as a sub-sequence modulo 109 + 7.

// Example 1:

// Input:
// s = "banana" , t = "ban"
// Output:
// 3
// Explanation:
// There are 3 sub-sequences:[ban], [ba n], [b an].
// Example 2:

// Input:
// s = "geeksforgeeks" , t = "ge"
// Output:
// 6
// Explanation:
// There are 6 sub-sequences:[ge], [ge], [g e], [g e] [g e] and [g e].
// Your Task:
// You don't need to read input or print anything.Your task is to complete the function subsequenceCount() which takes two strings as argument s and t and returns the count of the sub-sequences modulo 109 + 7.

// Expected Time Complexity: O(n*m).
// Expected Auxiliary Space: O(n*m).

// Constraints:
// 1 ≤ n,m ≤ 1000

class Solution
{
public:
    int M = 1e9 + 7;
    int dp[1005][1005];
    int helper(string &s, string &t, int m, int n)
    {
        if (n == 0)
            return 1;
        if (m == 0)
            return 0;

        if (dp[m - 1][n - 1] != -1)
            return dp[m - 1][n - 1];

        long long res = 0;

        if (s[m - 1] == t[n - 1])
        {
            res = (res + helper(s, t, m - 1, n - 1)) % M;
        }

        res = (res + helper(s, t, m - 1, n)) % M;

        return dp[m - 1][n - 1] = res;
    }
    int subsequenceCount(string s, string t)
    {
        // Your code here
        int m = s.length(), n = t.length();
        memset(dp, -1, sizeof(dp));
        return helper(s, t, m, n);
    }
};
