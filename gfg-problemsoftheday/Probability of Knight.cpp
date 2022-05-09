// Probability of Knight
// Medium Accuracy: 57.52% Submissions: 2328 Points: 4
// Given an NxN chessboard and a Knight at position (x, y). The Knight has to take exactly K steps, where at each step it chooses any of the 8 directions uniformly at random. Find the probability that the Knight remains in the chessboard after taking K steps, with the condition that it cant enter the board again once it leaves it.

// Example 1:

// Input : N = 8, x = 0, y = 0, K = 3
// Output: 0.125000
// Example 2:

// Input: N = 4, x = 1, y = 2, k = 4
// Output: 0.024414

// Your Task:
// You don't need to read or print anything. Your task is to complete the function findProb() which takes N, x, y and K as input parameter and returns the probability.

// Expected Time Complexity : O(N 3)
// Expected Space Complexity: O(N3)

// Constraints:
// 1 <= N <= 100
// 0 <= x, y <= N

// 0 <= K <= N

class Solution
{
public:
    bool isValid(int x, int y, int n)
    {
        if (x < 0 || y < 0 || x >= n || y >= n)
            return false;
        return true;
    }
    double findProb(int n, int x, int y, int steps)
    {
        vector<vector<double>> curr(n, vector<double>(n, 0.0));
        curr[x][y] = 1;
        int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        for (int move = 1; move <= steps; move++)
        {
            vector<vector<double>> next(n, vector<double>(n, 0.0));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (curr[i][j])
                    {
                        for (int k = 0; k < 8; k++)
                        {
                            int nx = i + dx[k];
                            int ny = j + dy[k];
                            if (isValid(nx, ny, n))
                                next[nx][ny] += curr[i][j] / 8.0;
                        }
                    }
                }
            }
            curr = next;
        }
        double ans = 0;
        for (auto it : curr)
            for (auto x : it)
                ans += x;
        return ans;
    }
};
