// Composite and Prime
// MediumAccuracy: 37.65%Submissions: 530Points: 4
// Given two integers L and R find the difference of number of composites and primes between the range L and R (both inclusive).

// Example 1:

// Input: L = 4, R = 6
// Output: 1
// Explanation: Composite no. are 4 and 6.
// And prime is 5.

// Example 2:

// Input: L = 4, R = 4
// Output: 1
// Explanation: There is no prime no. in [L,R]

// Your Task:
// You don't need to read or print anything. Your task is to complete the function Count() which takes L and R as input parameter and returns difference between no. of composites and primes between [L,R].

// Expected Time Complexity: O(nlog(n)) where n = R - L + 1
// Expected Space Complexity: O(n)

// Constraints:
// 1 <= L <= R <= 105

class Solution
{
public:
    int isprime(int n)
    {

        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    int Count(int L, int R)
    {
        // Code here
        int cnt_com = 0;
        int cnt_prime = 0;

        for (int i = L; i <= R; i++)
        {
            if (i == 1)
            {
                continue;
            }
            if (isprime(i) == true)
            {
                cnt_prime++;
            }
            else
            {
                cnt_com++;
            }
        }

        return cnt_com - cnt_prime;
    }
};
