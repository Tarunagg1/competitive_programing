// Scrambled String
// HardAccuracy: 74.41%Submissions: 2K+Points: 8
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled form of S1.

// Scrambled string: Given string str, we can represent it as a binary tree by partitioning it into two non-empty substrings recursively.
// Below is one possible representation of str = coder:

// To scramble the string, we may choose any non-leaf node and swap its two children.
// Suppose, we choose the node co and swap its two children, it produces a scrambled string ocder.
// Similarly, if we continue to swap the children of nodes der and er, it produces a scrambled string ocred.

// Note: Scrambled string is not the same as an Anagram.

// Print "Yes" if S2 is a scrambled form of S1 otherwise print "No".

// Example 1:

// Input: S1="coder", S2="ocder"
// Output: Yes
// Explanation: ocder is a scrambled
// form of coder.

//     ocder
//    /    \
//   oc    der
//  / \    
// o   c

// As "ocder" can represent it
// as a binary tree by partitioning
// it into two non-empty substrings.
// We just have to swap 'o' and 'c'
// to get "coder".
// Example 2:

// Input: S1="abcde", S2="caebd"
// Output: No
// Explanation: caebd is not a
// scrambled form of abcde.
// Your Task:
// You don't need to read input or print anything. You only need to complete the function isScramble() which takes two strings S1 and S2 as input and returns a boolean value.

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(N2)

// Constrains:

// S1.length = S2.length
// S1.length<=31
// S1 and S2 consist of lower-case English letters.
// View Bookmarked Problems

class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        // code here
        if (s1 == s2)
            return true;

        if (s1.size() != s2.size())
            return false;

        int n = s1.size();

        int count[26] = {0};

        for (int i = 0; i < n; i++)
        {

            count[s1[i] - 'a']++;

            count[s2[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)

            if (count[i])
                return false;

        bool dp[n][n][n + 1];

        memset(dp, false, sizeof dp);

        for (int i = n - 1; i >= 0; i--)
        {

            for (int j = n - 1; j >= 0; j--)
            {

                dp[i][j][1] = s1[i] == s2[j];

                for (int k = 2; i + k <= n && j + k <= n; k++)
                {

                    for (int p = 1; p < k; p++)
                    {

                        if ((dp[i][j][p] && dp[i + p][j + p][k - p]) || (dp[i][j + k - p][p] && dp[i + p][j][k - p]))
                        {

                            dp[i][j][k] = true;

                            break;
                        }
                    }
                }
            }
        }

        return dp[0][0][n];
    }
};
