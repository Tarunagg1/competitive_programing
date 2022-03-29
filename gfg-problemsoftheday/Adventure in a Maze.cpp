// Adventure in a Maze
// Hard Accuracy: 46.48% Submissions: 2213 Points: 8
// You have got a maze, which is a n*n Grid. Every cell of the maze contains these numbers 1, 2 or 3.
// If it contains 1 : means we can go Right from that cell only.
// If it contains 2 : means we can go Down from that cell only.
// If it contains 3 : means we can go Right and Down to both paths from that cell.
// We cant go out of the maze at any time.
// Initially, You are on the Top Left Corner of The maze(Entry). And, You need to go to the Bottom Right Corner of the Maze(Exit).
// You need to find the total number of paths from Entry to Exit Point.
// There may be many paths but you need to select that path which contains the maximum number of Adventure.
// The Adventure on a path is calculated by taking the sum of all the cell values thatlies in the path.

// Example 1:

// Input: matrix = {{1,1,3,2,1},{3,2,2,1,2},
// {1,3,3,1,3},{1,2,3,1,2},{1,1,1,3,1}}
// Output: {4,18}
// Explanation: There are total 4 Paths Available
// out of which The Max Adventure is 18. Total
// possible Adventures are 18,17,17,16. Of these
// 18 is the maximum.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function FindWays() which takes matrix as input parameter and returns a list containg total number of ways to reach at (n, n) modulo 109 + 7 and maximum number of Adventure.

// Expected Time Complexity: O(n2)
// Expected Space Complexity: O(n2)

// Constraints:
// 1 <= n <= 100

class Solution
{
public:
    int mod = 1000000007;
    pair<int, int> solve(vector<vector<int>> &a, int i, int j, int &n, int &m, vector<vector<pair<int, int>>> &dp)
    {
        if (i >= n || j >= m)
            return {0, 0};
        if (i == n - 1 && j == m - 1)
            return dp[i][j] = {1, a[i][j]};
        if (dp[i][j].first != -1)
            return dp[i][j];
        pair<int, int> ans = {0, 0};
        if (a[i][j] == 1 || a[i][j] == 3)
        {
            auto p = solve(a, i, j + 1, n, m, dp);
            if (p.first > 0)
            {
                ans.first += p.first;
                ans.first %= mod;
                if ((p.second + a[i][j]) > ans.second)
                {
                    ans.second = p.second + a[i][j];
                }
            }
        }
        if (a[i][j] == 2 || a[i][j] == 3)
        {
            auto p = solve(a, i + 1, j, n, m, dp);
            if (p.first > 0)
            {
                ans.first += p.first;
                ans.first %= mod;
                if ((p.second + a[i][j]) > ans.second)
                {
                    ans.second = p.second + a[i][j];
                }
            }
        }
        return dp[i][j] = ans;
    }
    vector<int> FindWays(vector<vector<int>> &a)
    {
        int n = a.size();
        int m = a[0].size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m, {-1, -1}));
        auto p = solve(a, 0, 0, n, m, dp);
        return {p.first, p.second};
    }
};
