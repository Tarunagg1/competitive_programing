// Maximum subset sum
// MediumAccuracy: 63.8%Submissions: 8K+Points: 4
// Finding a high paying job is easier than today's problem! Attend Job Fair 2023

// Given an array A of size N. Find the maximum subset-sum of elements that you can make from the given array such that for every two consecutive elements in the array, at least one of the elements is present in our subset.

// Example 1:

// Input:
// N = 4
// A[] = {1, -1, 3, 4}
// Output: 8
// Explanation:
// We can choose 0th,2nd & 3rd index(0 based
// Index),so that it can satisfy the
// condition & can make maximum sum 8.
// Example 2:

// Input:
// N = 3
// A[] =  {0, 2, 0};
// Output: 2
// Explanation:
// We can choose 1st index. Here the
// maximum possible sum is 2.
// Your task:

// You don't have to read input or print anything. Your task is to complete the function findMaxSubsetSum() which takes the array A and its size N as input and returns the Maximum possible subset-sum.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 2 ≤ N ≤ 105
// -105 ≤ A[i] ≤ 105

// View Bookmarked Problems
// Company Tags

class Solution
{

public:
    long long findMaxSubsetSum(int N, vector<int> &A)
    {
        // code here
        int dp[N]; // dp[i] = maximum sum for [0, i] elements if i-th element is included in the subset.
        dp[0] = A[0], dp[1] = A[1] + max(A[0], 0);
        for (int i = 2; i < N; i++)
        {
            // Either we include (i-1)-th element
            // If not, we are "forced" to include (i-2)-th element
            dp[i] = A[i] + max(dp[i - 1], dp[i - 2]);
        }
        return max(dp[N - 1], dp[N - 2]);
    }
};
