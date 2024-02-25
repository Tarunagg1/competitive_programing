// Reach a given score
// EasyAccuracy: 79.23%Submissions: 35K+Points: 2
// Internship Alert!
// Become an SDE Intern by topping this monthly leaderboard!

// banner
// Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find number of distinct combinations to reach the given score.

// Example 1:

// Input
// n = 10
// Output
// 2
// Explanation
// There are two ways {5,5} and {10}.
// Example 2:

// Input
// n = 20
// Output
// 4
// Explanation
// There are four possible ways. {5,5,5,5}, {3,3,3,3,3,5}, {10,10}, {5,5,10}.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function count( ) which takes n as input parameter and returns the answer to the problem.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:

// 1 ≤ n ≤ 106

class Solution
{
public:
    // Complete this function
    long long f(int ind, vector<int> &vals, long long n, vector<vector<int>> &dp)
    {
        if (ind < 0)
            return 0;
        if (n == 0)
            return 1;

        if (dp[ind][n] != -1)
            return dp[ind][n];

        int pick = 0, notPick = 0;

        if (vals[ind] <= n)
        {
            pick = f(ind, vals, n - vals[ind], dp);
        }

        notPick = f(ind - 1, vals, n, dp);

        return dp[ind][n] = pick + notPick;
    }

    long long int count(long long int n)
    {
        // Your code here
        vector<int> vals = {3, 5, 10};
        vector<vector<int>> dp(3, vector<int>(n + 1, -1));
        return f(2, vals, n, dp);
    }
};
