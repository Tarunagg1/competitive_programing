// Boolean Parenthesization
// HardAccuracy: 20.15%Submissions: 92K+Points: 8
// Internship Alert!
// Become an SDE Intern by topping this monthly leaderboard!

// banner
// Given a boolean expression s of length n with following symbols.
// Symbols
//     'T' ---> true
//     'F' ---> false
// and following operators filled between symbols
// Operators
//     &   ---> boolean AND
//     |   ---> boolean OR
//     ^   ---> boolean XOR
// Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

// Note: The answer can be large, so return it with modulo 1003

// Example 1:

// Input:
// n = 7
// s = T|T&F^T
// Output:
// 4
// Explaination:
// The expression evaluates to true in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
// Example 2:

// Input:
// n = 5
// s = T^F|F
// Output:
// 2
// Explaination:
// ((T^F)|F) and (T^(F|F)) are the only ways.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function countWays() which takes n and s as input parameters and returns number of possible ways modulo 1003.

// Expected Time Complexity: O(n3)
// Expected Auxiliary Space: O(n2)

// Constraints:
// 1 ≤ n ≤ 200

class Solution
{
public:
    long long MOD = 1003;
    // map<pair<int,int>,pair<int,int>>dp;
    pair<int, int> dfs(string &s, int low, int high, vector<vector<pair<int, int>>> &dp)
    {
        if (low == high)
        {
            if (s[low] == 'T')
                return {1, 0};
            else
                return {0, 1};
        }
        pair<int, int> default2 = {-1, -1};
        if (dp[low][high] != default2)
            return dp[low][high];
        long long truth = 0, falsy = 0;
        for (int i = low; i <= high - 2; i += 2)
        {
            auto left = dfs(s, low, i, dp);
            auto right = dfs(s, i + 2, high, dp);
            if (s[i + 1] == '|')
            {
                truth = (truth + left.first * right.first) % MOD;
                truth = (truth + left.first * right.second) % MOD;
                truth = (truth + left.second * right.first) % MOD;
                falsy = (falsy + left.second * right.second) % MOD;
            }
            else if (s[i + 1] == '&')
            {
                truth = (truth + left.first * right.first) % MOD;
                falsy = (falsy + left.first * right.second) % MOD;
                falsy = (falsy + left.second * right.first) % MOD;
                falsy = (falsy + left.second * right.second) % MOD;
            }
            else
            {

                truth = (truth + left.first * right.second) % MOD;
                truth = (truth + left.second * right.first) % MOD;
                falsy = (falsy + left.first * right.first) % MOD;
                falsy = (falsy + left.second * right.second) % MOD;
            }
            // cout<<low<<" "<<i<<" "<<truth<<" "<<falsy<<endl;
        }
        return dp[low][high] = {truth, falsy};
    }
    int countWays(int n, string s)
    {
        // code here
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, -1}));
        return dfs(s, 0, n - 1, dp).first;
    }
};
