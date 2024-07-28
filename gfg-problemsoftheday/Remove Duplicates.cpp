// Remove Duplicates
// Difficulty: EasyAccuracy: 52.35%Submissions: 114K+Points: 2
// Given a string str without spaces, the task is to remove all duplicate characters from it, keeping only the first occurrence.

// Note: The original order of characters must be kept the same.

// Examples :

// Input: str = "zvvo"
// Output: "zvo"
// Explanation: Only keep the first occurrence
// Input: str = "gfg"
// Output: "gf"
// Explanation: Only keep the first occurrence
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= |str| <= 105
// str contains lowercase English alphabets

class Solution
{
public:
    string removeDups(string str)
    {
        // Your code goes here
        vector<int> v(26, 0);

        for (int i = 0; i < str.size(); i++)
        {
            v[str[i] - 'a'] += 1;
        }

        string ans = "";
        for (int i = 0; i < str.size(); i++)
        {
            if (v[str[i] - 'a'] > 0)
            {
                ans += str[i];
                v[str[i] - 'a'] = 0;
            }
        }
        return ans;
    }
};
