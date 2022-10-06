// Lexicographically smallest string
// MediumAccuracy: 46.37%Submissions: 2506Points: 4
// Given a string S consisting of only lowercase characters. Find the lexicographically smallest string after removing exactly k characters from the string. But you have to correct the value of k, i.e., if the length of the string is a power of 2, reduce k by half, else multiply k by 2. You can remove any k character.
// NOTE: If it is not possible to remove k (the value of k after correction) characters or if the resulting string is empty return -1.

// Example 1:

// Input: S = "fooland", k = 2
// Output: "and"
// Explanation: As the size of the string = 7
// which is not a power of 2, hence k = 4.
// After removing 4 characters from the given
// string, the lexicographically smallest
// string is "and".
// Example 2:

// Input: S = "code", k = 4
// Output: "cd"
// Explanation: As the length of the string = 4,
// which is 2 to the power 2, hence k = 2.
// Hence, lexicographically smallest string after
// removal of 2 characters is "cd".

// Your Task:
// You dont need to read input or print anything. Complete the function lexicographicallySmallest() which takes S and k as input parameters and returns the lexicographically smallest string after removing k characters.

// Expected Time Complexity: O(n+k), n is size of the string
// Expected Auxiliary Space: O(n)

// Constraints:
// 1<= |S| <=105
// 1<= k <= 105

// View Bookmarked Problems

class Solution
{
public:
    string lexicographicallySmallest(string s, int k)
    {
        // code here
        int n = s.size();

        if ((n & n - 1) == 0)
            k /= 2;
        else
            k *= 2;

        if (k >= n)
            return "-1";

        stack<char> stk;
        string ans = "";

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];

            while (!stk.empty() && stk.top() > ch && k > 0)
            {
                stk.pop();
                k--;
            }

            stk.push(ch);
        }

        while (k > 0 && !stk.empty())
        {
            stk.pop();
            k--;
        }

        while (!stk.empty())
        {
            ans += (char)stk.top();
            stk.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
