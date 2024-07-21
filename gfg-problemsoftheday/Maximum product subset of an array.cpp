// Maximum product subset of an array
// Difficulty: MediumAccuracy: 17.21%Submissions: 40K+Points: 4
// Given an array arr. The task is to find and return the maximum product possible with the subset of elements present in the array.

// Note:

// The maximum product can be a single element also.
// Since the product can be large, return it modulo 109 + 7.
// Examples:

// Input: arr[] = [-1, 0, -2, 4, 3]
// Output: 24
// Explanation: Maximum product will be ( -1 * -2 * 4 * 3 ) = 24
// Input: arr[] = [-1, 0]
// Output: 0
// Explanation: Maximum product will be ( -1 * 0) = 0
// Input: arr[] = [5]
// Output: 5
// Explanation: Maximum product will be 5.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= arr.size() <= 2 * 104
// -10 <= arr[i] <= 10

class Solution
{
    const long long MOD = 1e9 + 7;

public:
    long long int findMaxProduct(vector<int> &arr)
    {
        // Write your code here
        long long prod = 1;
        long long maxi = -1e9;

        int cntneg = 0, cntpos = 0;

        for (auto &x : arr)
        {
            if (x != 0)
                prod = ((prod % MOD) * x) % MOD;
            if (x < 0)
            {
                maxi = max(maxi, (long long)x);
                cntneg++;
            }
            if (x > 0)
                cntpos++;
        }

        if (cntneg == 1 and cntpos == 0)
        {
            if (arr.size() == 1)
                return prod;
            if (arr.size() >= 1)
                return 0;
        }

        if (prod < 0)
            prod = prod / maxi;

        return prod;
    }
};
