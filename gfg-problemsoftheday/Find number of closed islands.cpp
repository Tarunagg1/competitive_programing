// Find number of closed islands
// HardAccuracy: 57.36%Submissions: 3K+Points: 8
// Applying for Jobs, Now Easier Than Today's Problem! Explore Now

// Given a binary matrix mat[][] of dimensions NxM such that 1 denotes land and 0 denotes water. Find the number of closed islands in the given matrix.

// Note: A closed island is a group of 1s surrounded by only 0s on all the boundaries (except diagonals). In simple words, a closed island is an island whose none of the 1s lie on the edges of the matrix.

// Example 1:

// Input:
// N = 5, M = 8
// mat[][] = {{0, 0, 0, 0, 0, 0, 0, 1},
//            {0, 1, 1, 1, 1, 0, 0, 1},
//            {0, 1, 0, 1, 0, 0, 0, 1},
//            {0, 1, 1, 1, 1, 0, 1, 0},
//            {1, 0, 0, 0, 0, 1, 0, 1}}
// Output:
// 2
// Explanation:
// mat[][] = {{0, 0, 0, 0, 0, 0, 0, 1},
//            {0, 1, 1, 1, 1, 0, 0, 1},
//            {0, 1, 0, 1, 0, 0, 0, 1},
//            {0, 1, 1, 1, 1, 0, 1, 0},
//            {1, 0, 0, 0, 0, 1, 0, 1}}
// There are 2 closed islands. The islands in dark are closed because they are completely surrounded by 0s (water). There are two more islands in the last column of the matrix, but they are not completely surrounded by 0s. Hence they are not closed islands.
// Example 2:

// Input:
// N = 3, M = 3
// mat[][] = {{1, 0, 0},
//            {0, 1, 0},
//            {0, 0, 1}}
// Output:
// 1
// Explanation:
// mat[][] = {{1, 0, 0},
//           {0, 1, 0},
//           {0, 0, 1}}
// There is just a one closed island.
// Your task:
// You dont need to read input or print anything. Your task is to complete the function closedIslands() which takes two integers N and M, and a 2D binary matrix mat as input parameters and returns the number of closed islands.

// Expected Time Complexity: O(N*M)
// Expected Auxiliary Space: O(N*M)

// Constraints:
// 1 ≤ N,M ≤ 500

class Solution
{
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool dfs(vector<vector<int>> &matrix, int i, int j, int N, int M)
    {

        if (i == 0 || i == N - 1 || j == 0 || j == M - 1)
            return false;

        matrix[i][j] = 0;

        bool rs = true;
        for (int t = 0; t < 4; t++)
        {

            int x = i + dx[t];
            int y = j + dy[t];

            if (x >= 0 && x < N && y >= 0 && y < M && matrix[x][y])
                rs &= dfs(matrix, x, y, N, M);
        }

        return rs;
    }

    int closedIslands(vector<vector<int>> &matrix, int N, int M)
    {
        // Code here

        int cnt = 0;
        for (int i = 1; i < N; i++)
        {
            for (int j = 1; j < M; j++)
            {

                if (matrix[i][j])
                {

                    if (dfs(matrix, i, j, N, M))
                        cnt += 1;
                }
            }
        }

        return cnt;
    }
};
