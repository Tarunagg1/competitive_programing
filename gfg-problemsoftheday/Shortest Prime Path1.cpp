// Shortest Prime Path
// MediumAccuracy: 70.4%Submissions: 9K+Points: 4
// Got your Geekbits? Now Get 90% Of Your Course Fee Refund!

// banner
// You are given two four digit prime numbers Num1 and Num2. Find the distance of the shortest path from Num1 to Num2 that can be attained by altering only single digit at a time such that every number that we get after changing a digit is a four digit prime number with no leading zeros.

// Example 1:

// Input:
// Num1 = 1033
// Num2 = 8179
// Output: 6
// Explanation:
// 1033 -> 1733 -> 3733 -> 3739 -> 3779 -> 8779 -> 8179.
// There are only 6 steps reuired to reach Num2 from Num1.
// and all the intermediate numbers are 4 digit prime numbers.
// Example 2:

// Input:
// Num1 = 1033
// Num2 = 1033
// Output:
// 0
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function solve() which takes two integers Num1 and Num2 as input parameters and returns the distance of the shortest path from Num1 to Num2. If it is unreachable then return -1.

// Expected Time Complexity: O(nlogn)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1000<=Num1,Num2<=9999
// Num1 and Num2 are prime numbers.

// Company Tags
// Topic Tags

class Solution
{
public:
    void SieveOfEratosthenes(int n, vector<bool> &prime)
    {
        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
    }
    int solve(int Num1, int Num2)
    {
        vector<bool> prime(10000, 1);
        SieveOfEratosthenes(9999, prime);
        int res = 0;
        queue<int> q;
        q.push(Num1);
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                int val = q.front();
                q.pop();
                if (val == Num2)
                    return res;
                string s = to_string(val);
                for (int j = 0; j < 4; j++)
                {
                    char c = s[j];
                    for (int k = 0; k < 10; k++)
                    {
                        if (k == 0 && j == 0)
                            continue;
                        s[j] = '0' + k;
                        int temp = stoi(s);
                        if (prime[temp])
                        {
                            q.push(temp);
                            prime[temp] = 0;
                        }
                    }
                    s[j] = c;
                }
            }
            res++;
        }
    }
};
