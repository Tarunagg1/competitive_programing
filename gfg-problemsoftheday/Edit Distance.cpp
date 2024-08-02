// Edit Distance
// Difficulty: HardAccuracy: 35.14%Submissions: 201K+Points: 8
// Given two strings str1 and str2. Return the minimum number of operations required to convert str1 to str2.
// The possible operations are permitted:

// Insert a character at any position of the string.
// Remove any character from the string.
// Replace any character from the string with any other character.
// Examples:

// Input: str1 = "geek", srt2 = "gesek"
// Output: 1
// Explanation: One operation is required, inserting 's' between two 'e'.
// Input : str1 = "gfg", str2 = "gfg"
// Output: 0
// Explanation: Both strings are same.
// Expected Time Complexity: O(|str1|*|str2|)
// Expected Space Complexity: O(|str1|*|str2|)

// Constraints:
// 1 ≤ str1.length(), str2.length() ≤ 100
// Both the strings are in lowercase.

// Seen this question in a real interview befor

class Solution
{
public:
    vector<vector<int>> dp;
    int solve(int i, int j, string &s1, string &s2)
    {
        int n = s1.size();
        int m = s2.size();
        if (i >= n)
            return m - j;
        if (j >= m)
            return n - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        int take = 0;
        int notTake = 0;
        if (s1[i] == s2[j])
        {
            take = solve(i + 1, j + 1, s1, s2);
        }
        else
        {
            int insertOp = 1 + solve(i, j + 1, s1, s2);
            int deleteOp = 1 + solve(i + 1, j, s1, s2);
            int replaceOp = 1 + solve(i + 1, j + 1, s1, s2);

            notTake = min(insertOp, min(deleteOp, replaceOp));
        }

        return dp[i][j] = take + notTake;
    }

    int editDistance(string str1, string str2)
    {
        // Code here
        int n = str1.size();
        int m = str2.size();
        dp.resize(n, vector<int>(m, -1));
        int ans = solve(0, 0, str1, str2);

        return ans;
    }
};
