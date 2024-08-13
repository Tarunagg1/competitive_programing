// Square root of a number
// Difficulty: EasyAccuracy: 54.03%Submissions: 231K+Points: 2
// Given an integer n, find the square root of n. If n is not a perfect square, then return the floor value.

// Floor value of any number is the greatest Integer which is less than or equal to that number

// Examples:

// Input: n = 5
// Output: 2
// Explanation: Since, 5 is not a perfect square, floor of square_root of 5 is 2.
// Input: n = 4
// Output: 2
// Explanation: Since, 4 is a perfect square, so its square root is 2.
// Expected Time Complexity: O(logn)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ n ≤ 107

// Seen this question in a real interview before ?
// Yes
// No
// Company Tags

class Solution
{
public:
    long long int floorSqrt(long long int n)
    {
        // Your code goes here
        if (n == 0 || n == 1)
        {
            return n;
        }

        long long start = 1, end = n, ans = 0;
        while (start <= end)
        {
            long long mid = (start + end) / 2;

            // Check if mid*mid is equal to n
            if (mid * mid == n)
            {
                return mid;
            }

            // If mid*mid is less than n, discard the left half
            if (mid * mid < n)
            {
                start = mid + 1;
                ans = mid; // Store the floor value of sqrt(n)
            }
            // If mid*mid is greater than n, discard the right half
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }
};
