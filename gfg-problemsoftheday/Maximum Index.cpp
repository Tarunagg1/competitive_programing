// Maximum Index
// MediumAccuracy: 13.46%Submissions: 152K+Points: 4
// Sharpen up your programming skills, participate in coding contests & explore high-paying jobs

// Given an array arr[] of n positive integers. The task is to find the maximum of j - i subjected to the constraint of arr[i] <= arr[j].

// Example 1:

// Input:
// n = 9
// arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
// Output:
// 6
// Explanation:
// In the given array arr[1] < arr[7]  satisfying
// the required condition (arr[i] <= arr[j])  thus
// giving the maximum difference of j - i which is
// 6(7-1).
// Example 2:

// Input:
// N = 2
// arr[] = {18, 17}
// Output:
// 0
// Explanation:
// We can either take i and j as 0 and 0
// or we cantake 1 and 1 both give the same result 0.
// Your Task:
// Complete the function maxIndexDiff() which takes array arr and size n, as input parameters and returns an integer representing the answer. You don't to print answer or take inputs.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 106
// 0 ≤ Arr[i] ≤ 109

class Solution
{
public:
    int maxIndexDiff(int arr[], int n)
    {
        // code here
        int i = 0;
        int j = n - 1;
        int ans = 0;
        while (i < j)
        {
            if (arr[i] <= arr[j])
            {
                ans = max(ans, j - i);
                i++;
                j = n - 1;
            }
            else
            {
                j--;
            }
        }
        return ans;
    }
};
