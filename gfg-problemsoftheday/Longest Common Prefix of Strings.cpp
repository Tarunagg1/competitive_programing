// Longest Common Prefix of Strings
// Difficulty: EasyAccuracy: 29.52%Submissions: 261K+Points: 2
// Given an array of strings arr. Return the longest common prefix among all strings present in the array. If there's no prefix common in all the strings, return "-1".

// Examples :

// Input: arr[] = ["geeksforgeeks", "geeks", "geek", "geezer"]
// Output: gee
// Explanation: "gee" is the longest common prefix in all the given strings.
// Input: arr[] = ["hello", "world"]
// Output: -1
// Explanation: There's no common prefix in the given strings.
// Expected Time Complexity: O(n*min(|arri|))
// Expected Space Complexity: O(min(|arri|))

// Constraints:
// 1 ≤ |arr| ≤ 103
// 1 ≤ |arr[i]| ≤ 103

// Seen this question in a real interview before ?
// Yes
// No
// Company Tags
// VMWareMicrosoftGoogle
// Topic Tags

class Solution
{
public:
    string longestCommonPrefix(vector<string> arr)
    {
        // your code here
        int i = 0;
        int sz = INT_MAX;
        for (auto it : arr)
        {
            int k = it.size();
            sz = min(sz, k);
        }
        bool exist = true;
        string st = arr[0];
        for (i = 0; i < sz; i++)
        {
            char ch = st[i];
            for (auto it : arr)
            {
                if (it[i] != ch)
                {
                    exist = false;
                    break;
                }
            }
            if (!exist)
                break;
        }
        if (i == 0)
            return "-1";
        return st.substr(0, i);
    }
};
