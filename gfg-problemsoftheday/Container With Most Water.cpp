// Container With Most Water
// MediumAccuracy: 53.84%Submissions: 21K+Points: 4
// Lamp
// Land your Dream Job with Mega Job-a-thon. Register Now!

// Given N non-negative integers a1,a2,....an where each represents a point at coordinate (i, ai). N vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i,0). Find two lines, which together with x-axis forms a container, such that it contains the most water.

// Note : In Case of single verticle line it will not be able to hold water.

// Example 1:

// Input:
// N = 4
// a[] = {1,5,4,3}
// Output: 6
// Explanation: 5 and 3 are distance 2 apart.
// So the size of the base = 2. Height of
// container = min(5, 3) = 3. So total area
// = 3 * 2 = 6.
// Example 2:

// Input:
// N = 5
// a[] = {3,1,2,4,5}
// Output: 12
// Explanation: 5 and 3 are distance 4 apart.
// So the size of the base = 4. Height of
// container = min(5, 3) = 3. So total area
// = 4 * 3 = 12.
// Your Task :
// You only need to implement the given function maxArea. Do not read input, instead use the arguments given in the function and return the desired output.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1<=N<=105
// 1<=A[i]<=100

// View Bookmarked Problems

long long maxArea(long long A[], int len)
{
    // Your code goes here
    long long ans = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            ans = max(min(A[i], A[j]) * (j - i), ans);
        }
    }
    return ans;
}
