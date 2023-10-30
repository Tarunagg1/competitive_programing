// Sum of XOR of all pairs
// MediumAccuracy: 45.14%Submissions: 15K+Points: 4
// GfG Weekly + You = Perfect Sunday Evenings!
// Register for free now

// banner
// Given an array of N integers, find the sum of xor of all pairs of numbers in the array arr. In other words, select all possible pairs of i and j from 0 to N-1 (i<j) and determine sum of all (arri xor arrj).

// Example 1:

// Input : arr[ ] = {7, 3, 5}
// Output : 12
// Explanation:
// All possible pairs and there Xor
// Value: ( 3 ^ 5 = 6 ) + (7 ^ 3 = 4)
//  + ( 7 ^ 5 = 2 ) =  6 + 4 + 2 = 12
// Example 2:

// Input : arr[ ] = {5, 9, 7, 6}
// Output :  47
// Explanation:
// All possible pairs and there Xor
// Value: (5 ^ 9 = 12) + (5 ^ 7 = 2)
//  + (5 ^ 6 = 3) + (9 ^ 7 = 14)
//  + (9 ^ 6 = 15) + (7 ^ 6 = 1)
//  = 12 + 2 + 3 + 14 + 15 + 1 = 47
// Your Task:
// You do not have to take input or print output. You only need to complete the function sumXOR() that takes an array (arr), sizeOfArray (n), and return the sum of xor of all pairs of numbers in the array.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(1).

// Constraints
// 2 ≤ n ≤ 105
// 1 ≤ arr[i] ≤ 105

class Solution
{
public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
        // Complete the function
        long long int ret = 0;
        vector<int> bits(32, 0);
        for (int i = 0; i < n; i++)
        {
            for (int b = 0; b < 32; b++)
            {
                if (arr[i] & (1 << b))
                {
                    // then, add unset bits to answer
                    ret += (i - bits[b]) * 1ll * (1 << b);
                    bits[b]++;
                }
                else
                {
                    // then, add set bits to answer
                    ret += bits[b] * 1ll * (1 << b);
                }
            }
        }
        return ret;
    }
};
