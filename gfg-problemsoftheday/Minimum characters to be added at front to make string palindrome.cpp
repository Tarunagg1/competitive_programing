// Minimum characters to be added at front to make string palindrome
// HardAccuracy: 43.43%Submissions: 4659Points: 8
// Given string str of length N. The task is to find the minimum characters to be added at the front to make string palindrome.
// Note: A palindrome is a word which reads the same backward as forward. Example: "madam".

// Example 1:

// Input:
// S = "abc"
// Output: 2
// Explanation:
// Add 'b' and 'c' at front of above string to make it
// palindrome : "cbabc"
// Example 2:

// Input:
// S = "aacecaaa"
// Output: 1
// Explanation: Add 'a' at front of above string
// to make it palindrome : "aaacecaaa"
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function minChar() which takes a string S and returns an integer as output.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= S.length <= 106

class Solution
{
public:
    int minChar(string str)
    {
        // Write your code here
        int l = str.length();
        int i;
        int j = l - 1;
        int j_temp = j;
        i = 0;
        int count = 0;
        while ((i != l) && (j != -1))
        {
            if (str[i] == str[j])
            {
                i++;
                j--;
                continue;
            }
            count++;
            i = 0;
            j_temp--;
            j = j_temp;
        }
        return (count);
    }
};
