// Consecutive 1's not allowed
// MediumAccuracy: 27.46%Submissions: 81K+Points: 4
// For the first time ever: GATE 2024 introduces DS & AI in its renowned exam. Take its first ever All India Mock Test

// banner
// Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. Output your answer modulo 109 + 7.

// Example 1:

// Input:
// N = 3
// Output: 5
// Explanation:
// 5 strings are (000,
// 001, 010, 100, 101).
// Example 2:

// Input:
// N = 2
// Output: 3
// Explanation:
// 3 strings are (00,01,10).
// Your Task:
// You don't have to print answer or take inputs. Complete the function countStrings() which takes single integer n, as input parameters and returns an integer denoting the answer.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 105

// Company Tags
// Topic

class Solution
{
public:
    // #define ll long long
    ll countStrings(int n)
    {
        int mod = 1e9 + 7;
        int zero = 1, sum = 2;
        for (int i = 2; i <= n; i++)
        {
            int temp = sum;
            sum = (sum + zero) % mod;
            zero = temp;
        }

        return sum % mod;
    }
};
