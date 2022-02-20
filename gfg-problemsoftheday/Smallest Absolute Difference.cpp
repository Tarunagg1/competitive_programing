// Smallest Absolute Difference 
// Medium Accuracy: 61.84% Submissions: 4074 Points: 4
// Given an array of size N containing positive integers n and a number k,The absolute difference between values at indices i and j is |a[i] – a[j]|. There are n*(n-1)/2 such pairs and you have to print the kth smallest absolute difference among all these pairs.
 

// Example 1:

// Input : 
// N = 4
// A[] = {1, 2, 3, 4}
// k = 3
// Output : 
// 1 
// Explanation :
// The possible absolute differences are :
// {1, 2, 3, 1, 2, 1}.
// The 3rd smallest value among these is 1.
 
// Example 2:
// Input : 
// N = 2
// A[] = {10, 10}
// k = 1
// Output :
// 0

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function kthDiff() which takes the array A[], its size N and an integer k as inputs and returns the kth smallest absolute difference among all these pairs.

 

// Expected Time Complexity: O( N. (Log(N))2 )
// Expected Auxiliary Space: O(Log(N))

 

// Constraints:
// 1<=N<=105
// 1<=a[i]<=105
// 1 <= k <= n*(n-1)/2



int kthDiff(int arr[], int n, int k)
{
    sort(arr,arr+n);
    
    int ans = arr[n-1]-arr[0];
    
    int smallest = arr[0]+k;
    int largest = arr[n-1]-k;
    
    int mi,ma;
    
    for(int i=0; i<n-1; i++){
        mi = min(smallest,arr[i+1]-k);
        ma = max(largest,arr[i]+k);
        
        if(mi < 0) continue;
        
        ans = min(ans,ma-mi);
    }
    return ans;
}





















































