// Modified Numbers and Queries
// EasyAccuracy: 60.29%Submissions: 78Points: 2
// Find the sum of all the numbers between the range l and r. Here each number is represented by the sum of its prime factors.
// Note : For example, 6 is represented by 5 because 6 has two prime factors 2 and 3 and 2 + 3 = 5.

// Example 1:

// Input: l = 1, r = 2
// Output: 3
// Explanation: 1->1, 2->2 and 1+2=3.

// Example 2:

// Input: l = 1, r = 6
// Output: 18
// Explanation: 1->1, 2->2, 3->3, 4->2
// 5->5, 6->2+3=5, 1+2+3+2+5+5 = 18.

// Your Task:
// You dont need to read input or print anything. Complete the function sumOfAll() which takes l and r as input parameter and returns sum all the numbers ( as represented ) in the given range both L and R included.

// Expected Time Complexity: O(nloglogn)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= l <= r <=104

class Solution
{
    bool isPrime(int n)
    {

        if (n == 1)
            return false;

        for (int i = 2; i <= sqrt(n); i++)
        {

            if (n % i == 0)
                return false;
        }

        return true;
    }

    long long sendFactors(int num)
    {

        long long sum = 0;

        for (int i = 2; i <= num / 2; i++)
        {

            if (num % i == 0 && isPrime(i))
                sum += i;
        }

        return sum;
    }

public:
    int sumOfAll(int l, int r)
    {

        // code here

        long long Fsum = 0;

        for (int i = l; i <= r; i++)
        {

            long long getSum = sendFactors(i);

            if (getSum)
                Fsum += getSum;

            else
                Fsum += i;
        }

        return Fsum;
    }
};
