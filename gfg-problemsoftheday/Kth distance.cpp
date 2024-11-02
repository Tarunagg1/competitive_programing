// Kth distance
// Difficulty: EasyAccuracy: 48.69%Submissions: 19K+Points: 2
// Given an unsorted array arr and a number k which is smaller than size of the array. Find if the array contains duplicates within k distance.

// Examples:

// Input: arr[] = [1, 2, 3, 4, 1, 2, 3, 4] and k = 3
// Output: false
// Explanation: All duplicates are more than k distance away.
// Input: arr[] = [1, 2, 3, 1, 4, 5] and k = 3
// Output: true
// Explanation: 1 is repeated at distance 3.
// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ k < arr.size()
// 1 ≤ arr[i] ≤ 105

class Solution
{
public:
    bool checkDuplicatesWithinK(vector<int> &arr, int k)
    {
        // your code
        unordered_map<int, int> mp;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int val = arr[i];
            if (mp[val] && abs(mp[val] - (i + 1)) <= k)
            {
                return true;
            }
            mp[val] = i + 1;
        }
        return false;
    }
};
