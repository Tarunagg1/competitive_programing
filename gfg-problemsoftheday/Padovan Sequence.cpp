// Padovan Sequence
// EasyAccuracy: 34.96%Submissions: 24K+Points: 2
// Solve today's problem-> Be the comment of the day-> Win a GfG T-Shirt!
// Daily rewards up for grabs!

// banner
// Given a number n, find the nth number in the Padovan Sequence.

// A Padovan Sequence is a sequence which is represented by the following recurrence relation
// P(n) = P(n-2) + P(n-3)
// P(0) = P(1) = P(2) = 1

// Note: Since the output may be too large, compute the answer modulo 10^9+7.

// Examples :

// Input: n = 3
// Output: 2
// Explanation: We already know, P1 + P0 = P3 and P1 = 1 and P0 = 1
// Input: n = 4
// Output: 2
// Explanation: We already know, P4  = P2 + P1 and P2 = 1 and P1 = 1
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= n <= 106

class Solution
{
public:
    int padovanSequence(int n)
    {
        // code here
        int mod = (int)1e9 + 7;
        if (n < 3)
        {
            return 1;
        }
        int prev1 = 1;
        int prev2 = 1;
        int prev3 = 1;
        for (int i = 3; i <= n; i++)
        {
            int temp = prev1;
            prev1 = (prev2 + prev3) % mod;
            prev3 = prev2;
            prev2 = temp;
        }
        return prev1;
    }
};
