// Generate IP Addresses
// MediumAccuracy: 43.42%Submissions: 18797Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.

// Given a string S containing only digits, Your task is to complete the function genIp() which returns a vector containing all possible combinations of valid IPv4 IP addresses and takes only a string S as its only argument.
// Note: Order doesn't matter.

// For string 11211 the IP address possible are
// 1.1.2.11
// 1.1.21.1
// 1.12.1.1
// 11.2.1.1

// Example 1:

// Input:
// S = 1111
// Output: 1.1.1.1
// Example 2:

// Input:
// S = 55
// Output: -1

// Your Task:

// Your task is to complete the function genIp() which returns a vector containing all possible combinations of valid IPv4 IP addresses in sorted order or -1 if no such IP address could be generated through the input string S, the only argument to the function.

// Expected Time Complexity: O(N * N * N * N)
// Expected Auxiliary Space: O(N * N * N * N)

// Constraints:
// 1<=N<=16
// here, N = length of S.
// S only contains digits(i.e. 0-9)

class Solution
{
public:
    bool isValid(string s, int part)
    {
        if (s.empty())
            return false;

        int val = stoi(s);
        if (s.size() > 1 && s[0] == '0')
            return false;
        return val <= 255;
    }
    void solve(string &s, vector<string> &ans, int idx, string res, string str, int part)
    {
        // base case
        if (idx >= s.size())
        {
            // cout<<res<<endl;
            if (isValid(str, part) && part == 3)
            {
                ans.push_back(res);
            }
            return;
        }

        if (str.size() > 3 || part > 3)
            return;

        // pick element
        solve(s, ans, idx + 1, res + s[idx], str + s[idx], part);

        // append dot
        if (!str.empty() && isValid(str, part))
            solve(s, ans, idx, res + '.', "", part + 1);
        else
            return;
    }
    vector<string> genIp(string &s)
    {

        vector<string> ans;
        int idx = 0;
        string res = "";
        int part = 0;
        solve(s, ans, idx, res, "", part);

        if (ans.empty())
            return {"-1"};
        return ans;
    }
};
