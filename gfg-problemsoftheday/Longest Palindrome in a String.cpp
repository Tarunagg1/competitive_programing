// Longest Palindrome in a String
// MediumAccuracy: 23.2%Submissions: 236K+Points: 4
// Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string that reads the same backward. More formally, S is a palindrome if reverse(S) = S. In case of conflict, return the substring which occurs first ( with the least starting index).

// Example 1:

// Input:
// S = "aaaabbaa"
// Output: aabbaa
// Explanation: The longest Palindromic
// substring is "aabbaa".
// Example 2:

// Input:
// S = "abc"
// Output: a
// Explanation: "a", "b" and "c" are the
// longest palindromes with same length.
// The result is the one with the least
// starting index.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function longestPalin() which takes the string S as input and returns the longest palindromic substring of S.

// Expected Time Complexity: O(|S|2).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ |S| ≤ 103

// View Bookmarked Problems

class Solution
{
public:
    string longestPalin(string s)
    {
        int maxi = INT_MIN;
        string ans;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = s.size() - 1; j >= i; j--)
            {
                if (ispali(i, j, s))
                {
                    if (maxi < (j - i + 1))
                    {
                        maxi = j - i + 1;
                        ans = s.substr(i, j - i + 1);
                    }
                    break;
                }
            }
        }
        return ans;
    }
    bool ispali(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
