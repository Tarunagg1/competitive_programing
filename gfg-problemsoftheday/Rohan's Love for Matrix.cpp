// Rohan's Love for Matrix
// HardAccuracy: 45.55%Submissions: 16K+Points: 8
// Exclusive Job-A-Thon | Apply to 15+ Companies via 1 Hiring Challenge | Starting from 29th April onwards

// banner
// Rohan has a special love for the matrices especially for the first element of the matrix. Being good at Mathematics, he also loves to solve the different problem on the matrices. So one day he started to multiply the matrix with the original matrix.  The elements of the original matrix a are given by [a00=1 , a01=1, a10=1, a11=0].
// Given the power of the matrix, n calculate the an and return the a10 element mod 1000000007.

// Example 1:

// Input:
// n = 3
// Output:
// 2
// Explanation: Take the cube of the original matrix
// i.e a3 and the (a10)th element is 2.
// Example 2:

// Input:
// n = 4
// Output:
// 3
// Explanation: Take the cube of the original matrix
// i.e a4 and the (a10)th element is 3.
// Your Task:
// You dont need to read input or print anything. Complete the function firstElement() which takes n as input parameter and returns the a10 element mod 1000000007 of an.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<= n <=106

class Solution
{
public:
    int firstElement(int n)
    {
        // code here
        if (n == 1 or n == 2)
            return 1;
        long long a = 1, b = 1, ans = 1, mod = 1e9 + 7;
        for (int i = 3; i <= n; i++)
        {
            ans = a + b;
            a = b;
            ans %= mod;
            a %= mod;
            b %= mod;
            b = ans;
        }
        return ans;
    }
};
