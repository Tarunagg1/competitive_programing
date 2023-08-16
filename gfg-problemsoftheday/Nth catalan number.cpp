// Nth catalan number
// MediumAccuracy: 31.06%Submissions: 77K+Points: 4
// Applying for Jobs, Now Easier Than Today's Problem! Explore Now

// Given a number N. The task is to find the Nth catalan number.
// The first few Catalan numbers for N = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …

// Catalan Number for N is equal to the number of expressions containing N pairs of paranthesis that are correct matched, i.e., for each of the N '(' there exist N ')' on there right and vice versa.

// Since answer can be huge return answer modulo 1e9+7.

// Note: Positions start from 0 as shown above.

// Example 1:

// Input:
// N = 5
// Output: 42
// Example 2:

// Input:
// N = 4
// Output: 14
// Your Task:
// Complete findCatalan() function that takes n as an argument and returns the Nth Catalan number. The output is printed by the driver code.

// Expected Time Complexity: O(N^2).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 103


class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
            vector<int>dp1(n+1,1),dp2(n+1,1);
       dp2[0]=0;
       for(int i=1;i<=n;++i){
           for(int j=1;j<=n;++j){
               if(i<j){
                   dp2[j] = (dp1[j] + dp2[j-1])%1000000007;
               }
               else{
                   dp2[j] = dp1[j]%1000000007;
               }
           }
           dp1 = dp2;
       }
       return dp2[n];
    }
};




















