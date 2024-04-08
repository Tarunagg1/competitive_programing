// Optimal Strategy For A Game
// MediumAccuracy: 49.03%Submissions: 59K+Points: 4
// You are given an array arr of size n. The elements of the array represent n coin of values v1, v2, ....vn. You play against an opponent in an alternating way. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.
// You need to determine the maximum possible amount of money you can win if you go first.
// Note: Both the players are playing optimally.

// Example 1:

// Input:
// n = 4
// arr[] = {5, 3, 7, 10}
// Output:
// 15
// Explanation: The user collects maximum
// value as 15(10 + 5). It is guarantee that we cannot get more than 15 by any possible moves.
// Example 2:

// Input:
// n = 4
// arr[] = {8, 15, 3, 7}
// Output:
// 22
// Explanation: The user collects maximum
// value as 22(7 + 15). It is guarantee that we cannot get more than 22 by any possible moves.
// Your Task:
// Complete the function maximumAmount() which takes an array arr[] (represent values of n coins) and n as a number of coins as a parameter and returns the maximum possible amount of money you can win if you go first.

// Expected Time Complexity : O(n*n)
// Expected Auxiliary Space: O(n*n)

// Constraints:
// 2 <= n <= 103
// 1 <= arr[i] <= 106

class Solution
{
public:
    long long dp[1001][1001];
    long long helper(int *arr, int i, int j)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        // we have 2 option either take from front or last and opponent also has 2 option

        // let say we pick from front, the opponent will try to make our total min
        // opponent picked it from first
        long long ans1 = helper(arr, i + 1, j - 1) + arr[i];
        // opponent picked from last
        if (i + 1 <= j)
            ans1 = min(ans1, helper(arr, i + 2, j) + arr[i]);

        // let say we pick from last , the opponent will try to make our total min
        long long ans2 = helper(arr, i + 1, j - 1) + arr[j];
        if (j - 1 >= i)
            ans2 = min(ans2, helper(arr, i, j - 2) + arr[j]);

        // max ans out of both
        return dp[i][j] = max(ans1, ans2);
    }
    long long maximumAmount(int n, int arr[])
    {
        memset(dp, -1, sizeof(dp));
        return helper(arr, 0, n - 1);
    }
};
