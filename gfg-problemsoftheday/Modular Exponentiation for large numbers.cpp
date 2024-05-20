// Modular Exponentiation for large numbers
// MediumAccuracy: 52.56%Submissions: 36K+Points: 4
// In need of more Geekbits? Win from a pool of 3500+ Geekbits via DSA-based Coding Contest every sunday!

// banner
// Implement pow(x, n) % M.
// In other words, for a given value of x, n, and M, find  (xn) % M.

// Example 1:

// Input:
// x = 3, n = 2, m = 4
// Output:
// 1
// Explanation:
// 32 = 9. 9 % 4 = 1.
// Example 2:

// Input:
// x = 2, n = 6, m = 10
// Output:
// 4
// Explanation:
// 26 = 64. 64 % 10 = 4.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function PowMod() which takes integers x, n, and M as input parameters and returns xn % M.

// Expected Time Complexity: O(log(n))
// Expected Space Complexity: O(1)

// Constraints:
// 1 ≤ x, n, M ≤ 109

// Seen this question in a real interview before ?
// 1/4
// Yes
// No

using ll = long long;
class Solution
{
public:
    long long myPow(ll x, ll n, ll mod)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            return 1 / myPow(x, -n, mod);
        if (n % 2 == 1)
            return (x * myPow(x, n - 1, mod)) % mod;
        ll temp = myPow(x * x % mod, n / 2, mod) % mod;
        return (temp + mod) % mod;
    }
    long long int PowMod(long long int x, long long int n, long long int M)
    {
        // Code here
        return myPow(x, n, M);
    }
};
