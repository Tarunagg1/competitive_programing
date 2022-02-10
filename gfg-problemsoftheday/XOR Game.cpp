// XOR Game
// Medium Accuracy: 53.72% Submissions: 4061 Points: 4
// Given a positive number k, we need to find a minimum value of positive integer n, such that XOR of n and n+1 is equal to k. If no such n exist then print -1.

// Example 1:

// Input: k = 3
// Output: 1
// Explaination: 1 xor 2 = 3.

// Example 2:

// Input: k = 6
// Output: -1
// Explaination: There is no such n, so that,
// n xor n+1 = k.

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function xorCal() which takes k as input parameter and returns the value of n. If there is no such , then it returns -1.

// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ k ≤ 100

class Solution
{
public:
    int xorCal(int k)
    {
        // code here
        if (k == 1)
            return 2;
        int val = (1 << (int)(log2(k + 1)));
        if ((val & (val - 1)) == 0 && val > k)
        {
            return k - val / 2;
        }
        else
        {
            return -1;
        }
    }
};
