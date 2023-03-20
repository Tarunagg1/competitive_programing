
// Shortest XY distance in Grid
// MediumAccuracy: 76.41%Submissions: 3K+Points: 4
// Register NOW for the latest GFG Job-a-thon: Hiring Challenge !!

// Give a N*M grid of characters 'O', 'X', and 'Y'. Find the minimum Manhattan distance between a X and a Y.

// Manhattan Distance :
// | row_index_x - row_index_y | + | column_index_x - column_index_y |

// Example 1:

// Input:
// N = 4, M = 4
// grid  = {{X, O, O, O}
//          {O, Y, O, Y}
//          {X, X, O, O}
//          {O, Y, O, O}}
// Output:
// 1
// Explanation:
// {{X, O, O, O}
// {O, Y, O, Y}
// {X, X, O, O}
// {O, Y, O, O}}
// The shortest X-Y distance in the grid is 1.
// One possible such X and Y are marked in bold
// in the above grid.
// Example 2:

// Input:
// N = 3, M = 3
// grid = {{X, X, O}
//         {O, O, Y}
//         {Y, O, O}}
// Output :
// 2
// Explanation:
// {{X, X, O}
//  {O, O, Y}
//  {Y, O, O}}
// The shortest X-Y distance in the grid is 2.
// One possible such X and Y are marked in bold
// in the above grid.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function shortestXYDist() which takes two integers N, and M and an 2D list of size N*M as input and returns the shortest Manhattan Distance between a X and a Y.

// Expected Time Complexity: O(N*M)
// Expected Auxiliary Space: O(N*M)

// Constraints:
// 1 ≤ N, M ≤ 103

// There exists at least one 'X' and at least one 'Y' in the grid.

// View Bookmarked Problems

class Solution
{
public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M)
    {
        // code here
        vector<pair<int, int>> X;
        vector<pair<int, int>> Y;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j] == 'X')
                    X.push_back({i, j});

                if (grid[i][j] == 'Y')
                    Y.push_back({i, j});
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < X.size(); i++)
        {
            for (int j = 0; j < Y.size(); j++)
            {
                ans = min(ans, abs(X[i].first - Y[j].first) + abs(Y[j].second - X[i].second));
                if (ans == 1)
                    return ans;
            }
        }
        return ans;
    }
};
