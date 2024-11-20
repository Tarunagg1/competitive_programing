// Majority Element II
// Difficulty: MediumAccuracy: 48.1%Submissions: 73K+Points: 4
// You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array.

// Note: The answer should be returned in an increasing format.

// Examples:

// Input: arr[] = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
// Output: [5, 6]
// Explanation: 5 and 6 occur more n/3 times.
// Input: arr[] = [1, 2, 3, 4, 5]
// Output: []
// Explanation: no candidate occur more than n/3 times.
// Constraint:
// 1 <= arr.size() <= 106
// -109 <= arr[i] <= 109

class Solution
{
public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int> &arr)
    {
        // Your code goes here.
        int n = arr.size();
        if (n == 1)
            return arr;
        int E1 = arr[0], E2 = arr[1], c1 = 0, c2 = 0;
        vector<int> ans;

        for (int i = 2; i < n; i++)
        {
            if (E1 == arr[i])
            {
                c1++;
            }
            else if (arr[i] == E2)
            {
                c2++;
            }
            else if (c1 == 0)
            {
                E1 = arr[i];
                c1++;
            }
            else if (c2 == 0)
            {
                E2 = arr[i];
                c2++;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        c1 = 0;
        c2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (E1 == arr[i])
                c1++;
            if (E2 == arr[i])
                c2++;
        }
        if ((c1 > n / 3))
            ans.push_back(E1);
        if ((c2 > n / 3))
            ans.push_back(E2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
