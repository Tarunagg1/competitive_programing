// Largest prime factor
// MediumAccuracy: 27.25%Submissions: 54K+Points: 4
// Given a number N, the task is to find the largest prime factor of that number.
//  Example 1:

// Input:
// N = 5
// Output:
// 5
// Explanation:
// 5 has 1 prime factor i.e 5 only.
// Example 2:

// Input:
// N = 24
// Output:
// 3
// Explanation:
// 24 has 2 prime factors 2 and 3 in which 3 is greater.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function largestPrimeFactor() which takes an integer N as input parameters and returns an integer, largest prime factor of N.

// Expected Time Complexity: O(sqrt(N))
// Expected Space Complexity: O(1)

// Constraints:
// 2 <= N <= 109

class Solution
{
public:
    long long int largestPrimeFactor(int N)
    {
        // code here
        int s = sqrt(N);
        long long maxi = INT_MIN;

        // making the number odd
        //  i.e to remove all the factos of 2
        while (N % 2 == 0)
        {
            maxi = max(maxi, (long long)2);
            N /= 2;
        }

        // traversing through odd numbers
        for (int i = 3; i <= s; i += 2)
        {

            // removing all the factors of i
            while (N % i == 0)
            {
                maxi = max((long long)i, maxi);
                N /= i;
            }
        }

        // if n is itself a prime number than we update the ans
        if (N > 2)
            maxi = max(maxi, (long long)N);

        return maxi;
    }
};
