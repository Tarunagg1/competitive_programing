// Minimum Deletions
// MediumAccuracy: 58.8%Submissions: 28K+Points: 4
// Short on funds for the festive season? Register for Hackathon and win cash rewards!

// banner
// Given a string of S as input. Your task is to write a program to delete the minimum number of characters from the string so that the resultant string is a palindrome.
// Note: The order of characters in the string should be maintained.

// Example 1:

// Input:
// S = "aebcbda"
// Output:
// 2
// Explanation:
// Remove characters 'e' and 'd'.
// Example 2:

// Input:
// S = "geeksforgeeks"
// Output:
// 8
// Explanation:
// One of the possible result string can be "eefee", so answer is 13 - 5 = 8.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function minimumNumberOfDeletions() which takes the string S as inputs and returns the minimum number of deletions required to convert S into a pallindrome.

// Expected Time Complexity: O(|S|2)
// Expected Auxiliary Space: O(|S|2)

// Constraints:
// 1 ≤ |S| ≤ 103

class Solution
{
public:
    int helperFun(int n, int m, string &str1, string &str2, vector<vector<int>> &dp)
    {
        if (n == 0 or m == 0)
        {
            return 0;
        }

        if (str1[n - 1] == str2[m - 1])
        {
            return 1 + helperFun(n - 1, m - 1, str1, str2, dp);
        }

        if (dp[n][m] != -1)
        {
            return dp[n][m];
        }

        int option1 = helperFun(n, m - 1, str1, str2, dp);
        int option2 = helperFun(n - 1, m, str1, str2, dp);

        return dp[n][m] = max(option1, option2);
    }

    int minimumNumberOfDeletions(string str1)
    {
        int n = str1.size();
        string str2 = str1;
        reverse(str2.begin(), str2.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int cnt = helperFun(n, n, str1, str2, dp);
        return n - cnt;
    }
};
