// Longest Prefix Suffix
// Difficulty: HardAccuracy: 27.91%Submissions: 129K+Points: 8
// Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

// NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

// Examples :

// Input: str = "abab"
// Output: 2
// Explanation: "ab" is the longest proper prefix and suffix.
// Input: str = "aaaa"
// Output: 3
// Explanation: "aaa" is the longest proper prefix and suffix.
// Expected Time Complexity: O(|str|)
// Expected Auxiliary Space: O(|str|)

// Constraints:
// 1 ≤ |str| ≤ 106
// str contains lower case English alphabets

// Seen this question in a real interview before ?
// Yes
// No
// Company Tags
// AccoliteAmazonMicrosoftMakeMyTrip
// Topic Tags
// Related Interview Experiences

class Solution
{
public:
    int lps(string str)
    {
        // Your code goes here
        int n = str.size();
        vector<int> kmp(n);

        int i = 0;
        for (int j = 1; j < n; j++)
        {
            if (str[i] == str[j])
            {
                kmp[j] = ++i;
            }
            else
            {
                while ((--i) >= 0)
                {
                    i = kmp[i];
                    if (str[i] == str[j])
                        break;
                }
                kmp[j] = ++i;
            }
        }
        return kmp[n - 1];
    }
};
