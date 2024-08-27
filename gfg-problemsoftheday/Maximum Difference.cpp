// Maximum Difference
// Difficulty: MediumAccuracy: 33.3%Submissions: 56K+Points: 4
// Given an integer array arr of integers, the task is to find the maximum absolute difference between the nearest left smaller element and the nearest right smaller element of every element in array arr. If for any component of the arr, the nearest smaller element doesn't exist then consider it as 0.

// Examples :

// Input: arr = [2, 1, 8]
// Output: 1
// Explanation: left smaller array ls = [0, 0, 1], right smaller array rs = [1, 0, 0]. Maximum Diff of abs(ls[i] - rs[i]) = 1
// Input: arr = [2, 4, 8, 7, 7, 9, 3]
// Output: 4
// Explanation: left smaller array ls = [0, 2, 4, 4, 4, 7, 2], right smaller rs = [0, 3, 7, 3, 3, 3, 0]. Maximum Diff of abs(ls[i] - rs[i]) = abs(7 - 3) = 4
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(n)

// Constraints:
// 1 <= arr.size() <= 106
// 1<= arr[i] <=109

// Seen this question in a real interview before ?

class Solution
{
public:
    /*You are required to complete this method */
    void leftsmaller(vector<int> &a, int n, vector<int> &left)
    {
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            int ele = a[i];
            while (!st.empty() && ele <= st.top())
            {
                st.pop();
            }
            if (!st.empty())
            {
                left[i] = st.top();
            }
            st.push(ele);
        }
    }

    void rightsmaller(vector<int> &a, int n, vector<int> &right)
    {
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            int ele = a[i];
            while (!st.empty() && ele <= st.top())
            {
                st.pop();
            }
            if (!st.empty())
            {
                right[i] = st.top();
            }
            st.push(ele);
        }
    }

    int findMaxDiff(vector<int> &arr)
    {
        // Your code here
        int n = arr.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        leftsmaller(arr, n, left);
        rightsmaller(arr, n, right);
        int maxi = -1;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, abs(left[i] - right[i]));
        }
        return maxi;
    }
};
