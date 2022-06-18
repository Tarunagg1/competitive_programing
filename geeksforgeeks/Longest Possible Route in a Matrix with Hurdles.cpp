// Longest Possible Route in a Matrix with Hurdles 
// Medium Accuracy: 51.18% Submissions: 1315 Points: 4
// Given an N x M matrix, with a few hurdles(denoted by 0) arbitrarily placed, calculate the length of the longest possible route possible from source(xs,ys) to a destination(xd,yd) within the matrix. We are allowed to move to only adjacent cells which are not hurdles. The route cannot contain any diagonal moves and a location once visited in a particular path cannot be visited again.If it is impossible to reach the destination from the source return -1.

 

// Example 1:

// Input:
// {xs,ys} = {0,0}
// {xd,yd} = {1,8}
// matrix = 1 1 1 1 1 1 1 1 1 1
//          1 1 0 1 1 0 1 1 0 1
//          1 1 1 1 1 1 1 1 1 1
// Output: 24
// Explanation:

 

// Example 2:

// Input: 
// {xs,ys} = {0,3}
// {xd,yd} = {2,2}
// matrix = 1 0 0 1 0
//          0 0 0 1 0
//          0 1 1 0 0
// Output: -1
// Explanation:
// We can see that it is impossible to
// reach the cell (2,2) from (0,3).
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function longestPath() which takes matrix ,source and destination as input parameters and returns an integer denoting the longest path.


// Expected Time Complexity: O(2^(N*M))
// Expected Auxiliary Space: O(N*M)


// Constraints:
// 1 <= N,M <= 10

// View Bookmarked Problems
// Topic Tags



class Solution {
public:
void solve(int i,int j,int x,int y,int n,int m,vector<vector<int>> &matrix,int cnt,int &ans)
    {
        if(i<0 || i>=n || j<0 || j>=m || matrix[i][j]==0) return;
        if(i==x && j==y)
        {
            ans=max(ans,cnt);
            return;
        }
        int a=matrix[i][j];
        matrix[i][j]=0;
        solve(i+1,j,x,y,n,m,matrix,cnt+1,ans);
        solve(i-1,j,x,y,n,m,matrix,cnt+1,ans);
        solve(i,j+1,x,y,n,m,matrix,cnt+1,ans);
        solve(i,j-1,x,y,n,m,matrix,cnt+1,ans);
        matrix[i][j]=a;
    }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
         int n=matrix.size();
        int m=matrix[0].size();
        int ans=INT_MIN,cnt=0;
        solve(xs,ys,xd,yd,n,m,matrix,cnt,ans);
        if(ans==INT_MIN) return -1;
        return ans;
    }
};








































