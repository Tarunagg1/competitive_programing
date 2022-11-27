// Add Binary Strings
// MediumAccuracy: 23.25%Submissions: 23198Points: 4
// Given two binary strings A and B consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
// Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

// Example 1:

// Input:
// A = "1101", B = "111"
// Output: 10100
// Explanation:
//  1101
// + 111
// 10100
// Example 2:

// Input:
// A = "10", B = "01"
// Output: 11
// Explanation:
//   10
// + 01
//   11

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function addBinary() which takes 2 binary string A and B and returns a binary string denoting the addition of both the strings.

// Expected Time Complexity: O(max(|A|, |B|)).
// Expected Auxiliary Space: O(max(|A|, |B|)) (for output string).

// Constraints:
// 1 ≤ |A|, |B| ≤ 106

// View Bookmarked Problems

class Solution
{
public:
    string addBinary(string A, string B)
    {
        // your code here
        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());

        int i = 0, carry = 0;
        string res;
        while (i < A.size() || i < B.size() || carry > 0)
        {
            int sum = 0;
            if (i < A.size())
                sum += A[i] - '0';
            if (i < B.size())
                sum += B[i] - '0';
            sum += carry;
            int curr = sum % 2;
            carry = sum / 2;
            res.push_back(curr + '0');
            i++;
        }

        reverse(res.begin(), res.end());
        int count = 0;
        while (res[count] == '0')
            count++;
        return res.substr(count);
    }
};
