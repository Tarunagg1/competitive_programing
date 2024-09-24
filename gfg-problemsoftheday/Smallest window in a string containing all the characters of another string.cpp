// Smallest window in a string containing all the characters of another string
// Difficulty: HardAccuracy: 30.19%Submissions: 146K+Points: 8
// Given two strings s and p. Find the smallest window in the string s consisting of all the characters(including duplicates) of the string p.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index.
// Note : All characters are in Lowercase alphabets.

// Examples:

// Input: s = "timetopractice", p = "toc"
// Output: toprac
// Explanation: "toprac" is the smallest
// substring in which "toc" can be found.
// Input: s = "zoomlazapzo", p = "oza"
// Output: apzo
// Explanation: "apzo" is the smallest
// substring in which "oza" can be found.
// Expected Time Complexity: O(|s|)
// Expected Auxiliary Space: O(n), n = len(p)

// Constraints:
// 1 ≤ |s|, |p| ≤ 105

// Seen this question in a real interview before ?

class Solution
{
public:
    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.
    string smallestWindow(string s, string p)
    {
        // Your code here
        vector<int> mp(26), curr(26);
        int start = 0, len = INT_MAX, cnt = 0, n = s.size(), m = p.size();
        for (char ch : p)
            mp[ch - 'a']++;
        for (int i = 0, j = 0, cnt = 0; j < n; j++)
        {
            cnt += curr[s[j] - 'a'] < mp[s[j] - 'a'];
            curr[s[j] - 'a']++;
            while (i <= j and cnt == m)
            {
                if (j - i + 1 < len)
                    len = j - i + 1, start = i;
                cnt -= curr[s[i] - 'a'] == mp[s[i] - 'a'];
                curr[s[i] - 'a']--;
                i++;
            }
        }
        return len == INT_MAX ? "-1" : s.substr(start, len);
    }
};
