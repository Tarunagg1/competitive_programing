// Sort an array of 0s, 1s and 2s
// EasyAccuracy: 51.36%Submissions: 100k+Points: 2
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.

// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

// Example 1:

// Input:
// N = 5
// arr[]= {0 2 1 2 0}
// Output:
// 0 0 1 2 2
// Explanation:
// 0s 1s and 2s are segregated
// into ascending order.
// Example 2:

// Input:
// N = 3
// arr[] = {0 1 0}
// Output:
// 0 0 1
// Explanation:
// 0s 1s and 2s are segregated
// into ascending order.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function sort012() that takes an array arr and N as input parameters and sorts the array in-place.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 10^6
// 0 <= A[i] <= 2


class Solution
{
public:
    void sort012(int a[], int n)
    {
        // code here
        int lo = 0, mid = 0, hi = n - 1;
        while (mid <= hi)
        {
            if (a[mid] == 0)
            {
                swap(a[mid], a[lo]);
                mid++;
                lo++;
            }
            else if (a[mid] == 1)
                mid++;
            else
            {
                swap(a[mid], a[hi]);
                hi--;
            }
        }
    }
};
