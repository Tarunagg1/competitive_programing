// Swap two nibbles in a byte
// EasyAccuracy: 66.11%Submissions: 27K+Points: 2
// Skill-Up Summer Sale! Get 30% Off on all GfG Courses.
// Get Certified this Summer!

// banner
// Given a number n, Your task is to swap the two nibbles and find the resulting number.

// A nibble is a four-bit aggregation, or half an octet. There are two nibbles in a byte. For example, the decimal number 150 is represented as 10010110 in an 8-bit byte. This byte can be divided into two nibbles: 1001 and 0110.

// Example 1:

// Input: n = 100
// Output: 70
// Explanation: 100 in binary is 01100100, two nibbles are (0110) and (0100). If we swap the two nibbles, we get 01000110 which is 70 in decimal.
// Example 2:

// Input: n = 129
// Output: 24
// Explanation: 129 in binary is 10000001, two nibbles are (1000) and (0001). If we swap the two nibbles, we get 00011000 which is 24 in decimal.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function swapNibbles() which takes an integer n as input parameter and returns an integer after swapping nibbles in the binary representation of n.

// Expected Time Complexity: O(1)
// Expected Space Complexity: O(1)

// Constraints:
// 0 ≤ n ≤ 255

class Solution
{
public:
    int swapNibbles(int n)
    {
        // code here
        int ans = 0;
        int x = 1;
        int multi1 = 16;
        int multi2 = 1;
        for (int i = 0; i < 8; i++)
        {
            if (i < 4)
            {
                int a = (n & (x << i)) != 0 ? 1 : 0;
                ans += (multi1 * a);
                multi1 = multi1 * 2;
            }
            else
            {

                int b = (n & (x << i)) != 0 ? 1 : 0;
                ans += (multi2 * b);

                multi2 = multi2 * 2;
            }
        }
        return ans;
    }
};
