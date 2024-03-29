// Complement
// MediumAccuracy: 27.67%Submissions: 5K+Points: 4
// You are given a binary string str. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and complement the characters between L and R i.e strL, strL+1, …, strR. By complement, we mean change character 0 to 1 and vice-versa.

// You task is to perform ATMOST one operation such that in final string number of 1s is maximised. If there is no need to completement, i.e., string contains all 1s, return -1. Else, return the two values denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

// Example 1:

// Input:
// N = 3
// str = "111"
// Output: -1
// Explanation: As all characters are '1',
// so don't need to complement any.
// Example 2:

// Input:
// N = 2
// str = "01"
// Output: 1 1
// Explanation: After complementing [1, 1]
// the string becomes "11".
// Your Task:
// You don't need to read input or print anything. Complete the function findRange() which takes the string str and the size of the string, n, as input parameters and returns an array of length 2 or 1 representing the answer. You don't to print answer or take inputs.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 105
// Str is a binary string i.e. contains only '0' and '1'.

// View Bookmarked Problems

class Solution
{
public:
    vector<int> findRange(string str, int n)
    {
        int c0 = 0;
        for (int i = 0; i < n; ++i)
        {
            if (str[i] == '0')
            {
                ++c0;
            }
        }
        if (c0 == 0)
        {
            vector<int> A;
            A.push_back(-1);
            return A;
        }
        int maxi = 0;
        int l = 0;
        int r = 0;
        int ml, mr;
        vector<int> s;
        for (int i = 0; i < n; ++i)
        {
            if (str[i] == '0')
            {
                s.push_back(1);
            }
            else
            {
                s.push_back(-1);
            }
        }
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] + sum >= s[i])
            {
                sum = sum + s[i];
            }
            else
            {
                sum = s[i];
                l = i;
            }
            if (sum > maxi)
            {
                maxi = sum;
                ml = l;
                mr = i;
            }
        }
        vector<int> ans;
        ans.push_back(ml + 1);
        ans.push_back(mr + 1);
        return ans;
    }
};
