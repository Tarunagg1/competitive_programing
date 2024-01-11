// Remove K Digits
// MediumAccuracy: 26.8%Submissions: 31K+Points: 4
// You've won Geekbits by solving daily. Now win 90% of your money-back by learning daily!

// banner
// Given a non-negative integer S represented as a string, remove K digits from the number so that the new number is the smallest possible.
// Note : The given num does not contain any leading zero.

// Example 1:

// Input:
// S = "149811", K = 3
// Output:
// 111
// Explanation:
// Remove the three digits
// 4, 9, and 8 to form the new number 111
// which is smallest.
// Example 2:

// Input:
// S = "1002991", K = 3
// Output:
// 21
// Explanation:
// Remove the three digits 1(leading
// one), 9, and 9 to form the new number 21(Note
// that the output must not contain leading
// zeroes) which is the smallest.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function removeKdigits() which takes the string S and an integer K as input and returns the new number which is the smallest possible.

// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(|S|).

// Constraints:
// 1<= K <= |S|<=106

class Solution
{
public:
    string removeKdigits(string S, int k)
    {
        int n = S.size();
        stack<char> myStack;

        for (auto c : S)
        {
            while (!myStack.empty() && k > 0 && myStack.top() > c)
            {
                myStack.pop();
                k--;
            }

            if (!myStack.empty() || c != '0')
            {
                myStack.push(c);
            }
        }

        // if string in incresing oder
        while (!myStack.empty() && k--)
        {
            myStack.pop();
        }

        if (myStack.empty())
        {
            return "0";
        }

        while (!myStack.empty())
        {
            S[n - 1] = myStack.top();
            myStack.pop();
            n--;
        }

        return S.substr(n);
    }
};
