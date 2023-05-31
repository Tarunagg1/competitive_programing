// Frequency Game
// EasyAccuracy: 62.74%Submissions: 18K+Points: 2
// Given an array A of size N. The elements of the array consist of positive integers. You have to find the largest element with minimum frequency.

// Example 1:

// Input:
// 5
// 2 2 5 50 1
// Output:
// 50
// Explanation :
// All elements are having frequency 1 except 2.
// 50 is the maximum element with minimum frequency.
// Example 2:

// Input:
// 4
// 3 3 5 5
// Output:
// 5
// Explanation:
// Both 3 and 5 have the same frequency, so 5 should be returned.
// User Task:
// Your task is to complete the provided function LargButMinFreq(A, n) which accepts array A and n. Hence you have to return the largest element with minimum frequency.

// Expected Time Complexity: O(N)
// Expected Space Complexity: O(N)

// Constraints:
// 1 <= N <= 105
// 1 <= A[i] <= 106

// View Bookmarked Problems

class Solution
{
public:
    int LargButMinFreq(int arr[], int n)
    {
        // code here
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }

        int maxEl = -1;
        int minCount = INT_MAX;

        for (auto j : mp)
        {
            int el = j.first;
            int count = j.second;
            if (el > maxEl && count <= minCount)
            {
                maxEl = el;
                minCount = count;
            }
        }

        return maxEl;
    }
};
