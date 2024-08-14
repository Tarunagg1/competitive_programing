// Longest Common Substring
// Difficulty: MediumAccuracy: 42.69%Submissions: 221K+Points: 4
// You are given two strings str1 and str2. Your task is to find the length of the longest common substring among the given strings.

// Examples:

// Input: str1 = "ABCDGH", str2 = "ACDGHR"
// Output: 4
// Explanation: The longest common substring is "CDGH" which has length 4.
// Input: str1 = "ABC", str2 = "ACB"
// Output: 1
// Explanation: The longest common substrings are "A", "B", "C" all having length 1.
// Expected Time Complexity: O(n*m).
// Expected Auxiliary Space: O(n*m).

// Constraints:
// 1<= str1.size(), str2.size()<=1000
// Both strings may contain upper and lower case alphabets.

// Seen this question in a real interview before ?
// Yes
// No
// Company Tags
// Morgan StanleyAmazonMicrosoft

class Solution
{
public:
    int longestCommonSubstr(string str1, string str2)
    {
        // your code here
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>> dp(2, vector<int>(m + 1, 0));
        int maxLength = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                    maxLength = max(maxLength, dp[i % 2][j]);
                }
                else
                {
                    dp[i % 2][j] = 0;
                }
            }
        }

        return maxLength;
    }
};
