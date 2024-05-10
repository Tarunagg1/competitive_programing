// Combination Sum II
// MediumAccuracy: 49.5%Submissions: 13K+Points: 4
//  Done with winning Geekbits? Now win GfG Bag, GfG T-shirt & much more just by writing your experiences. Start Writing, Start Winning.
// banner
// Given an array of integers arr, the length of the array n, and an integer k, find all the unique combinations in arr where the sum of the combination is equal to k. Each number can only be used once in a combination.

// Example 1:

// Input:
// n = 5, k = 7
// arr[] = { 1, 2, 3, 3, 5 }
// Output:
// { { 1, 3, 3 }, { 2, 5 } }
// Explanation:
// 1 + 3 + 3 = 7
// 2 + 5 = 7
// Example 2:

// Input:
// n = 6, k = 35
// arr[] = { 5, 10, 15, 20, 25, 30 }
// Output:
// { { 5,10, 20 }, { 5, 30 }, { 10, 25 }, { 15, 20 } }
// Explanation:
// 5 + 10 + 20 = 35
// 5 + 30 = 35
// 10 + 25 = 35
// 15 + 20 = 35
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function CombinationSum2() which takes arr[],n, and k as input parameters and returns all the unique combinations.

// Constraints:
// 1 <= n <= 100
// 1 <= arr[i] <= 50
// 1 <= k <= 30

// let p = number of elements, at maximum, can sum up to the given value k.

// Expected Time Complexity: O(2min(n,p))
// Expected Auxiliary Space: O(n)

class Solution
{
public:
    set<vector<int>> ans;
    void solve(int i, int k, vector<int> &arr, vector<int> &temp)
    {
        if (k == 0)
        {
            ans.insert(temp);
            return;
        }
        if (i >= arr.size())
        {
            return;
        }

        // include
        if (k - arr[i] >= 0)
        {
            temp.push_back(arr[i]);
            solve(i + 1, k - arr[i], arr, temp);
            temp.pop_back();
        }

        // exclude
        solve(i + 1, k, arr, temp);
    }
    vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k)
    {
        // code here
        sort(arr.begin(), arr.end());
        vector<int> temp;
        solve(0, k, arr, temp);
        vector<vector<int>> vs(ans.begin(), ans.end());
        return vs;
    }
};
