// Minimum number of deletions and insertions.
// Difficulty: MediumAccuracy: 65.29%Submissions: 50K+Points: 4
// Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

// Examples :

// Input: str1 = "heap", str2 = "pea"
// Output: 3
// Explanation: 2 deletions and 1 insertion.
// p and h deleted from heap. Then, p is inserted at the beginning.
// One thing to note, though p was required yet it was removed/deleted first from its position and then it is inserted to some other position. Thus, p contributes one to the deletion_count and one to the insertion_count.
// Input : str1 = "geeksforgeeks", str2 = "geeks"
// Output: 8
// Explanation: 8 deletions, i.e. remove all characters of the string "forgeeks".
// Expected Time Complexity: O(|str1|*|str2|)
// Expected Space Complexity: O(|str1|*|str2|)

// Constraints:
// 1 ≤ |str1|, |str2| ≤ 1000
// All the characters are lowercase English alphabets

// Seen this question in a real interview before ?

class Solution
{
public:
    int minOperations(string str1, string str2)
    {
        // Your code goes here
        int n = str1.size(), m = str2.size();
        long long dp[n + 1][m + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
                dp[i][j] = -1e15;
            dp[i][m] = 0;
        }
        for (int j = 0; j < m + 1; j++)
            dp[n][j] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (str1[i] == str2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return n + m - 2 * dp[0][0];
    }
};
