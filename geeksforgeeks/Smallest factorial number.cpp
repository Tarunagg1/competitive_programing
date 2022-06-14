// Smallest factorial number 
// Easy Accuracy: 50.44% Submissions: 16492 Points: 2
// Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.

// Example 1:

// Input:
// n = 1
// Output: 5
// Explanation : 5! = 120 which has at
// least 1 trailing 0.
// Example 2:

// Input:
// n = 6
// Output: 25
// Explanation : 25! has at least
// 6 trailing 0.

// User Task:
// Complete the function findNum() which takes an integer N as input parameters, and returns the answer.

// Expected Time Complexity: O(log2 N * log5 N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= n <= 104

// View Bookmarked Problems
// Topic Tags


class Solution
{
    public:
    int zeroes(int mid){
      int res=0;
      for(int i=5;i<=mid;i=i*5){
          res=res+mid/i;
      }
         return res;
       }
    
    
        int findNum(int n)
        {
        //complete the function here
            int high=n*5,low=1,mid,ans=-1;
           while(low<=high){
               mid=low+((high-low)/2);
               if(zeroes(mid)>=n){
                   ans=mid;
                   high=mid-1;
               }else{
                   low=mid+1;
               }
           }
           return ans;
        }
};































