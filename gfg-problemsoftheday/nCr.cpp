// nCr
// MediumAccuracy: 14.82%Submissions: 229K+Points: 4
// Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.

// Example 1:

// Input: n = 3, r = 2
// Output: 3
// Explaination: 3C2 = 3.
// Example 2:

// Input: n = 2, r = 4
// Output: 0
// Explaination: r is greater than n.
// Your Task:
// You do not need to take input or print anything. Your task is to complete the function nCr() which takes n and r as input parameters and returns nCr modulo 109+7..

// Expected Time Complexity: O(n*r)
// Expected Auxiliary Space: O(r)

// Constraints:
// 1 ≤ n ≤ 1000
// 1 ≤ r ≤ 800

// View Bookmarked Problems

class Solution
{
public:
    const int N = 1e9 + 7;

    int nCr(int n, int r)
    {
        // code here
        if (r > n)
        {
            return 0;
        }
        vector<int> temp;
        temp.push_back(1);
        for (int i = 1; i <= n; i++)
        {
            temp.push_back(1);
            for (int j = i - 1; j > 0; j--)
            {
                temp[j] = (temp[j] + temp[j - 1]) % N;
            }
        }
        return temp[r];
    }
};
