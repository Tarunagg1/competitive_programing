// Minimum Cost To Make Two Strings Identical
// EasyAccuracy: 52.29%Submissions: 13K+Points: 2
// In need of more Geekbits? Win from a pool of 3500+ Geekbits via DSA-based Coding Contest every sunday!

// banner
// Given two strings x and y, and two values costX and costY, the task is to find the minimum cost required to make the given two strings identical. You can delete characters from both the strings. The cost of deleting a character from string X is costX and from Y is costY. The cost of removing all characters from a string is the same.

// Example 1:

// Input: x = "abcd", y = "acdb", costX = 10
//        costY = 20.
// Output: 30
// Explanation: For Making both strings
// identical we have to delete character
// 'b' from both the string, hence cost
// will be = 10 + 20 = 30.
// Example 2:

// Input : x = "ef", y = "gh", costX = 10
//         costY = 20.
// Output: 60
// Explanation: For making both strings
// identical, we have to delete 2-2
// characters from both the strings, hence
// cost will be = 10 + 10 + 20 + 20 = 60.
// Your Task:
// You don't need to read or print anything. Your task is to complete the function findMinCost() which takes both strings and the costs as input parameters and returns the minimum cost.

// Expected Time Complexity: O(|x|*|y|)
// Expected Space Complexity: O(|x|*|y|)

// Constraints:
// 1 ≤ |x|, |y| ≤ 1000
// 1<= costX, costY <= 105

class Solution
{

public:
    int lcs(string x, string y)
    {
        int n = x.length(), m = y.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (x[i - 1] == y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
    int findMinCost(string x, string y, int costX, int costY)
    {
        int len = lcs(x, y);
        int ans = 0;
        int n = x.length(), m = y.length();
        ans = (n - len) * costX + (m - len) * costY;
        return ans;
    }
};
