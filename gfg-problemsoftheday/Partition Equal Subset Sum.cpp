// Partition Equal Subset Sum
// MediumAccuracy: 30.24%Submissions: 188K+Points: 4
// 100+ Candidates recieved offers in the last 3 months through Job-A-Thon. Your call is just a click away

// Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

// Example 1:

// Input: N = 4
// arr = {1, 5, 11, 5}
// Output: YES
// Explanation:
// The two parts are {1, 5, 5} and {11}.
// Example 2:

// Input: N = 3
// arr = {1, 3, 5}
// Output: NO
// Explanation: This array can never be
// partitioned into two such parts.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.

// Expected Time Complexity: O(N*sum of elements)
// Expected Auxiliary Space: O(N*sum of elements)

// Constraints:
// 1 ≤ N ≤ 100
// 1 ≤ arr[i] ≤ 1000
// N*sum of elements ≤ 5*106

class Solution
{
public:
    int solve(int n, int arr[], int &sum, int i, int cnt, vector<vector<int>> &dp)
    {
        if (i >= n or cnt > sum / 2)
        {
            return 0;
        }
        if (dp[i][cnt] != -1)
        {
            return dp[i][cnt];
        }
        if (cnt == sum / 2 and sum % 2 == 0)
        {
            return 1;
        }
        int inc = solve(n, arr, sum, i + 1, cnt + arr[i], dp);
        int exc = solve(n, arr, sum, i + 1, cnt, dp);
        return dp[i][cnt] = (inc || exc);
    }
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return solve(n, arr, sum, 0, 0, dp);
    }
};
