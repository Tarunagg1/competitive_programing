// Generalised Fibonacci numbers
// HardAccuracy: 46.51%Submissions: 15K+Points: 8
// 200+ people shotlisted last month for SDE Internship. Grab your spot this month via GfG Weekly Contest!

// banner
// Consider the generalized Fibonacci number g, which is dependent on a, b and c as follows :-
// g(1) = 1, g(2) = 1. For any other number n, g(n) = a*g(n-1) + b*g(n-2) + c.

// For a given value of m, determine g(n)%m.

// Example 1:

// Input:
// a = 3
// b = 3
// c = 3
// n = 3
// m = 5
// Output:
// 4
// Explanation:
// g(1) = 1 and g(2) = 1
// g(3) = 3*g(2) + 3*g(1) + 3 = 3*1 + 3*1 + 3 = 9
// We need to return answer modulo 5, so 9%5 = 4, is the answer.
// Example 2:

// Input:
// a = 2
// b = 2
// c = 2
// n = 4
// m = 100
// Output:
// 16
// Explanation:
// g(1) = 1 and g(2) = 1
// g(3) = 2*g(2) + 2*g(1) + 2 = 2*1 + 2*1 + 2 = 6
// g(4) = 2*g(3) + 2*g(2) + 2  = 2*6 + 2*1 + 2 = 16
// We need to return answer modulo 100, so 16%100 = 16, is the answer.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function genFibNum() which takes 5 Integers a, b, c, n, and m as input and returns g(n)%m.

// Expected Time Complexity: O( log(n) ).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= a, b, c, n, m <= 109+7

// // Topic Tags

class Solution
{
public:
    vector<vector<long long>> idenmat()
    {
        vector<vector<long long>> mat(3, vector<long long>(3, 0));
        mat[0][0] = 1;
        mat[1][1] = 1;
        mat[2][2] = 1;
        return mat;
    }

    vector<vector<long long>> mul(vector<vector<long long>> mat1, vector<vector<long long>> mat2, long long &m)
    {

        long long n1 = mat1.size();
        long long m1 = mat1[0].size();
        long long n2 = mat2.size();
        long long m2 = mat2[0].size();

        vector<vector<long long>> ans(n1, vector<long long>(m2, 0));

        for (long long i = 0; i < n1; i++)
        {
            for (long long j = 0; j < n1; j++)
            {
                long long temp = 0;
                for (long long k = 0; k < m1; k++)
                {
                    temp = (temp + ((mat1[i][k] % m) * (mat2[k][j] % m)) % m) % m;
                }
                ans[i][j] = temp;
            }
        }

        return ans;
    }

    vector<vector<long long>> matpow(vector<vector<long long>> &basemat, long long p, long long &m)
    {
        if (p == 0)
        {
            return idenmat();
        }

        vector<vector<long long>> mat = matpow(basemat, p / 2, m);
        mat = mul(mat, mat, m);

        if (p & 1)
        { // odd
            mat = mul(mat, basemat, m);
        }
        return mat;
    }

    long long solve(long long &a, long long &b, long long &c, long long &n, long long &m)
    {

        // base matrix
        vector<vector<long long>> basemat(3, vector<long long>(3, 0));
        basemat[0][0] = a;
        basemat[0][1] = b;
        basemat[0][2] = 1;
        basemat[1][0] = 1;
        basemat[2][2] = 1;

        vector<vector<long long>> powmatrix = matpow(basemat, n - 2, m);

        vector<vector<long long>> initialval(3, vector<long long>(1, 0));
        initialval[0][0] = 1;
        initialval[1][0] = 1;
        initialval[2][0] = c;

        powmatrix = mul(powmatrix, initialval, m);
        return powmatrix[0][0];
    }

    long long genFibNum(long long a, long long b, long long c, long long n, long long m)
    {
        if (n == 1 || n == 2)
        {
            return 1;
        }

        return solve(a, b, c, n, m);
    }
};
