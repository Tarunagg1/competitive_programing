// Longest subsequence-1
// MediumAccuracy: 39.79%Submissions: 55K+Points: 4
// In need of more Geekbits? Win from a pool of 3500+ Geekbits via DSA-based Coding Contest every sunday!

// banner
// Given an integer array a[] of size n, find the length of the longest subsequence such that the absolute difference between adjacent elements is 1.

// Example 1:

// Input:
// n = 7
// a[] = {10, 9, 4, 5, 4, 8, 6}
// Output:
// 3
// Explaination:
// The three possible subsequences of length 3 are {10, 9, 8}, {4, 5, 4}, and {4, 5, 6}, where adjacent elements have a absolute difference of 1. No valid subsequence of greater length could be formed.
// Example 2:

// Input:
// n = 5
// a[] = {1, 2, 3, 4, 5}
// Output:
// 5
// Explaination:
// All the elements can be included in the valid subsequence.
// Your Task:
// You do not need to read input. Your task is to complete the function longestSubseq() which takes integer n and array a[] as input parameters and returns the length of the longest subsequence where the absolute difference of adjacent elements is 1.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 ≤ n ≤ 103
// 1 ≤ a[i] ≤ 103

class Solution
{
public:
    int longestSubseq(int n, vector<int> &a)
    {
        // code here
        int mx = *max_element(a.begin(), a.end()), ans = 0;
        vector<int> scr(mx + 2, 0);
        for (auto x : a)
        {
            scr[x] = max(scr[x - 1], scr[x + 1]) + 1;
            ans = max(ans, scr[x]);
        }
        return ans;
    }
};
