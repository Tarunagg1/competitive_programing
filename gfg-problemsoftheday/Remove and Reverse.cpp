// Remove and Reverse
// MediumAccuracy: 64.95%Submissions: 4K+Points: 4
// Win Prize worth ₹6000 with Ease. Register for the Easiest Coding Challenge!

// Given a string S which consists of only lowercase English alphabets, you have to perform the below operations:
// If the string S contains any repeating character, remove the first repeating character and reverse the string and again perform the above operation on the modified string, otherwise, you stop.
// You have to find the final string.

// Example 1:

// Input: S = "abab"
// Output: ba
// Explanation:
// In 1st operation: The first repeating
// character is a. After Removing the first
// character, S = "bab". After Reversing the
// string, S = "bab".
// In 2nd operation: The first non repeating
// character is b. After Removing the first
// character, S = "ab". After Reversing the
// string, S = "ba".
// Now the string S does not contain any
// repeating character.
// Example 2:

// Input: S = "dddd"
// Output: d
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function removeReverse( ) which accepts a string S input parameter and returns the modified string.

// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(K), K <= 26.

// Constraints:
// The string contains only lowercase English alphabets.
// 1 < |S| < 105
// |S| denotes the length of the string S.

// View Bookmarked Problems
// Topic Tags

class Solution
{
public:
    string removeReverse(string S)
    {
        // code here
        unordered_map<char, int> mp;
        int n = S.size();
        for (int i = 0; i < n; ++i)
        {
            mp[S[i]]++;
        }
        int i = 0, j = n - 1, k = 0;
        string ans1 = "", ans2 = "";
        while (i <= j)
        {
            if (k % 2 == 0)
            {
                if (mp[S[i]] > 1)
                {
                    mp[S[i]]--;
                    k++;
                }
                else
                {
                    ans1 += S[i];
                }
                i++;
            }
            else
            {
                if (mp[S[j]] > 1)
                {
                    mp[S[j]]--;
                    k++;
                }
                else
                {
                    ans2 += S[j];
                }
                j--;
            }
        }
        reverse(ans2.begin(), ans2.end());
        ans1 = ans1 + ans2;
        if (k % 2 == 0)
            return ans1;
        reverse(ans1.begin(), ans1.end());
        return ans1;
    }
};
