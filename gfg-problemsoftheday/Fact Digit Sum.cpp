// Fact Digit Sum
// EasyAccuracy: 61.98%Submissions: 1871Points: 2
// A(X) for positive integer X is the sum of factorials of its digits. For example, A(154) = 1! + 5! + 4!= 145.
// Given a number N, find the minimum number X such that A(X) = N. You have to return a list of digits which represent the number X.

// Example 1:

// Input: N = 40321
// Output: 18
// Explanation: A(18)=1!+ 8! =40321
// Note that A(80) and A(81) are also
// 40321, But 18 is the smallest
// number.
// Example 2:

// Input: N = 5040
// Output: 7
// Explanation: A(7) = 7! = 5040.
// Your Task:
// You don't need to read or print anything. Your task is to complete the function FactDigit() which takes N as input parameter and returns a list of digits which represent the number X.

// Expected Time Complexity: O(X) where X ≤ 106
// Expected Space Complexity: O(X)

// Constraints:
// 1 ≤ N ≤ 109

#define ll long long

bool flag = true;

ll fact[9] = {1};

class Solution
{
public:
    vector<int> FactDigit(int N)
    {
        // Code here
        if (flag)
        {
            for (int i = 1; i < 10; i++)
            {
                fact[i] = i * fact[i - 1];
            }

            flag = false;
        }
        vector<int> res;

        while (N > 0)
        {
            for (int i = 9; i > 0; i--)
            {
                if (fact[i] > N)
                    continue;
                else
                {
                    res.push_back(i);
                    N -= fact[i];
                    break;
                }
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
