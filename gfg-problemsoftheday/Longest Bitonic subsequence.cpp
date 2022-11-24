// Longest Bitonic subsequence
// MediumAccuracy: 47.34%Submissions: 31728Points: 4
// Given an array of positive integers. Find the maximum length of Bitonic subsequence.
// A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing.

// Example 1:

// Input: nums = [1, 2, 5, 3, 2]
// Output: 5
// Explanation: The sequence {1, 2, 5} is
// increasing and the sequence {3, 2} is
// decreasing so merging both we will get
// length 5.
// Example 2:

// Input: nums = [1, 11, 2, 10, 4, 5, 2, 1]
// Output: 6
// Explanation: The bitonic sequence
// {1, 2, 10, 4, 2, 1} has length 6.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function LongestBitonicSequence() which takes the array nums[] as input parameter and returns the maximum length of bitonic subsequence.

// Expected Time Complexity: O(n2)
// Expected Space Complexity: O(n)

// Constraints:
// 1 ≤ length of array ≤ 1000
// 1 ≤ arr[i] ≤ 1000000

// View Bookmarked Problems

class Solution
{
public:
    int LongestBitonicSequence(vector<int> nums)
    {
        // code here
        int n = nums.size();
        vector<int> right(n); // longest decreasing order;
        vector<int> left(n);  // longest increasing order;

        for (int i = 0; i < n; i++)
        {
            right[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && right[j] + 1 > right[i])
                    right[i] = right[j] + 1;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            left[i] = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] < nums[i] && left[j] + 1 > left[i])
                    left[i] = left[j] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, right[i] + left[i] - 1);
        }
        return ans;
    }
};
