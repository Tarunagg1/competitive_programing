// LCS of three strings
// MediumAccuracy: 48.52%Submissions: 47K+Points: 4
// Got your Geekbits? Now Get 90% Of Your Course Fee Refund! 

// banner
// Given 3 strings A, B and C, the task is to find the length of the longest sub-sequence that is common in all the three given strings.

// Example 1:

// Input:
// A = "geeks"
// B = "geeksfor", 
// C = "geeksforgeeks"
// Output: 5
// Explanation: 
// "geeks"is the longest common
// subsequence with length 5.
// Example 2:

// Input: 
// A = "abcd"
// B = "efgh"
// C = "ijkl"
// Output: 0
// Explanation: 
// There's no subsequence common
// in all the three strings.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function LCSof3() which takes the strings A, B, C and their lengths n1, n2, n3 as input and returns the length of the longest common subsequence in all the 3 strings.

// Expected Time Complexity: O(n1*n2*n3).
// Expected Auxiliary Space: O(n1*n2*n3).

// Constraints:
// 1 <= n1, n2, n3 <= 20
// Elements of the strings consitutes only of the lower case english alphabets.



class Solution
{
    public:

           int dp[21][21][21];
        int solve(int i, int j, int k, string& a, string& b, string& c){
            if(i < 0 || j < 0 || k < 0) return 0;
            if(dp[i][j][k] != -1) return dp[i][j][k];
            int take = 0;
            if(a[i] == b[j] && b[j] == c[k]) take = 1 + solve(i-1, j-1, k-1, a, b, c);
            int nottake = max({solve(i-1,j,k,a,b,c), solve(i,j-1,k,a,b,c), solve(i,j,k-1,a,b,c)});
            return dp[i][j][k] = max(take, nottake);
        }
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            memset(dp, -1, sizeof dp);
            return solve(n1-1, n2-1, n3-1, A, B, C);
        }
};

















