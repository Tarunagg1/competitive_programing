// Sorted subsequence of size 3
// Difficulty: MediumAccuracy: 25.95%Submissions: 57K+Points: 4
// You are given an array arr, you need to find any three elements in it such that arr[i] < arr[j] < arr[k] and i < j < k.

// Note:

// The output will be 1 if the subsequence returned by the function is present in the array arr
// If the subsequence is not present in the array then return an empty array, the driver code will print 0.
// If the subsequence returned by the function is not in the format as mentioned then the output will be -1.
// Examples :

// Input: arr = [1, 2, 1, 1, 3]
// Output: 1
// Explanation: A subsequence 1 2 3 exist.
// Input: arr = [1, 1, 3]
// Output: 0
// Explanation: No such Subsequence exist, so empty array is returned (the driver code automatically prints 0 in this case).
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= arr.size() <= 105
// 1 <= arr[i] <= 106

// Seen this question in a real interview before ?

class Solution
{
public:
    vector<int> find3Numbers(vector<int> &arr)
    {
        // Code here
        int n = arr.size();
        vector<int> small(n);
        vector<int> big(n);
        small[0] = arr[0];
        big[n - 1] = arr[n - 1];
        for (int i = 1; i < n; i++)
        {
            small[i] = min(arr[i], small[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            big[i] = max(arr[i], big[i + 1]);
        }
        for (int i = 0; i < n; i++)
        {
            if (small[i] < arr[i] && big[i] > arr[i])
            {
                return {small[i], arr[i], big[i]};
            }
        }
        return {};
    }
};