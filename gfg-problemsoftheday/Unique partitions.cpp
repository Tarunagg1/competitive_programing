// Unique partitions
// MediumAccuracy: 47.91%Submissions: 2324Points: 4
// Given a positive integer n, generate all possible unique ways to represent n as sum of positive integers.

// Note: The generated output is printed without partitions. Each partition must be in decreasing order. Printing of all the partitions is done in reverse sorted order.

// Example 1:

// Input: n = 3
// Output: 3 2 1 1 1 1
// Explanation: For n = 3,
// {3}, {2, 1} and {1, 1, 1}.

// Example 2:

// Input: n = 4
// Output: 4 3 1 2 2 1 1 1 1
// Explanation: For n = 4,
// {4}, {3, 1}, {2, 2}, {1, 1, 1, 1}.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function UniquePartitions() which takes n as input parameter and returns a list of all possible combinations in lexicographically decreasing order.

// Expected Time Complexity: O(2^n)
// Expected Space Complexity: O(n)

// Constraints:
// 1 <= n <= 25

// View Bookmarked Problems

class Solution
{
public:
    void solve(vector<int> &arr, int n, vector<int> t, set<vector<int>> &st, int sum)
    {

        if (sum == 0)
        {

            sort(t.begin(), t.end(), greater<int>());

            st.insert(t);
        }

        if (n < 0)
        {

            return;
        }

        if (arr[n] <= sum)
        {

            solve(arr, n - 1, t, st, sum);

            t.push_back(arr[n]);

            solve(arr, n, t, st, sum - arr[n]);
        }

        else
        {

            solve(arr, n - 1, t, st, sum);
        }
    }

    vector<vector<int>> UniquePartitions(int n)
    {

        // Code here

        vector<vector<int>> ans;

        set<vector<int>> st;

        vector<int> arr(n, 1);

        for (int i = 1; i < n; i++)
        {

            arr[i] = i + 1;
        }

        vector<int> t;

        int sum = n;

        solve(arr, n - 1, t, st, sum);

        for (auto it = st.rbegin(); it != st.rend(); it++)
        {

            ans.push_back(*it);
        }

        return ans;
    }
};
