// Nth Fibonacci Number
// EasyAccuracy: 22.3%Submissions: 226K+Points: 2
// Applying for Jobs, Now Easier Than Today's Problem! Explore Now

// Given a positive integer n, find the nth fibonacci number. Since the answer can be very large, return the answer modulo 1000000007.

// Example 1:

// Input:
// n = 2
// Output:
// 1
// Explanation:
// 1 is the 2nd number of fibonacci series.
// Example 2:

// Input:
// n = 5
// Output:
// 5
// Explanation:
// 5 is the 5th number of fibonacci series.
// Your Task:
// You dont need to read input or print anything. Complete the function nthFibonacci() which takes n as input parameter and returns nth fibonacci number.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1<= n <=105

class Solution
{
public:
    int nthFibonacci(int n)
    {
        // code here
        int last = 1, secondLast = 1, nth = 0, mod = 1000000007;
        if (n == 1)
        {
            return last;
        }
        else if (n == 2)
        {
            return secondLast;
        }
        else
        {
            while (n > 2)
            {
                nth = last % mod + secondLast % mod;
                last = secondLast;
                secondLast = nth;
                n--;
            }
            return nth % mod;
        }
    }
};
