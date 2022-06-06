// Count pairs in array divisible by K 
// Medium Accuracy: 46.06% Submissions: 6067 Points: 4
// Given an array A[] and positive integer K, the task is to count total number of pairs in the array whose sum is divisible by K.

// Example 1:

// Input : 
// A[] = {2, 2, 1, 7, 5, 3}, K = 4
// Output : 5
// Explanation : 
// There are five pairs possible whose sum
// is divisible by '4' i.e., (2, 2), 
// (1, 7), (7, 5), (1, 3) and (5, 3)
// Example 2:

// Input : 
// A[] = {5, 9, 36, 74, 52, 31, 42}, K = 3
// Output : 7 
// Explanation : 
// There are seven pairs whose sum is divisible by 3, 
// i.e, (9, 36), (9,42), (74, 52), (36, 42), (74, 31), 
// (31, 5) and (5, 52).
// Your task :
// You don't have to read input or print anything. Your task is to complete the function countKdivPairs() which takes the array, it's size and an integer K as input and returns the count of pairs whose sum is divisible by K.
 
// Expected Time Complexity : O(n)
// Expected Auxiliary Space : O(k)
 
// Constraints :
// 1 <= N <=10^6
// 1 <= A[i] <= 10^6
// 1 <= K <= 100
// View Bookmarked Problems


#define ll long long
class Solution
{
    public:
    long long countKdivPairs(int a[], int n, int k)
    {
        //code here
         vector<ll> cnt(k,0);
        for(int i=0;i<n;i++) {
            cnt[a[i]%k]++;
        }
        ll ans=(cnt[0]*(cnt[0]-1))/2;
        for(int i=1;i<=k/2 and 2*i!=k;i++) {
            ans+=(cnt[i]*cnt[k-i]);
        }
        if(k%2==0) 
            ans+=(cnt[k/2]*(cnt[k/2]-1))/2;
        return ans;
    }
};













































