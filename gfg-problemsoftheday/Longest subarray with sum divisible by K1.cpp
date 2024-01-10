// Longest subarray with sum divisible by K
// MediumAccuracy: 33.72%Submissions: 57K+Points: 4
// You've won Geekbits by solving daily. Now win 90% of your money-back by learning daily! 

// banner
// Given an array arr containing N integers and a positive integer K, find the length of the longest sub array with sum of the elements divisible by the given value K.

// Example 1:

// Input:
// N = 6, K = 3
// arr[] = {2, 7, 6, 1, 4, 5}
// Output: 
// 4
// Explanation:
// The subarray is {7, 6, 1, 4} with sum 18, which is divisible by 3.
// Example 2:

// Input:
// N = 7, K = 3
// arr[] = {-2, 2, -5, 12, -11, -1, 7}
// Output: 
// 5
// Explanation:
// The subarray is {2,-5,12,-11,-1} with sum -3, which is divisible by 3.
// Your Task:
// The input is already taken care of by the driver code. You only need to complete the function longSubarrWthSumDivByK() that takes an array arr, sizeOfArray n and a  positive integer K, and returns the length of the longest subarray which has sum divisible by K. 

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 105
// 1 <= K <= 109
// -109 <= A[i] <= 109 

// Company Tags



class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	      unordered_map<int,int> pre;
        int presum = 0;
        int maxi = 0;
        pre[0] = -1;  // Initializing with a dummy entry for easier calculation

        for(int i = 0; i < n; i++) {
            presum += arr[i];
            int remainder = (presum % k + k) % k; 

            if(pre.count(remainder))
                maxi = max(maxi, i - pre[remainder]);

            if(!pre.count(remainder))
                pre[remainder] = i;
        }

        return maxi;
	}
};


















