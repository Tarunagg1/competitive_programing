// Substrings of length k with k-1 distinct elements
// MediumAccuracy: 60.64%Submissions: 2897Points: 4
// Given a String S and an integer K. Find the count of all substrings of length K which have exactly K-1 distinct characters.

// Example 1:

// Input:
// S = "abcc"
// K = 2
// Output:
// 1
// Explanation:
// Possible substrings of length K = 2 are
// ab : 2 distinct characters
// bc : 2 distinct characters
// cc : 1 distinct character
// Only one valid substring exists {"cc"}.
// Example 2:
// Input:
// S = "aabab"
// K = 3
// Output :
// 3
// Explanation:
// Possible substrings of length K = 3 are
// aab : 2 distinct characters
// aba : 2 distinct characters
// bab : 2 distinct characters.
// All of these Substrings are a possible answer,
// so the count is 3.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function countOfSubstrings() which takes a String S and an integer K as input and returns the count of substrings of length K having K-1 distinct characters.

// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(constant)

// Constraints:
// 1 ≤ K ≤ |S| ≤ 105

class Solution
{
public:
    int countOfSubstrings(string S, int K)
    {
        // code here
        unordered_map<char, int> mp;

        for (int i = 0; i < K; i++)

            mp[S[i]]++;

        int ans;

        ans = mp.size() == (K - 1) ? 1 : 0;

        for (int i = K; i < S.length(); i++)

        {

            mp[S[i]]++;

            mp[S[i - K]]--;

            if (mp[S[i - K]] == 0)
                mp.erase(S[i - K]);

            if (mp.size() == K - 1)
                ans++;
        }
        return ans;
    }
};
