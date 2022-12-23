// Burst Balloons
// HardAccuracy: 60.57%Submissions: 289+Points: 8
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// You are given N balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array arr. You are asked to brust all the balloons.
// If you brust the ith  balloon,, you will get arr[ i - 1 ] * arr[ i ] * arr[ i + 1] coins. If i - 1, or i + 1 goes out of bounds of the array, consider it as if there is a balloon with a 1 painted on it.
// Return the maximum coins you can collect by brusting the balloons wisely.

// Example 1:

// Input:
// N = 4
// arr[ ] = {3, 1, 5, 8}
// Output: 167
// Explanation:
// arr[ ] = {3, 1, 5, 8}  - - > {3, 5, 8} - - > {3, 8} - - > { 8} - -> { }
// coins = 3 *1 *5,      +      3*5*8     +   1*3*8   +  1*8*1   = 167

// Example 2:

// Input:
// N = 2
// arr[ ] = {1, 10}
// Output: 20

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maxCoins() which takes the array of integers arr and N as parameters and returns the maximum coin you can collect.

// Expected Time Complexity: O(N*N*N)
// Expected Auxiliary Space: O(N*N)

// Constraints:
// 1 ≤ N ≤ 300
// 0 ≤ arr [ i ]  ≤ 100

// View Bookmarked Problems

class Solution
{
public:
    int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MIN;

        for (int ind = i; ind <= j; ind++)
        {
            int cost = (arr[i - 1] * arr[ind] * arr[j + 1]) + f(i, ind - 1, arr, dp) + f(ind + 1, j, arr, dp);
            ans = max(ans, cost);
        }
        return dp[i][j] = ans;
    }

    int maxCoins(int n, vector<int> &arr)
    {

        arr.push_back(1);

        arr.insert(arr.begin(), 1);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return f(1, n, arr, dp);
    }
};
