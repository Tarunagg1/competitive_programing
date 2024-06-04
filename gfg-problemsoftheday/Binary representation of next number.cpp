// Binary representation of next number
// EasyAccuracy: 50.0%Submissions: 17K+Points: 2
// In need of more Geekbits? Win from a pool of 3500+ Geekbits via DSA-based Coding Contest every sunday!

// banner
// Given a binary representation in the form of a string(s) of a number n, the task is to find a binary representation of n+1.

// Note: Output binary string should not contain leading zeros.

// Example 1:

// Input: s = "10"
// Output: 11
// Explanation: "10" is the binary representation of 2 and binary representation of 3 is "11"
// Example 2:

// Input: s = "111"
// Output: 1000
// Explanation: "111" is the binary representation of 7 and binary representation of 8 is "1000"
// Your Task:
// You don't need to read input or print anything. Complete the function binaryNextNumber()which takes s as input parameter and returns the string.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n) to store resultant string

// Constraints:
// 1 <= n <= 105

class Solution
{
public:
    string binaryNextNumber(string s)
    {
        // code here.
        int zero = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
            {
                zero++;
            }
            else
            {
                break;
            }
        }
        s.erase(s.begin(), s.begin() + zero);
        reverse(s.begin(), s.end());
        int carry = 0;
        int first = s[0] - '0';
        if (first == 0)
        {
            s[0] = '1';
            reverse(s.begin(), s.end());
            string st = s;
            return st;
        }
        carry = 1;
        s[0] = '0';
        for (int i = 1; i < s.length(); i++)
        {
            if (carry & s[i] == '1')
            {
                s[i] = '0';
            }
            else
            {
                s[i] = '1';
                carry--;
                break;
            }
        }
        if (carry)
        {
            s += '1';
        }
        reverse(s.begin(), s.end());
        string st = s;
        return st;
    }
};
