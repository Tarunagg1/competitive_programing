// Palindrome with minimum sum
// MediumAccuracy: 78.55%Submissions: 5K+Points: 4
// Finding a high paying job is easier than today's problem! Attend Job Fair 2023

// Given a string, S.The string can contain small case English letters or '?'. You can replace '?' with any small English letter. Now if it is possible to make the string S a palindrome after replacing all '?' then find the palindromic string with a minimum ascii sum of differences of adjacent characters. Otherwise, return -1.

// Example 1:

// Input: S = a???c??c????
// Output: 4
// Explanation:
// We can see that we can make the string
// palindrome. Now to get minimum ascii sum we should
// replace all the '?' between 'a' and 'c' with
// 'b' and all the '?' between two 'c' with 'c'.
// So after replacing all the '?' the string:
// abbbccccbbba.
// The sum of differences of adjacent characters is 4.
// Example 2:

// Input: S = a???c??c???c
// Output: -1
// Explanation:
// It is not possible to make the string palindrome.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function minimumSum() which takes a string S input parameter and returns an integer denoting the sum of differences of adjacent characters. If it is not possible to make string palindrome, return -1.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= |S| <= 105

// View Bookmarked Problems

class Solution
{
public:
    int minimumSum(string s)
    {
        // code here
        int n = s.size();
        int l = 0, h = n - 1;
        while (l <= h)
        {
            if (s[l] != s[h])
            {
                if (s[l] != '?' and s[h] != '?')
                    return -1;
            }
            l++;
            h--;
        }
        int cnt = 0;
        char prev = '2';
        l = 0, h = n - 1;
        while (l <= h)
        {
            if (s[l] != '?')
            {
                if (prev == '2')
                {
                    prev = s[l];
                }
                else
                {
                    cnt += (2 * (abs(s[l] - prev)));
                    prev = s[l];
                }
            }
            else if (s[h] != '?')
            {
                if (prev == '2')
                {
                    prev = s[h];
                }
                else
                {
                    cnt += (2 * (abs(s[h] - prev)));
                    prev = s[h];
                }
            }
            l++;
            h--;
        }
        return cnt;
    }
};
