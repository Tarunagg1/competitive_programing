// Search Pattern (KMP-Algorithm)
// MediumAccuracy: 45.04%Submissions: 25K+Points: 4
// 90% Refund available on all premium courses
// Discover How

// banner
// Given two strings, one is a text string, txt and other is a pattern string, pat. The task is to print the indexes of all the occurences of pattern string in the text string. Use one-based indexing while returing the indices.
// Note: Return an empty list incase of no occurences of pattern. Driver will print -1 in this case.

// Example 1:

// Input:
// txt = "geeksforgeeks"
// pat = "geek"
// Output:
// 1 9
// Explanation:
// The string "geek" occurs twice in txt, one starts are index 1 and the other at index 9.
// Example 2:

// Input:
// txt = "abesdu"
// pat = "edu"
// Output:
// -1
// Explanation:
// There's not substring "edu" present in txt.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function search() which takes the string txt and the string pat as inputs and returns an array denoting the start indices (1-based) of substring pat in the string txt.

// Expected Time Complexity: O(|txt|).
// Expected Auxiliary Space: O(|txt|).

// Constraints:
// 1 ≤ |txt| ≤ 105
// 1 ≤ |pat| < |S|
// Both the strings consists of lowercase English alphabets.

class Solution
{
public:
    vector<int> search(string pat, string txt)
    {
        // code here
        int n = txt.length();
        int m = pat.length();
        // cout<<m<<endl;
        vector<int> ans;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    break;
                }
                if (j == m - 1)
                {
                    ans.push_back(i + 1);
                }
            }
        }
        return ans;
    }
};
