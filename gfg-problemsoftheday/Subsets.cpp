// Subsets 
// Medium Accuracy: 35.37% Submissions: 7077 Points: 4
// Given a set of positive integers, find all its subsets.

// Example 1 :

// Input : 
// array = {1, 2, 3}
// Output :
// // this space denotes null element. 
// 1
// 1 2
// 1 2 3
// 1 3
// 2
// 2 3
// 3
// Explanation: 
// The following are the subsets 
// of the array {1, 2, 3}.
// Example 2 :

// Input :
// array = {1, 2}
// Output :

// 1 
// 1 2
// 2
// Explanation :
// The following are the 
// subsets of {1, 2}.
// Your task :
// You don't have to read input or print anything. Your task is to complete the function subsets() which takes the array of integers as input and returns the list of list containing the subsets of the given set of numbers in lexicographical order.
 
// Expected Time Complexity : O(2^n)))
// Expected Auxiliary Space : O(2^n*length of each subset)
 
// Constraints :
// 1 <= n <= 20
// 1 <= arr[i] <=10
// View Bookmarked Problems

class Solution
{
    public:
     vector<vector<int>> ans;
    void gen_sub(vector<int> A, int i, vector<int> temp){
         if(i == A.size()){
             ans.push_back(temp);
             return;
         }
         temp.push_back(A[i]);
         gen_sub(A,i+1,temp);
         temp.pop_back();
         gen_sub(A,i+1,temp);
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
         vector<int> temp;
         gen_sub(A,0,temp);
         sort(ans.begin(),ans.end());
         return ans;
    }
};
























