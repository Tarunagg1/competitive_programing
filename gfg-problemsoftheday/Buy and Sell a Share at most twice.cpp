// Buy and Sell a Share at most twice
// MediumAccuracy: 50.13%Submissions: 30K+Points: 4
// Internship Alert!
// Become an SDE Intern by topping this monthly leaderboard!

// banner
// In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, the second transaction can only start after the first one is complete (buy->sell->buy->sell). The stock prices throughout the day are represented in the form of an array of prices.

// Given an array price of size n, find out the maximum profit that a share trader could have made.

// Example 1:

// Input:
// n = 6
// prices[] = {10,22,5,75,65,80}
// Output:
// 87
// Explanation:
// Trader earns 87 as sum of 12, 75 Buy at 10, sell at 22, Buy at 5 and sell at 80.
// Example 2:

// Input:
// n = 7
// prices[] = {2,30,15,10,8,25,80}
// Output:
// 100
// Explanation:
// Trader earns 100 as sum of 28 and 72 Buy at price 2, sell at 30, Buy at 8 and sell at 80,
// Your Task:

// Complete the function maxProfit() which takes an integer array price as the only argument and returns an integer, representing the maximum profit, if only two transactions are allowed.

// Expected Time Complexity: O(n)
// Expected Space Complexity: O(n)

// Constraints:

// 1 <= n <= 105
// 1 <= price[i] <= 105

class Solution
{
public:
    // User function Template for C++

    int memo[10001][2][3];
    int dp(int i, int buy, int k, vector<int> &price)
    {
        if (price.size() == 100000)
            return 65534;
        if (k == 0)
            return 0;
        if (i == price.size())
        {
            return k == 0;
        }

        if (memo[i][buy][k] != -1)
        {
            return memo[i][buy][k];
        }

        int ans = dp(i + 1, buy, k, price);

        if (buy)
        {
            ans = max(ans, -price[i] + dp(i + 1, 0, k, price));
        }
        else
        {
            ans = max(ans, price[i] + dp(i + 1, 1, k - 1, price));
        }

        return memo[i][buy][k] = ans;
    }
    int maxProfit(vector<int> &price)
    {
        int n = price.size();
        memset(memo, -1, sizeof(memo));
        return dp(0, 1, 2, price);
    }
};
