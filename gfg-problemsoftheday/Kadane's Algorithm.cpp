// Kadane's Algorithm
// Difficulty: MediumAccuracy: 36.28%Submissions: 959K+Points: 4
// Given an integer array arr[]. Find the contiguous sub-array(containing at least one number) that has the maximum sum and return its sum.

// Examples:

// Input: arr[] = [1, 2, 3, -2, 5]
// Output: 9
// Explanation: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.
// Input: arr[] = [-1, -2, -3, -4]
// Output: -1
// Explanation: Max subarray sum is -1 of element (-1)
// Input: arr[] = [5, 4, 7]
// Output: 16
// Explanation: Max subarray sum is 16 of element (5, 4, 7)
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ arr.size() ≤ 105
// -107 ≤ arr[i] ≤ 107

// Seen this question in a real interview before ?

class Solution
{
public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr)
    {
        // code here...
        long long sum = 0;
        long long maxi = arr[0];
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            maxi = max(maxi, sum);
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxi;
    }
};
