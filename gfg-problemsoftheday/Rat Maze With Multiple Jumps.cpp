// Rat Maze With Multiple Jumps 
// Medium Accuracy: 41.1% Submissions: 2320 Points: 4
// A Maze is given as n*n matrix of blocks where source block is the upper left most block i.e., matrix[0][0] and destination block is lower rightmost block i.e., matrix[n-1][n-1]. A rat starts from source and has to reach the destination. The rat can move in only two directions: first forward if possible or down. If multiple solutions exist, the shortest earliest hop will be accepted. For the same hop distance at any point, forward will be preferred over downward. In the maze matrix, 0 means the block is the dead end and non-zero number means the block can be used in the path from source to destination. The non-zero value of mat[i][j] indicates number of maximum jumps rat can make from cell mat[i][j]. In this variation, Rat is allowed to jump multiple steps at a time instead of 1. Find a matrix which describes the position the rat to reach at the destination.
 

// Example:

// Input: {{2,1,0,0},{3,0,0,1},{0,1,0,1},
// {0,0,0,1}}
// Output: {{1,0,0,0},{1,0,0,1},{0,0,0,1},
// {0,0,0,1}}
// Explanation: Rat started with matrix[0][0] and 
// can jump up to 2 steps right/down. First check 
// matrix[0][1] as it is 1, next check 
// matrix[0][2] ,this won't lead to the solution. 
// Then check matrix[1][0], as this is 3(non-zero)
// ,so we can make 3 jumps to reach matrix[1][3]. 
// From matrix[1][3] we can move downwards taking 
// 1 jump each time to reach destination at 
// matrix[3][3].
// Example 2:

// Input: {{2,1,0,0},{2,0,0,1},{0,1,0,1},
// {0,0,0,1}}
// Output: {{-1}}
// Explanation: As no path exists so, -1.
 

// Your Task:
// You don't need to read or print anyhting, Your task is to complete the function ShortestDistance() which takes the matrix as input parameter and returns a matrix of size n if path exists otherwise returns a matrix of 1x1 which contains -1. In output matrix, 1 at (i, j) represents the cell is taken into the path otherwise 0 if any path exists.
 

// Expected Time Complexity: O(n*n*k) where k is max(matrix[i][j])
// Expected Space Complexity: O(1)
 

// Constraints:
// 1 <= n <= 50
// 1 <= matrix[i][j] <= 20

// View Bookmarked Problems



class Solution {
public:
bool fun(vector<vector<int>>&mat,vector<vector<int>>&v,int i,int j,int n){
          if(i==n-1 && j==n-1){
              v[i][j]=1;
              return true;
          }
          if(i>=n ||j>=n || i<0 || j<0 || mat[i][j]==0) return false;
          
          v[i][j]=1;
          for(int k=1;k<=mat[i][j];k++){
              if(fun(mat,v,i,j+k,n)) return true;
              if(fun(mat,v,i+k,j,n)) return true;
          }
          v[i][j]=0;
          
          return false;
      }
	vector<vector<int>> ShortestDistance(vector<vector<int>>&mat){
	   // Code here
	   
	     int n=mat.size();
   vector<vector<int>>v(n,vector<int>(n,0));
   bool x=fun(mat,v,0,0,n);
   if(x==false) return {{-1}};
   
   else return v;
	   
	}

};























