// Geek hates too many 1s
// MediumAccuracy: 78.25%Submissions: 3K+Points: 4
// Lamp
// Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!

// Given an non-negative integer n. You are only allowed to make set bit unset. You have to find the maximum possible value of query so that after performing the given operations, no three consecutive bits of the integer query are set-bits.

// Example 1:

// Input:
// n = 2
// Output:
// 2
// Explanation:
// 2's binary form is 10, no 3 consecutive set bits are here.
// So, 2 itself would be answer.
// Example 2:

// Input:
// n = 7
// Output:
// 6
// Explanation:
// 7's binary form is .....00111.We can observe that 3
// consecutive bits are set bits. This is not allowed.
// So, we can perfrom the operation of changing set
// bit to unset bit. Now, the number
// becomes 6 that is .....00110. It satifies the
// given condition. Hence, the maximum possible
// value is 6.

// Your Task:   You don't need to read input or print anything. Your task is to complete the function noConseBits(), which takes integer n as input parameter and returns the maximum value possible so that it satifies the given condition.

// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

// Constraints:
// 0 ≤ n ≤ 109

// View Bookmarked Problems

class Solution
{

public:
    int noConseBits(int n)
    {
        // code here
        vector<int> binary;
        while (n > 0)
        {
            // storing remainder in binary array
            binary.push_back(n % 2);
            n = n / 2;
        }
        reverse(binary.begin(), binary.end());
        // check if three consecutive ones are there then make last 1 to zero
        int c = 0;
        n = binary.size();
        int i = 0;

        while (i < n)
        {
            if (binary[i] == 1)
                c++;
            else
                c = 0;
            if (c == 3)
            {
                binary[i] = 0;
                c = 0;
            }
            i++;
        }

        // reform the number to integer
        n = 0;
        for (auto &x : binary)
        {
            n <<= 1;
            n += x;
        }
        return n;
    }
};
