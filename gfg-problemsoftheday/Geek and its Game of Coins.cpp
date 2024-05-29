// Geek and its Game of Coins
// MediumAccuracy: 42.49%Submissions: 22K+Points: 4
// Skill-Up Summer Sale! Get 30% Off on all GfG Courses.
// Get Certified this Summer!

// banner
// Given three numbers n, x, and y, Geek and his friend are playing a coin game. In the beginning, there are n coins. In each move, a player can pick x, y, or 1 coin. Geek always starts the game. The player who picks the last coin wins the game. The task is to determine whether Geek will win the game or not if both players play optimally.

// Example 1:

// Input:
// n = 5
// x = 3
// y = 4
// Output:
// 1
// Explanation:
// There are 5 coins, every player can pick 1 or 3 or 4 coins on his/her turn. Geek can win by picking 3 coins in first chance. Now 2 coins will be left so his friend will pick one coin and now Geek can win by picking the last coin.
// Example 2:
// Input:
// n = 2
// x = 3
// y = 4
// Output:
// 0
// Explanation:
// Geek picks 1 coin and then his friend picks 1 coin.
// Your Task:
// You don't need to read input or print anything. Complete the function findWinner() which takes n, x, and y as input parameters and returns 1 if Geek can win otherwise 0.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 ≤ n, x, y ≤ 105

class Solution
{
public:
    int findWinner(int n, int x, int y)
    {
        // code here
        int wins(int n, int &x, int &y, vector<int> &dp)
        {
            if (n == 0)
            {
                return 0;
            }
            else if (dp[n] != -1)
            {
                return dp[n];
            }
            int ans = 0;
            ans |= (!(wins(n - 1, x, y, dp)));
            if (n - x >= 0)
            {
                ans |= (!(wins(n - x, x, y, dp)));
            }
            if (n - y >= 0)
            {
                ans |= (!(wins(n - y, x, y, dp)));
            }
            return dp[n] = ans;
        }
        int findWinner(int n, int x, int y)
        {
            // code here
            vector<int> dp(n + 1, -1);
            return wins(n, x, y, dp);
        }
    }
};
