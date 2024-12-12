// Number of occurrence
// Difficulty: EasyAccuracy: 59.34%Submissions: 260K+Points: 2
// Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[].

// Examples :

// Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
// Output: 4
// Explanation: target = 2 occurs 4 times in the given array so the output is 4.
// Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
// Output: 0
// Explanation: target = 4 is not present in the given array so the output is 0.
// Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
// Output: 3
// Explanation: target = 12 occurs 3 times in the given array so the output is 3.
// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ arr[i] ≤ 106
// 1 ≤ target ≤ 106

class Solution
{
public:
    int firstOccurence(vector<int> &arr, int target, int n)
    {
        int s = 0;
        int e = n - 1;
        int ans = -1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (arr[mid] == target)
            {
                ans = mid;
                e = mid - 1; // first occurence
            }
            else if (arr[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }

        return ans;
    }

    int lastOccurence(vector<int> &arr, int target, int n)
    {
        int s = 0;
        int e = n - 1;
        int ans = -1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (arr[mid] == target)
            {
                ans = mid;
                s = mid + 1; // last Ocuurence
            }
            else if (arr[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }

        return ans;
    }

    int countFreq(vector<int> &arr, int target)
    {
        // code here
        int n = arr.size();
        int first = firstOccurence(arr, target, n);
        int last = lastOccurence(arr, target, n);

        if (first == -1 || last == -1)
            return 0;

        int count = last - first + 1;
        return count;
    }
};
