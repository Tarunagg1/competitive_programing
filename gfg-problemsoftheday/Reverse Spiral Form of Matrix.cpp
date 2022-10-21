// Reverse Spiral Form of Matrix
// MediumAccuracy: 74.91%Submissions: 681Points: 4
// Given a matrix as 2D array. Find the reverse spiral traversal of the matrix.

// Example 1:

// Input: R = 3, C = 3
//   a = {{9, 8, 7},
//        {6, 5, 4},
//        {3, 2, 1}}
// Output: 5 6 3 2 1 4 7 8 9
// Explanation: Spiral form of the matrix
// in reverse order starts from the centre
// and goes outward.

// Example 2:

// Input: R = 4, C = 4
//   a = {{1, 2, 3, 4},
//        {5, 6, 7, 8},
//        {9, 10, 11, 12},
//        {13, 14, 15, 16}}
// Output: 10 11 7 6 5 9 13 14 15 16 12 8 4 3 2 1
// Explanation:

// Your Task:
// You dont need to read input or print anything. Complete the function reverseSpiral() which takes R, C and a as input parameters and returns the matrix in reverse spiral form.

// Expected Time Complexity: O(R*C)
// Expected Auxiliary Space: O(R*C)

// Constraints:
// 1 <= R,C <=100
// 1 <= a[R][C] <=100

// View Bookmarked Problems

class Solution
{
public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>> &a)
    {
        // code here
        vector<int> ans;

        int startingrow = 0;

        int endingrow = R - 1;

        int startingcol = 0;

        int endingcol = C - 1;

        int total = R * C;

        int count = 0;

        while (count < total)
        {

            // print first row

            for (int i = startingcol; i <= endingcol && count < total; i++)
            {

                int x = a[startingrow][i];

                ans.push_back(x);

                count++;
            }

            startingrow++;

            // printing last col

            for (int i = startingrow; i <= endingrow && count < total; i++)
            {

                int x = a[i][endingcol];

                ans.push_back(x);

                count++;
            }

            endingcol--;

            // printing last row

            for (int i = endingcol; i >= startingcol && count < total; i--)
            {

                int x = a[endingrow][i];

                ans.push_back(x);

                count++;
            }

            endingrow--;

            // printing first col

            for (int i = endingrow; i >= startingrow && count < total; i--)
            {

                int x = a[i][startingcol];

                ans.push_back(x);

                count++;
            }

            startingcol++;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
