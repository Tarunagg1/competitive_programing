// Partition a number into two divisible parts
// Medium Accuracy: 61.63% Submissions: 1477 Points: 4
// Given a number (as string) and two integers a and b, divide the string in two non-empty parts such that the first part is divisible by a and the second part is divisible by b. In case multiple answers exist, return the string such that the first non-empty part has minimum length.

// Example 1:

// Input:
// 1200 4 3
// Output:
// 12 00
// Explanation:
// 12 is divisible by 4, and
// 00 is divisible by 3.

// Example 2:

// Input:
// 125 12 5
// Output:
// 12 5
// Explanation:
// 12 is divisible by 12, and
// 5 is divisible by 5.

// Your Task:

// You don't need to read input or print anything. Your task is to complete the function stringPartition() which takes the string S and returns a string which will be in the form of first sub-string + " " (Single Space) + second sub-string. If not found return -1 as a string.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:

// 1<=N<=106

// 1<=a,b<=N

// View Bookmarked Problems
// Company Tags

class Solution
{
public:
    bool divisible(string x, string y, int a, int b)
    {
        long long u = stol(x);
        long long v = stol(y);
        return u % a == 0 && v % b == 0;
    }

    string stringPartition(string S, int a, int b)
    {
        // code here
        string s = "";
        string t = "";
        for (int i = 1; i < S.size(); i++)
        {
            string x = S.substr(0, i);
            string y = S.substr(i);
            if (divisible(x, y, a, b))
            {
                if (s == "" && t == "")
                {
                    s = x;
                    t = y;
                }
                else if (s.size() > x.size() && t.size() > y.size())
                {
                    s = x;
                    t = y;
                }
            }
        }
        if (s == "" && t == "")
            return "-1";
        return s + " " + t;
    }
};
