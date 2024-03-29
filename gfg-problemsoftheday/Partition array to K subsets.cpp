// Partition array to K subsets
// HardAccuracy: 43.89%Submissions: 20435Points: 8
// Given an integer array a[ ] of N elements and an integer K, the task is to check if the array a[ ] could be divided into K non-empty subsets with equal sum of elements.
// Note: All elements of this array should be part of exactly one partition.

// Example 1:

// Input: 
// N = 5
// a[] = {2,1,4,5,6}
// K = 3
// Output: 
// 1
// Explanation: we can divide above array 
// into 3 parts with equal sum as (2, 4), 
// (1, 5), (6)
// Example 2:

// Input: 
// N = 5 
// a[] = {2,1,5,5,6}
// K = 3
// Output: 
// 0
// Explanation: It is not possible to divide
// above array into 3 parts with equal sum.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isKPartitionPossible() which takes the array a[], the size of the array N, and the value of K as inputs and returns true(same as 1) if possible, otherwise false(same as 0).

// Expected Time Complexity: O(N*2N).
// Expected Auxiliary Space: O(2N).

// Constraints:
// 1 ≤ K ≤ N ≤ 10
// 1 ≤ a[i] ≤ 100




class Solution{
  public:
    bool func(int a[],int n,int k,int sum,int i,vector<int>& v){
     if(i==n){
        return 1; 
     }
     unordered_set<int> st;
     for(int j=0;j<k;j++){
         if(st.insert(v[j]).second==0) continue;
         if(v[j]+a[i]>sum) continue;

         v[j]+=a[i];
         if( func(a,n,k,sum,i+1,v) ) return 1;
         v[j]-=a[i];
     }
     return 0;
 }
   bool isKPartitionPossible(int a[], int n, int k)
   {
        sort(a,a+n,greater<int>());
        int sum=0;
        for(int i=0;i<n;i++) sum+=a[i];
        if(sum%k!=0) return 0;
        sum/=k;
        vector<int> v(k,0);
        return func(a,n,k,sum,0,v);
   }
};





























