// Find all distinct subset (or subsequence) sums
// MediumAccuracy: 45.78%Submissions: 1165Points: 4
// Given a set of integers, find all distinct sums that can be generated from the subsets of the given sets.

// Example 1:

// Input: nums = {1,2}
// Output: {0,1,2,3}
// Explanation: Four distinct sums can be
// calculated which are 0, 1, 2 and 3.
// 0 if we do not choose any number.
// 1 if we choose only 1.
// 2 if we choose only 2.
// 3 if we choose 1 and 2.

// Example 2:

// Input: nums = {1,2,3}
// Output: {0,1,2,3,4,5,6}
// Explanation: Seven distinct sum can be calculated
// which are 0, 1, 2, 3, 4, 5 and 6.
// 0 if we do not choose any number.
// 1 if we choose only 1.
// 2 if we choose only 2.
// 3 if we choose only 3.
// 4 if we choose 1 and 3.
// 5 if we choose 2 and 3.
// 6 if we choose 1, 2 and 3.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function DistinictSum() which takes nums as input parameter and returns a list containing the distinict sum in increasing order,

// Expected Time Complexity: O(n * sum) where sum = sum of all elements of nums.
// Expected Space Complexity: O(n * sum)

// Constraints:
// 1 <= length of nums <= 102
// 1 <= nums[i] <= 102

class Solution
{
public:
    vector<int> DistinctSum(vector<int> nums)
    {
        int sumi = 0;
        for (auto it : nums)
        {
            sumi += it;
        }
        int n = nums.size();
        vector<int> prev(sumi + 1, 0);
        vector<int> curr(sumi + 1, 0);
        prev[0] = 1;
        prev[nums[0]] = 1;
        for (int ind = 1; ind < n; ind++)
        {
            prev[0] = 1;
            for (int tar = 1; tar <= sumi; tar++)
            {
                int ntak = prev[tar];
                int tak = 0;
                if (nums[ind] <= tar)
                    tak = prev[tar - nums[ind]];
                curr[tar] = tak | ntak;
            }
            prev = curr;
        }
        vector<int> res;
        prev[0] = 1;
        for (int i = 0; i <= sumi; i++)
        {
            if (prev[i] > 0)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
