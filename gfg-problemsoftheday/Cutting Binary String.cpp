// Cutting Binary String
// MediumAccuracy: 49.71%Submissions: 11K+Points: 4
// Finding a high paying job is easier than today's problem! Attend Job Fair 2023

// Given a string s containing 0's and 1's. You have to return the smallest positive integer C, such that the binary string can be cut into C pieces and each piece should be of the power of 5  with no leading zeros.
// Note: The string s is a binary string. And if no such cuts are possible, then return -1.

// Example 1:

// Input:
// s = "101101101"
// Output:
// 3
// Explanation:
// We can split the given string into
// three 101s, where 101 is the binary
// representation of 5.
// Example 2:

// Input:
// s = "00000"
// Output:
// -1
// Explanation:
// 0 is not a power of 5.
// Your Task:
// Your task is to complete the function cuts() which take a single argument(string s). You need not take any input or print anything. Return an int C if the cut is possible else return -1.

// Expected Time Complexity: O(|s|*|s|*|s|).
// Expected Auxiliary Space: O(|s|).

// Constraints:
// 1<= |s| <=50

// View Bookmarked Problems

class Solution
{
public:
    float power(int x)
    {
        float p = log10(x) / log10(5);
        return x == pow(5, p);
    }

    long long solve(int idx, string &s)
    {
        if (idx < 0)
            return 0;

        if (s[idx] == '0')
            return INT_MAX;

        long long no = 0;
        long long res = INT_MAX;

        for (int i = 0; i <= idx; i++)
        {
            if (s[idx - i] == '1')
            {
                no += pow(2, i);
                bool p = power(no);
                if (p == true)
                {
                    res = min(res, 1 + solve(idx - i - 1, s));
                }
            }
        }
        return res;
    }

    int cuts(string s)
    {
        int n = s.size();

        long long ans = solve(n - 1, s);
        if (ans > 50)
            return -1;
        return ans;
    }
};
