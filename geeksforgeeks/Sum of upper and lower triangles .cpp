// Sum of upper and lower triangles 
// Basic Accuracy: 62.43% Submissions: 12029 Points: 1
// Given a square matrix of size N*N, print the sum of upper and lower triangular elements. Upper Triangle consists of elements on the diagonal and above it. The lower triangle consists of elements on the diagonal and below it. 

// Example 1:

// Input:
// N = 3 
// mat[][] = {{6, 5, 4},
//            {1, 2, 5}
//            {7, 9, 7}}
// Output: 29 32
// Explanation:
// The given matrix is
// 6 5 4
// 1 2 5
// 7 9 7
// The elements of upper triangle are
// 6 5 4
//   2 5
//     7
// Sum of these elements is 6+5+4+2+5+7=29
// The elements of lower triangle are
// 6
// 1 2
// 7 9 7
// Sum of these elements is 6+1+2+7+9+7= 32.
// Example 2:

// Input:
// N = 2
// mat[][] = {{1, 2},
//            {3, 4}}
// Output: 7 8
// Explanation:
// Upper triangular matrix:
// 1 2
//   4
// Sum of these elements are 7.
// Lower triangular matrix:
// 1
// 3 4
// Sum of these elements are 8.

// Your Task:
// You don't need to read input or print anything. Complete the function sumTriangles() that takes matrix and its size N as input parameters and returns the list of integers containing the sum of upper and lower triangle.

// Expected Time Complexity: O(N * N)
// Expected Auxiliary Space: O(1)

// Constraints: 
// 1 <= N <= 100
// 1 <= matrix[i][j] <= 100

// View Bookmarked Problems


class Solution
{   
   public:
   //Function to return sum of upper and lower triangles of a matrix.
   vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
   {
       // code here
       vector<int> l;
       int sumT=0;
       int sumB=0;
       
       for(int i=0;i<n;i++)
       {
           int j=0+i;
           for(j;j<n;j++)
           {
               sumT+=matrix[i][j];
           }
       }
       
       for(int i=n-1;i>=0;i--)
       {
           int j=0+i;
           for(j;j>=0;j--)
           {
               sumB+=matrix[i][j];
           }
       }
       l.push_back(sumT);
       l.push_back(sumB);
       return l;
       
   }
};














