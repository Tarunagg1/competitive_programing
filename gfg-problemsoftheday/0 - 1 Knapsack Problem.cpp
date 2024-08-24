// 0 - 1 Knapsack Problem
// Difficulty: MediumAccuracy: 31.76%Submissions: 423K+Points: 4
// You are given weights and values of items, and put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
// In other words, given two integer arrays val and wt which represent values and weights associated with items respectively. Also given an integer W which represents knapsack capacity, find out the maximum sum values subset of val[] such that the sum of the weights of the corresponding subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don't pick it (0-1 property).

// Examples :

// Input: W = 4, val[] = {1,2,3}, wt[] = {4,5,1}
// Output: 3
// Explanation: Choose the last item that weighs 1 unit and holds a value of 3. 
// Input: W = 3, val[] = {1,2,3}, wt[] = {4,5,6}
// Output: 0
// Explanation: Every item has a weight exceeding the knapsack's capacity (3).
// Expected Time Complexity: O(N*W).
// Expected Auxiliary Space: O(N*W)

// Constraints:
// 2 ≤ N ≤ 1000
// 1 ≤ W ≤ 1000
// 1 ≤ wt[i] ≤ 1000
// 1 ≤ val[i] ≤ 1000

// Seen this question in a real interview before ?




class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int solve(int W,vector<int>& wt,vector<int>& val,int sum,int& n,int i){
        if(i>=n){
            return sum;
        }
        if(W-wt[i]>=0){
            int taken = solve(W-wt[i],wt,val,sum+val[i],n,i+1);
            int notTaken = solve(W,wt,val,sum,n,i+1);
            return max(taken,notTaken);
        }
        else{
            int notTaken = solve(W,wt,val,sum,n,i+1);
            return max(sum,notTaken);
        }
    }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        int sum = 0;
        int n = wt.size();
        int taken = solve(W,wt,val,sum,n,0);
        int notTaken = solve(W,wt,val,sum,n,1);
        return max(taken,notTaken);
    }
};















