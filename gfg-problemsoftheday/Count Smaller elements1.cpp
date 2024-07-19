// Count Smaller elements
// Difficulty: HardAccuracy: 38.16%Submissions: 53K+Points: 8
// Given an array arr containing non-negative integers. Count and return an array ans where ans[i] denotes the number of smaller elements on right side of arr[i].

// Examples:

// Input: arr[] = [12, 1, 2, 3, 0, 11, 4]
// Output: [6, 1, 1, 1, 0, 1, 0]
// Explanation: There are 6 smaller elements right after 12. There is 1 smaller element right after 1. And so on.
// Input: arr[] = [1, 2, 3, 4, 5]
// Output: [0, 0, 0, 0, 0]
// Explanation: There are 0 smaller elements right after 1. There are 0 smaller elements right after 2. And so on.
// Expected Time Complexity: O(n*logn)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 ≤ arr.size() ≤ 106
// 0 ≤ arr[i]  ≤ 108

class Solution
{
public:
    int binarySearch(vector<int> &a, int key, int l, int h)
    {
        if (l <= h)
        {
            int mid = (l + h) / 2;
            if (a[mid] >= key)
            {
                return binarySearch(a, key, l, mid - 1);
            }
            return binarySearch(a, key, mid + 1, h);
        }
        return l;
    }
    vector<int> constructLowerArray(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        int k = n - 2;
        vector<int> a;
        a.push_back(arr[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            int ind = binarySearch(a, arr[i], 0, a.size() - 1);
            ans[k--] = ind;
            a.insert(a.begin() + ind, arr[i]);
        }
        return ans;
    }
};
