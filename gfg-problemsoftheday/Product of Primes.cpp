// Product of Primes
// Medium Accuracy: 55.97% Submissions: 7403 Points: 4
// Given two numbers L and R (inclusive) find the product of primes within this range. Print the product modulo 109+7. If there are no primes in that range you must print 1.

// Example 1:

// Input: L = 1, R = 10
// Output: 210
// Explaination: The prime numbers are
// 2, 3, 5 and 7.
// Example 2:

// Input: L = 1, R = 20
// Output: 9699690
// Explaination: The primes are 2, 3,
// 5, 7, 11, 13, 17 and 19.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function primeProduct() which takes L and R and returns the product of the primes within the range. If there are no primes in that range then return 1.

// Expected Time Complexity: O((R-L)*(logR))
// Expected Auxiliary Space: O(sqrt(R))

// Constraints:
// 1 ≤ L ≤ R ≤ 109
// 0 ≤ L - R ≤ 106

// View Bookmarked Problems

class Solution
{
public:
    bool isPrime(long long n)
    {
        if (n == 1 || n == 0)
        {
            return false;
        }
        if (n == 2 || n == 3)
        {
            return true;
        }
        if (n % 2 == 0)
        {
            return false;
        }

        for (long long i = 3; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    long long primeProduct(long long L, long long R)
    {
        long long prod = 1;
        long long mod = 1e9 + 7;
        for (long long i = L; i <= R; i++)
        {
            if (isPrime(i))
            {
                prod *= i;
                prod = prod % mod;
            }
        }
        return prod;
    }
};
