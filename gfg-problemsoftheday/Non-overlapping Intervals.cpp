// Non-overlapping Intervals
// Difficulty: MediumAccuracy: 51.92%Submissions: 11K+Points: 4
// Given a 2D array intervals[][] of representing intervals where intervals [i] = [starti, endi ]. Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Examples:

// Input: intervals[][] = [[1, 2], [2, 3], [3, 4], [1, 3]]
// Output: 1
// Explanation: [1, 3] can be removed and the rest of the intervals are non-overlapping.
// Input: intervals[][] = [[1, 3], [1, 3], [1, 3]]
// Output: 2
// Explanation: You need to remove two [1, 3] to make the rest of the intervals non-overlapping.
// Input: intervals[][] = [[1, 2], [5, 10], [18, 35], [40, 45]]
// Output: 0
// Explanation: All ranges are already non overlapping.
// Constraints:
// 1 ≤ intervals.size() ≤  105
// |intervalsi| == 2
// 0 ≤ starti < endi <=5*104

class cmp
{
public:
    bool operator()(vector<int> &a, vector<int> &b)
    {
        if (a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    }
};

class Solution
{
public:
    int minRemoval(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp());

        int e = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (intervals[i][0] >= e)
            {
                ans++;
                e = intervals[i][1];
            }
        }
        return n - ans;
    }
};
