// Count number of substrings
// MediumAccuracy: 20.46%Submissions: 40K+Points: 4
// Continue solving this problem now on your mobile! Download the GfG App Today

// banner
// Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly k distinct characters.

// Example 1:

// Input:
// S = "aba", K = 2
// Output:
// 3
// Explanation:
// The substrings are: "ab", "ba" and "aba".
// Example 2:

// Input:
// S = "abaaca", K = 1
// Output:
// 7
// Explanation:
// The substrings are: "a", "b", "a", "aa", "a", "c", "a".
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function substrCount() which takes the string S and an integer K as inputs and returns the number of substrings having exactly K distinct characters.

// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ |S| ≤ 106
// 1 ≤ K ≤ 26

class Solution
{
public:
    long long int f(string s, int k)
    {
        if (k < 0)
            return 0;
        long long int lo = 0, hi = 0, ans = 0, n = s.size(), cnt = 0;
        vector<int> A(26, 0);
        while (hi < n)
        {
            A[s[hi] - 'a']++;
            if (A[s[hi] - 'a'] == 1)
                cnt++;
            while (cnt > k)
            {
                A[s[lo] - 'a']--;
                if (A[s[lo] - 'a'] == 0)
                    cnt--;
                lo++;
            }
            ans += (hi - lo + 1);
            hi++;
        }
        return ans;
    }
    long long int substrCount(string s, int k)
    {
        return f(s, k) - f(s, k - 1);
    }
};
