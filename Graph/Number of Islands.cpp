// 200. Number of Islands
// Medium

// 11632

// 296

// Add to List

// Share
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.
// Accepted
// 1,355,578
// Submissions
// 2,576,344



class Solution {
public:
        
    bool isValid(int i,int j, int n, int m, vector<vector<char>>& grid){
        if(i >= 0 && i<n && j>=0 && j<m && grid[i][j] == '1')
            return true;
        return false;
    }

    void numsIland(int i,int j, int n, int m, vector<vector<char>>& grid){
        grid[i][j] = '0';
        
        if(isValid(i+1,j,n,m,grid)){
            numsIland(i+1,j,n,m,grid);
        }
        if(isValid(i-1,j,n,m,grid)){
            numsIland(i-1,j,n,m,grid);
        }
        if(isValid(i,j+1,n,m,grid)){
            numsIland(i,j+1,n,m,grid);
        }
        if(isValid(i,j-1,n,m,grid)){
            numsIland(i,j-1,n,m,grid);
        }
        
    }
       
    
    int numIslands(vector<vector<char>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
        
      int ans = 0; 
    
      for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
              if(grid[i][j] == '1'){
                  ans++;
                  numsIland(i,j,n,m,grid);
              }
          }
      }
    
      return ans;
    }
};















