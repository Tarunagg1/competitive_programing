// Walls Coloring
// MediumAccuracy: 83.2%Submissions: 4K+Points: 4
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// There is a row of N walls in Geeksland. The king of Geeksland ordered Alexa to color all the walls on the occasion of New Year. Alexa can color each wall with either pink, black, or yellow. The cost associated with coloring each wall with a particular color is represented by a 2D array colors of size N*3 , where colors[i][0], colors[i][1], and colors[i][2] is the cost of painting ith wall with colors pink, black, and yellow respectively.

// You need to find the minimum cost to color all the walls such that no two adjacent walls have the same color.

// Example 1:

// Input:
// N = 3
// colors[][] = {{14, 2, 11},
//              {11, 14, 5},
//              {14, 3, 10}}
// Output:
// 10
// Explanation:
// Color wall 0 with black. Cost = 2.
// Color wall 1 with yellow. Cost = 5.
// Color wall 2 with black. Cost = 3.
// Total Cost = 2 + 5 + 3 = 10
// Example 2:

// Input:
// N = 2
// colors[][] = {{1, 2, 3},
//              {1, 4, 6}}
// Output:
// 3
// Explanation:
// Color wall 0 with black. Cost = 2
// Color wall 1 with pink. Cost = 1
// Total Cost = 1 + 2 = 3
// Your Task:

// Your task is to complete the function minCost() which takes the 2D integer array colors and an integer N as the input parameters and returns an integer, representing the minimum cost to color all the walls.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:

// 1 <= N <= 105
// 1 <= colors[i][0], colors[i][1], colors[i][2] <= 104

// View Bookmarked Problems

class Solution
{
public:
    int minCost(vector<vector<int>> &colors, int N)
    {
        // Write your code here.
        for (int i = 0; i < N; i++)
        {

            for (int j = 0; j < 3; j++)
            {

                if (i == 0)
                {

                    continue;
                }

                if (j == 0)
                {

                    colors[i][j] = colors[i][j] + min(colors[i - 1][j + 1], colors[i - 1][j + 2]);
                }

                else if (j == 1)
                {

                    colors[i][j] = colors[i][j] + min(colors[i - 1][j - 1], colors[i - 1][j + 1]);
                }

                else
                {

                    colors[i][j] = colors[i][j] + min(colors[i - 1][j - 1], colors[i - 1][j - 2]);
                }
            }
        }

        return min(colors[N - 1][0], min(colors[N - 1][1], colors[N - 1][2]));
    }
};
