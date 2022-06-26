// Equivalent Sub-Arrays 
// Medium Accuracy: 60.59% Submissions: 2652 Points: 4
// Given an array arr[] of n integers. Count the total number of sub-array having total distinct elements same as that of total distinct elements of the original array.

 

// Example 1:

// Input:
// N=5
// arr[] = {2, 1, 3, 2, 3} 
// Output: 5
// Explanation:
// Total distinct elements in array is 3
// Total sub-arrays that satisfy the condition
// are:
// Subarray from index 0 to 2
// Subarray from index 0 to 3
// Subarray from index 0 to 4
// Subarray from index 1 to 3
// Subarray from index 1 to 4

// Example 2:

// Input:
// N=5
// arr[] = {2, 4, 4, 2, 4} 
// Output: 9

// Your Task:
// Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function countDistinctSubarray() that takes array arr and integer n  as parameters and returns the desired result.

 

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

 

// Constraints:
// 1 ≤ N ≤ 104

 

// View Bookmarked Problems
// Topic Tags






class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        int cnt = 0 ;
        map<int,int> mp1 ;
        for(int i = 0 ; i < n ; i++ )
        {
            if( mp1[arr[i]] == 0 )
            {
                cnt++ ;
                mp1[arr[i]]++ ;
            }
        }
        
        map<int,int> mp2 ;
        
        int curCnt = 1 , ans = 0 ;
        int i = 0, j = 0;
        
        mp2[arr[0]]++ ;
        
        while( j < n )
        {
            if( curCnt == cnt )
            {
                ans += (n - j ) ;
                
                mp2[arr[i]]-- ;
                
                if( mp2[arr[i]] == 0 ) curCnt -= 1 ;
                i++ ;
            }
            else 
            {
                j++ ;
                
                if( j >= n ) break ;
                
                mp2[arr[j]]++ ;
                if( mp2[arr[j]] == 1 ) curCnt += 1 ;
            }
        }
        return ans ;
    }
};




























