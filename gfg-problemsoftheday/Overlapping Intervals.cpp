// Overlapping Intervals
// Difficulty: MediumAccuracy: 57.41%Submissions: 74K+Points: 4
// Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.

// Examples:

// Input: arr[][] = [[1,3],[2,4],[6,8],[9,10]]
// Output: [[1,4], [6,8], [9,10]]
// Explanation: In the given intervals we have only two overlapping intervals here, [1,3] and [2,4] which on merging will become [1,4]. Therefore we will return [[1,4], [6,8], [9,10]].
// Input: arr[][] = [[6,8],[1,9],[2,4],[4,7]]
// Output: [[1,9]]
// Explanation: In the given intervals all the intervals overlap with the interval [1,9]. Therefore we will return [1,9].
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 0 ≤ starti ≤ endi ≤ 105

class Solution
{
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>> &arr)
    {
        // Code here
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        int n = arr.size();

        for (int i = 1; i < n; i++)
        {
            int start = arr[i][0];
            int lastBack = ans.back()[1];
            if (start <= lastBack)
            {
                ans.back()[1] = max(lastBack, arr[i][1]);
            }
            else
            {
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};
