// Subarray with given sum
// EasyAccuracy: 16.5%Submissions: 1.3MPoints: 2
// Applying for Jobs, Now Easier Than Today's Problem! Explore Now

// Given an unsorted array A of size N that contains only positive integers, find a continuous sub-array that adds to a given number S and return the left and right index(1-based indexing) of that subarray.

// In case of multiple subarrays, return the subarray indexes which come first on moving from left to right.

// Note:- You have to return an ArrayList consisting of two elements left and right. In case no such subarray exists return an array consisting of element -1.

// Example 1:

// Input:
// N = 5, S = 12
// A[] = {1,2,3,7,5}
// Output: 2 4
// Explanation: The sum of elements 
// from 2nd position to 4th position 
// is 12.
// Example 2:

// Input:
// N = 10, S = 15
// A[] = {1,2,3,4,5,6,7,8,9,10}
// Output: 1 5
// Explanation: The sum of elements 
// from 1st position to 5th position
// is 15.
// Your Task:
// You don't need to read input or print anything. The task is to complete the function subarraySum() which takes arr, N, and S as input parameters and returns an ArrayList containing the starting and ending positions of the first such occurring subarray from the left where sum equals to S. The two indexes in the array should be according to 1-based indexing. If no such subarray is found, return an array consisting of only one element that is -1.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 105
// 1 <= Ai <= 109
// 0<= S <= 109

// Company Tags


class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
           if(s==0) return {-1};
        long long int l=0,r=0,sum=0;
        while(r<n || l<n){
            if(sum==s) return {l+1,r};
            else if(sum<s && r<n) {sum+=arr[r];r++;}
            else {sum-=arr[l];l++;}
            if(l>r) break;
        }
        
        return {-1};
    }
};























