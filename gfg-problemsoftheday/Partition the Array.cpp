// Partition the Array
// HardAccuracy: 83.86%Submissions: 3K+Points: 8
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// Given an array A[] of N integers. The task is to partition the array into four non-empty contiguous subarrays P, Q, R, and S such that each element of the array A[] should be present in exactly one subarray.
// Let W, X, Y, and Z be the sum of the elements in P, Q, R, and S respectively.
// Find the smallest absolute difference between the maximum and the minimum among W, X, Y, and Z.

// Example 1:

// Input:
// N = 5
// A[] = [4,2,2,5,1]
// Output: 4
// Explanation: let partition the array
// P,Q,R,S = [4],[2,2],[5],[1]
// W = 4, X = 4, Y = 5, Z = 1
// Differnce = max(W,X,Y,Z)-min(W,X,Y,Z)= 5-1 = 4
// Example 2:

// Input:
// N = 4
// A[] = {4,4,4,4}
// Output: 0
// Explanation:
// There is only one way to partition
// the array. P,Q,R,S = [4],[4],[4],[4]
// Your Task:
// You don't need to read input or print anything. The task is to complete the function minDifference() which takes the integer N and the array A[] as inputs and returns the smallest absolute difference.

// Expected Time Complexity: O(NLogN)
// Expected Auxiliary Space: O(N)

// Constraints:
// 4 < N < 105
// 1 < A[i] < 109

// View Bookmarked Problems

class Solution
{
public:
    pair<long long, long long> findmedianpair2(vector<long long> &a, int start, int end)
    {
        int low = start;
        int high = end - 1;
        long long prev = 0;
        if (start != 0)
            prev = a[start - 1];
        long long mini = 1e10;
        long long ret1;
        long long ret2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long first = a[mid] - prev;
            long long second = a[end - 1] - a[mid];
            if (first > second)
            {
                if ((first - second) < mini)
                {
                    mini = first - second;
                    ret1 = second;
                    ret2 = first;
                }
                high = mid - 1;
            }
            else if (first == second)
            {
                return {first, second};
            }
            else
            {
                if ((second - first) < mini)
                {
                    mini = second - first;
                    ret2 = second;
                    ret1 = first;
                }
                low = mid + 1;
            }
        }
        return {ret1, ret2};
    }
    long long minDifference(int n, vector<int> &a)
    {
        vector<long long> prefixsum(n, 0);
        for (int i = 0; i < n; i++)
        {
            prefixsum[i] = a[i];
            if (i > 0)
                prefixsum[i] += prefixsum[i - 1];
        }
        long long ans = 1e15;
        for (int i = 2; i <= n - 2; i++)
        {
            auto p = findmedianpair2(prefixsum, 0, i);
            auto q = findmedianpair2(prefixsum, i, n);
            long long mini = min(p.first, q.first);
            long long maxi = max(p.second, q.second);
            ans = min(ans, (maxi - mini));
        }
        return ans;
    }
};
