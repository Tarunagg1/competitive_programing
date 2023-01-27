// Total Decoding Messages
// MediumAccuracy: 15.79%Submissions: 101K+Points: 4
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// You are an FBI agent. You have to determine the total number of ways that message can be decoded, as the answer can be large return the answer modulo 109 + 7.
// Note: An empty digit sequence is considered to have one decoding. It may be assumed that the input contains valid digits from 0 to 9 and If there are leading 0s, extra trailing 0s and two or more consecutive 0s then it is an invalid string.

// Example 1:

// Input: str = "123"
// Output: 3
// Explanation: "123" can be decoded as "ABC"(123),
// "LC"(12 3) and "AW"(1 23).
// Example 2:

// Input: str = "90"
// Output: 0
// Explanation: "90" cannot be decoded as it's an invalid string and we cannot decode '0'.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function CountWays() which takes the string as str as input parameter and returns the total number of ways the string can be decoded modulo 109 + 7.

// Expected Time Complexity: O(n)
// Expected Space Complexity: O(n) where n  = |str|

// Constraints:
// 1 <= |str| <= 104

// View Bookmarked Problems

const int mod = 1e9 + 7;
class Solution
{
public:
    int CountWays(string s)
    {
        // Code here
        int n = s.size();

        if (n == 0)
            return 0;

        if (s[0] == '0')
            return 0;

        int dp[n + 1];

        dp[0] = 1;

        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {

            if (s[i - 1] == '0')
            {

                if (s[i - 2] == '1' || s[i - 2] == '2')
                {

                    dp[i] = dp[i - 2];
                }
                else
                {

                    return 0;
                }
            }
            else if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] >= '1' && s[i - 1] <= '6'))
            {

                dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
            }
            else
            {

                dp[i] = dp[i - 1];
            }
        }

        return dp[n];
    }
};
