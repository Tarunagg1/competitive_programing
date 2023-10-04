// Roman Number to Integer
// EasyAccuracy: 43.31%Submissions: 124K+Points: 2
// Win 2X Geekbits, Get on the Leaderboard & Top the Coding Charts! Register for GFG Weekly Coding Contest

// banner
// Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
// I 1
// V 5
// X 10
// L 50
// C 100
// D 500
// M 1000

// Example 1:

// Input:
// s = V
// Output: 5
// Example 2:

// Input:
// s = III
// Output: 3
// Your Task:
// Complete the function romanToDecimal() which takes a string as input parameter and returns the equivalent decimal number.

// Expected Time Complexity: O(|S|), |S| = length of string S.
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<=roman no range<=3999

class Solution
{
public:
    int mp(char s)
    {
        if (s == 'I')
            return 1;
        if (s == 'V')
            return 5;
        if (s == 'X')
            return 10;
        if (s == 'L')
            return 50;
        if (s == 'C')
            return 100;
        if (s == 'D')
            return 500;
        if (s == 'M')
            return 1000;
    }
    int romanToDecimal(string &str)
    {
        int n = str.size();
        int cnt = mp(str[0]), ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (mp(str[i]) == mp(str[i - 1]))
            {
                cnt += mp(str[i]);
            }
            else if (mp(str[i]) > mp(str[i - 1]))
            {
                ans += mp(str[i]) - cnt;
                cnt = 0;
            }
            else
            {
                ans += cnt;
                cnt = mp(str[i]);
            }
        }
        ans += cnt;
        return ans;
    }
};
