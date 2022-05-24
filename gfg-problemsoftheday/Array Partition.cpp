// Array Partition 
// Hard Accuracy: 72.16% Submissions: 528 Points: 8
// Given an array of N integers, you have to find if it is possible to partition the array with following rules:

// Each element should belong to exactly one partition.
// Each partition should have atleast K elements.
// Absolute difference between any pair of elements in the same partition should not exceed M.
// Example 1:

// Input:
// N = 5
// K = 2
// M = 3
// A[] = {8, 3, 9, 1, 2}
// Output:
// YES
// Explanation:
// We can partition the array into two 
// partitions: {8, 9} and {3, 1, 2} such that
// all rules are satisfied.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function partitionArray() which takes the number of elements N, integer K, integer M and array A[ ] as input parameters and returns true if we can partition the array such that all rules are satisfied, else returns false.

// Expected Time Complexity: O(N * Log(N))
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 2*105
// 1 ≤ K ≤ N
// 1 ≤ M ≤ 109
// 1 ≤ A[i] ≤ 109

// View Bookmarked Problems
// Topic Tags


class Solution{
    public:
    bool partitionArray(int N, int K, int M, vector<int> &A){
        // code here
            bool dp[N+1] = {0};
       dp[0] = 1;
       sort(A.begin(), A.end());
       for(int i=K; i<=N; i++){
           int l = lower_bound(A.begin(), A.end(), A[i-1] - M) - A.begin();
           int h = i - K;
           for(int j=l; j<=h; j++){
               dp[i] |= dp[j];
               if (dp[i])
                   break;
           }
       }
       return dp[N];
    }
};






















