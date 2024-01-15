// Grinding Geek
// MediumAccuracy: 46.09%Submissions: 9K+Points: 4
// You've won Geekbits by solving daily. Now win 90% of your money-back by learning daily!

// banner
// GeeksforGeeks has introduced a special offer where you can enroll in any course, and if you manage to complete 90% of the course within 90 days, you will receive a refund of 90%.

// Geek was fascinated by this offer. This offer was valid for only n days, and each day a new course was available for purchase. Geek decided that if he bought a course on some day, he will complete that course on the same day itself and redeem floor[90% of cost of the course] amount back. Find the maximum number of courses that Geek can complete in those n days if he had total amount initially.

// Note: On any day, Geek can only buy the new course that was made available for purchase that day.

// Example 1:

// Input:
// n = 2
// total = 10
// cost = [10, 9]
// Output: 2
// Explanation:
// Geek can buy the first course for 10 amount,
// complete it on the same date and redeem 9 back.
// Next, he can buy and complete the 2nd course too.
// Example 2:

// Input:
// n = 11
// total = 10
// cost = [10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
// Output: 10
// Explanation:
// Geek can buy and complete all the courses that cost 1.
// Your Task:
// This is a function problem. The input is already taken care of by the driver code. You only need to complete the function max_courses() that takes N the number of days, the total amount, and the cost array as input argument and return the maximum amount of courses that could be purchased.

// Expected Time Complexity: O(n*total)
// Expected Auxiliary Space: O(n*total)

// Constraints:
// 1 <= n <= 1000
// 0 <= total <= 1000
// 1 <= cost[i] <= 1000

class Solution
{
public:
    int f(int idx, int total, vector<int> &cost, vector<vector<int>> &dp)
    {
        if (idx == cost.size())
            return 0;
        if (dp[idx][total] != -1)
            return dp[idx][total];
        if (total < cost[idx])
        {
            return dp[idx][total] = f(idx + 1, total, cost, dp);
        }
        else
        {
            int newTotal = total - cost[idx];
            int refund = cost[idx] * 0.9;
            newTotal += refund;

            int pick = 1 + f(idx + 1, newTotal, cost, dp);
            int notPick = f(idx + 1, total, cost, dp);
            return dp[idx][total] = max(pick, notPick);
        }
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        // Code Here
        vector<vector<int>> dp(n + 1, vector<int>(total + 1, -1));
        return f(0, total, cost, dp);
    }
};
