// Check if a number is divisible by 8
// EasyAccuracy: 22.22%Submissions: 33K+Points: 2
// Internship Alert!
// Become an SDE Intern by topping this monthly leaderboard!

// banner
// Given a string representation of a decimal number s, check whether it is divisible by 8.

// Example 1:

// Input:
// s = "16"
// Output:
// 1
// Explanation:
// The given number is divisible by 8,
// so the driver code prints 1 as the output.
// Example 2:

// Input:
// s = "54141111648421214584416464555"
// Output:
// -1
// Explanation:
// Given Number is not divisible by 8,
// so the driver code prints -1 as the output.
// Your Task:
// You don't need to read input or print anything.Your task is to complete the function DivisibleByEight() which takes a string s as the input and returns 1 if the number is divisible by 8, else it returns -1.

// Expected Time Complexity: O(1).
// Expected Auxillary Space: O(1).

// Constraints:
// 1 <= Number represented by the string s < 106

class Solution
{
public:
    int DivisibleByEight(string s)
    {
        // code here
        int n = s.length();
        int num = 0;
        if (n < 3)
        {
            num = stoi(s);
        }
        else
        {
            num = stoi(s.substr(n - 3, 3));
        }
        if (num % 8 == 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
};
