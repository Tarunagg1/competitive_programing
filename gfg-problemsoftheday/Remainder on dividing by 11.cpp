// Remainder on dividing by 11
// EasyAccuracy: 58.87%Submissions: 5K+Points: 2
// Attend free LIVE Webinars with Summer Skill-Up Sessions! Enroll Now!

// Given a big positive number x represented as string, find value of x % 11 or x mod 11. Output is expected as an integer.

// Example 1:

// Input: x = 1345
// Output: 3
// Explanation: 1345 % 11 = 3
// Example 1:

// Input: x = 231456786543567898765
// Output: 1
// Explanation: 231456786543567898765 % 11 = 1

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function xmod11() which takes string x as the input parameter and returns the integer value of x%11.

// Expected Time Complexity: O(length of string x)
// Expected Space Complexity: O(1)

// Constraints:
// 1 ≤ length of string x ≤ 100000

// View Bookmarked Problems

class Solution
{

public:
    int xmod11(string x)
    {
        // code here
        int rem = 0;
        for (int i = 0; i < x.size(); i++)
        {
            rem = (rem * 10) + (x[i]);
            rem %= 11;
        }
        return rem;
    }
};
