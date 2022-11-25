// Shreyansh and his bits
// MediumAccuracy: 21.11%Submissions: 1709Points: 4
// Shreyansh has an integer N. He is really curious about the binary representation of integers. He sees that any given integer has a number of set bits. Now he wants to find out that how many positive integers, strictly less than N, have the same number of set bits as N.
// He is a little weak in maths. Help him find the number of integers.
// Note : Since N takes large values, brute force won't work.

// Example 1:

// Input:
// N = 8
// Output: 3
// Explanation:
// Binary representation of 8 : 1000
// So the integers less than 8 with
// same number of set bits are : 4, 2, 1
// Hence, the result is 3.

// Example 2:

// Input:
// N = 4
// Output: 2
// Explanation:
// Binary representation of 4 : 100
// So the integers less than 4 with
// same number of set bits are : 2, 1
// So, The result is 2.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function count() which takes the integer N as input parameters and returns the required answer.

// Expected Time Complexity: O(log(n))
// Expected Auxiliary Space: O(log(n)*log(n))

// Constraints :
// 1 <= N <= 10^12

// View Bookmarked Problems

const int kN = 40;
long long cache[kN][kN];

class Solution
{
public:
    long long ncr(int n, int r)
    {

        if (r > n)
        {

            return 0;
        }

        if (r == 0 || r == n)
        {

            return 1;
        }

        if (cache[n][r] != -1)
        {

            return cache[n][r];
        }

        auto res = ncr(n - 1, r - 1) + ncr(n - 1, r);

        return (cache[n][r] = res);
    }

    long long count(long long x)
    {

        for (int i = 0; i < kN; i++)
        {

            for (int j = 0; j < kN; j++)
            {

                cache[i][j] = -1;
            }
        }

        long long res = 0;

        int ones = 0;

        int bits = 0;

        while (x != 0)
        {

            if (x & 1)
            {

                res += ncr(bits, ++ones);
            }

            bits++;

            x >>= 1;
        }

        return res;
    }
};
