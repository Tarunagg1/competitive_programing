// Valid Compressed String
// MediumAccuracy: 54.15%Submissions: 7K+Points: 4
// Lamp
// Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!

// A special compression mechanism can arbitrarily delete 0 or more characters and replace them with the deleted character count.
// Given two strings, S and T where S is a normal string and T is a compressed string, determine if the compressed string  T is valid for the plaintext string S.

// Example 1:

// Input:
// S = "GEEKSFORGEEKS"
// T = "G7G3S"
// Output:
// 1
// Explanation:
// We can clearly see that T is a valid
// compressed string for S.

// Example 2:

// Input:
// S = "DFS"
// T = "D1D"
// Output :
// 0
// Explanation:
// T is not a valid compressed string.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function checkCompressed() which takes 2 strings S and T as input parameters and returns integer 1 if T is a valid compression of S and 0 otherwise.

// Expected Time Complexity: O(|T|)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ |S| ≤ 106
// 1 ≤ |T| ≤ 106
// All characters are either capital or numeric.

// View Bookmarked Problems

class Solution
{
public:
    int checkCompressed(string S, string T)
    {
        // code here
        int len = 0, idx = 0, flag = 0;
        for (int i = 0; i < T.length(); i++)
        {
            if (T[i] >= 'A' && T[i] <= 'Z')
            {
                if (T[i] != S[len])
                {
                    return 0;
                }
                else
                {
                    len++;
                }
            }
            else
            {
                int num = 0;
                while (!(T[i] >= 'A' && T[i] <= 'Z') && i < T.length())
                {
                    num = (num * 10) + (T[i] - '0');
                    i++;
                }
                i--;
                len += num;
            }
        }
        if (len == S.length())
        {
            return 1;
        }
        return 0;
    }
};
