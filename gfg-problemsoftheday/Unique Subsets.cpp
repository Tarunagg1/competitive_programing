// Unique Subsets
// Medium Accuracy: 50.0% Submissions: 13186 Points: 4
// Given an array arr[] of integers of size N that might contain duplicates, the task is to find all possible unique subsets.

// Note: Each subset should be sorted.

// Example 1:

// Input: N = 3, arr[] = {2,1,2}
// Output:(),(1),(1 2),(1 2 2),(2),(2 2)
// Explanation:
// All possible subsets = (),(2),(1),(1,2),(2),(2,2),(2,1),(2,1,2)
// After Sorting each subset = (),(2),(1),(1,2),(2),(2,2),(1,2),(1,2,2)
// Unique Susbsets in Lexicographical order = (),(1),(1,2),(1,2,2),(2),(2,2)
// Example 2:

// Input: N = 4, arr[] = {1,2,3,3}
// Output: (),(1),(1 2),(1 2 3)
// (1 2 3 3),(1 3),(1 3 3),(2),(2 3)
// (2 3 3),(3),(3 3)
// Your Task:
// Your task is to complete the function AllSubsets() which takes the array arr[] and N as input parameters and returns list of all possible unique subsets in lexicographical order.

// Expected Time Complexity: O(2N).
// Expected Auxiliary Space: O(2N * X), X = Length of each subset.

// Constraints:
// 1 ≤ N ≤ 12
// 1 ≤ arr[i] ≤ 9

// View Bookmarked Problems

class Solution
{
public:
    void func(vector<int> &arr, set<vector<int>> &sol, vector<int> &dp, int n, int ind)
    {
        if (ind == n)
        {
            vector<int> lol = dp;
            sort(lol.begin(), lol.end());
            sol.insert(lol);
            return;
        }
        func(arr, sol, dp, n, ind + 1);
        dp.push_back(arr[ind]);
        func(arr, sol, dp, n, ind + 1);
        dp.pop_back();
    }

    // Function to find all possible unique subsets.
    vector<vector<int>> AllSubsets(vector<int> arr, int n)
    {
        // code here
        set<vector<int>> sol;
        vector<vector<int>> ans;
        vector<int> dp;
        func(arr, sol, dp, n, 0);
        for (auto it : sol)
        {
            ans.push_back(it);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
