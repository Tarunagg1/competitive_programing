// Count digit groupings of a number 
// Medium Accuracy: 66.2% Submissions: 1571 Points: 4
// Given a string str consisting of digits, one may group these digits into sub-groups while maintaining their original order.
// The task is to count number of groupings such that for every sub-group except the last one, sum of digits in a sub-group is less than or equal to sum of the digits in the sub-group immediately on its right.

// For example, a valid grouping of digits of number 1119 is (1-11-9). Sum of digits in first subgroup is 1, next subgroup is 2, and last subgroup is 9. Sum of every subgroup is less than or equal to its immediate right.
 

// Example 1: 

// Input: str = "1119"
// Output: 7
// Explanation: [1-119], [1-1-19], [1-11-9], 
// [1-1-1-9], [11-19], [111-9] and [1119] 
// are seven sub-groups.

// Example 2:

// Input: str = "12"
// Output: 2
// Explanation: [1-2] and [12] are two sub-groups.
 

// Your Task:
// You don't need to read or print anything. Your task is to complete the function TotalCount() which takes the string str as input parameter and returns total possible groupings.

// Expected Time Complexity: O(N * N ) where N is length of string.
// Expected Space Complexity: O(N * N)
 

// Constraints:
// 1 <= length of string <= 100

// View Bookmarked Problems


class Solution{
    int n;
    int presum[105] = {0};
	public:
		int rec(int ind, int prev, string s, vector<vector<int>>& dp){
	    if(ind == n)    return 1;
	    if(dp[ind][prev] != -1)     return dp[ind][prev];
	    
	    int res = 0;
	    for(int i=ind; i<n;i++){
	        int sum = presum[i+1] - presum[ind];
	        if(sum >= prev)     res += rec(i+1, sum, s, dp);
	    }
	    return dp[ind][prev] = res;
	}

	int TotalCount(string str){
	    // Code here
	    n = str.length();
	    for(int i=1;i<=n;i++)    presum[i] = presum[i-1] + (str[i-1]-'0');
	    
	    vector<vector<int>> dp(n, vector<int>(1000, -1));
	    return rec(0, str[0]-'0', str, dp);
	}

};


































