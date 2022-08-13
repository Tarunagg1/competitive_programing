// Max length chain
// MediumAccuracy: 43.55%Submissions: 86584Points: 4
// You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. You have to find the longest chain which can be formed from the given set of pairs.

// Example 1:

// Input:
// N = 5
// P[] = {5  24 , 39 60 , 15 28 , 27 40 , 50 90}
// Output: 3
// Explanation: The given pairs are { {5, 24}, {39, 60},
// {15, 28}, {27, 40}, {50, 90} },the longest chain that
// can be formed is of length 3, and the chain is
// {{5, 24}, {27, 40}, {50, 90}}

// Example 2:

// Input:
// N = 2
// P[] = {5 10 , 1 11}
// Output: 1
// Explanation:The max length chain possible is only of
// length one.

// Your Task:
// You don't need to read input or print anything. Your task is to Complete the function maxChainLen() which takes a structure p[] denoting the pairs and n as the number of pairs and returns the length of the longest chain formed.

// Expected Time Complexity: O(Nlog(N))
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<=N<=105

class Solution
{
public:
    /*You are required to complete this method*/

    int solve(vector<pair<int, int>> store, int curr, int prev, int n)
    {

        if (curr >= n)
        {
            return 0;
        }

        int include = 0;
        if (prev == -1 || (store[prev].second < store[curr].first))
        {
            include = 1 + solve(store, curr + 1, curr, n);
        }
        int exclude = solve(store, curr + 1, prev, n);
        return max(include, exclude);
    }

    // Memoization
    int solveDP(vector<pair<int, int>> store, int curr, int prev, int n, vector<vector<int>> &dp)
    {

        if (curr >= n)
        {
            return 0;
        }

        if (dp[curr][prev + 1] != -1)
        {
            return dp[curr][prev + 1];
        }
        int include = 0;
        if (prev == -1 || (store[prev].second < store[curr].first))
        {
            include = 1 + solveDP(store, curr + 1, curr, n, dp);
        }
        int exclude = solveDP(store, curr + 1, prev, n, dp);

        return dp[curr][prev + 1] = max(include, exclude);
    }

    int maxChainLen(struct val p[], int n)
    {
        // Your code here

        vector<pair<int, int>> store;
        for (int i = 0; i < n; i++)
        {
            int o = p[i].first;
            int s = p[i].second;
            store.push_back({o, s});
        }
        int siz = store.size();
        sort(store.begin(), store.end());
        vector<vector<int>> dp(siz + 1, vector<int>(siz + 1, -1));
        return solveDP(store, 0, -1, siz, dp);
    }
}
