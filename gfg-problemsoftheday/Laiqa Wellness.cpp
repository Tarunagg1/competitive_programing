// Sort 0s, 1s and 2s
// Difficulty: EasyAccuracy: 50.58%Submissions: 683K+Points: 2
// Given an array arr containing only 0s, 1s, and 2s. Sort the array in ascending order.

// Examples:

// Input: arr[]= [0, 2, 1, 2, 0]
// Output: 0 0 1 2 2
// Explanation: 0s 1s and 2s are segregated into ascending order.
// Input: arr[] = [0, 1, 0]
// Output: 0 0 1
// Explanation: 0s 1s and 2s are segregated into ascending order.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= arr.size() <= 106
// 0 <= arr[i] <= 2

// // Seen this question in a real interview before ?

class Solution
{
public:
    void sort012(vector<int> &arr)
    {
        // code here
        int low = 0;
        int mid = 0;
        int end = arr.size() - 1;
        while (mid <= end)
        {
            if (arr[mid] == 1)
            {
                mid++;
            }
            else if (arr[mid] == 0)
            {
                swap(arr[mid], arr[low]);
                mid++;
                low++;
            }
            else
            {
                swap(arr[mid], arr[end]);
                end--;
            }
        }
    }
};
