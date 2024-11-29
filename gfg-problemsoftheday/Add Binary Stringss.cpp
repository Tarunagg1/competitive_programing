// Add Binary Strings
// Difficulty: MediumAccuracy: 23.25%Submissions: 60K+Points: 4
// Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
// Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

// Input: s1 = "1101", s2 = "111"
// Output: 10100
// Explanation:
//  1101
// + 111
// 10100
// Input: s1 = "00100", s2 = "010"
// Output: 110
// Explanation:
//   100
// +  10
//   110
// Constraints:
// 1 ≤s1.size(), s2.size()≤ 106

class Solution
{
public:
    string addBinary(string &s1, string &s2)
    {
        // your code here
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        int carry = 0;
        string ans = "";
        int len1 = s1.length(), len2 = s2.length();
        int i = 0, j = 0;
        while (i < len1 && j < len2)
        {
            if ((s1[i] == '1' && s2[j] == '1' && carry == 0) ||
                (s1[i] == '1' && s2[j] == '0' && carry == 1) ||
                (s1[i] == '0' && s2[j] == '1' && carry == 1))
            {
                carry = 1;
                ans += '0';
            }
            else if (s1[i] == '1' && s2[j] == '1' && carry == 1)
            {
                carry = 1;
                ans += '1';
            }
            else if ((s1[i] == '1' && s2[j] == '0' && carry == 0) ||
                     (s1[i] == '0' && s2[j] == '1' && carry == 0) ||
                     (s1[i] == '0' && s2[j] == '0' && carry == 1))
            {
                carry = 0;
                ans += '1';
            }
            else
            {
                carry = 0;
                ans += '0';
            }
            i++;
            j++;
        }
        while (j < len2)
        {
            if (s2[j] == '1' && carry == 1)
            {
                carry = 1;
                ans += '0';
            }
            else if ((s2[j] == '1' && carry == 0) ||
                     (s2[j] == '0' && carry == 1))
            {
                carry = 0;
                ans += '1';
            }
            else
            {
                ans += s2[j];
            }
            j++;
        }
        while (i < len1)
        {
            if (s1[i] == '1' && carry == 1)
            {
                carry = 1;
                ans += '0';
            }
            else if ((s1[i] == '1' && carry == 0) ||
                     (s1[i] == '0' && carry == 1))
            {
                carry = 0;
                ans += '1';
            }
            else
            {
                ans += s1[i];
            }
            i++;
        }
        if (carry == 1)
            ans += '1';
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.length(); i++)
        {
            if (ans[i] != '0')
                return ans.substr(i);
        }
        return ans;
    }
};
