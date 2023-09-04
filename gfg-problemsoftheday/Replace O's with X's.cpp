// Replace O's with X's
// MediumAccuracy: 34.0%Submissions: 56K+Points: 4
// Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O' with 'X' that are surrounded by 'X'.

// A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

// Example 1:

// Input: 
// n = 5, m = 4
// mat = {{'X', 'X', 'X', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'O', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Output: 
// ans = {{'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Explanation: 
// Following the rule the above matrix is the resultant matrix. 
// Example 2:

 

// Input: 
// n = 5, m = 4
// mat = {{'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'O', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Output: 
// ans = {{'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'O', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Explanation: 
// Following the rule the above matrix is the resultant matrix.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function fill() which takes N, M and mat as input parameters ad returns a 2D array representing the resultant matrix.

// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n*m)

// Constraints:
// 1 ≤ n, m ≤ 500



class Solution{
public:
        int r[4]={-1, 0, 1, 0};
    int c[4]={0, 1, 0, -1};
    void dfs(int i, int j, int n, int m, vector<vector<char>>& mat, vector<vector<bool>>& vis){
       vis[i][j]=true;
        for(int k=0; k<4; ++k){
            int ni=i+r[k];
            int nj=j+c[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && mat[ni][nj]=='O' && !vis[ni][nj]){
                dfs(ni, nj, n, m, mat, vis);
            }
        }
        
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if((i==0 || i==n-1 || j==0 || j==m-1) && mat[i][j]=='O' && !vis[i][j]){
                    dfs(i, j,n, m, mat, vis);
                }
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(mat[i][j]=='O' && !vis[i][j]){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};



























