// Max Circular Subarray Sum
// Difficulty: HardAccuracy: 29.37%Submissions: 112K+Points: 8
// Given an array of integers arr[] in a circular fashion. Find the maximum subarray sum that we can get if we assume the array to be circular.

// Examples:

// Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
// Output: 22
// Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.
// Input: arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
// Output: 23
// Explanation: Maximum sum of the circular subarray is 23. The subarray is [7, 6, 5, -4, -1, 10].
// Input: arr[] = [-1, 40, -14, 7, 6, 5, -4, -1]
// Output: 52
// Explanation: Circular Subarray [7, 6, 5, -4, -1, -1, 40] has the maximum sum, which is 52.
// Constraints:
// 1 <= arr.size() <= 105
// -104 <= arr[i] <= 104

class Solution
{
public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int kadane(vector<int> &a)
    {
        int mx = a[0];
        int cur = a[0];
        for (int i = 1; i < a.size(); i++)
        {
            cur = max(a[i], cur + a[i]);
            mx = max(mx, cur);
        }
        return mx;
    }
    int circularSubarraySum(vector<int> &arr)
    {
        int n = arr.size();
        int max1 = kadane(arr);
        if (max1 < 0)
            return max1;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            arr[i] = -arr[i];
        }
        int min1 = kadane(arr);
        int max2 = sum + min1;
        return max(max2, max1);
    }
};
