// Special Digits
// HardAccuracy: 54.38%Submissions: 3K+Points: 8
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// You are given 5 integers - N,A,B,C,D.
// Let us say all the integers of length N, having only A or B in their decimal representation are good integers. Also, among all the good integers, all those integers whose sum of digits contains only C and D are best integers.
// Find the number of best integers of length N. Since the number of best integers can be huge, print it modulo 109+7.

// Example 1:

// Input:
// N = 2, A = 1, B = 2, C = 3, D = 5
// Output:
// 2
// Explanation:
// The following are good integers:-
// { 12 , 22 , 11 , 21 }
// And the following are best integers:-
// { 12, 21 } because sum of digits of 11,22
// are 2 and 4, they are not equal to C or D.
// Example 2:

// Input:
// N = 1, A = 1, B = 1, C = 2, D = 3
// Output:
// 0
// Explanation:
// The following are good integers: - { 1 }
// Since sum of digits is 1 which is not equal to
// C or D, therefore, answer is 0.
// Your Task:
// The task is to complete the function solve() which takes five integers N,A,B,C and D as input parameters and returns the number of best integers modulo 109+7.

// Expected Time Complexity: O(NlogN)
// Expected Space Complexity: O(N)

// Constraints:
// 1 ≤ A, B, C, D ≤ 9
// 1 ≤ N ≤ 105

// View Bookmarked Problems

#define mod 1000000007
class Solution
{
public:
    bool check(int n, int c, int d)
    {
        while (n)
        {
            int r = n % 10;
            n /= 10;
            if (r != c && r != d)
                return false;
        }
        return true;
    }
    long long binpower(long long a, long long n)
    {
        long long res = 1;
        while (n)
        {
            if (n % 2)
                res = (res * a) % mod;
            a = (a * a) % mod;
            n /= 2;
        }
        return res;
    }

public:
    int bestNumbers(int N, int A, int B, int C, int D)
    {
        // code here
        long long res = 0;
        long long fact[N + 1];
        fact[0] = 1;
        for (int i = 1; i <= N; i++)
            fact[i] = (fact[i - 1] * 1LL * i) % mod;
        for (int i = 0; i <= N; i++)
        {
            int cnta = i, cntb = N - i;
            if (check(cnta * A + cntb * B, C, D))
            {
                res += (fact[N] * binpower((fact[i] * fact[N - i]) % mod, mod - 2)) % mod;
                res %= mod;
            }
        }
        return res;
    }
};
