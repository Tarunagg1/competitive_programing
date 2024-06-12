// Count numbers containing 4
// EasyAccuracy: 37.85%Submissions: 31K+Points: 2
// Solve today's problem-> Be the comment of the day-> Win a GfG T-Shirt!
// Daily rewards up for grabs!

// banner
// You are given a number n, Return the count of total numbers from 1 to n containing 4 as a digit.

// Examples:

// Input: n = 9
// Output: 1
// Explanation: 4 is the only number between 1 to 9 which contains 4 as a digit.
// Input: n = 44
// Output: 9
// Explanation: 4, 14, 24, 34, 40, 41, 42, 43 & 44, there are total 9 numbers containing 4 as a digit.
// Expected Time Complexity: O(nlogn)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= n <= 105

class Solution
{
public:
    bool IsFour(int num)
    {
        int org = num;
        int div = 1;
        while (num)
        {
            int digit = num % 10;
            if (digit == 4)
            {
                return true;
            }
            num = num / 10;
        }
        return false;
    }
    int countNumberswith4(int n)
    {
        // code here
        vector<int> ans;
        for (int i = 0; i <= n; i++)
        {
            ans.push_back(i);
        }
        int cnt = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            if (IsFour(ans[i]))
                cnt++;
            else
                continue;
        }
        return cnt;
    }
};
