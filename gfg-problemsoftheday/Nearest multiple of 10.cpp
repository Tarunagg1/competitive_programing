// Nearest multiple of 10
// Difficulty: EasyAccuracy: 19.32%Submissions: 60K+Points: 2
// A string str is given to represent a positive number. The task is to round str to the nearest multiple of 10.  If you have two multiples equally apart from str, choose the smallest element among them.

// Examples:

// Input: str = 29
// Output: 30
// Explanation: Close multiples are 20 and 30, and 30 is the nearest to 29.
// Input: str = 15
// Output: 10
// Explanation: 10 and 20 are equally distant multiples from 20. The smallest of the two is 10.
// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= str.size()<= 105

class Solution
{
public:
    string roundToNearest(string str)
    {
        // Complete the function
        int n = str.size();
        int val = str[n - 1] - '0';
        if (val <= 5)
        {
            str[n - 1] = '0';
        }
        else
        {
            val = 10 - val;
            int carry = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                int temp = val + carry + (str[i] - '0');
                str[i] = (temp % 10) + '0';
                carry = temp / 10;
                val = 0;
            }
            if (carry > 0)
                str = "1" + str;
        }
        return str;
    }
};
