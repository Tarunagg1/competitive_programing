// Form a palindrome
// Difficulty: MediumAccuracy: 45.4%Submissions: 92K+Points: 4
// Given a string, find the minimum number of characters to be inserted to convert it to a palindrome.

// Examples :

// Input: str = "abcd"
// Output: 3
// Explanation: Inserted character marked with bold characters in dcbabcd, here we need minimum three characters to make it palindrome.
// Input: str = "aa"
// Output: 0
// Explanation: "aa" is already a palindrome.
// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(n2)

// Constraints:
// 1 ≤ |str| ≤ 500
// str contains only lowercase alphabets.

class Solution
{
public:
    int f(string s, string t)
    {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[n][n];
    }
    int countMin(string str)
    {
        // complete the function here
        string t = str;
        reverse(t.begin(), t.end());
        int n = str.size();
        int v = f(str, t);
        return n - v;
    }
};
