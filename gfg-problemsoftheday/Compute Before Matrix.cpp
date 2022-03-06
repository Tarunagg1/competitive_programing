// Compute Before Matrix 
// Medium Accuracy: 94.57% Submissions: 1112 Points: 4
// For a given 2D Matrix before, the corresponding cell (x, y) of the after matrix is calculated as follows: 

// res = 0;
// for(i = 0; i <= x; i++){
//     for( j = 0; j <= y; j++){              
//         res += before(i,j);
//     }
// }
// after(x,y) = res;
// Given an N*M 2D-Matrix after, your task is to find the corresponding before matrix for the given matrix.

 

// Example 1:

// Input:
// N = 2, M = 3
// after[][] = {{1, 3, 6},
//             {3, 7, 11}}
// Output:
// 1 2 3
// 2 2 1
// Explanation:
// The before matrix for the given after matrix
// matrix is {{1, 2, 3}, {2, 2, 1}}.
// Example 2:

// Input: 
// N = 1, M = 3
// after[][] = {{1, 3, 5}}
// Output:
// 1 2 2
// Explanation: 
// The before matrix for the given after matrix
// is {{1, 2, 2}}.
// Your Task:
// Complete the function computeBeforeMatrix() which takes the integers N, M, and the 2D Matrix after as the input parameters, and returns the before matrix of the given after matrix.

// Expected Time Complexity: O(N*M)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N, M, after[i][j]  ≤  109

// View Bookmarked Problems

class Solution{
    public:
    vector<vector<int>> computeBeforeMatrix(int N, int M, vector<vector<int>> after){
        // Code here
        vector<vector<int>> ans(N,vector<int>(M,0));
        
        ans[0][0] = after[0][0];
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(i == 0 && j==0) continue;
                
                if(i == 0) {
                    ans[i][j] = after[i][j] - after[i][j-1];
                }
                else if(j == 0){
                    ans[i][j] = after[i][j] - after[i-1][j];
                }else{
                    ans[i][j] = after[i][j] + after[i-1][j-1] - after[i][j-1] - after[i-1][j];
                }
            }
        }
        return ans;
    }
};
























