// Given a number X and two positions (from right side) in binary representation of x, write a program that swaps N bits at given two positions and returns the result.

// Example 1:

// Input:
// X = 47
// P1 = 1
// P2 = 5
// N = 3
// Output: 227
// Explanation:
// The 3 bits starting from the second bit
// (from the right side) are swapped with 3 bits
// starting from 6th position (from the right side)
// X = 47 (00101111)
// [001]0[111]1
// ANS = [111]0[001]1
// ANS = 227 (11100011)
// Hence, the result is 227.

// Example 2:

// Input:
// X = 28
// P1 = 0
// P2 = 3
// N = 2
// Output: 7

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function swapBits() which takes the integer X, integer P1, integer P2, and integer N as input parameters and returns the new integer after swapping.

// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

class Solution
{
public:
    int swapBits(int x, int p1, int p2, int n)
    {
        // Code Here
        unsigned int a = (x >> p1) & ((1U << n) - 1);
        unsigned int b = (x > p2) & ((1U << n) - 1);
        unsigned int c = (a ^ b);
        c = (c << p1) | (c << p2);
        unsigned ans = x ^ c;
        return ans;
    }
};

