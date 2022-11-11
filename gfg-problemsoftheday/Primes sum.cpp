// Primes sum
// EasyAccuracy: 21.74%Submissions: 12856Points: 2
// Given a number N. Find if it can be expressed as sum of two prime numbers.

// Example 1:

// Input: N = 34
// Output: "Yes"
// Explanation: 34 can be expressed as
// sum of two prime numbers.
// Example 2:

// Input: N = 23
// Output: "No"
// Explanation: 23 cannnot be expressed as
// sum of two prime numbers.

// Your Task:
// You dont need to read input or print anything. Complete the function isSumOfTwo() which takes N as input parameter and returns "Yes" if can be expressed as sum of two prime numbers. else return "No".

// Expected Time Complexity: O(N*sqrt(N))
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 105

// View Bookmarked Problems

class Solution
{
public:
    string isSumOfTwo(int n)
    {
        vector<bool> nums(n, true);
        vector<int> primes;
        primes.push_back(1);
        for (int i = 2; i < n; i++)
        {
            for (int j = 2 * i; j < n; j += i)
            {
                nums[j] = false;
            }
            if (nums[i] == true)
            {
                primes.push_back(i);
            }
        }

        int i = 0, j = primes.size() - 1;
        while (j > i)
        {
            int temp = primes[i] + primes[j];
            if (temp == n)
                return "Yes";
            else if (temp > n)
                j--;
            else
                i++;
        }
        return "No";
    }
};
