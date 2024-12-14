// Search in Rotated Sorted Array
// Difficulty: MediumAccuracy: 37.64%Submissions: 236K+Points: 4
// Given a sorted and rotated array arr[] of distinct elements, the task is to find the index of a target key. Return -1 if the key is not found.

// Examples :

// Input: arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 3
// Output: 8
// Explanation: 3 is found at index 8.
// Input: arr[] = [3, 5, 1, 2], key = 6
// Output: -1
// Explanation: There is no element that has value 6.
// Input: arr[] = [33, 42, 72, 99], key = 42
// Output: 1
// Explanation: 42 is found at index 1.
// Constraints:
// 1 ≤ arr.size() ≤ 106
// 0 ≤ arr[i] ≤ 106
// 1 ≤ key ≤ 106

class Solution
{
public:
    int search(vector<int> &arr, int key)
    {
        // complete the function here
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (arr[mid] == key)
            {
                return mid;
            }
            if (arr[mid] >= arr[s])
            {
                if (key >= arr[s] && key <= arr[mid])
                {
                    e = mid;
                }
                else
                {
                    s = mid + 1;
                }
            }
            else
            {
                if (key >= arr[mid] && key <= arr[e])
                {
                    s = mid;
                }
                else
                {
                    e = mid - 1;
                }
            }
        }
        return -1;
    }
};
