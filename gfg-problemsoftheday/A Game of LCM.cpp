// A Game of LCM
// MediumAccuracy: 29.21%Submissions: 723+Points: 4
// Given an integer N. Find maximum LCM (Least Common Multiple) that can be obtained from four numbers less than or equal to N.
// Note: Duplicate numbers can be used.

// Example 1:

// Input:
// N = 4
// Output: 12
// Explanation:
// The four numbers can be [4,4,3,2] or
// [4,4,4,3], etc. It can be shown that 12 is
// the maximum LCM of four numbers that can
// be obtained from numbers less than or equal
// to 4.
// Example 2:

// Input:
// N = 5
// Output: 60
// Explanation:
// The four numbers can be [5,5,4,3] or
// [5,4,3,2], etc. 60 is the maximum that can
// be obtained.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maxGcd() which takes N as the input parameter and returns the maximum LCM that can be obtained from four numbers less than or equal to N.

// Expected Time Complexity: O( Log2(max(N)) )
// Expected Auxillary Space: O(1)

// Constraints:
// 2 ≤ N ≤ 104

// View Bookmarked Problems

class Solution
{
public:
    long long maxGcd(int N)
    {
        // code here
        long long int ans = N * (N - 1);
        int c = 0;
        for (long long int i = N - 2; i > 2 && c < 2; i--)
        {
            if (__gcd(ans, i) == 1)
            {
                ans *= i;
                c++;
            }
        }
        return ans;
    }
};
