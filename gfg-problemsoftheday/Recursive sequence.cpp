// Recursive sequence
// EasyAccuracy: 49.57%Submissions: 22K+Points: 2
// Internship Alert!
// Become an SDE Intern by topping this monthly leaderboard!

// banner
// A function F is defined as follows F(n)= (1) +(2*3) + (4*5*6) ... upto n terms (look at the examples for better clarity). Given an integer n, determine the F(n).

// Note: As the answer can be very large, return the answer modulo 109+7.

// Example 1:

// Input: n = 5
// Output: 365527
// Explanation:
// F(5) = 1 + 2*3 + 4*5*6 + 7*8*9*10 + 11*12*13*14*15 = 365527.
// Example 2:

// Input: n = 7
// Output: 6006997207
// Explanation:
// F(5) = 1 + 2*3 + 4*5*6 + 7*8*9*10 + 11*12*13*14*15 +
// 16*17*18*19*20*21 + 22*23*24*25*26*27*28 = 6006997207.
// 6006997207 % 109+7 = 6997165
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function sequence() which takes an integer n as an input parameter and returns the value of F(n).

// Expected Time Complexity: O(n2)
// Expected Space Complexity: O(1)

// Constraints:
// 1 ≤ n ≤ 103

// Company Tags

class Solution
{
public:
    const int Mod = 1000000007;

    long long sequence(int n)
    {
        // code here4
        long long num = 1, ans = 0;

        for (long long i = 1; i <= n; i++)
        {
            long long product = 1;
            for (long long j = 1; j <= i; j++)
            {
                product = (product % Mod * num) % Mod;
                num++;
            }
            ans = (ans % Mod + product % Mod) % Mod;
        }

        return ans;
    }
};
