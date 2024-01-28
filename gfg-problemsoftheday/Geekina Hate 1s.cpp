// Geekina Hate 1s
// HardAccuracy: 66.78%Submissions: 8K+Points: 8
// Got your Geekbits? Now Get 90% Of Your Course Fee Refund!

// banner
// It is a universal fact that Geekina hates 1s however it is also known that Geekina loves the integers having atmost k 1s (set-bits) in their binary representation.

// Geekina demanded nth such non-negative number from Geek, and being a good friend of Geek, now it's your responsibility to tell him that number.

// Note: The test cases are generated such that the answer always exists and will fit in the 64-bit data type.

// Example 1:

// Input:
// n = 5
// k = 1
// Output:
// 8
// Explanation:
// Following numbers are loved by Geekina -
// 0 = (0)2
// 1 = (1)2
// 2 = (10)2
// 4 = (100)2
// 8 = (1000)2
// Example 2:

// Input:
// n = 6
// k = 2
// Output:
// 5
// Explanation:
// Following numbers are loved by Geekina -
// 0 = (0)2
// 1 = (1)2
// 2 = (10)2
// 3 = (11)2
// 4 = (100)2
// 5 = (101)2
// Your Task:
// This is a function problem. The input is already taken care of by the driver code. You only need to complete the function findNthNumer() that takes n and k as input parameters. Return the nth number having at most k set-bits.

// Expected Time Complexity: O(k*log(n) + constant)
// Expected Auxiliary Space: O(k*log(n) + constant)

// Constraints:
// 1 <= n <= 109
// 1 <= k <= 63

// Topic Tags
// If

class Solution
{
public:
    vector<vector<vector<long long>>> dp;

    long long findNthNumber(int n, int k)
    {
        // code here
        long long low = 0, high = 1e18;
        dp = vector<vector<vector<long long>>>(2, vector<vector<long long>>(65, vector<long long>(65, -1)));
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long count = find(mid, k);
            if (count >= n)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
