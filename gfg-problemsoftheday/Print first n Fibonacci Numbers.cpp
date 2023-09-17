// Print first n Fibonacci Numbers
// BasicAccuracy: 29.92%Submissions: 173K+Points: 1
// Learn Google Cloud with Curated Lab Assignments. Register, Earn Rewards, Get noticed by experts at Google & Land your Dream Job! 

// Given a number N, find the first N Fibonacci numbers. The first two number of the series are 1 and 1.

// Example 1:

// Input:
// N = 5
// Output: 1 1 2 3 5
// Example 2:

// Input:
// N = 7
// Output: 1 1 2 3 5 8 13
// Your Task:
// Your task is to complete printFibb() which takes single argument N and returns a list of first N Fibonacci numbers.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).
// Note: This space is used to store and return the answer for printing purpose.

// Constraints:
// 1<= N <=84



class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        //code here
         if(n == 1 ){
             vector<long long > ans;
             ans.push_back(1);
             return ans;
         }else if(n== 0){
              vector<long long > ans;
              return ans;
         }
         
         
         vector<long long > ans;
         ans.push_back(1);
         ans.push_back(1);
         
         for(int i = 2 ; i < n ; i++){
             long long val = ans[i-1] + ans[i-2];
             ans.push_back(val);
         }
         
         
         return ans;
    }
};






















