// Form a palindrome 
// Medium Accuracy: 65.94% Submissions: 6904 Points: 4
// Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
// For Example:
// ab: Number of insertions required is 1. bab or aba
// aa: Number of insertions required is 0. aa
// abcd: Number of insertions required is 3. dcbabcd

// Example 1:

// Input:
// abcd
// Output:
// 3
// Explanation:
// Here we can append 3 characters in the 
// beginning,and the resultant string will 
// be a palindrome ("dcbabcd").
// Example 2:

// Input:
// aba
// Output:
// 0
// Explanation:
// Given string is already a pallindrome hence
// no insertions are required.
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function findMinInsertions() which takes string S as input parameters and returns minimimum numser of insertions required.

// Expected Time Complexity: O(|S|2)
// Expected Auxiliary Space: O(|S|2)

// Constraints:
// 1 ≤ |S| ≤ 500



class Solution{   
public:
    int findMinInsertions(string s){
        // code here 
        int n=s.length();
       string p=s;
       reverse(s.begin(),s.end());
       
       int dp[n+1][n+1];
       
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=n;j++)
           {
               if(i==0||j==0)
                   dp[i][j]=0;
               else if(s[i-1]==p[j-1])
                   dp[i][j]=1+dp[i-1][j-1];
               else
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }
       }
       return n-dp[n][n];
    }
};






















