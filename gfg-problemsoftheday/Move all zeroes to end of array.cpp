// Move all zeroes to end of array
// EasyAccuracy: 45.51%Submissions: 133K+Points: 2
// GfG Weekly + You = Perfect Sunday Evenings!
// Register for free now

// banner
// Given an array arr[] of n positive integers. Push all the zeros of the given array to the right end of the array while maintaining the order of non-zero elements. Do the mentioned change in the array in-place.

// Example 1:

// Input:
// N = 5
// Arr[] = {3, 5, 0, 0, 4}
// Output: 3 5 4 0 0
// Explanation: The non-zero elements
// preserve their order while the 0
// elements are moved to the right.
// Example 2:

// Input:
// N = 4
// Arr[] = {0, 0, 0, 4}
// Output: 4 0 0 0
// Explanation: 4 is the only non-zero
// element and it gets moved to the left.
// Your Task:
// You don't need to read input or print anything. Complete the function pushZerosToEnd() which takes the array arr[] and its size n as input parameters and modifies arr[] in-place such that all the zeroes are moved to the right.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 105
// 0 ≤ arri ≤ 105

class Solution
{
public:
    void pushZerosToEnd(int arr[], int n)
    {
        // code here
        int idx = 0;
        while (idx < n - 1 && arr[idx] != 0)
            idx++;
        int ne = idx + 1;
        while (ne < n)
        {
            if (arr[ne] != 0)
            {
                int temp = arr[idx];
                arr[idx] = arr[ne];
                arr[ne] = temp;
                idx++;
            }
            ne++;
        }
    }
};
