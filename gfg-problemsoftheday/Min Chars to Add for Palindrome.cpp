// Min Chars to Add for Palindrome
// Difficulty: HardAccuracy: 46.79%Submissions: 50K+Points: 8
// Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

// Note: A palindrome string is a sequence of characters that reads the same forward and backward.

// Examples:

// Input: s = "abc"
// Output: 2
// Explanation: Add 'b' and 'c' at front of above string to make it palindrome : "cbabc"
// Input: s = "aacecaaaa"
// Output: 2
// Explanation: Add 2 a's at front of above string to make it palindrome : "aaaacecaaaa"
// Constraints:
// 1 <= s.size() <= 106

class Solution
{
public:
    int minChar(string &s)
    {
        // Write your code here
        string rev = s;
        reverse(rev.begin(), rev.end());
        s += "$";
        s += rev;
        int pre = 0, suff = 1;
        vector<int> LPS(s.length(), 0);
        while (suff < s.length())
        {
            if (s[suff] == s[pre])
            {
                LPS[suff] = pre + 1;
                suff++;
                pre++;
            }
            else
            {
                if (pre == 0)
                    suff++;
                else
                    pre = LPS[pre - 1];
            }
        }
        return rev.length() - LPS[s.length() - 1];
    }
};
