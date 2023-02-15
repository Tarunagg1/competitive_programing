// Geeks Island
// MediumAccuracy: 79.61%Submissions: 3K+Points: 4
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// Geeks Island is represented by an N * M matrix mat. The island is touched by the Indian Ocean from the top and left edges and the Arabian Sea from the right and bottom edges. Each element of the matrix represents the height of the cell.

// Due to the rainy season, the island receives a lot of rainfall, and the water can flow in four directions(up, down, left, or right) from one cell to another one with height equal or lower.

// You need to find the number of cells from where water can flow to both the Indian Ocean and the Arabian Sea.

// Example 1:

// Input:
// N = 5, M = 5
// mat[][] =    {{1, 3, 3, 2, 4},
//                {4, 5, 6, 4, 4},
//                {2, 4, 5, 3, 1},
//                {6, 7, 1, 4, 5},
//                {6, 1, 1, 3, 4}}
// Output:
// 8
// Explanation:
// Indian    ~   ~   ~   ~   ~
// Ocean  ~  1   3   3   2  (4) *
//         ~  4   5  (6) (4) (4) *
//         ~  2   4  (5)  3   1  *
//         ~ (6) (7)  1   4   5  *
//         ~ (6)  1   1   3   4  *
//            *   *   *   *   * Arabian Sea
// Water can flow to both ocean and sea from the cells
// denoted by parantheses().For example at index(1,2), the height of that island is 6. If a water drop falls on that island, water can flow to up direction(as 3<=6) and reach to Indian Ocean. ALso, water can flow to right direction(as 6>=4>=4) and reach to Arabian Sea.
// Example 2:

// Input:
// N = 3, M = 2
// mat[][] =    {{1, 1, 1},
//                {1, 1, 1}}
// Output:
// 6
// Explanation:
// Water can flow from all cells to both Indian Ocean and Arabian Sea as the height of all islands are same.
// Your Task:

// Your task is to complete the function water_flow() which takes an integer array mat, integer N and integer M as the input parameter and returns an integer, denoting the number of cells from which water can to both ocean and sea.

// Expected Time Complexity : O(N*M)
// Expected Auxiliary Space : O(N*M)

// Constraints:

// 1 <= N, M <= 103
// 1 <= mat[i][j] <= 106
// View Bookmarked Problems

class Solution
{
public:
private:
    int dr[4] = {1, 0, -1, 0};

    int dc[4] = {0, -1, 0, 1};

    bool isvalid(int row, int col, int N, int M)
    {

        return (row >= 0 && row < N && col >= 0 && col < M);
    }

    void dfsSolve(int row, int col, vector<vector<bool>> &vis, vector<vector<int>> &mat, int &N, int &M)
    {

        vis[row][col] = true;

        int val = mat[row][col];

        for (int i = 0; i < 4; i++)
        {

            int nrow = row + dr[i];

            int ncol = col + dc[i];

            if (isvalid(nrow, ncol, N, M) && !vis[nrow][ncol] && mat[nrow][ncol] >= val)
            {

                dfsSolve(nrow, ncol, vis, mat, N, M);
            }
        }
    }

public:
    int water_flow(vector<vector<int>> &mat, int N, int M)
    {

        // Write your code here.

        vector<vector<bool>> indianVis(N, vector<bool>(M, false));

        vector<vector<bool>> arabVis(N, vector<bool>(M, false));

        for (int i = 0; i < N; i++)
            dfsSolve(i, 0, indianVis, mat, N, M);

        for (int j = 0; j < M; j++)
            dfsSolve(0, j, indianVis, mat, N, M);

        for (int i = 0; i < N; i++)
            dfsSolve(i, M - 1, arabVis, mat, N, M);

        for (int j = 0; j < M; j++)
            dfsSolve(N - 1, j, arabVis, mat, N, M);

        int ans = 0;

        for (int i = 0; i < N; i++)
        {

            for (int j = 0; j < M; j++)
            {

                if (indianVis[i][j] && arabVis[i][j])
                    ans++;
            }
        }

        return ans;
    }
};
