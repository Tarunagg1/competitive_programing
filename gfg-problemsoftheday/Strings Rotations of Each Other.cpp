// Strings Rotations of Each Other
// Difficulty: EasyAccuracy: 43.83%Submissions: 197K+Points: 2
// You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.

// Note: The characters in the strings are in lowercase.

// Examples :

// Input: s1 = "abcd", s2 = "cdab"
// Output: true
// Explanation: After 2 right rotations, s1 will become equal to s2.
// Input: s1 = "aab", s2 = "aba"
// Output: true
// Explanation: After 1 left rotation, s1 will become equal to s2.
// Input: s1 = "abcd", s2 = "acbd"
// Output: false
// Explanation: Strings are not rotations of each other.
// Constraints:
// 1 <= s1.size(), s2.size() <= 105

class Solution
{
public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2)
    {
        // Your code here
        if (s1.length() != s2.length())
        {
            return false;
        }

        // Construct the temporary string
        string temp = s2 + "$" + s1 + s1;
        int n = temp.length();

        // Initialize the LPS (Longest Prefix Suffix) array
        vector<int> arr(n, 0);
        int i = 1;
        int len = 0;

        // Build the LPS array
        while (i < n)
        {
            if (temp[i] == temp[len])
            {
                len++;
                arr[i] = len;
                i++;
            }
            else
            {
                if (len > 0)
                {
                    len = arr[len - 1];
                }
                else
                {
                    i++;
                }
            }
        }

        // Check if the length of `s1` appears in the LPS array
        for (int a : arr)
        {
            if (a == s1.length())
            {
                return true;
            }
        }
        return false;
    }
};
