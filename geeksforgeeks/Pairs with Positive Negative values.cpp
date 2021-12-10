// Pairs with Positive Negative values
// Easy Accuracy: 31.89% Submissions: 1366 Points: 2
// Given an array of distinct integers, print all the pairs having positive value and negative value of a number that exists in the array.

// NOTE: If there is no such pair in the array , return empty array.

// Example 1:

// Input:
// n = 6
// a[] = {1, -3, 2, 3, 6, -1}
// Output:
// -1 1 -3 3

// Example 2:

// Input:
// n = 8
// a[] = {4, 8, 9, -4, 1, -1, -8, -9}
// Output:
// -1 1 -4 4 -8 8 -9 9

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function PosNegPair() which takes the array a[] and its size n as inputs and returns all the required pairs in the increasing order of their absolute numbers.

// Expected Time Complexity: O(nLog(n))
// Expected Auxiliary Space: O(n)

// Constraints:
// 1<=n<=105
// -105<=a[i]<=105

class Solution
{
public:
    vector<int> PosNegPair(int a[], int n)
    {
        vector<int> v, ans;
        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
            {
                v.push_back(a[i]);
            }
            else
            {
                mp[a[i]]++;
            }
        }

        sort(v.begin(), v.end());

        for (int i = (int)v.size(); i >= 0; i--)
        {
            int data = abs(v[i]);
            if (mp[data] > 0)
            {
                ans.push_back(v[i]);
                ans.push_back(data);
                mp[data] -= 1;
            }
        }
        return ans;
    }
};