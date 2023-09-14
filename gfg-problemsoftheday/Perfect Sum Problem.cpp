// Perfect Sum Problem
// MediumAccuracy: 20.58%Submissions: 195K+Points: 4
// 100+ Candidates recieved offers in the last 3 months through Job-A-Thon. Your call is just a click away

// Given an array arr[] of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

// Note: Answer can be very large, so, output answer modulo 109+7

// Example 1:

// Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
//        sum = 10
// Output: 3
// Explanation: {2, 3, 5}, {2, 8}, {10} are
// possible subsets.
// Example 2:
// Input: N = 5, arr[] = {1, 2, 3, 4, 5}
//        sum = 10
// Output: 3
// Explanation: {1, 2, 3, 4}, {1, 4, 5},
// {2, 3, 5} are possible subsets.
// Your Task:
// You don't need to read input or print anything. Complete the function perfectSum() which takes N, array arr[] and sum as input parameters and returns an integer value

// Expected Time Complexity: O(N*sum)
// Expected Auxiliary Space: O(N*sum)

// Constraints:
// 1 ≤ N*sum ≤ 106
// 0<=arr[I]<=106

class Solution
{

public:
    int mod = 1000000007;
    int solve(int i, int sum, int &n, int a[], vector<vector<int>> &dp)
    {
        if (i >= n)
        {
            if (sum == 0)
                return 1;
            return 0;
        }
        // if(sum == 0) return 1;
        if (sum < 0)
            return 0;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        int include = solve(i + 1, sum - a[i], n, a, dp) % mod;
        int exclude = solve(i + 1, sum, n, a, dp) % mod;
        return dp[i][sum] = (include + exclude) % mod;
    }
    // 1 0
    //
    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return solve(0, sum, n, arr, dp);
    }
};
