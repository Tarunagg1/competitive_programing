// Number of 1 Bits
// EasyAccuracy: 76.5%Submissions: 101K+Points: 2
// Sharpen up your programming skills, participate in coding contests & explore high-paying jobs

// Given a positive integer N, print count of set bits in it.

// Example 1:

// Input:
// N = 6
// Output:
// 2
// Explanation:
// Binary representation is '110'
// So the count of the set bit is 2.
// Example 2:

// Input:
// 8
// Output:
// 1
// Explanation:
// Binary representation is '1000'
// So the count of the set bit is 1.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function setBits() which takes an Integer N and returns the count of number of set bits.

// Expected Time Complexity: O(LogN)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 109

// View Bookmarked Problems
// Company Tags

class Solution
{
public:
    int setBits(int N)
    {
        // Write Your Code here
        int count = 0;

        // Iterate until N becomes zero
        while (N != 0)
        {
            // Check if the least significant bit is set (i.e., equals 1)
            if ((N & 1) == 1)
            {
                // If the bit is set, increment the count
                count++;
            }

            // Right shift N by 1 to discard the least significant bit
            N = N >> 1;
        }

        // Return the count of set bits
        return count;
    }
};
