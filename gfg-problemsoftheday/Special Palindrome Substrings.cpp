// Special Palindrome Substrings
// MediumAccuracy: 78.74%Submissions: 2K+Points: 4
// Participate in Monthly Hiring Challenge conducted by GeeksforGeeks !!

// Given two strings s1 and s2, The task is to convert s1 into a palindrome such that s1 contain s2 as a substring in a minimum number of operation.
// In a single operation, we can replace any word of s1 with any character.

// Note: If it is not possible to convert s1 such that it is a palindrome as well as contains substring of s2, then return -1.

// Example 1:

// Input:
// s1="abaa" s2="bb"
// Output: 1
// Explanation:
// we can replace s1[2]='a' with 'b'.
// So the new s1 will be like "abba",
// having s2 as a substring.
// Example 2:

// Input:
// s1="abbd" s2="mr"
// Output: 4
// Explanation:
// 1st: s1="mrbd" --> 2 operations (this is the
// minimum operation to make s2 a substring of s1)
// 2nd: s1="mrrm" --> 2 operations
// (this is the minimum operation to make s1 palindrome)
// Your Task:
// You don't need to read input or print anything. Complete the function specialPalindrome() which takes the two strings s1 and s2 as input parameters. Return the minimum number of operations needs to convert s1 such that it is a palindrome and having s2 as a substring in s1.

// Expected Time Complexity: O(N*M) [N: size of s1 and M: size of s2]
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ |s2| ≤ |s1| ≤  1000

// View Bookmarked Problems

class Solution
{
    // Complete the function and return minimum number of operations
public:
    int noofop(string &s, int k, int m)
    {
        int i = 0;
        int j = s.length() - 1;
        int ans = 0;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                /*
                WE SHOULD NOT CHANGE CHARACTERS OF S2 WHICH IS A SUBSTRING IN S1 ,
                   IF THERE ARISES A CASE TO CHANGE THEM THEN IT IS NOT POSSIBLE TO MAKE S1 A PALINDROME, SO RETURNING INT_MAX
                */
                if (i >= k && j <= (k + m - 1))
                    return 1e9;
                ans++;
            }
            i++;
            j--;
        }
        return ans;
    }
    int specialPalindrome(string s1, string s2)
    {
        // Code Here
        int n = s1.size();
        int m = s2.size();
        if (n < m)
            return -1;

        if (s1 == s2)
        {
            int ans = noofop(s1, -1, -1);
            if (ans == 0)
                return 0;
            else
                return -1;
        }
        int minans = 1e9;
        int ans = 0;
        string temp;
        for (int i = 0; i <= n - m; i++)
        {
            ans = 0;
            temp = s1;
            int k = i;
            /*VERIFYING EACH AND EVERY VALID POSITIONS*/
            for (int j = 0; j < m; j++)
            {
                if (temp[k] == s2[j])
                {
                    k++;
                    continue;
                }
                ans++;
                temp[k] = s2[j];

                k++;
            }
            /* NO OF OPERATIONS FUNCTION FOR
                FINDING NO OF OPERATIONS NEED TO BE PERFORMED FOR MAKING S1 PALINDROME*/
            ans += noofop(temp, i, m);
            minans = min(minans, ans);
        }
        if (minans == 1e9)
            return -1;
        return minans;
    }
};
