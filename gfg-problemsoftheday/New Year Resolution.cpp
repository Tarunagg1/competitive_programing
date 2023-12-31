// New Year Resolution
// MediumAccuracy: 66.45%Submissions: 7K+Points: 4
// Win from a cash prize pool of INR 15,000
// Check out Hack-For-Health Hackathon Now!

// banner
// As the clock struck midnight on New Year's Eve, Geek bid farewell to the wasted moments of 2023, realizing the untapped potential of GFG's Problem of the Day.

// His 2024 resolution: Solve POTD every day.

// Eager to earn coins for GFG Merchandise, Geek faces new rules:

// Earning Coin: Geek can accumulate coins[i] by solving the POTD on the ith day, where 1 <= coins[i] <= 2024 and the sum of coins <= 2024.
// Merchandise Eligibility: To purchase merchandise, the coins earned must be divisible by 20 or 24, or precisely equal to 2024.
// Geek's resolutions often fades over time. Realistically, he can only commit to active participation for N (where N ≤ 366) days. Given the value of N and number of coins associated with each POTD, can Geek strategically solve some (or all) POTDs to become eligible for redeeming merchandise?

// Example 1:

// Input:
// N = 8
// coins = [5, 8, 9, 10, 14, 2, 3, 5]

// Output: 1

// Explanation:
// Geek can fulfill the criteria in many ways.
// One such way is to solve POTD on 4th and 5th day.
// Another way is to solve POTD on 1st, 4th and 8th day.
// Example 2:

// Input:
// N = 5
// coins = [1, 2, 3, 4, 5]

// Output: 0

// Explanation: There is no way Geek can become eligible.
// Your Task:
// You don't need to read input or print anything. Complete the function isPossible() which takes n and coins[ ] as input parameters and returns a boolean value.

// Expected Time Complexity: O(N*(Sum of coins))
// Expected Auxiliary Space: O(N*(Sum of coins))

// Constraints:
// 1 <= N <= 366
// 1 <= coins[i] <= 2024
// 1 <= Sum of coins <=  2024

class Solution
{

public:
    int isPossible(int N, int coins[])
    {
        int s = 0;
        for (int i = 0; i < N; i++)
        {
            s += coins[i];
        }
        vector<int> dp(s + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < N; i++)
        {
            for (int j = s; j >= 0; j--)
            {
                if (j - coins[i] >= 0)
                {
                    dp[j] |= dp[j - coins[i]];
                }
            }
        }
        for (int i = 1; i <= s; i++)
        {
            if (i % 20 == 0 || i % 24 == 0 || i == 2024)
            {
                if (dp[i])
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};
