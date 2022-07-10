// Find all possible paths from top to bottom 
// Easy Accuracy: 85.87% Submissions: 2890 Points: 2
// Given a N x M grid. Find All possible paths from top left to bottom right.From each cell you can either move only to right or down.

// Example 1:

// Input: 1 2 3
//        4 5 6
// Output: 1 4 5 6
//         1 2 5 6 
//         1 2 3 6
// Explanation: We can see that there are 3 
// paths from the cell (0,0) to (1,2).
// Example 2:

// Input: 1 2
//        3 4
// Output: 1 2 4
//         1 3 4
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findAllPossiblePaths() which takes two integers n,m and grid[][]  as input parameters and returns all possible paths from the top left cell to bottom right cell in a 2d array.

// Expected Time Complexity: O(2^N*M)
// Expected Auxiliary Space: O(N)


// Constraints:
// 1 <= n,m <= 10 
// 1 <= grid[i][j] <= n*m
// n * m < 20
 

// View Bookmarked Problems
// Topic Tags


class Solution
{
public:
vector<vector<int>> ans;

    void paths(int i, int j, int n, int m, vector<vector<int>> &v, vector<int> &cur) {

        if(i == n-1 && j == m-1) {

            cur.push_back(v[i][j]); 

            ans.push_back(cur); 

        }

      if(i!=n-1 or j!=m-1) 

        cur.push_back(v[i][j]);

        

        if(i+1 < n){

            paths(i+1,j,n,m,v,cur);

        }

        

        if(j+1 < m) {

            paths(i,j+1,n,m,v,cur);

        }

    

        cur.pop_back();
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
         vector<int> cur;

        paths(0,0,grid.size(), grid[0].size(),grid,cur);

        return ans;
    }
};






















