// Aggressive Cows
// Difficulty: MediumAccuracy: 59.57%Submissions: 86K+Points: 4
// You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

// Examples :

// Input: stalls[] = [1, 2, 4, 8, 9], k = 3
// Output: 3
// Explanation: The first cow can be placed at stalls[0],
// the second cow can be placed at stalls[2] and
// the third cow can be placed at stalls[3].
// The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.
// Input: stalls[] = [10, 1, 2, 7, 5], k = 3
// Output: 4
// Explanation: The first cow can be placed at stalls[0],
// the second cow can be placed at stalls[1] and
// the third cow can be placed at stalls[4].
// The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.
// Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
// Output: 1
// Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
// The minimum distance between cows, in this case, is 1, which also is the largest among all possible ways.
// Constraints:
// 2 <= stalls.size() <= 106
// 0 <= stalls[i] <= 108
// 1 <= k <= stalls.size()

class Solution
{
public:
    bool check(vector<int> &stalls, int k, int dist)
    {
        int prev = stalls[0];
        int n = stalls.size();

        k--;
        for (int i = 1; i < n; i++)
        {
            if (k == 0)
                break;
            int diff = stalls[i] - prev;
            if (diff >= dist)
            {
                prev = stalls[i];
                k--;
            }
            else
                continue;
        }

        return (k == 0);
    }

    int aggressiveCows(vector<int> &stalls, int k)
    {
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int ans = 1;
        int l = 0;
        int r = stalls[n - 1] - stalls[0];

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (check(stalls, k, mid))
            {
                l = mid + 1;
                ans = mid;
            }
            else
            {
                r = mid - 1;
            }
        }

        return ans;
    }
};
