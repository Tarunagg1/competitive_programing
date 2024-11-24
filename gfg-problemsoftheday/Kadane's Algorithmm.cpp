// Kadane's Algorithm
// Difficulty: MediumAccuracy: 36.28%Submissions: 1MPoints: 4
// Given an integer array arr[]. You need to find the maximum sum of a subarray.

// Examples:

// Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
// Output: 11
// Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.
// Input: arr[] = [-2, -4]
// Output: -2
// Explanation: The subarray {-2} has the largest sum -2.
// Input: arr[] = [5, 4, 1, 7, 8]
// Output: 25
// Explanation: The subarray {5, 4, 1, 7, 8} has the largest sum 25.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// -109 ≤ arr[i] ≤ 104

class Solution
{
public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr)
    {
        // code here...
        int current = arr[0];
        int result = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            current = max(arr[i] + current, arr[i]);
            result = max(current, result);
        }
        return result;
    }
};
