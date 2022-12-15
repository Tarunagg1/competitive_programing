// Balanced string
// EasyAccuracy: 19.07%Submissions: 1K+Points: 2
// Given an integer N.Create a string using only lowercase characters from a to z that follows the given rules.

// When N is even:

// Use N/2 characters from the beginning of a-z and N/2 characters from the ending of a-z.

// When N is greater than 26,continue repeating the instructions until length of string becomes N.

// When N is odd:

// Case 1: If the sum of digits of N is even, Select (N+1)/2 characters from the beginning of a-z and (N-1)/2 characters from the ending of a-z.

// Case 2: If the sum of digits of N is odd, Select (N-1)/2 characters from the beginning of a-z and (N+1)/2 characters from the ending of a-z.

// When N is greater than 26,continue repeating the instructions until length of string becomes N.

// Example 1:

// Input:
// N=21
// Output:
// abcdefghijpqrstuvwxyz
// Explanation:
// Since 21 is odd and sum of digits
// of 21 is also odd,we take (21-1)/2=10
// characters from the beginning and
// (21+1)/2=11 characters from the
// end of a-z.
// Example 2:

// Input:
// N=28
// Output:
// abcdefghijklmnopqrstuvwxyzaz
// Explanation:
// Since 28>26, we keep repeating
// the process until length of string becomes
// 28.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function BalancedString() which takes the integer N as input parameter and returns the string created using given procedures.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 105

// View Bookmarked Problems

class Solution
{
public:
    string BalancedString(int N)
    {
        // code here
        string alphabet = "abcdefghijklmnopqrstuvwxyz";

        string ans = "";

        int dig = N;

        while (N > 26)
        {

            ans += alphabet;

            N -= 26;
        }

        int start = 0, end = 0;

        int sum = 0;

        while (dig > 0)
        {

            sum += dig % 10;

            dig /= 10;
        }

        if ((N & 1) == 1)
        {

            if ((sum & 1) == 1)
            {

                start = (N - 1) / 2;

                end = (N + 1) / 2;
            }
            else
            {

                start = (N + 1) / 2;

                end = (N - 1) / 2;
            }
        }
        else
        {

            start = N / 2;

            end = N / 2;
        }

        ans += alphabet.substr(0, (start));

        ans += alphabet.substr((26 - end), end);

        return ans;
    }
};
