// Minimum sum partition
// HardAccuracy: 38.97%Submissions: 97299Points: 8
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.

// Given an array arr of size n containing non-negative integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference

// Example 1:

// Input: N = 4, arr[] = {1, 6, 11, 5}
// Output: 1
// Explanation:
// Subset1 = {1, 5, 6}, sum of Subset1 = 12
// Subset2 = {11}, sum of Subset2 = 11
// Example 2:
// Input: N = 2, arr[] = {1, 4}
// Output: 3
// Explanation:
// Subset1 = {1}, sum of Subset1 = 1
// Subset2 = {4}, sum of Subset2 = 4

// Your Task:
// You don't need to read input or print anything. Complete the function minDifference() which takes N and array arr as input parameters and returns the integer value

// Expected Time Complexity: O(N*|sum of array elements|)
// Expected Auxiliary Space: O(N*|sum of array elements|)

// Constraints:
// 1 ≤ N*|sum of array elements| ≤ 106
// 0 < arr[i] <= 105

// View Bookmarked Problems

class Solution
{

public:
    int ans = INT_MAX;

    int fun(int nums[], int n, int s1, int s2, int i, vector<vector<int>> &dp)
    {

        if (i == n)
        {

            return ans = min(ans, abs(s1 - s2));
        }

        if (dp[i][s1] != -1)
            return dp[i][s1];

        int op1 = INT_MAX;

        int op2 = INT_MAX;

        op1 = fun(nums, n, s1 + nums[i], s2 - nums[i], i + 1, dp);

        op2 = fun(nums, n, s1, s2, i + 1, dp);

        return dp[i][s1] = min(op1, op2);
    }

    int minDifference(int nums[], int n)
    {

        int s2 = 0;

        for (int i = 0; i < n; i++)
        {

            s2 += nums[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(s2 + 1, -1));

        return fun(nums, n, 0, s2, 0, dp);
    }
};
