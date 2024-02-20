// Word Break
// MediumAccuracy: 40.86%Submissions: 97K+Points: 4
// Internship Alert!
// Become an SDE Intern by topping this monthly leaderboard!

// banner
// Given a string s and a dictionary of n words dictionary, find out if a s can be segmented into a space-separated sequence of dictionary words. Return 1 if it is possible to break the s into a sequence of dictionary words, else return 0.

// Note: From the dictionary dictionary each word can be taken any number of times and in any order.

// Example 1:

// Input:
// n = 6
// s = "ilike"
// dictionary = { "i", "like", "sam", "sung", "samsung", "mobile"}
// Output:
// 1
// Explanation:
// The string can be segmented as "i like".
// Example 2:

// Input:
// n = 6
// s = "ilikesamsung"
// dictionary = { "i", "like", "sam", "sung", "samsung", "mobile"}
// Output:
// 1
// Explanation:
// The string can be segmented as
// "i like samsung" or "i like sam sung".
// Your Task:
// Complete wordBreak() function which takes a string and list of strings as a parameter and returns 1 if it is possible to break words, else return 0. You don't need to read any input or print any output, it is done by driver code.

// Expected Time Complexity: O(len(s)2)
// Expected Space Complexity: O(len(s))

// Constraints:
// 1 ≤ n ≤ 12
// 1 ≤ len(s) ≤ 1100

class Solution
{
public:
    int wordBreak(int n, string s, vector<string> &wordDict)
    {
        // code here
        n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        unordered_set<string> dict(wordDict.begin(), wordDict.end()); // Convert wordDict to unordered_set for O(1) lookup

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end())
                { // Use unordered_set's find for O(1) lookup
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
