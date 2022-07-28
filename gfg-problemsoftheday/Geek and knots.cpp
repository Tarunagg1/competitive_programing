// Geek and knots
// MediumAccuracy: 49.99%Submissions: 110Points: 4
// M hooks are present in a straight line on wall A and N hooks are present in a straight line on wall B. Each hook on wall A is connected to each hooks on wall B by ropes. K ropes must be used to make the desired giant knot. How many such knots can Geek make ?
// Note: 2 knots are considered to be the same if they involve the same hooks.

// Example 1:

// Input:
// M = 3, N = 2, K = 2
// Output: 3
// Explaination:
// hooks on Wall A are A1 A2 A3.
// hooks on wall B are B1 B2.

// Joining
//  A1  A2  A3
//  |       |
//  B1      B2

// is same as joining
//  A1  A2  A3
//  |       |
//  B2      B1
// because the two groups involve the same hooks.
// But the groups (A1-B1, A3-B2), (A1-B1, A2-B2),
// (A2-B1, A3-B2) are all different.

// Example 2:

// Input:
// M = 2, N = 2, K = 2
// Output: 1
// Explaination: Any one of (A1-B1, A2-B2)
// and (A1-B2, A2-B1) can be used.

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function knots() which takes M, N and K as input parametes and returns the number of possible knots. Return the answer modulo 109+7.

// Expected Time Complexity: O(max(N2, M2))
// Expected Auxiliary Space: O(max(N2, M2))

// Constraints:
// 1 ≤ N, M, K ≤ 1000
// 1 ≤ K ≤ min(N, M)

class Solution
{
public:
    vector<long long> factorial;
    long long MOD = 1e9 + 7;
    long long power(long long x, long long y)
    {
        long long res = 1;
        x = x % MOD;
        while (y > 0)
        {
            if (y & 1)
                res = (res * x) % MOD;
            y = y >> 1;
            x = (x * x) % MOD;
        }
        return res;
    }
    long long modInverse(long long n)
    {
        return power(n, MOD - 2);
    }
    int knots(int M, int N, int K)
    {
        // code here
        factorial = vector<long long>(max(M, N) + 1, 1);
        for (int i = 1; i <= max(M, N); i++)
            factorial[i] = (factorial[i - 1] * i) % MOD;
        long long revK = modInverse(factorial[K]);
        revK = (revK * revK) % MOD;
        long long res = (factorial[M] * factorial[N]) % MOD;
        res = (res * revK) % MOD;
        res = (res * modInverse(factorial[M - K])) % MOD;
        res = (res * modInverse(factorial[N - K])) % MOD;
        return res;
    }
};
