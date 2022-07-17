// Binary Matrix with at most K 1s
// MediumAccuracy: 31.44%Submissions: 659Points: 4
// Given a binary matrix M with R rows and C columns, where each element of the matrix will be 0 or 1. Find the largest square that can be formed with center (i, j) and contains atmost K 1’s. There are Q queries, a single query has two integers denoting the centre (i,j) of the square.

 

// Example 1:

// Input:
// R = 4, C = 5
// M = {{1, 0, 1, 0, 0} 
//      {1, 0, 1, 1, 1} 
//      {1, 1, 1, 1, 1} 
//      {1, 0, 0, 1, 0}}
// K = 9, Q = 1
// q_i[] = {1}
// q_j[] = {2}
// Output:
// 3
// Explanation:
// Maximum length square with center
// at (1, 2) that can be formed is of
// 3 length from (0, 1) to (2, 4).
// Example 2:
// Input:
// R = 3, C = 3
// M = {{1, 1, 1} 
//      {1, 1, 1} 
//      {1, 1, 1}}
// K = 9, Q = 2
// q_i[] = {1, 2}
// q_j[] = {1, 2}
// Output :
// 3 1

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function largestSquare() which takes 2 integers R, and C followed by a list of lists M denoting the binary matrix and then three integers i,j, and K as input and returns a list of integers denting the largest Square possible for each query.


// Expected Time Complexity: O(R*C + Q*log(MIN_DIST)), where MIN_DIST is the minimum distance of the center from the edges of the matrix where MIN_DIST is the minimum distance of the center from the edges of the matrix.
// Expected Auxiliary Space: O(R*C)


// Constraints:
// 1 ≤ R,C ≤ 500
// 1 ≤ Q ≤ 104
// 0 ≤ K ≤ R*C
// 0 ≤ i < R
// 0 ≤ j < C

// View Bookmarked Problems 



class Solution {
  public:
    vector<int> largestSquare(vector<vector<int>> m, int r, int c, int k, int q, int q_i[], int q_j[]) {
    vector< vector<int> > no(r, vector<int>(c)) ;
    no[0][0] = m[0][0] ;
    for(int i=1 ; i<r ; i++)
        no[i][0] = no[i-1][0] + m[i][0] ;
    for(int j=1 ; j<c ; j++)
        no[0][j] = no[0][j-1] + m[0][j] ;
    
    for(int i=1 ; i<r ; i++)
        for(int j=1 ; j<c ; j++)
            no[i][j] = m[i][j] + no[i-1][j] + no[i][j-1] - no[i-1][j-1] ;
    vector<int> ans(q) ;
    for(int i=0 ; i<q ; i++){
        int sr = q_i[i], sc = q_j[i] ;
        for(int t = 0 ; sr+t < r && sr-t >= 0 && sc+t < c && sc-t >= 0 ; t++){
            int total = no[sr+t][sc+t] ;
            total -= (sc-t-1>=0 ? no[sr+t][sc-t-1] : 0) ;
            total -= (sr-t-1>=0 ? no[sr-t-1][sc+t] : 0) ;
            total += (sc-t-1>=0 && sr-t-1>=0 ? no[sr-t-1][sc-t-1] : 0) ;
            if(total <= k )
                ans[i] = 2*t+1 ;
            else
                break ;
        }
    }
    return ans ;
}
};





































