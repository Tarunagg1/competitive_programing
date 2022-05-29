// Longest Path in a matrix 
// Hard Accuracy: 60.72% Submissions: 1632 Points: 8
// Given a n*m matrix, find the maximum length path (starting from any cell) such that all cells along the path are in strictly increasing order.

// We can move in 4 directions from a given cell (i, j), i.e., we can move to (i+1, j) or (i, j+1) or (i-1, j) or (i, j-1).
 

// Example 1:

// Input: matrix = {{1,2,9},{5,3,8},{4,6,7}}
// Output: 7
// Explanation: The longest increasing path is
// {1,2,3,6,7,8,9}.
// Example 2:

// Input: matrix = {{3,4,5},{3,2,6},{2,2,1}}
// Output: 4
// Explanation: The longest increasing path is
// {3,4,5,6}.
 

// Your Task:
// You don't need to read or print anyhting. Your task is to complete the function longestIncreasingPath() which takes matrix as input parameter and returns the length of the lonest increasing path.

// Expected Time Complexity: O(n*m)
// Expected Space Comeplxity: O(n*m)
 

// Constraints:
// 1 <= n, m <= 100
// 1 <= matrix[i][j] <= 104

// View Bookmarked Problems
// Topic Tags




class Solution {
public:
    int ROW,COL;

    int dfs(int i,int j,vector<vector<int>>& m,vector<vector<int>>& dp){
        vector<pair<int,int>>dr={{-1,0},{0,-1},{0,1},{1,0}};
        if(dp[i][j])return dp[i][j];
        int count=1;
        for(auto r:dr){
            int x=i+r.first, y=j+r.second;
            if(x<0||x>ROW-1||y<0||y>COL-1)continue;
            if(m[i][j]<m[x][y])
                count=max(count,dfs(x,y,m,dp)+1);
        }
        dp[i][j]=count;
        return count;
    }
    
    int longestIncreasingPath(vector<vector<int>>& m) {
        // Code here
         ROW=m.size(),COL=m[0].size();
        vector<vector<int>>dp(ROW,vector<int>(COL));
        int ans=0;
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                ans=max(dfs(i,j,m,dp),ans);
            }
        }
        return ans;
    }
};





































