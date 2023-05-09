// Count Binary Strings With No Consecutive 1s
// HardAccuracy: 73.76%Submissions: 4K+Points: 8
// Finding a high paying job is easier than today's problem! Attend Job Fair 2023

// Given an integer N. Your task is to find the number of binary strings of length N having no consecutive 1s.
// As the number can be large, return the answer modulo 10^9+7.

// Example 1:

// Input:
// N = 3
// Output:
// 5
// Explanation:
// All the binary strings of length 3 having
// no consecutive 1s are "000", "001", "101",
// "100" and "010".
// Example 2:

// Input:
// N = 2
// Output:
// 3
// Explanation:
// All the binary strings of length 2 having no
// consecutive 1s are "10", "00" and "01".
// Your Task:
// You dont need to read input or print anything. Complete the function countStrings() which takes the integer N as the input parameter, and returns the number of binary strings of length N with no consecutive 1s.

// Expected Time Complexity: O(log(N))
// Expected Auxiliary Space: O(Height of the recursive call stack)

// Constraints:
// 1 ≤ N ≤ 1018

// View Bookmarked Problems

class Solution
{
public:
    long long MOD = 1000000007;

    vector<vector<long long>> power(vector<vector<long long>> a, long long N)
    {
        if (N == 1)
        {
            return a;
        }
        vector<vector<long long>> b = power(a, N / 2);
        vector<vector<long long>> c(2, vector<long long>(2, 0));
        c[0][0] = (b[0][0] * b[0][0] + b[0][1] * b[1][0]) % MOD;
        c[0][1] = (b[0][0] * b[0][1] + b[0][1] * b[1][1]) % MOD;
        c[1][0] = (b[1][0] * b[0][0] + b[1][1] * b[1][0]) % MOD;
        c[1][1] = (b[1][0] * b[0][1] + b[1][1] * b[1][1]) % MOD;
        if (N % 2 == 0)
        {
            return c;
        }
        b[0][0] = (a[0][0] * c[0][0] + a[0][1] * c[1][0]) % MOD;
        b[0][1] = (a[0][0] * c[0][1] + a[0][1] * c[1][1]) % MOD;
        b[1][0] = (a[1][0] * c[0][0] + a[1][1] * c[1][0]) % MOD;
        b[1][1] = (a[1][0] * c[0][1] + a[1][1] * c[1][1]) % MOD;
        return b;
    }
    int countStrings(long long int N)
    {
        // Code here
        long long x = 1, y = 1;
        vector<vector<long long>> a = {{1, 1}, {1, 0}};
        a = power(a, N + 1);
        return a[0][0];
    }
};
