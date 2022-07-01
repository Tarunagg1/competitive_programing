// Matrix Exponentiation
// Medium Accuracy: 31.87% Submissions: 2145 Points: 4
// Given an equation of the form f(n) = f(n-1) + f(n-2) where f(0) = 1, F(1) = 1 , the task is to find the nth term of this sequence.

// Example 1:

// Input: n = 3
// Output: 3
// Explanation: f(3) = f(2) + f(1) = 3

// Example 2:

// Input: n = 2
// Output: 2
// Explanation: f(2) = f(1) + f(0) = 2

// Yout Task:
// You don't need to read or print anything. Your task is to complete the function FindNthTerm() which takes n as input parameter and returns nth term mod 10^9+7 .

// Expected Time Compelxity: O(log(n))
// Expected Space Complexity: O(K) where K is constant.

// Constraints:
// 1 <= n <= 109

// View Bookmarked Problems
// Topic Tags

class Solution
{
public:
    int FindNthTerm(long long int n)
    {
        // Code here
        long long int f[2][2] = {{1, 1}, {1, 0}};

        power(f, n);

        return f[0][0];
    }

    void multiplication(long long int a[2][2], long long int b[2][2])
    {
        long long int p = ((a[0][0] * b[0][0]) % 1000000007 + (a[0][1] * b[1][0]) % 1000000007) % 1000000007;
        long long int q = ((a[0][0] * b[0][1]) % 1000000007 + (a[0][1] * b[1][1]) % 1000000007) % 1000000007;
        long long int r = ((a[1][0] * b[0][0]) % 1000000007 + (a[1][1] * b[1][0]) % 1000000007) % 1000000007;
        long long int s = ((a[1][0] * b[0][1]) % 1000000007 + (a[1][1] * b[1][1]) % 1000000007) % 1000000007;

        a[0][0] = p;
        a[0][1] = q;
        a[1][0] = r;
        a[1][1] = s;
    }

    void power(long long int a[2][2], long long int n)
    {
        if (n == 0 || n == 1)
            return;
        long long int m[2][2] = {{1, 1}, {1, 0}};
        power(a, n / 2);
        multiplication(a, a);
        if (n % 2 != 0)
            multiplication(a, m);
    }
};
