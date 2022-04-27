// Killing Spree
// Medium Accuracy: 59.97% Submissions: 2243 Points: 4
// There are Infinite People Standing in a row, indexed from 1.
// A person having index 'i' has strength of (i*i).
// You have Strength 'P'. You need to tell what is the maximum number of People You can Kill With your Strength P.
// You can only Kill a person with strength 'X' if P >= 'X'  and after killing him, Your Strength decreases by 'X'.

// Example 1:

// Input:
// N = 14
// Output: 3
// Explanation:
// The strengths of people is 1, 4, 9, 16, ....
// and so on. WE can kill the first 3 person ,
// after which our Power becomes 0 and we cant
// kill anyone else. So answer is 3

// Example 2:

// Input:
// N = 10
// Output: 2

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function killinSpree() which takes the integer N as input parameters and returns the maximum Number of People You can kill.

// Expected Time Complexity: O(log(n))
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ T ≤ 103
// 1 ≤ N ≤ 1012

// View Bookmarked Problems
// Topic Tags

class Solution
{
public:
    long long int killinSpree(long long int n)
    {
        // Code Here
        long long int l = 0, r = sqrt(n), ans = 0;
        while (l <= r)
        {
            long long int mid = (l + r) / 2;
            long long int val = (mid * (mid + 1) * ((2 * mid) + 1)) / 6; // summation of square of first n natural numbers
            if (val <= n)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
};

