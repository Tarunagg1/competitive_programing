// Stickler Thief
// MediumAccuracy: 37.98%Submissions: 173K+Points: 4
// Learn Google Cloud with Curated Lab Assignments. Register, Earn Rewards, Get noticed by experts at Google & Land your Dream Job!
// Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. ith house has a[i] amount of money present in it.

// Example 1:

// Input:
// n = 5
// a[] = {6,5,5,7,4}
// Output:
// 15
// Explanation:
// Maximum amount he can get by looting 1st, 3rd and 5th house. Which is 6+5+4=15.
// Example 2:

// Input:
// n = 3
// a[] = {1,5,3}
// Output:
// 5
// Explanation:
// Loot only 2nd house and get maximum amount of 5.
// Your Task:
// Complete the functionFindMaxSum() which takes an array arr[] and n as input which returns the maximum money he can get following the rules.

// Expected Time Complexity:O(N).
// Expected Space Complexity:O(N).

// Constraints:
// 1 ≤ n ≤ 105
// 1 ≤ a[i] ≤ 104

class Solution
{
public:
    // Function to find the maximum money the thief can get.
    int help(int i, int arr[], vector<int> &dp)
    {
        if (i == 0)
            return arr[0];
        if (dp[i] != -1)
            return dp[i];

        int take = arr[i] + help(i - 2, arr, dp);
        int not_take = help(i - 1, arr, dp);

        return dp[i] = max(take, not_take);
    }

    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n, -1);
        return help(n - 1, arr, dp);
    }
};
