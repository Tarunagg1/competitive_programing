// Prime List
// MediumAccuracy: 65.25%Submissions: 3K+Points: 4
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// You are given the head of a linked list. You have to replace all the values of the nodes with the nearest prime number. If more than one prime number exists at an equal distance, choose the smallest one.

// Example 1:

// Input:
// 2 → 6 → 10
// Output:
// 2 → 5 → 11
// Explanation:
// The nearest prime of 2 is 2 itself.
// The nearest primes of 6 are 5 and 7,
// since 5 is smaller so, 5 will be chosen.
// The nearest prime of 10 is 11.

// Example 2:

// Input:
// 1 → 15 → 20
// Output:
// 2 → 13 → 19
// Explanation:
// The nearest prime of 1 is 2.
// The nearest primes of 15 are 13 and 17,
// since 13 is smaller so, 13 will be chosen.
// The nearest prime of 20 is 19.
// Your Task:
// The task is to complete the function primeList() which contains a reference to the head as the only argument. This function should return the head of the modified linked list.

// Expected Time Complexity: O(number of nodes * sqrt(value of node)).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ Number of Nodes ≤ 104
// 1 ≤ Value on Node ≤ 104

// View Bookmarked Problems

class Solution
{

    int dp[100001];

    bool isPrime(int n)
    {

        dp[0] = 0;

        dp[1] = 0;

        dp[2] = 1;

        if (dp[n] != -1)
            return dp[n];

        for (int i = 2; i * i <= n; i++)
        {

            if (n % i == 0)
            {

                return dp[n] = 0;
            }
        }

        return dp[n] = 1;
    }

public:
    Node *primeList(Node *head)
    {

        memset(dp, -1, sizeof(dp));

        Node *temp = head;

        while (temp)
        {

            if (!isPrime(temp->val))
            {

                int a = 0, b = 0, num = temp->val;

                for (int i = num; i >= 2; i--)
                {

                    if (isPrime(i))
                    {

                        a = i;

                        break;
                    }
                }

                for (int i = num; i < 1e5 + 1; i++)
                {

                    if (isPrime(i))
                    {

                        b = i;

                        break;
                    }
                }

                if (a != 0 && b != 0)
                {

                    if (abs(num - a) < abs(num - b))
                    {

                        temp->val = a;
                    }

                    else if (abs(num - a) > abs(num - b))
                    {

                        temp->val = b;
                    }

                    else
                    {

                        if (a < b)
                        {

                            temp->val = a;
                        }

                        else
                        {

                            temp->val = b;
                        }
                    }
                }

                else if (a != 0)
                {

                    temp->val = a;
                }

                else
                {

                    temp->val = b;
                }
            }

            temp = temp->next;
        }

        return head;
    }
};
