// Largest Sum Subarray of Size at least K
// MediumAccuracy: 37.64%Submissions: 25K+Points: 4
// 90% Refund available on all premium courses
// Discover How

// banner
// Given an array a of length n and a number k, find the largest sum of the subarray containing at least k numbers. It is guaranteed that the size of array is at-least k.

// Example 1:

// Input :
// n = 4
// a[] = {-4, -2, 1, -3}
// k = 2
// Output :
// -1
// Explanation :
// The sub-array of length at-least 2
// that produces greatest sum is {-2, 1}
// Example 2:
// Input :
// n = 6
// a[] = {1, 1, 1, 1, 1, 1}
// k = 2
// Output :
// 6
// Explanation :
// The sub-array of length at-least 2
// that produces greatest sum is {1, 1, 1, 1, 1, 1}
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maxSumWithK() which takes the array a[], its size n and an integer k as inputs and returns the value of the largest sum of the subarray containing at least k numbers.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= n <= 105
// -105 <= a[i] <= 105
// 1 <= k <= n

class Solution
{
public:
    long long int maxSumWithK(long long int a[], long long int n, long long int k)
    {
        long long int currentSum = 0;
        long long int maxSum = INT_MIN;
        long long int accumulatedNegative = 0;

        for (int start = 0, end = 0; end < n;)
        {
            currentSum += a[end];

            if (end - start + 1 < k)
            {
                ++end;
            }

            else if (end - start + 1 == k)
            {
                maxSum = max(maxSum, currentSum);
                ++end;
            }

            else
            {
                maxSum = max(maxSum, currentSum);
                accumulatedNegative += a[start++];

                if (accumulatedNegative < 0)
                {
                    currentSum -= accumulatedNegative;
                    maxSum = max(maxSum, currentSum);
                    accumulatedNegative = 0;
                }

                ++end;
            }
        }

        return maxSum;
    }
};
