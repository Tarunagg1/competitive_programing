// Split Array Largest Sum
// HardAccuracy: 52.83%Submissions: 388+Points: 8
// Given an array arr[] of N elements and a number K. Split the given array into K subarrays such that the maximum subarray sum achievable out of K subarrays formed is minimum possible. Find that possible subarray sum.

// Example 1:

// Input:
// N = 4, K = 3
// arr[] = {1, 2, 3, 4}
// Output: 4
// Explanation:
// Optimal Split is {1, 2}, {3}, {4}.
// Maximum sum of all subarrays is 4,
// which is minimum possible for 3 splits.
// Example 2:

// Input:
// N = 3, K = 2
// A[] = {1, 1, 2}
// Output:
// 2
// Explanation:
// Splitting the array as {1,1} and {2} is optimal.
// This results in a maximum sum subarray of 2.

// Your Task:
// The task is to complete the function splitArray() which returns the maximum sum subarray after splitting the array into K subarrays such that maximum sum subarray is minimum possible.

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ K ≤ N
// 1 ≤ arr[i] ≤ 104

// Expected Time Complexity: O(N*log(sum(arr))).
// Expected Auxiliary Space: O(1).

// View Bookmarked Problems

class Solution
{
public:
    bool check(int arr[], int k, int n, int mid)
    {
        int sum = 0, count = 1;
        for (int i = 0; i < n; i++)
        {
            if (sum + arr[i] <= mid)
            {
                sum += arr[i];
            }
            else
            {
                count++;
                sum = arr[i];
            }
        }
        return count <= k;
    }

    int splitArray(int arr[], int n, int k)
    {
        if (k > n)
            return -1;
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        int low = *max_element(arr, arr + n), high = sum, ans = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (check(arr, k, n, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
