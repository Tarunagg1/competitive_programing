// Triangle and Square
// Easy Accuracy: 82.11% Submissions: 2086 Points: 2

// Lamp Geeks Summer Carnival is LIVE NOW
// Note: This POTD is a part of Geek Summer Carnival. Solve all POTD consecutively from 5th to 10th April and get a chance to win exclusive discount vouchers on our GfG courses.

// Geek has a ticket to the Geek Summer Carnival. The ticket has a positive integer B written on it. B denotes the base of a right-angled isosceles triangle.
// Geek can avail discounts on X courses in the carnival.

// X is the maximum number of squares of size 2x2 units that can fit in the given right-angled isosceles triangle.
// Find X.

// Example 1:

// Input:
// B = 8
// Output:
// 6
// Explanation:

// Example 2:

// Input:
// B = 2
// Output:
// 0

// Your Task:
// You don't need to read input or print anything. Complete the function countSquare() that takes integer b as input parameter and returns the number of possible squares that can fit into the isosceles triangle.

// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= B <= 1000


class Solution
{
public:
    int countSquare(int B)
    {
        // code here
        int count = 0;
        while (B > 0)
        {
            B -= 2;
            count += B / 2;
        }

        return count;
    }
};
}
