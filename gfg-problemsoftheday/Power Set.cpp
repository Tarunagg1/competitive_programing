// Power Set
// MediumAccuracy: 43.3%Submissions: 66K+Points: 4
// Internship Alert!
// Become an SDE Intern by topping this monthly leaderboard!

// banner
// Given a string s of length n, find all the possible subsequences of the string s in lexicographically-sorted order.

// Example 1:

// Input :
// s = "abc"
// Output:
// a ab abc ac b bc c
// Explanation :
// There are a total 7 number of subsequences possible
// for the given string, and they are mentioned above
// in lexicgraphically sorted order.
// Example 2:

// Input:
// s = "aa"
// Output:
// a a aa
// Explanation :
// There are a total 3 number of subsequences possible
// for the given string, and they are mentioned above
// in lexicgraphically sorted order.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function AllPossibleStrings() which takes a string s as the input parameter and returns a list of all possible subsequences (non-empty) that can be formed from s in lexicographically-sorted order.

// Expected Time Complexity: O( n*2n  )
// Expected Space Complexity: O( n * 2n )

// Constraints:
// 1 <= n <= 16
// s will constitute of lower case english alphabets

class Solution
{
public:
    vector<string> AllPossibleStrings(string s)
    {
        // Code here
        int n = s.length();
        vector<string> ans;
        for (int i = 0; i <= (1 << n) - 1; i++)
        {
            string sub = "";
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    sub += s[j];
                }
            }
            if (sub != "")
                ans.push_back(sub);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
