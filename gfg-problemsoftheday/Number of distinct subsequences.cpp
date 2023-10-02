// Number of distinct subsequences
// HardAccuracy: 30.43%Submissions: 24K+Points: 8
// Win 2X Geekbits, Get on the Leaderboard & Top the Coding Charts! Register for GFG Weekly Coding Contest

// banner
// Given a string consisting of lower case English alphabets, the task is to find the number of distinct subsequences of the string
// Note: Answer can be very large, so, ouput will be answer modulo 109+7.

// Example 1:

// Input:
// s = "gfg"
// Output:
// 7
// Explanation:
// The seven distinct subsequences are "", "g", "f", "gf", "fg", "gg" and "gfg" .
// Example 2:

// Input:
// s = "ggg"
// Output:
// 4
// Explanation:
// The four distinct subsequences are "", "g", "gg", "ggg".
// Your task:
// You do not need to read any input or print anything. The task is to complete the function distinctSubsequences(), which takes a string as input and returns an integer.

// Expected Time Complexity: O(|str|)
// Expected Auxiliary Space: O(|str|)

// Constraints:
// 1 ≤ |s| ≤ 105
// s contains lower case English alphabets

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	     int n = s.size();
    int dp[n + 1];
    
    int mod = 1e9 + 7;
    dp[0] = 1;
    
    // Space : O(n)
    unordered_map <char, int> mp;
    
    // Time : O(n)
    for(int i = 1;i <= n;i++){
        
        dp[i] = (dp[i - 1] * 2) % mod;
        
        
        char c = s[i - 1];
        
        if(mp.find(c) != mp.end()){
            dp[i] = (dp[i] - dp[mp[c] - 1] + mod) % mod;
        }
        mp[c] = i;
    }
    
    return dp[n] % mod;
	}
};

