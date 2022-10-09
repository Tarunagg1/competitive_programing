// Help Ishaan
// EasyAccuracy: 38.19%Submissions: 178Points: 2
// Ishaan has been given a task by his teacher. He needs to find the Nth term of a series. His teacher gives him some examples to help him out (Refer examples below). He is a bit weak in pattern searching so to help him his teacher told him that the Nth term is related to prime numbers. The Nth term is the difference of N and the closest prime number to N. Help him find the Nth term for a given N.

// Example 1:

// Input: N = 10
// Output: 1
// Explanation: Closest prime to 10 is 11.
// Example 2:

// Input: N = 7
// Output: 0
// Explanation: Closest prime to 7 is 7.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function NthTerm() which takes N as input paramater and returns Nth term.

// Expected Time Complexity: O(N* √ N)
// Expected Space Complexity: O(1)

// Constraints:
// 1 <= N <= 100000

class Solution
{
public:
    int NthTerm(int N)
    {
        // Code here
        int ans1 = 0;

        int ans2 = 0;

        int flag1 = 0;

        if (N == 1)
            return 1;

        if (N == 0)
            return 2;

        if (N == 2)
            return 0;

        for (int i = N; i >= 2; i--)
        {

            for (int j = 2; j <= N / 2; j++)
            {

                if (i % j == 0)
                {

                    flag1 = 1;

                    break;
                }
            }

            if (flag1 == 0)
            {

                ans1 = i;

                break;
            }

            flag1 = 0;
        }

        int flag2 = 0;

        for (int i = N + 1; i < 1e9; i++)
        {

            for (int j = 2; j <= N / 2; j++)
            {

                if (i % j == 0)
                {

                    flag2 = 1;

                    break;
                }
            }

            if (flag2 == 0)
            {

                ans2 = i;

                break;
            }

            flag2 = 0;
        }

        return min(abs(N - ans1), abs(N - ans2));
    }
};
