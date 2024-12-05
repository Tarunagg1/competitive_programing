// Sort 0s, 1s and 2s
// Difficulty: EasyAccuracy: 50.58%Submissions: 719K+Points: 2
// Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.

// Examples:

// Input: arr[] = [0, 1, 2, 0, 1, 2]
// Output: [0, 0, 1, 1, 2, 2]
// Explanation: 0s 1s and 2s are segregated into ascending order.
// Input: arr[] = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
// Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
// Explanation: 0s 1s and 2s are segregated into ascending order.
// Constraints:
// 1 <= arr.size() <= 106
// 0 <= arr[i] <= 2

// Company Tags

class Solution
{
public:
    void sort012(vector<int> &arr)
    {
        // code here
        int mid = 0, low = 0, high = arr.size() - 1;

        while (mid <= high)
        {
            if (arr[mid] == 0)
            {
                swap(arr[mid], arr[low]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};
