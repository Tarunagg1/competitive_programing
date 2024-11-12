// Meeting Rooms
// Difficulty: MediumAccuracy: 75.91%Submissions: 7K+Points: 4
// Given an array arr[][] such that arr[i][0] is the starting time of ith meeting and arr[i][1] is the ending time of ith meeting, the task is to check if it is possible for a person to attend all the meetings such that he can attend only one meeting at a particular time.

// Note: A person can attend a meeting if its starting time is greater than or equal to the previous meeting's ending time.

// Examples:

// Input: arr[][] = [[1, 4], [10, 15], [7, 10]]
// Output: true
// Explanation: Since all the meetings are held at different times, it is possible to attend all the meetings.
// Input: arr[][] = [[2, 4], [9, 12], [6, 10]]
// Output: false
// Explanation: It is not possible to attend the second and third meetings simultaneously.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 0 ≤ arr[i] ≤ 2*106

class Solution
{
public:
    bool canAttend(vector<vector<int>> &arr)
    {
        // Your Code Here
        map<int, int> m;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            m[arr[i][1]] = arr[i][0];
        }

        for (auto it = m.begin(); it != m.end(); it++)
        {
            auto curr = it;
            it++;

            if (it != m.end())
            {
                if (curr->first > it->second)
                    return false;
            }
            it = curr;
        }
        return true;
    }
};
