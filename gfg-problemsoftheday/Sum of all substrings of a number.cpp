// Sum of all substrings of a number
// MediumAccuracy: 38.11%Submissions: 31K+Points: 4
// Given an integer s represented as a string, the task is to get the sum of all possible sub-strings of this string.
// As the answer will be large, return answer modulo 109+7.

// Note: The number may have leading zeros.

// Example 1:

// Input:
// s = "1234"
// Output:
// 1670
// Explanation:
// Sum = 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234 = 1670
// Example 2:

// Input:
// s = "421"
// Output:
// 491
// Explanation:
// Sum = 4 + 2 + 1 + 42 + 21 + 421 = 491
// Your Task:
// You only need to complete the function sumSubstrings that takes s as an argument and returns the answer modulo 109+7.

// Expected Time Complexity: O(|s|).
// Expected Auxiliary Space: O(|s|).

// Constraints:
// 1 <= |s| <= 105

class Solution
{
public:
    // Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s)
    {

        // your code here
        long long sum = 0;
        long long multiplier = 1;
        long long mod = 1000000007;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            sum = (sum + (s[i] - '0') * multiplier * (i + 1)) % mod;
            multiplier = (multiplier * 10 + 1) % mod;
        }
        return sum;
    }
};
