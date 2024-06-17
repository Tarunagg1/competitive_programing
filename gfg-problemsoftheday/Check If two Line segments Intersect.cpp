// Check If two Line segments Intersect
// MediumAccuracy: 24.51%Submissions: 23K+Points: 4
// Solve today's problem-> Be the comment of the day-> Win a GfG T-Shirt!
// Daily rewards up for grabs!

// banner
// Given the coordinates of the endpoints(p1,q1, and p2,q2) of the two line segments. Check if they intersect or not. If the Line intersects return true otherwise return false.

// Note: Please check the intersection within the line segments.

// Examples

// Input: p1=(1,1), q1=(10,1), p2=(1,2), q2=(10,2)
// Output: false
// Explanation:The two line segments formed by p1-q1 and p2-q2 do not intersect.
// Input: p1=(10,0), q1=(0,10), p2=(0,0), q2=(10,10)
// Output: true
// Explanation: The two line segments formed by p1-q1 and p2-q2 intersect.
// Input: p1=(5,-2), q1=(13,2), p2=(2,-3), q2=(3,0)
// Output: false
// Explanation: The two line segments formed by p1-q1 and p2-q2 are intersecting beyond endpoints, so it is not considerable.
// Expected Time Complexity: O(1)
// Expected Auxillary Space: O(1)

// Constraints:
// -106<=X,Y(for all points)<=106

class Solution
{
public:
    int orientation(int p[], int q[], int r[])
    {
        long long val = (long long)(q[1] - p[1]) * (r[0] - q[0]) - (long long)(r[1] - q[1]) * (q[0] - p[0]);
        if (val == 0)
            return 0;
        return (val > 0) ? 1 : 2;
    }

    bool onsegment(int a[], int b[], int c[])
    {
        if ((c[0] >= min(a[0], b[0]) && c[0] <= max(a[0], b[0])) && (c[1] >= min(a[1], b[1]) && c[1] <= max(a[1], b[1])))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string doIntersect(int p1[], int q1[], int p2[], int q2[])
    {
        // code here
        int o1 = orientation(p1, q1, p2);
        int o2 = orientation(p1, q1, q2);
        int o3 = orientation(p2, q2, p1);
        int o4 = orientation(p2, q2, q1);

        if (o1 != o2 && o3 != o4)
            return "true";

        if (o1 == 0 && onsegment(p1, q1, p2))
            return "true";
        if (o2 == 0 && onsegment(p1, q1, q2))
            return "true";
        if (o3 == 0 && onsegment(p2, q2, p1))
            return "true";
        if (o4 == 0 && onsegment(p2, q2, q1))
            return "true";

        return "false";
    }
};
