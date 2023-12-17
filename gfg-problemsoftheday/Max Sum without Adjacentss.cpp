// Max Sum without Adjacents
// EasyAccuracy: 47.25%Submissions: 80K+Points: 2
// For the first time ever: GATE 2024 introduces DS & AI in its renowned exam. Take its first ever All India Mock Test

// banner
// Given an array Arr of size N containing positive integers. Find the maximum sum of a any possible subsequence such that no two numbers in the subsequence should be adjacent in Arr.

// Example 1:

// Input:
// N = 6
// Arr[] = {5, 5, 10, 100, 10, 5}
// Output: 110
// Explanation: If you take indices 0, 3
// and 5, then Arr[0]+Arr[3]+Arr[5] =
// 5+100+5 = 110.
// Example 2:

// Input:
// N = 4
// Arr[] = {3, 2, 7, 10}
// Output: 13
// Explanation: 3 and 10 forms a non
// continuous subsequence with maximum
// sum.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findMaxSum() which takes the array of integers Arr and N as parameters and returns an the maximum sum possible of any valid subsequence.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ Arri ≤ 105

// Company Tags
// Topic

class Solution
{
public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(int *arr, int n)
    {
        // code here
        int next_0, next_1;
        next_0 = next_1 = 0;

        for (int i = n - 1; i > -1; i--)
        {
            int cur_0 = max(arr[i] + next_1, next_0);
            int cur_1 = next_0;

            next_0 = cur_0;
            next_1 = cur_1;
        }

        return next_0;
    }
};
