// Find Transition Point
// EasyAccuracy: 37.9%Submissions: 213K+Points: 2
// Hiring Challenge for Working Professionals on 10th November.
// Apply to 6 Companies through 1 Contest!

// banner
// Given a sorted array containing only 0s and 1s, find the transition point, i.e., the first index where 1 was observed, and before that, only 0 was observed.

// Example 1:

// Input:
// N = 5
// arr[] = {0,0,0,1,1}
// Output: 3
// Explanation: index 3 is the transition
// point where 1 begins.
// Example 2:

// Input:
// N = 4
// arr[] = {0,0,0,0}
// Output: -1
// Explanation: Since, there is no "1",
// the answer is -1.
// Your Task:
// You don't need to read input or print anything. The task is to complete the function transitionPoint() that takes array arr and N as input parameters and returns the 0-based index of the position where 0 ends and 1 begins. If array does not have any 1, return -1. If array does not have any 0, return 0.

// Expected Time Complexity: O(Log(N))
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 105
// 0 ≤ arr[i] ≤ 1

class Solution
{
public:
    int transitionPoint(int arr[], int n)
    {
        // code here
        int s = 0;
        int e = n - 1;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (arr[mid - 1] == 0 and arr[mid] == 1)
            {
                return mid;
            }
            else if (arr[mid - 1] == 0 and arr[mid] == 0)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return -1;
    }
};