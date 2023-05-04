// Max Coins
// MediumAccuracy: 75.68%Submissions: 5K+Points: 4
// Finding A Job Is Now Easier Than Today's Problem! Explore Job Fair 2023

// Your are given an 2D integer array  ranges whose length is n where  ranges[i]=[starti,endi,coinsi] means all integers from starti to  endi inclusive starti and endi are present and  we get coinsi amount of coins when we select this ith range . You can select atmost two intervals so as to collect maximum coins but if u select two ranges than those two ranges should not intersect or overlapp than can touch each other.

// Note : You can select at max 2 ranges and they should not intersect with each other but they can touch themselves.

// Example 1:

// Input :
// n=3
// ranges={{1,3,4},{2,3,5},{3,4,2}}
// Output: 7
// Explanation:
// We can see that we can take 2nd and
// 3rd ranges as they are not intersecting
// (only touching) we get maximum Coins by
// taking these ranges(5+2=7).
// Example 2:

// Input :
// n=5
// ranges={{1,3,4},{2,3,5},{3,4,2},{5,8,9},{2,8,10}}
// Output: 14
// Explanation:
// We can see that we can take 2nd and
// 4th ranges as they are not intersecting
// we get maximum Coins(5+9=14) by taking
// these ranges.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maxCoins() which takes an integer n(length of ranges) and integer 2D integer array ranges and you have to  return the maximum number of coins which you can get after selecting atmost two ranges which are not intersecting.

// Expected Time Complexity: O(nlogn)
// Expected Space Complexity: O(n)

// Constraints:
// 1<=n<=105
// 0<=ranges[i][0]<=ranges[i][1]<=109
// 0<=ranges[i][2](coins)<=106
// The sum of n over all test cases won't exceed 106

// View Bookmarked Problems

class Solution
{
public:
    vector<vector<int>> dp;

    int binarySearch(int i, int j, int end, vector<vector<int>> &ranges)
    {
        int res = ranges.size();
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (ranges[mid][0] >= end)
            {
                res = mid;
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        return res;
    }

    int solve(int i, int rem, vector<vector<int>> &ranges)
    {
        if (i == ranges.size() || rem == 0)
            return 0;
        if (dp[i][rem] != -1)
            return dp[i][rem];
        int notTake = solve(i + 1, rem, ranges);
        int take = ranges[i][2];
        int ind = binarySearch(i + 1, ranges.size() - 1, ranges[i][1], ranges);
        take += solve(ind, rem - 1, ranges);
        return dp[i][rem] = max(take, notTake);
    }

    int maxCoins(int n, vector<vector<int>> &ranges)
    {
        // Code here
        sort(ranges.begin(), ranges.end());
        dp = vector<vector<int>>(ranges.size(), vector<int>(3, -1));

        return solve(0, 2, ranges);
    }
};
