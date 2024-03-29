// Maximum Index
// MediumAccuracy: 24.5%Submissions: 181K+Points: 4
// Internship Alert!
// New month-> Fresh Chance to top the leaderboard and get SDE Internship!

// banner
// Given an array a of n positive integers. The task is to find the maximum of j - i subjected to the constraint of a[i] < a[j] and i < j.

// Example 1:

// Input:
// n = 2
// a[] = {1, 10}
// Output:
// 1
// Explanation:
// a[0] < a[1] so (j-i) is 1-0 = 1.
// Example 2:

// Input:
// n = 9
// a[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
// Output:
// 6
// Explanation:
// In the given array a[1] < a[7] satisfying the required condition(a[i] < a[j]) thus giving the maximum difference of j - i which is 6(7-1).
// Your Task:
// The task is to complete the function maxIndexDiff() which finds and returns maximum index difference. Printing the output will be handled by driver code.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ n ≤ 106
// 0 ≤ a[i] ≤ 109

class Solution
{
public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n)
    {
        // Your code here
        int res = 0;
        int diff = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j > i; j--)
            {

                if (a[i] <= a[j])
                {
                    diff = j - i;
                    if (diff > res)
                    {
                        res = diff;
                    }
                    break;
                }
            }
        }
        return res;
    }
};
