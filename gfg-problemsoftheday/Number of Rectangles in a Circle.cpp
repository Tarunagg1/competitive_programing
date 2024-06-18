// Number of Rectangles in a Circle
// MediumAccuracy: 72.29%Submissions: 6K+Points: 4
// Solve today's problem-> Be the comment of the day-> Win a GfG T-Shirt!
// Daily rewards up for grabs!

// banner
// Given a circular sheet of radius, r. Find the total number of rectangles with integral length and width that can be cut from the sheet that can fit on the circle, one at a time.

// Examples :

// Input: r=1
// Output: 1
// Explanation: Only 1 rectangle of dimensions 1x1.
// Input: r=2
// Output: 8
// Explanation: The 8 possible rectangles are
// (1x1)(1x2)(1x3)(2x1)(2x2)(2x3)(3x1)(3x2).
// Expected Time Complexity: O(r2)
// Expected Auxillary Space: O(1)

// Constraints:
// 1<=r<=1000

class Solution
{
public:
    int rectanglesInCircle(int r)
    {
        // code here
        int count = 0;

        for (int l = 1; l < 2 * r; l++)
        {
            for (int w = 1; w < 2 * r; w++)
            {
                if (l * l + w * w <= 4 * r * r)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
