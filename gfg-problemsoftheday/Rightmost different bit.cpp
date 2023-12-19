// Rightmost different bit
// EasyAccuracy: 61.61%Submissions: 82K+Points: 2
// Fast-Track your resumes to top tech companies and get the job you deserve! Register for hiring challenge exclusively for Freshers

// banner
// Given two numbers M and N. The task is to find the position of the rightmost different bit in the binary representation of numbers. If both M and N are the same then return -1 in this case.

// Example 1:

// Input:
// M = 11, N = 9
// Output:
// 2
// Explanation:
// Binary representation of the given numbers are: 1011 and 1001, 2nd bit from right is different.
// Example 2:

// Input:
// M = 52, N = 4
// Output:
// 5
// Explanation:
// Binary representation of the given numbers are: 110100 and 0100, 5th-bit from right is different.
// User Task:
// The task is to complete the function posOfRightMostDiffBit() which takes two arguments M and N and returns the position of first different bits in M and N from right. If both m and n are the same then return -1 in this case.

// Expected Time Complexity: O(max(log M, log N)).
// Expected Auxiliary Space: O(1).

// Constraints:
// 0 <= M, N <= 109

// Topic Tags

class Solution
{
public:
    // Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        int count = 0;

        if (m == 0 && n == 0)
            return -1;

        while (max(m, n) != 0)
        {
            if (m == n)
                return -1;
            count++;

            if ((m & 1) != (n & 1))
                return count;
            m = m / 2;
            n = n / 2;
        }
    }
};
