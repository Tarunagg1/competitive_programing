// Search in Rotated Sorted Array
// Difficulty: MediumAccuracy: 37.64%Submissions: 202K+Points: 4
// Given a sorted (in ascending order) and rotated array arr of distinct elements which may be rotated at some point and given an element key, the task is to find the index of the given element key in the array arr. The whole array arr is given as the range to search.

// Rotation shifts elements of the array by a certain number of positions, with elements that fall off one end reappearing at the other end.

// Note:- 0-based indexing is followed & returns -1 if the key is not present.

// Examples :

// Input: arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 10
// Output: 5
// Explanation: 10 is found at index 5.
// Input: arr[] = [3, 5, 1, 2], key = 6
// Output: -1
// Explanation: There is no element that has value 6.
// Expected Time Complexity: O(log n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ arr.size() ≤ 106
// 0 ≤ arr[i] ≤ 106
// 1 ≤ key ≤ 105

class Solution
{
public:
    int findCriticalPoint(vector<int> &arr, int left, int right, int n)
    {

        if (arr[left] < arr[right])
        {
            return -1;
        }

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (mid + 1 < n && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            if (mid - 1 >= 0 && arr[mid] < arr[mid - 1])
            {
                return mid - 1;
            }

            if (arr[mid] >= arr[left])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return -1;
    }

    int search_binary(vector<int> &arr, int left, int right, int target)
    {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target)
            {
                return mid;
            }
            else if (arr[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return -1;
    }

public:
    int search(vector<int> &arr, int key)
    {
        int n = arr.size();

        int left = 0;
        int right = n - 1;

        int criticalPoint = findCriticalPoint(arr, left, right, n);

        if (criticalPoint == -1)
        {
            return search_binary(arr, left, right, key);
        }

        int result = search_binary(arr, left, criticalPoint, key);
        if (result != -1)
            return result;

        return search_binary(arr, criticalPoint + 1, right, key);
    }
};
