// Trail of ones
// EasyAccuracy: 49.81%Submissions: 8K+Points: 2
// In need of more Geekbits? Win from a pool of 3500+ Geekbits via DSA-based Coding Contest every sunday!

// banner
// Given a number n, find the number of binary strings of length n that contain consecutive 1's in them. Since the number can be very large, return the answer after modulo with 1e9+7.

// Example 1:

// Input:
// n = 2
// Output:
// 1
// Explanation:
// There are 4 strings of
// length 2, the strings
// are 00, 01, 10, and
// 11. Only the string 11
// has consecutive 1's.
// Example 2:

// Input:
// n = 5
// Output:
// 19
// Explanation:
// There are 19 strings
// having consecutive 1's.
// Your Task:

// You don't need to read input or print anything. Your task is to complete the function numberOfConsecutiveOnes() which takes an integer n and returns the number of binary strings that contain consecutive 1's in them.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints
// 2 <= n <= 105

class Solution
{
public:
    int numberOfConsecutiveOnes(int n)
    {
        // code here
        long long a = 1, b = 1;
        long long mod = 1e9 + 7;
        for (int i = 1; i < n; i++)
        {
            long long c = a;
            a = (a + b) % mod;
            b = c;
        }
        long long total = 1;
        long long p = 2;
        while (n)
        {
            if (n & 1)
                total = (total * p) % mod;
            p = (p * p) % mod;
            n >>= 1;
        }
        return (total - (a + b) % mod + mod) % mod;
    }
};
