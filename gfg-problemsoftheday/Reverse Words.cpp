// Reverse Words
// Difficulty: EasyAccuracy: 56.08%Submissions: 325K+Points: 2
// Given a String str, reverse the string without reversing its individual words. Words are separated by dots.

// Note: The last character has not been '.'.

// Examples :

// Input: str = i.like.this.program.very.much
// Output: much.very.program.this.like.i
// Explanation: After reversing the whole string(not individual words), the input string becomes much.very.program.this.like.i
// Input: str = pqr.mno
// Output: mno.pqr
// Explanation: After reversing the whole string , the input string becomes mno.pqr
// Expected Time Complexity: O(|str|)
// Expected Auxiliary Space: O(|str|)

// Constraints:
// 1 <= |str| <= 105

// Seen this question in a real interview before ?

class Solution
{
public:
    // Function to reverse words in a given string.
    string reverseWords(string str)
    {
        // code here
        string ans = "";
        int i = str.size() - 1;
        int j = 0;
        while (i >= 0)
        {
            if (str[i] != '.')
            {
                j++;
            }
            else if (str[i] == '.')
            {
                ans += str.substr(i + 1, j);
                j = 0;
                ans += '.';
            }
            i--;
        }
        ans += str.substr(i + 1, j);
        return ans;
    }
};
