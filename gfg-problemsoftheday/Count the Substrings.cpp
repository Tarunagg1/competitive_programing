// Count the Substrings
// EasyAccuracy: 79.6%Submissions: 5K+Points: 2
// Attend free LIVE Webinars with Summer Skill-Up Sessions! Enroll Now!

// Given a string S. The task is to count the number of substrings which contains equal number of lowercase and uppercase letters.

// Example 1:

// Input:
// S = "gEEk"
// Output: 3
// Explanation: There are 3 substrings of
// the given string which satisfy the
// condition. They are "gE", "gEEk" and "Ek".
// Example 2:

// Input:
// S = "WomensDAY"
// Output: 4
// Explanation: There are 4 substrings of
// the given string which satisfy the
// condition. They are "Wo", "ensDAY",
// "nsDA" and "sD"
// Your Task:
// The task is to complete the function countSubstring() which takes the string S as input parameter and returns the number of substrings which contains equal number of uppercase and lowercase letters.

// Expected Time Complexity: O(N*N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ |S| ≤ 103

// View Bookmarked Problems

class Solution
{
public:
    int countSubstring(string S)
    {
        // code here
        int cnt_l = 0, cnt_u = 0;
        unordered_map<int, int> mp; // diff,cnt

        mp[0]++;
        int ans = 0;
        for (auto x : S)
        {
            if (x >= 'a' && x <= 'z')
            {
                cnt_l++;
            }
            else
            {
                cnt_u++;
            }
            ans += mp[cnt_l - cnt_u];
            mp[cnt_l - cnt_u]++;
        }

        return ans;
    }
};
