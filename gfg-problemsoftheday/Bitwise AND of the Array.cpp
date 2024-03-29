// Bitwise AND of the Array 
// Medium Accuracy: 64.53% Submissions: 994 Points: 4
// Given an array A[ ] of N integers and an integer X. In one operation, you can change the ith element of the array to any integer value where 1 ≤ i ≤ N. Calculate minimum number of such operations required such that the bitwise AND of all the elements of the array is strictly greater than X.

// Example 1:

// Input:
// N = 4, X = 2
// A[] = {3, 1, 2, 7}
// Output: 
// 2
// Explanation: 
// After performing two operations:
// Modified array: {3, 3, 11, 7} 
// Now, Bitwise AND of all the elements
// is 3 & 3 & 11 & 7 = 3 
// Example 2:

// Input:
// N = 3, X = 1
// A[] = {2, 2, 2}
// Output: 
// 0
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function count( ) which takes N, A[ ] and X as input parameters and returns the minimum number of operations required.

// Expected Time Complexity: O(N * Log(max(A[ ])))
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ A[i] ≤ 109
// 1 ≤ X ≤ 109

// View Bookmarked Problems

class Solution{
    public:
    int count(int N, vector<int> A,int X)
    {
        // code here
        int ans = N;
        int mask = 0;
        
        for(int i=30;i>=0;i--){
            int bitVal = ((1 << i) & X);
            if(bitVal > 0){
                mask ^= (1<<i);
            }
            else{
                int count = 0;
                int greaterMask = (mask ^ (1 << i));
                for(int elem : A){
                    int val = (greaterMask & elem);
                    if(val != greaterMask){
                        count++;
                    }
                }
                ans = min(ans, count);
            }
        }
        return ans;
    }
};























