// Longest repeating and non-overlapping substring
// HardAccuracy: 46.71%Submissions: 21K+Points: 8
// Internship Alert!
// New month-> Fresh Chance to top the leaderboard and get SDE Internship! 

// banner
// Given a string s of length n, find the longest repeating non-overlapping substring in it. In other words find 2 identical substrings of maximum length which do not overlap. Return the longest non-overlapping substring. Return "-1" if no such string exists.

// Note: Multiple Answers are possible but you have to return the substring whose first occurrence is earlier.

// For Example: "abhihiab", here both "ab" and "hi" are possible answers. But you will have to return "ab" because it's first occurrence appears before the first occurrence of "hi".

// Example 1:

// Input:
// n = 9
// s = "acdcdacdc"
// Output:
// "acdc"
// Explanation:
// The string "acdc" is the longest Substring of s which is repeating but not overlapping.
// Example 2:

// Input:
// n = 7
// s = "heheheh"
// Output:
// "heh"
// Explanation:
// The string "heh" is the longest Substring of s which is repeating but not overlapping.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function longestSubstring() which takes an Integer n and a string s as input and returns the answer.

// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(n2)

// Constraints:
// 1 <= n <= 103

// Company Tags



class Solution {
  public:
    long long mod = (1LL << 45) - 1;
    string possible(int p, string& txt){
        int t = txt.size();
        unordered_map<long long, int> mp;
        long long pr = 1;
        long long pp = 31;
        long long th = 0;
        for(int i=p-1; i>=0; i--){
            th = (th % mod + ((txt[i] - 'a' + 1) % mod * pr % mod) % mod) % mod;
            if(i > 0) pr = (pr * pp) % mod;
        }
        mp[th] = 0;
        int j = 0;
        for(int i=p; i<t; i++){
            th = (th % mod - ((txt[j++] - 'a' + 1) * pr) % mod + mod) % mod;
            th = ((th % mod * pp % mod) + (txt[i] - 'a' + 1)) % mod;
            mp[th] = j;
        }
        pr = 1, pp = 31, th = 0;
        for(int i=p-1; i>=0; i--){
            th = (th % mod + ((txt[i] - 'a' + 1) % mod * pr % mod) % mod) % mod;
            if(i > 0) pr = (pr * pp) % mod;
        }
        if(mp[th] >= p) return txt.substr(0, p);
        j = 0;
        for(int i=p; i<t; i++){
            th = (th % mod - ((txt[j++] - 'a' + 1) * pr) % mod + mod) % mod;
            th = ((th % mod * pp % mod) + (txt[i] - 'a' + 1)) % mod;
            if(mp[th] >= (j+p)) return txt.substr(j, p);
        }
        return "";
    }
    string longestSubstring(string s, int n) {
        long long p = 31;
        long long pw = 1;
        int l = 1, h = s.size();
        string ans = "";
        while(l <= h){
            int mid = l + (h - l) / 2;
            string c = possible(mid, s);
            if(c.size() == 0) h = mid - 1;
            else{
                if(c.size() > ans.size()) ans = c;
                l = mid + 1;
            }
        }
        if(ans.empty()) return "-1";
        return ans;
    }
};























