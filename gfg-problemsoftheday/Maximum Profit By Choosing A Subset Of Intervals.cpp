// Maximum Profit By Choosing A Subset Of Intervals
// MediumAccuracy: 25.0%Submissions: 4+Points: 4
// Lamp
// Stand out from the crowd. Prepare with Complete Interview Preparation

// Given a list intervals of n intervals, the ith element [s, e, p] denotes the starting point s, ending point e, and the profit p earned by choosing the ith interval. Find the maximum profit one can achieve by choosing a subset of non-overlapping intervals.

// Two intervals [s1, e1, p1] and [s2, e2, p2] are said to be non-overlapping if [e1 <= s2] and [s1 < s2].

// Example 1:

// Input:
// n = 3
// intervals = {
// {1, 2, 4},
// {1, 5, 7},
// {2, 4, 4}
// }
// Output:
// 8
// Explanation:
// One can choose intervals [1, 2, 4] and [2, 4, 4] for a
// profit of 8.
// Example 2:

// Input:
// n = 3
// intervals = {
// {1, 4, 4},
// {2, 3, 7},
// {2, 3, 4}
// }
// Output:
// 7
// Explanation:
// One can choose interval [2, 3, 7] for a profit of 7.
// Your Task:

// You don't need to print or output anything. Complete the function maximum_profit() which takes an integer n and a 2D integer array intervals and returns an integer, denoting the maximum profit which one can get by choosing the non-overlapping intervals.

// Constraints:

// 1 <= n and n <= 104
// 1 <= starting point of ith interval < ending point of ith interval <= 105
// 1 <= profit earned by choosing ith interval <= 105
// View Bookmarked Problems

class Solution
{
public:
    int getLowerBound(int ind, vector<vector<int>> &arr)
    {
        int lb = -1;
        int low = ind + 1;
        int high = arr.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid][0] >= arr[ind][1])
            {
                lb = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return lb;
    }

    int getMaxProfit(int ind, vector<vector<int>> &arr, vector<int> &dp)
    {
        if (ind >= arr.size())
            return 0;
        if (dp[ind] != -1)
            return dp[ind];

        int notPick = getMaxProfit(ind + 1, arr, dp);
        int nextIdx = getLowerBound(ind, arr);

        int pick = arr[ind][2] + (nextIdx == -1 ? 0 : getMaxProfit(nextIdx, arr, dp));

        return dp[ind] = max(pick, notPick);
    }

    int maximum_profit(int n, vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<int> dp(n, -1);
        return getMaxProfit(0, intervals, dp);
    }
};
