// Palindromic Partitioning
// HardAccuracy: 27.82%Submissions: 105K+Points: 8
// Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.

// Example 1:

// Input: str = "ababbbabbababa"
// Output: 3
// Explaination: After 3 partitioning substrings
// are "a", "babbbab", "b", "ababa".
// Example 2:

// Input: str = "aaabba"
// Output: 1
// Explaination: The substrings after 1
// partitioning are "aa" and "abba".

// Your Task:
// You do not need to read input or print anything, Your task is to complete the function palindromicPartition() which takes the string str as the input parameter and returns the minimum number of partitions required.

// Expected Time Complexity: O(n*n) [n is the length of the string str]
// Expected Auxiliary Space: O(n*n)

// Constraints:
// 1 ≤ length of str ≤ 500

class Solution
{
public:
private:
    int dp[500];
    int solve(vector<int> adj[], int n, int i)
    {
        // base case
        if (i >= n)
            return 0;
        // memoization case
        if (dp[i] != -1)
            return dp[i];
        // calling recursion
        int ret = 1e9;
        for (int &j : adj[i])
        {
            ret = min(ret, 1 + solve(adj, n, j + 1));
        }
        return dp[i] = ret;
    }

public:
    int palindromicPartition(string str)
    {
        // first precompute all l to r palindromic combinations
        int n = str.size();
        vector<int> adj[n];
        // odd length
        for (int i = 0; i < n; i++)
        {
            int l = i;
            int r = i;
            while (l >= 0 and r < n and str[l] == str[r])
            {
                adj[l].push_back(r);
                l--;
                r++;
            }
        }
        // even length
        for (int i = 1; i < n; i++)
        {
            int l = i - 1;
            int r = i;
            while (l >= 0 and r < n and str[l] == str[r])
            {
                adj[l].push_back(r);
                l--;
                r++;
            }
        }
        // now, using knapsack dp to calculate minimum partitions
        memset(dp, -1, sizeof(dp));
        return solve(adj, n, 0) - 1;
    }
};
