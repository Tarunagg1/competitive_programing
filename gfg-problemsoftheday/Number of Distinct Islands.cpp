// Number of Distinct Islands
// MediumAccuracy: 50.37%Submissions: 3128Points: 4
// Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

// Example 1:

// Input:
// grid[][] = {{1, 1, 0, 0, 0},
//             {1, 1, 0, 0, 0},
//             {0, 0, 0, 1, 1},
//             {0, 0, 0, 1, 1}}
// Output:
// 1
// Explanation:
// grid[][] = {{1, 1, 0, 0, 0}, 
//             {1, 1, 0, 0, 0}, 
//             {0, 0, 0, 1, 1}, 
//             {0, 0, 0, 1, 1}}
// Same colored islands are equal.
// We have 2 equal islands, so we 
// have only 1 distinct island.

// Example 2:

// Input:
// grid[][] = {{1, 1, 0, 1, 1},
//             {1, 0, 0, 0, 0},
//             {0, 0, 0, 0, 1},
//             {1, 1, 0, 1, 1}}
// Output:
// 3
// Explanation:
// grid[][] = {{1, 1, 0, 1, 1}, 
//             {1, 0, 0, 0, 0}, 
//             {0, 0, 0, 0, 1}, 
//             {1, 1, 0, 1, 1}}
// Same colored islands are equal.
// We have 4 islands, but 2 of them
// are equal, So we have 3 distinct islands.

// Your Task:

// You don't need to read or print anything. Your task is to complete the function countDistinctIslands() which takes the grid as an input parameter and returns the total number of distinct islands.

// Expected Time Complexity: O(n * m)
// Expected Space Complexity: O(n * m)

// Constraints:
// 1 ≤ n, m ≤ 500
// grid[i][j] == 0 or grid[i][j] == 1


class Solution {
  public:
     void dfs(int r,int c,int m,int n,vector<vector<int>>&vis,vector<vector<int>>&grid,vector<pair<int,int>>&v){
       if(r<0 || c<0 || r>=m ||c>=n || vis[r][c] || grid[r][c]==0){
           return;
       }
        v.push_back({r,c});
        vis[r][c]=1;
        dfs(r+1,c,m,n,vis,grid,v);
        dfs(r-1,c,m,n,vis,grid,v);
        dfs(r,c+1,m,n,vis,grid,v);
        dfs(r,c-1,m,n,vis,grid,v);
        
       
   }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int  count=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        set<vector<pair<int,int>>>s;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(!vis[r][c] && grid[r][c]==1){
                    vector<pair<int,int>>v;
                    dfs(r,c,m,n,vis,grid,v);
                    auto t=v[0];
                    for(auto &it:v){
                        it.first-=t.first;
                        it.second-=t.second;
                    }
                    if(s.find(v)==s.end()){
                        s.insert(v);
                    }
                   
                }
            }
        }
        return s.size();
    }
};
































