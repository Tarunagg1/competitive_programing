// Does array represent Heap
// EasyAccuracy: 30.97%Submissions: 36K+Points: 2
// Internship Alert!
// Become an SDE Intern by topping this monthly leaderboard!

// banner
// Given an array arr of size n, the task is to check if the given array can be a level order representation of a Max Heap.

// Example 1:

// Input:
// n = 6
// arr[] = {90, 15, 10, 7, 12, 2}
// Output:
// 1
// Explanation:
// The given array represents below tree
//        90
//      /    \
//    15      10
//   /  \     /
// 7    12  2
// The tree follows max-heap property as every
// node is greater than all of its descendants.
// Example 2:
// Input:
// n = 6
// arr[] = {9, 15, 10, 7, 12, 11}
// Output:
// 0
// Explanation:
// The given array represents below tree
//        9
//      /    \
//    15      10
//   /  \     /
// 7    12  11
// The tree doesn't follows max-heap property 9 is
// smaller than 15 and 10, and 10 is smaller than 11.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isMaxHeap() which takes the array arr[] and its size n as inputs and returns True if the given array could represent a valid level order representation of a Max Heap, or else, it will return False.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ n ≤ 105
// 1 ≤ arri ≤ 105

// Company Tags
// Topic Tags
// If you are facing any issue on this page. Please let us know.
// C++ (g++ 5.4)

// Custom Input

class Solution
{
public:
    bool rec(int arr[], int i, int n)
    {
        if (i >= n)
            return false;
        if ((2 * i + 1) < n && arr[i] < arr[2 * i + 1])
            return true;
        if ((2 * i + 2) < n && arr[i] < arr[2 * i + 2])
            return true;
        return rec(arr, i + 1, n);
    }
    bool isMaxHeap(int arr[], int n)
    {
        return !rec(arr, 0, n);
    }
};
