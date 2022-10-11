// Decode the string
// MediumAccuracy: 58.52%Submissions: 6914Points: 4
// An encoded string (s) is given, the task is to decode it. The encoding pattern is that the occurance of the string is given at the starting of the string and each string is enclosed by square brackets.

// Example 1:

// Input: s = 1[b]
// Output: b
// Explaination: 'b' is present only one time.
// Example 2:

// Input: s = 3[b2[ca]]
// Output: bcacabcacabcaca
// Explaination: 2[ca] means 'ca' is repeated
// twice which is 'caca' which concatenated with
// 'b' becomes 'bcaca'. This string repeated
// thrice becomes the output.
// Your Task:
// You do not need to read input or print annything. Your task is to complete the function decodedString() which takes s as input parameter and returns the decoded string.

// Expected Time Complexity: O(|s|)
// Expected Auxiliary Space: O(|s|)

// Constraints:
// 1 ≤ |s| ≤ 103

class Solution
{
public:
    string dfs(string &s, int &i)
    {
        string ret = "";

        while (i < s.size() && s[i] != ']')
        {
            // find a begin of encoding
            if (isdigit(s[i]))
            {
                int cnt = 0;

                // compose the counter
                while (i < s.size() && isdigit(s[i]))
                    cnt = cnt * 10 + s[i++] - '0';

                // skip the '['
                ++i;

                // nested encoding
                string r = dfs(s, i);

                // decode
                while (cnt--)
                    ret += r;

                // skip the ']'
                ++i;
            }
            else
                // normal case
                ret.push_back(s[i++]);
        }

        return ret;
    }

public:
    string decodedString(string s)
    {
        string ret = "";
        int i = 0;

        return dfs(s, i);
    }
};
