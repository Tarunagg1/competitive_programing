// Array Pair Sum Divisibility Problem
// EasyAccuracy: 27.85%Submissions: 61K+Points: 2
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.

// Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.

// Example 1 :

// Input : arr = [9, 5, 7, 3], k = 6
// Output: True
// Explanation: {(9, 3), (5, 7)} is a
// possible solution. 9 + 3 = 12 is divisible
// by 6 and 7 + 5 = 12 is also divisible by 6.

// Example 2:

// Input : arr = [2, 4, 1, 3], k = 4
// Output: False
// Explanation: There is no possible solution.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function canPair() which takes array and k as input parameter and returns true if array can be divided into pairs such that sum of every pair is divisible by k otherwise returns false.

// Expected Time Complexity: O(n)
// Expected Space Complexity : O(n)

// Constraints:
// 1 <= length of array <= 10^5
// 1 <= elements of array <= 10^5
// 1 <= k <= 10^5

// View Bookmarked Problems

class Solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        // Code here.
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[nums[i] % k]++;

        for (int i = 0; i <= k / 2; i++)
        {
            if (i == 0 || i == k - i)
            {
                if (mp[i] % 2 != 0)
                    return false;
                continue;
            }
            if (mp[i] != mp[k - i])
                return false;
        }
        return true;
    }
};
