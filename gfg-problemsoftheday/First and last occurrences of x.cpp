// First and last occurrences of x
// MediumAccuracy: 37.36%Submissions: 212K+Points: 4
// Learn Google Cloud with Curated Lab Assignments. Register, Earn Rewards, Get noticed by experts at Google & Land your Dream Job!
// Given a sorted array arr containing n elements with possibly duplicate is to find indexes of first elements, the task is to find the first and last occurrences of an element x in the given array.
// Note: If the number x is not found in the array then return both the indices as -1.

// Example 1:

// Input:
// n=9, x=5
// arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
// Output:
// 2 5
// Explanation:
// First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5.
// Example 2:

// Input:
// n=9, x=7
// arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
// Output:
// 6 6
// Explanation:
// First and last occurrence of 7 is at index 6.
// Your Task:
// Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function find() that takes array arr, integer n and integer x as parameters and returns the required answer.

// Expected Time Complexity: O(logN)
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ N ≤ 106
// 1 ≤ arr[i],x ≤ 109

// Company Tags

class Solution
{
public:
    vector<int> find(int arr[], int n, int x)
    {
        // code here
        int a = lowerBond(arr, 0, n - 1, x);
        if (arr[a] != x)
            return {-1, -1};
        int b = lowerBond(arr, 0, n - 1, x + 1);
        return {a, b - 1};
    }

    int lowerBond(int arr[], int low, int high, int x)
    {

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= x)
            {

                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};
