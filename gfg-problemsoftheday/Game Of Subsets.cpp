// Game Of Subsets
// HardAccuracy: 82.36%Submissions: 2K+Points: 8
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// Elena is the topper of the class. Once her teacher asked her a problem. He gave Elena an array of intergers of length n. He calls a subset of array arr good if its product can be represented as a product of one or more distinct prime numbers. He asked her to find the number of different good subsets in arr modulo 109 + 7.

// As a good friend of Elena help her to solve the problem.

// Example 1:

// Input:
// N: 4
// arr: {1,2,3,4}
// Output: 6
// Explanation:
// The good subsets are:
// - [1,2]: product is 2, which is the product of distinct
// prime 2.
// - [1,2,3]: product is 6, which is the product of
// distinct primes 2 and 3.
// - [1,3]: product is 3, which is the product of distinct
// prime 3.
// - [2]: product is 2, which is the product of distinct
//  prime 2.
// - [2,3]: product is 6, which is the product of distinct
// primes 2 and 3.
// - [3]: product is 3, which is the product of distinct
// prime 3.
// Example 2:

// Input:
// N : 3
// arr : {2, 2, 3}
// Output: 5
// Explanantion:
// The good subsets are : {2}, {2}, {2, 3}, {2, 3}, {3}
// Your Task:
// The task is to complete the function goodSubsets() which takes an integer n and an array arr as the input parameters and should return the number of different good subsets.

// Expected Time Complexity: O(NlogN)
// Expected Space Complexity: O(N)

// Constraints:

// 1 <= N <= 105
// 1< = arr[i] <= 30
// View Bookmarked Problems

class Solution
{
public:
    void precom(vector<int> &v, vector<int> prime)
    {
        for (int i = 2; i <= 30; i++)
        {
            if ((i % 4) && (i % 9) && (i % 25))
            {
                int mask = 0;
                for (int j = 0; j < 10; j++)
                    if (!(i % prime[j]))
                        mask |= (1 << j);
                v[i] = mask;
            }
        }
    }
    int goodSubsets(vector<int> &arr, int n)
    {
        vector<int> v(31, 0);
        vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        precom(v, prime);
        const int mod = 1e9 + 7;
        map<int, int> mp;
        long long ans = 0;
        vector<long long> dp((1 << 10) + 1, 0);
        int onecnt = 0;
        for (auto i : arr)
        {
            if (i == 1)
                onecnt++;
            else
                mp[i]++;
        }
        dp[0] = 1;
        // counting
        for (auto i : mp)
        {
            if (v[i.first])
            {
                for (int j = 0; j < (1 << 10); j++)
                {
                    if ((v[i.first] & j) == 0)
                    {
                        dp[j | v[i.first]] += dp[j] * i.second;
                        dp[j | v[i.first]] %= mod;
                    }
                }
            }
        }
        for (auto i : dp)
            ans += i, ans %= mod;
        ans--;
        if (onecnt)
        {
            while (onecnt--)
            {
                ans *= 2;
                ans %= mod;
            }
        }
        return ans;
    }
};
