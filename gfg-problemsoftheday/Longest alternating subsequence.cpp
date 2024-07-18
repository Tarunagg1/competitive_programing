// Longest alternating subsequence
// Difficulty: MediumAccuracy: 38.32%Submissions: 38K+Points: 4
// You are given an array arr. Your task is to find the longest length of a good sequence. A good sequence {x1, x2, .. xn} is an alternating sequence if its elements satisfy one of the following relations :

// 1.  x1 < x2 > x3 < x4 > x5. . . . . and so on
// 2.  x1 >x2 < x3 > x4 < x5. . . . . and so on

// Examples:

// Input: arr= [1, 5, 4]
// Output: 3
// Explanation: The entire sequenece is a good sequence.
// Input: arr= [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
// Output: 7
// Explanation: There are several subsequences that achieve this length.
// One maximum length good subsequences is [1, 17, 10, 13, 10, 16, 8].
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)

// Constraints:
// 1 <= nums.size() <= 105
// 1 <= nums[i] <= 104

class Solution
{
public:
    int f(int curr_ind, vector<int> &arr, int isUp, vector<vector<int>> &dp)
    {
        if (curr_ind == 0)
            return 1;

        if (dp[curr_ind][isUp] != -1)
        {
            return dp[curr_ind][isUp];
        }
        int nottake = f(curr_ind - 1, arr, isUp, dp);
        int take = 0;
        if (isUp)
        {
            if (arr[curr_ind] > arr[curr_ind - 1])
            {
                take = 1 + f(curr_ind - 1, arr, 0, dp);
            }
        }
        else
        {
            if (arr[curr_ind] < arr[curr_ind - 1])
            {
                take = 1 + f(curr_ind - 1, arr, 1, dp);
            }
        }
        return dp[curr_ind][isUp] = max(take, nottake);
    }

    int alternatingMaxLength(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return max(f(n - 1, arr, 1, dp), f(n - 1, arr, 0, dp));
    }
};
