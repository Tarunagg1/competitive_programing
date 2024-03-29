// Find first set bit
// EasyAccuracy: 46.89%Submissions: 120K+Points: 2
// Learn Google Cloud with Curated Lab Assignments. Register, Earn Rewards, Get noticed by experts at Google & Land your Dream Job!
// Given an integer N. The task is to return the position of first set bit found from the right side in the binary representation of the number.
// Note: If there is no set bit in the integer N, then return 0 from the function.

// Example 1:

// Input:
// N = 18
// Output:
// 2
// Explanation:
// Binary representation of 18 is 010010,the first set bit from the right side is at position 2.
// Example 2:

// Input:
// N = 12
// Output:
// 3
// Explanation:
// Binary representation of  12 is 1100, the first set bit from the right side is at position 3.
// Your Task:
// The task is to complete the function getFirstSetBit() that takes an integer n as a parameter and returns the position of first set bit.

// Expected Time Complexity: O(log N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 0 <= N <= 108

class Solution
{
public:
    // Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        int i = 1;
        while (n > 0)
        {
            int bit = n % 2;
            if (bit == 1)
                return i;
            n /= 2;
            i++;
        }
        return 0;
    }
};
