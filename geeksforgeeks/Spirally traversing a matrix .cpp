/*

Given a matrix of size R*C. Traverse the matrix in spiral form.

Example 1:

Input:
R = 4, C = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
Explanation:

Example 2:

Input:
R = 3, C = 4  
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12}}
Output: 
1 2 3 4 8 12 11 10 9 5 6 7
Explanation:
Applying same technique as shown above, 
output for the 2nd testcase will be 
1 2 3 4 8 12 11 10 9 5 6 7.

Your Task:
You dont need to read input or print anything. Complete the function spirallyTraverse() that takes matrix, R and C as input parameters and returns a list of integers denoting the spiral traversal of matrix. 

Expected Time Complexity: O(R*C)
Expected Auxiliary Space: O(R*C)

Constraints:
1 <= R, C <= 100
0 <= matrixi <= 100

*/

 vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> res;
        int top = 0,bottom = r-1, left = 0, right = c-1;
        
        while(top <= bottom && left<= right){
            
            for(int i=left; i<=right; i++)
                res.push_back(matrix[top][i]);
            top++;
            
            for(int i=top; i<=bottom; i++)
                res.push_back(matrix[i][right]);
            right--;
                
            if(top<=bottom){
                for(int i=right; i>=left; i--)
                    res.push_back(matrix[bottom][i]);
                bottom--;
            }
            
            if(left<=right){
                for(int i=bottom; i>=top; i--)
                    res.push_back(matrix[i][left]);
                left++;
            }
            
        }
        return res;
    }















