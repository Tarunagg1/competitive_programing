// Maximum Product of Increasing Subsequence of Size 3 
// Medium Accuracy: 32.08% Submissions: 2389 Points: 4
// Given a sequence of non-negative integers, find the subsequence of length 3 having maximum product, with the elements of the subsequence being in increasing order.

 

// Example 1:

// â€‹Input:
// n = 8
// arr[ ] = {6, 7, 8, 1, 2, 3, 9, 10}
// Output:
// 8 9 10
// Explanation: 3 increasing elements of 
// the given arrays are 8,9 and 10 which 
// forms the subsequence of size 3 with 
// maximum product.

// â€‹Example 2:

// Input:
// n = 4
// arr[ ] = {3, 4, 2, 1} 
// Output:
// Not Present 
 

// Your Task:
// This is a function problem. The input is already taken care of by the driver code. You only need to complete the function maxProductSubsequence() that takes an array arr, sizeOfArray n, and return the subsequence of size 3 having the maximum product, numbers of subsequence being in increasing order. If no such sequence exists, return "-1". The driver code takes care of the printing.


// Expected Time Complexity: O(N*LOG(N)).
// Expected Auxiliary Space: O(N).



// Constraints:
// 1 <= N <= 105
// 1 <= Arr[i] <= 105



class Solution{
  public:
    vector<int> maxProductSubsequence(int *arr , int n) 
    { 
        // Complete the function
        
         set<int> s;
        long long ans = -1;
        vector<int> res,suff;
        for(int i=0;i<n;i++){
            suff.push_back(arr[i]);
        }
        for(int i=n-1;i>=0;i--){
            suff[i] = arr[i];
            if(i+1<n){
                suff[i] = max(suff[i],suff[i+1]);
            }
        }
        for(int i=1;i<n-1;i++){
            s.insert(arr[i-1]);
            auto itr = s.lower_bound(arr[i]);
            if(itr!=s.begin() and arr[i]<suff[i+1]){
                itr--;
                long long curr = arr[i]*1LL*(*itr)*1LL*(suff[i+1]);
                if(curr>ans){
                    ans = curr;
                    res = {*itr,arr[i],suff[i+1]};
                }
            }
        }
        if(res.empty()){
            res.push_back(ans);
        }
        return res;
    } 

};




































