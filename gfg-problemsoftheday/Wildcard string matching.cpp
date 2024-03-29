// Wildcard string matching
// HardAccuracy: 23.88%Submissions: 33K+Points: 8
// Win from a cash prize pool of INR 15,000
// Check out Hack-For-Health Hackathon Now!

// banner
// Given two strings wild and pattern. Determine if the given two strings can be matched given that, wild string may contain * and ? but string pattern will not. * and ? can be converted to another character according to the following rules:

// * --> This character in string wild can be replaced by any sequence of characters, it can also be replaced by an empty string.
// ? --> This character in string wild can be replaced by any one character.
// Example 1:

// Input:
// wild = ge*ks
// pattern = geeks
// Output: Yes
// Explanation: Replace the '*' in wild string
// with 'e' to obtain pattern "geeks".
// Example 2:

// Input:
// wild = ge?ks*
// pattern = geeksforgeeks
// Output: Yes
// Explanation: Replace '?' and '*' in wild string with
// 'e' and 'forgeeks' respectively to obtain pattern
// "geeksforgeeks"
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function match() which takes the string wild and pattern as input parameters and returns true if the string wild can be made equal to the string pattern, otherwise, returns false.

// Expected Time Complexity: O(length of wild string * length of pattern string)
// Expected Auxiliary Space: O(length of wild string * length of pattern string)

// Constraints:
// 1 <= length of the two string <= 10^3

// Company Tags

class Solution
{
public:
    bool f(int i, int j, string &wild, string &pat, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
            return true;
        if (i < 0 || j < 0)
            return false;
        if (dp[i][j] != -1)
            return dp[i][j];

        bool op1 = false, op2 = false;
        if ((wild[i] == pat[j]) || (wild[i] == '?'))
        {
            op1 = f(i - 1, j - 1, wild, pat, dp);
        }
        if (wild[i] == '*')
        {
            op2 = f(i - 1, j - 1, wild, pat, dp) | f(i, j - 1, wild, pat, dp) | f(i - 1, j, wild, pat, dp);
        }

        return dp[i][j] = (op1 | op2);
    }

    bool match(string wild, string pattern)
    {
        // code here
        int n = wild.size(), m = pattern.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, wild, pattern, dp);
    }
};
