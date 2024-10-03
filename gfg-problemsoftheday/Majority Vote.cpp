// Majority Vote
// Difficulty: MediumAccuracy: 48.1%Submissions: 27K+Points: 4
// You are given an array of integer nums[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return -1.

// Note: The answer should be returned in an incresing format.

// Examples:

// Input: nums = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
// Output: [5, 6]
// Explanation: 5 and 6 occur more n/3 times.
// Input: nums = [1, 2, 3, 4, 5]
// Output: [-1]
// Explanation: no candidate occur more than n/3 times.
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)

// Constraint:
// 1 <= nums.size() <= 106
// 0 <= nums[i] <= 109

class Solution
{
public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int> &nums)
    {
        // Your code goes here.
        vector<int> ans;
        int n = nums.size();
        int vote1 = 0, vote2 = 0;
        int candidate1, candidate2;

        for (int i = 0; i < n; i++)
        {
            if (vote1 == 0)
            {
                candidate1 = nums[i];
                vote1 = 1;
            }
            else if (vote2 == 0)
            {
                candidate2 = nums[i];
                vote2 = 1;
            }
            else if (candidate1 == nums[i])
                vote1++;

            else if (candidate2 == nums[i])
                vote2++;

            else
            {
                vote1--;
                vote2--;
            }
        }

        int count1 = 0, count2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (candidate1 == nums[i])
                count1++;

            else if (candidate2 == nums[i])
                count2++;
        }

        if (count1 > n / 3)
            ans.push_back(candidate1);

        if (count2 > n / 3)
            ans.push_back(candidate2);

        if (!ans.empty())
            return ans;

        return {-1};
    }
};
