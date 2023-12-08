// Transform to prime
// MediumAccuracy: 42.44%Submissions: 18K+Points: 4
// Job-A-Thon Hiring Challenge: Now Revamped for Professionals. Fast-track your Resumes to Job Openings today

// banner
// Given an array of n integers. Find the minimum positive number to be inserted in array, so that sum of all elements of array becomes prime.

// Example 1:

// Input:
// N=5
// arr = {2, 4, 6, 8, 12}
// Output:
// 5
// Explanation:
// The sum of the array is 32 ,we can add 5 to this to make it 37 which is a prime number.
// Example 2:

// Input:
// N=3
// arr = {1, 5, 7}
// Output:
// 0
// Explanation:
// The sum of the array is 13 which is already prime.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function minNumber() that takes array arr and integer N as input parameters and returns the minimum positive number to be inserted in the array so as to make it's sum a prime number.

// Expected Time Complexity: O(N log(log N))
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ sum of all elements ≤ 106

class Solution
{
public:
    int minNumber(int arr[], int N)
    {
        int sum = 0;

        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }

        vector<int> dp(sum + 1001, true);
        dp[0] = false;
        dp[1] = false;

        for (int i = 2; i * i <= (sum + 1000); i++)
        {

            if (dp[i] == true)
            {
                for (int j = i * i; j <= (sum + 1000); j += i)
                {
                    dp[j] = false;
                }
            }
        }
        for (int i = sum; i <= sum + 1000; i++)
        {
            if (dp[i] == true)
            {
                return i - sum;
            }
        }
        return 0;
    }
};
