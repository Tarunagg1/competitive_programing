// Split Array Largest Sum
// HardAccuracy: 58.9%Submissions: 20K+Points: 8
// 90% Refund available on all premium courses
// Discover How

// banner
// Given an array arr[] of N elements and a number K., split the given array into K subarrays such that the maximum subarray sum achievable out of K subarrays formed is minimum possible. Find that possible subarray sum.

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
// You do not have to take any input or print anything. The task is to complete the function splitArray() which returns the maximum sum subarray after splitting the array into K subarrays such that maximum sum subarray is minimum possible.

// Expected Time Complexity: O(N*log(sum(arr))).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ K ≤ N
// 1 ≤ arr[i] ≤ 104

// Company Tags

class Solution
{
public:
    int splitArray(int arr[], int N, int K)
    {
        // code here
        int sum = 0;
        int l = 1;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
            l = max(l, arr[i]);
        }
        int r = sum;
        while (l < r)
        {
            int mid = (l + r) / 2;
            int z = 0;
            int ct = 0;
            for (int i = 0; i < N; i++)
            {
                z += arr[i];
                if (z > mid)
                {
                    ct++;
                    z = arr[i];
                }
            }
            ct++;
            if (ct > K)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
            if (r - l == 1)
            {
                break;
            }
        }
        int z = 0;
        int ct = 0;
        for (int i = 0; i < N; i++)
        {
            z += arr[i];
            if (z > l)
            {
                ct++;
                z = arr[i];
            }
        }
        ct++;
        if (ct <= K)
        {
            return l;
        }
        return r;
    }
};
