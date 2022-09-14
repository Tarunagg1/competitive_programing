// Power Of 2 and Subsequences
// MediumAccuracy: 59.92%Submissions: 1406Points: 4
// Given is an array A[] of size N. Return the number of non-empty subsequences such that the product of all numbers in the subsequence is Power of 2. Since the answer may be too large, return it modulo 109 + 7.

// Example 1:

// Input:
// N = 3
// A[] = {1, 6, 2}
// Output:
// 3
// Explanation:
// The subsequence that
// can be chosen is {1},
// {2} and {1,2}.
// Example 2:

// Input:
// N = 3
// A[] = {3, 5, 7}
// Output:
// 0
// Explanation:
// No subsequences exist.
// Your Task:

// You don't need to read input or print anything. Your task is to complete the function numberOfSubsequences() which takes an integer N and an array A and returns the number of subsequences that exist. As this number can be very large return the result under modulo 109+7.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 105
// 1 <= A[i] <= 109

class Solution
{
public:
    long long mod = 1e9 + 7;
    long long numberOfSubsequences(int N, long long A[])
    {

        long long cnt = 0;

        for (int i = 0; i < N; i++)
        {
            if ((A[i] & A[i] - 1) == 0)
                cnt++;
        }

        long long res = 1;

        while (cnt--)
        {
            res = (res * 2) % mod;
        }

        return res - 1;
    }
};
