// Max Sum without Adjacents
// EasyAccuracy: 72.1%Submissions: 3K+Points: 2
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// Given an array Arr of size N containing positive integers. Find the maximum sum of a subsequence such that no two numbers in the sequence should be adjacent in the array.

// Example 1:

// Input:
// N = 6
// Arr[] = {5, 5, 10, 100, 10, 5}
// Output: 110
// Explanation: If you take indices 0, 3
// and 5, then Arr[0]+Arr[3]+Arr[5] =
// 5+100+5 = 110.

// Example 2:

// Input:
// N = 4
// Arr[] = {3, 2, 7, 10}
// Output: 13
// Explanation: 3 and 10 forms a non
// continuous  subsequence with maximum
// sum.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findMaxSum() which takes the array of integers arr and n as parameters and returns an integer denoting the answer. It is guaranteed that your answer will always fit in the 32-bit integer.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 106
// 1 ≤ Arri ≤ 107

// View Bookmarked Problems

class Solution
{
public:
    // calculate the maximum sum with out adjacent
    int f(int ind, int *arr, int n, int dp[])
    {
        if (ind >= n)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int pick = arr[ind] + f(ind + 2, arr, n, dp);
        int notpick = 0 + f(ind + 1, arr, n, dp);
        return dp[ind] = max(pick, notpick);
    }

    int findMaxSum(int *arr, int n)
    {
        int dp[n + 1];
        memset(dp, -1, sizeof(dp));
        return f(0, arr, n, dp);
    }
};
