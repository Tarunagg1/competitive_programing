// Brackets in Matrix Chain Multiplication 
// Hard Accuracy: 74.65% Submissions: 2306 Points: 8
// Given an array p[] of length n used to denote the dimensions of a series of matrices such that dimension of i'th matrix is p[i] * p[i+1]. There are a total of n-1 matrices. Find the most efficient way to multiply these matrices together. 
// The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications such that you need to perform minimum number of multiplications. There are many options to multiply a chain of matrices because matrix multiplication is associative i.e. no matter how one parenthesize the product, the result will be the same.


// Example 1:

// Input: 
// n = 5
// p[] = {1, 2, 3, 4, 5}
// Output: (((AB)C)D)
// Explaination: The total number of 
// multiplications are (1*2*3) + (1*3*4) 
// + (1*4*5) = 6 + 12 + 20 = 38.
 

// Example 2:

// Input: 
// n = 3
// p = {3, 3, 3}
// Output: (AB)
// Explaination: The total number of 
// multiplications are (3*3*3) = 27.
 

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function matrixChainOrder() which takes n and p[] as input parameters and returns the string with the proper order of parenthesis for n-1 matrices. Use uppercase alphabets to denote each matrix.


// Expected Time Complexity: O(n3)
// Expected Auxiliary Space: O(n2)


// Constraints:
// 2 ≤ n ≤ 26 
// 1 ≤ p[i] ≤ 500 

// View Bookmarked Problems
// Company Tags



class Solution{
public:
    pair<int, string> solve(int p[], int n, int low, int high, pair<int, string> dp[27][27])
    {
        if(low == high)
        {
            char ch = 'A' + low;
            string s = "" ; 
            s += ch;
            pair<int, string> pr = {0, s};
            return pr;
        }
        
        if(dp[low][high].first != -1)
            return dp[low][high];

        pair<int, string> ans;
        ans.first = INT_MAX;
        for(int i=low; i<high; i++)
        {
            pair<int, string> p1 = solve(p, n, low, i, dp);
            pair<int, string> p2 = solve(p, n, i+1, high, dp);
            
            int temp = p1.first + p2.first + (p[low] * p[i+1] * p[high+1]);
            if(ans.first > temp)
            {
                ans.first = temp;
                ans.second = "(" + p1.second + p2.second + ")";
            }
        }
        return dp[low][high] = ans;
    }
    string matrixChainOrder(int p[], int n){
        pair<int, string> dp[27][27];
        pair<int, string> empty; empty.first = -1;
        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
                dp[i][j] = empty;
        return solve(p, n, 0, n-2, dp).second;
    }
};





















