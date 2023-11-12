// Check if string is rotated by two places
// EasyAccuracy: 32.7%Submissions: 172K+Points: 2
// GfG Weekly + You = Perfect Sunday Evenings!
// Register for free now

// banner
// Given two strings a and b. The task is to find if the string 'b' can be obtained by rotating (in any direction) string 'a' by exactly 2 places.

// Example 1:

// Input:
// a = amazon
// b = azonam
// Output:
// 1
// Explanation:
// amazon can be rotated anti-clockwise by two places, which will make it as azonam.
// Example 2:

// Input:
// a = geeksforgeeks
// b = geeksgeeksfor
// Output:
// 0
// Explanation:
// If we rotate geeksforgeeks by two place in any direction, we won't get geeksgeeksfor.
// Your Task:
// The task is to complete the function isRotated() which takes two strings as input parameters and checks if given strings can be formed by rotations. The function returns true if string 1 can be obtained by rotating string 2 by two places, else it returns false.

// Expected Time Complexity: O(N).
// Expected Auxilary Complexity: O(N).
// Challenge: Try doing it in O(1) space complexity.

// Constraints:
// 1 ≤ length of a, b ≤ 105

class Solution
{
public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        if (str1.length() != str2.length())
        {
            return false;
        }
        string rot_clock = str1.substr(2) + str1.substr(0, 2);
        string rot_anti = str1.substr(str1.length() - 2) + str1.substr(0, str1.length() - 2);
        if (rot_clock == str2)
        {
            return true;
        }
        if (rot_anti == str2)
        {
            return true;
        }
        return false;
    }
};
