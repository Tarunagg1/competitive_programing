// Pascal Triangle
// EasyAccuracy: 23.68%Submissions: 75K+Points: 2
// GfG Weekly + You = Perfect Sunday Evenings!
// Register for free now

// banner
// Given a positive integer N, return the Nth row of pascal's triangle.
// Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.
// The elements can be large so return it modulo 109 + 7.

// File:PascalTriangleAnimated2.gif

// Example 1:

// Input:
// N = 4
// Output:
// 1 3 3 1
// Explanation:
// 4th row of pascal's triangle is 1 3 3 1.
// Example 2:

// Input:
// N = 5
// Output:
// 1 4 6 4 1
// Explanation:
// 5th row of pascal's triangle is 1 4 6 4 1.
// Your Task:
// Complete the function nthRowOfPascalTriangle() which takes n, as input parameters and returns an array representing the answer. You don't to print answer or take inputs.

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(N2)

// Constraints:
// 1 ≤ N ≤ 103

class Solution
{
public:
    vector<long long> nthRowOfPascalTriangle(int n)
    {
        // code here
        long long MOD = 1000000007;
        vector<long long> ans(n, 1);
        vector<long long> ptemp(n, 1);
        for (int i = 2; i < n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                ans[j] = (ptemp[j] + ptemp[j - 1]) % MOD;
            }
            ptemp = ans;
        }
        return ans;
    }
};
