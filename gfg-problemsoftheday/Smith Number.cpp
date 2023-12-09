// Smith Number
// MediumAccuracy: 50.0%Submissions: 17K+Points: 4
// Job-A-Thon Hiring Challenge: Now Revamped for Professionals. Fast-track your Resumes to Job Openings today

// banner
// Given a number n, the task is to find out whether this number is a Smith number or not. A Smith number is a composite number whose sum of digits is equal to the sum of digits of its prime factors.

// Example 1:

// Input:
// n = 4
// Output:
// 1
// Explanation:
// The sum of the digits of 4 is 4, and the sum of the digits of its prime factors is 2 + 2 = 4.
// Example 2:

// Input:
// n = 378
// Output:
// 1
// Explanation:
// 378 = 21*33*71 is a Smith number since 3+7+8 = 2*1+3*3+7*1.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function smithNum() which takes an Integer n as input and returns the answer.

// Expected Time Complexity: O(n * log(n))
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= n <= 105

class Solution
{
public:
    int smithNum(int n)
    {
        // code here
        int prime = 0;
        int digit = 0;
        int num = n;
        int flag = 0;
        int num2 = n;
        for (int i = 2; i < num2; i++)
        {
            if (num2 % i == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            return 0;
        }
        while (num > 0)
        {
            int rem = num % 10;
            digit = digit + rem;
            num = num / 10;
        }
        while (n % 2 == 0)
        {
            prime = prime + 2;
            n = n / 2;
        }
        for (int i = 3; i * i <= n; i += 2)
        {
            while (n % i == 0)
            {
                int res = i;
                while (res)
                {
                    prime += res % 10;
                    res /= 10;
                }
                // prime+=i;
                n = n / i;
            }
        }
        if (n > 2)
        {
            while (n > 0)
            {
                prime = prime + n % 10;
                n = n / 10;
            }
        }
        if (prime == digit)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
