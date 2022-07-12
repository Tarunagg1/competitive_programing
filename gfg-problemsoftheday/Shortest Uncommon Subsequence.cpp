// Shortest Uncommon Subsequence 
// Medium Accuracy: 62.61% Submissions: 1271 Points: 4
// Given two strings S and T, find length of the shortest subsequence in S which is not a subsequence in T. If no such subsequence is possible, return -1. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. A string of length n has 2^n different possible subsequences.

 

// Example 1:

// Input:
// S = "babab"
// T = "babba"
// Output:
// 3
// Explanation:
// There are no subsequences of S with
// length less than 3 which is not a
// subsequence of T. "aab" is an example of
// a subsequence of length 3 which isn't a
// subsequence of T.
// Example 2:

// Input:
// S = "babhi"
// T = "babij"
// Output:
// 1
// Explanation:
// "h" is a subsequence of S that is
// not a subsequence of T.
 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function shortestUnSub() which takes two Strings S, and T as input and returns the shortest Uncommon Subsequence.

 

// Expected Time Complexity: O(|S|2*|T|)
// Expected Auxiliary Space: O(|S|*|T|)

 

// Constraints:
// 1 <= |S|, |T| <= 500

// View Bookmarked Problems
// Topic Tags



class Solution {
  public:
    int shortestUnSub(string s, string t) {
        // code here
         int n = s.size(), m = t.size() ;
        vector< vector<int> > dp(n+1, vector<int>(m+1,INT_MAX)) ;
        for(int i=0 ; i<=n-1 ; i++)
            dp[i][m] = 1 ;
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=m-1 ; j>=0 ; j--){
                int k = j ;
                while(k<m && s[i] != t[k])
                    k++ ;
                if(k == m)
                    dp[i][j] = 1 ;
                else
                    dp[i][j] = min(dp[i+1][j],(dp[i+1][k+1] == INT_MAX ? INT_MAX : dp[i+1][k+1] + 1)) ;
            }
        }
        return dp[0][0] == INT_MAX ? -1 : dp[0][0];
    }
};




























