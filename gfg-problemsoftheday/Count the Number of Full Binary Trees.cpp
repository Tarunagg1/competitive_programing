// Count the Number of Full Binary Trees
// MediumAccuracy: 25.21%Submissions: 1962Points: 4
// Given an array arr[] of n integers, where each integer is greater than 1. The task is to find the number of Full binary tree from the given integers, such that each non-leaf node value is the product of its children value.

// Note: Each integer can be used multiple times in a full binary tree. The answer can be large, return  answer modulo 1000000007

// Example 1:
// Input:
// n = 4
// arr[] = {2, 3, 4, 6}
// Output:
// 7
// Explanation:
// There are 7 full binary tree with
// the given product property.
// Four trees with single nodes
// 2  3  4  6
// Three trees with three nodes
//     4
//    / \
//   2   2 ,
//    6
//   / \
//  2   3 ,
//    6
//   / \
//  3   2

// Example 2:
// Input:
// n = 3
// arr[] = {2, 4, 5}
// Output: 4
// Explanation: There are 4 full binary tree
// with the given product property.
// Three trees with single nodes 2 4 5
// One tree with three nodes
//    4
//   / \
//  2  2

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function numoffbt() which takes the array arr[]and its size n as inputs and returns the number of Full binary tree.

// Expected Time Complexity: O(n. Log(n))
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 ≤ n ≤ 105
// 2 ≤ arr[i] ≤ 105

// View Bookmarked Problems

class Solution
{
public:
    long long int numoffbt(long long int arr[], int n)
    {
        // Your code goes here
        const long long int MOD = 1000000007;
        long long int mn = INT_MAX, mx = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            mn = (mn > arr[i]) ? arr[i] : mn;
            mx = (mx < arr[i]) ? arr[i] : mx;
        }

        long long int ans = 0;
        int pd;
        vector<bool> vis(mx + 1, false);
        vector<long long int> sol(mx + 1, 0);
        for (int i = 0; i < n; i++)
        {
            vis[arr[i]] = 1;
            sol[arr[i]] = 1;
        }
        for (int i = mn; i <= mx; i++)
        {
            if (!vis[i])
            {
                continue;
            }
            for (int j = 2; i * j <= mx && j <= i; j++)
            {
                pd = i * j;
                if (!vis[pd])
                {
                    continue;
                }
                sol[pd] = (sol[pd] + (sol[i] * sol[j]) % MOD) % MOD;
                if (i != j)
                {
                    sol[pd] = (sol[pd] + (sol[i] * sol[j]) % MOD) % MOD;
                }
            }
            ans = (ans + sol[i]) % MOD;
        }
        return ans;
    }
};
