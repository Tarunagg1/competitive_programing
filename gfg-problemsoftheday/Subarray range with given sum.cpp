// Subarray range with given sum
// Difficulty: MediumAccuracy: 42.21%Submissions: 35K+Points: 4
// Given an unsorted array of integers arr[], and a target tar, determine the number of subarrays whose elements sum up to the target value.

// Examples:

// Input: arr[] = [10, 2, -2, -20, 10] , tar = -10
// Output: 3
// Explanation: Subarrays with sum -10 are: [10, 2, -2, -20], [2, -2, -20, 10] and [-20, 10].
// Input: arr[] = [1, 4, 20, 3, 10, 5] , tar = 33
// Output: 1
// Explanation: Subarray with sum 33 is: [20,3,10].
// Expected Time Complexity: O(n)
// Expected Auxilary Space: O(n)

// Constraints:
// 1 <= arr.size() <= 106
// -105 <= arr[i] <= 105
// -105 <= tar <= 105Two Swaps



class Solution
{
public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int> &arr, int tar)
    {
        // Your code here
        unordered_map<int, int> mp;

        mp[0] = 1;
        int ans = 0, sum = 0;
        for (auto &it : arr)
        {
            sum += it;
            ans += mp[sum - tar];
            mp[sum]++;
        }
        return ans;
    }
};
