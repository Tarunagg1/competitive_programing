// Wildcard Pattern Matching
// Difficulty: HardAccuracy: 31.13%Submissions: 60K+Points: 8
// Given two strings pattern and str which may be of different size, You have to return 1 if the wildcard pattern i.e. pattern, matches with str else return 0. All characters of the string str and pattern always belong to the Alphanumeric characters.

// The wildcard pattern can include the characters ? and *
// ‘?’ – matches any single character.
// ‘*’ – Matches any sequence of characters (including the empty sequence).

// Note: The matching should cover the entire str (not partial str).

// Examples:

// Input: pattern = "ba*a?", str = "baaabab"
// Output: 1
// Explanation: replace '*' with "aab" and
// '?' with 'b'.
// Input: pattern = "a*ab", str = "baaabab"
// Output: 0
// Explanation: Because in string pattern character 'a' at first position,
// pattern and str can't be matched.
// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n*m)

// Constraints:
// 1 <= length of(str, pattern) <= 200

class Solution
{
public:
    /*You are required to complete this method*/
    bool f(int i, int j, string pat, string str, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;
        if (i >= 0 && j < 0)
        {
            for (int k = 0; k <= i; k++)
            {
                if (pat[k] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (pat[i] == str[j] || pat[i] == '?')
        {
            return dp[i][j] = f(i - 1, j - 1, pat, str, dp);
        }
        if (pat[i] == '*')
        {
            return dp[i][j] = f(i, j - 1, pat, str, dp) || f(i - 1, j, pat, str, dp);
        }
    }
    int wildCard(string pattern, string str)
    {
        // code here
        int n = pattern.length();
        int m = str.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, pattern, str, dp);
    }
};
