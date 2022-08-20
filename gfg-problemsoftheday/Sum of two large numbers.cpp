// Sum of two large numbers
// MediumAccuracy: 47.9%Submissions: 14512Points: 4
// Given two strings denoting non-negative numbers X and Y. Calculate the sum of X and Y.

// Example 1:

// Input:
// X = "25", Y = "23"
// Output:
// 48
// Explanation:
// The sum of 25 and 23 is 48.
// Example 2:

// Input:
// X = "2500", Y = "23"
// Output:
// 2523
// Explanation:
// The sum of 2500 and 23 is 2523.

// Your Task:
// Your task is to complete the function findSum() which takes two strings as inputs and returns the string without leading zeros. You do not need to take any input or print anything.

// Expected Time Complexity: O(|X| + |Y|)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= |X|, |Y| <= 105

class Solution
{
public:
    void makeequal(string &x, string &y)
    {
        if (x.length() > y.length())
            while (x.length() != y.length())
                y = '0' + y;
        else
            while (x.length() != y.length())
                x = '0' + x;
    }
    string findSum(string x, string y)
    {
        makeequal(x, y);
        int x1 = x.length() - 1, y1 = y.length() - 1, c = 0;
        string ans = "";
        while (x1 >= 0)
        {
            int s = (-'0' + x[x1--]) + (-'0' + y[y1--]) + c;
            ans += ((char)(('0' + s % 10)));
            c = s / 10;
        }
        if (c > 0)
            ans += ((char)(('0' + c)));
        reverse(ans.begin(), ans.end());
        int i = 0;
        for (i = 0; i < ans.size(); i++)
            if (ans[i] != '0')
                break;
        if (i == ans.size())
            return "0";
        return ans.substr(i, ans.length() - i);
    }
};
