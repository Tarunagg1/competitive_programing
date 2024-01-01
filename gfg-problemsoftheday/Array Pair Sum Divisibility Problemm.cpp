// Array Pair Sum Divisibility Problem
// MediumAccuracy: 27.85%Submissions: 95K+Points: 4
// Get 90% refund on courses in just 90 days!
// Discover How

// banner
// Given an array of integers nums and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.

// Example 1 :

// Input :
// nums = [9, 5, 7, 3]
// k = 6
// Output:
// True
// Explanation:
// {(9, 3), (5, 7)} is a
// possible solution. 9 + 3 = 12 is divisible
// by 6 and 7 + 5 = 12 is also divisible by 6.
// Example 2:

// Input :
// nums = [4, 4, 4]
// k = 4
// Output:
// False
// Explanation:
// You can make 1 pair at max, leaving a single 4 unpaired.
// Your Task:
// You don't need to read or print anything. Your task is to complete the function canPair() which takes array nums and k as input parameter and returns true if array can be divided into pairs such that sum of every pair is divisible by k otherwise returns false.

// Expected Time Complexity: O(n)
// Expected Space Complexity : O(n)

// Constraints:
// 1 <= length( nums ) <= 105
// 1 <= numsi <= 105
// 1 <= k <= 105

class Solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        // Code here.

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            int mod = nums[i] % k;
            mp[mod]++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int num1 = nums[i] % k;
            int target = (num1 == 0) ? 0 : k - num1;

            if (mp[num1] == 0)
            {
                continue;
            }

            if (num1 == target)
            {
                if (mp[num1] < 2)
                {
                    return false;
                }
            }
            else if (mp[target] == 0)
            {
                return false;
            }

            mp[num1]--;
            mp[target]--;
        }

        return true;
    }
};
