// Maximum number of 2X2 squares
// EasyAccuracy: 61.07%Submissions: 693Points: 2
// Given the base (in units) of a right-angled isoceles traingle, find the maximum number of 2X2 squares that can fit in the triangle with given base.

// Example 1:

// Input: 8
// Output: 6
// Explanation:
// Please refer below diagram for explanation.
// squares-in-triangle

// Example 2:

// Input : 7
// Output : 3
// Explanation : In the base we can keep 2 squares
// and above the two squares we can only keep 1 square.
// So the total number of squares are equal to 3.

// Your task :
// You don't need to read input or print anything. Your task is to complete the function numberOfSquares() which takes the base of the triangle as input and returns the maximum number of squares that can be fit into the triangle with given base.

// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

// Constraints :
// 1 <= N <= 10^9
// View Bookmarked Problems

class Solution
{
public:
    long long int numberOfSquares(long long int base)
    {
        // code here
        if (base <= 3)
        {

            return 0;
        }

        (base % 2 == 1) ? base -= 3 : base -= 2;

        base /= 2;

        return (base * (base + 1)) / 2;
    }
};
