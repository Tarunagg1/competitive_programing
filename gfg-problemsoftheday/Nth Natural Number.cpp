// Nth Natural Number
// Difficulty: MediumAccuracy: 29.99%Submissions: 58K+Points: 4
// Given a positive integer n. You have to find nth natural number after removing all the numbers containing the digit 9.

// Examples :

// Input: n = 8
// Output: 8
// Explanation: After removing natural numbers which contains digit 9, first 8 numbers are 1,2,3,4,5,6,7,8 and 8th number is 8.
// Input: n = 9
// Output: 10
// Explanation: After removing natural numbers which contains digit 9, first 9 numbers are 1,2,3,4,5,6,7,8,10 and 9th number is 10.
// Expected Time Complexity: O(logn)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ n ≤ 109

class Solution
{
public:
    long long findNth(long long n)
    {
        // code here.
        long long ans = 0;
        long long mult = 1;
        while (n > 0)
        {
            ans += (n % 9) * mult;
            n /= 9;
            mult *= 10;
        }
        return ans;
    }
};
