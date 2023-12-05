// Sum-string
// HardAccuracy: 51.15%Submissions: 10K+Points: 8
// Job-A-Thon Hiring Challenge: Now Revamped for Professionals. Fast-track your Resumes to Job Openings today

// banner
// Given a string of digits, the task is to check if it is a ‘sum-string’. A string S is called a sum-string when it is broken down into more than one substring and the rightmost substring can be written as a sum of two substrings before it and the same is recursively true for substrings before it.

// Example 1:

// Input:
// S = "12243660"
// Output:
// 1
// Explanation:
// "12243660" can be broken down as {"12", "24", "36", "60"}.
// We can get 60 from 24 and 36 as 24 + 36 = 60. Similarly 36 can be written as 12 + 24.
// Example 2:

// Input:
// 1111112223
// Output:
// 1
// Explanation:
// "1111112223" can be broken down as {"1", "111", "112", "223"}.
// We can get 223 from 111 and 1112 as 111 + 112 = 223. Similarly 112 can be written as 1 + 111.
// Your Task:

// You don't need to read input or print anything. Your task is to complete the function isSumString() which takes the string S and returns 1 is S is a sum-string otherwise returns 0.

// Expected Time Complexity: O(|S|3)
// Expected Auxiliary Space: O(|S|)

// Constraints:
// 1 <= |S| <= 500
// String consists of characters from '0' to '9'.

class Solution
{
public:
    string sum(string s1, string s2)
    {
        int i = s1.length() - 1, j = s2.length() - 1;
        vector<char> ans;

        int x, y, res, rem, carry;
        char ch;

        while (i >= 0 and j >= 0)
        {

            x = s1[i] - '0';

            y = s2[j] - '0';

            res = x + y + carry;

            rem = res % 10;

            carry = res / 10;

            ans.push_back(rem + '0');

            i--;

            j--;
        }

        while (i >= 0)
        {

            x = s1[i] - '0';

            res = x + carry;

            rem = res % 10;

            carry = res / 10;

            ans.push_back(rem + '0');

            i--;
        }

        while (j >= 0)
        {
            y = s2[j] - '0';

            res = y + carry;

            rem = res % 10;

            carry = res / 10;

            ans.push_back(rem + '0');

            j--;
        }

        while (carry)
        {

            int rem = carry % 10;

            ans.push_back(rem + '0');

            carry /= 10;
        }

        string t;
        int p;

        for (p = ans.size() - 1; p >= 0; p--)
        {

            if (ans[i] != '0')

                break;
        }

        while (p >= 0)
        {
            t += ans[p];
            p--;
        }

        return t;
    }

    bool isValid(string s, int pos, int l1, int l2)
    {
        string s1 = s.substr(pos, l1);
        string s2 = s.substr(pos + l1, l2);
        string s3 = sum(s1, s2);

        int n = s3.length();
        if (n > s.length() - pos - l1 - l2)
            return 0;

        if (s.substr(pos + l1 + l2, n) == s3)
        {
            if (pos + l1 + l2 + n == s.length())
                return 1;

            return isValid(s, pos + l1, l2, n);
        }

        return 0;
    }

public:
    int isSumString(string s)
    {
        // code here
        int n = s.length();

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j + i < n; j++)
            {
                if (isValid(s, 0, i, j))
                    return 1;
            }
        }

        return 0;
    }
};
