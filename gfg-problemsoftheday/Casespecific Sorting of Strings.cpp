// Case-specific Sorting of Strings
// MediumAccuracy: 69.88%Submissions: 33K+Points: 4
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// Given a string S consisting of only uppercase and lowercase characters. The task is to sort uppercase and lowercase letters separately such that if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.

// Example 1:

// Input:
// N = 12
// S = defRTSersUXI
// Output: deeIRSfrsTUX
// Explanation: Sorted form of given string
// with the same case of character as that
// in original string is deeIRSfrsTUX
// Example 2:

// Input:
// N = 6
// S = srbDKi
// Output: birDKs
// Explanation: Sorted form of given string
// with the same case of character will
// result in output as birDKs.
// Your Task:
// You only need to complete the function caseSort that takes a string str and length of the string n and returns sorted string.

// Expected Time Complexity: O(Nlog(N)).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 ≤ N ≤ 105

// View Bookmarked Problems

class Solution
{
public:
    // Function to perform case-specific sorting of strings.
    string caseSort(string s, int n)
    {
        // your code here
        vector<int> a(26, 0), b(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                a[s[i] - 'A']++;
            else
                b[s[i] - 'a']++;
        }
        int p = 0, q = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                while (a[p] == 0)
                    p++;
                s[i] = p + 'A';
                a[p]--;
            }
            else
            {
                while (b[q] == 0)
                    q++;
                s[i] = q + 'a';
                b[q]--;
            }
        }
        return s;
    }
};
