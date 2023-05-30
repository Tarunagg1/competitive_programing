// Word Search
// MediumAccuracy: 32.69%Submissions: 22K+Points: 4
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// Given a 2D board of letters and a word. Check if the word exists in the board. The word can be constructed from letters of adjacent cells only. ie - horizontal or vertical neighbors. The same letter cell can not be used more than once.

// Example 1:

// Input: board = {{a,g,b,c},{q,e,e,l},{g,b,k,s}},
// word = "geeks"
// Output: 1
// Explanation: The board is-
// a g b c
// q e e l
// g b k s
// The letters which are used to make the
// "geeks" are colored.
// Example 2:

// Input: board = {{a,b,c,e},{s,f,c,s},{a,d,e,e}},
// word = "sabfs"
// Output: 0
// Explanation: The board is-
// a b c e
// s f c s
// a d e e
// Same letter can not be used twice hence ans is 0
// Your Task:
// You don't need to read or print anything. Your task is to complete the function isWordExist() which takes board and word as input parameter and returns boolean value true if word can be found otherwise returns false.

// Expected Time Complexity: O(N * M * 4L) where N = No. of rows in board, M = No. of columns in board, L = Length of word
// Expected Space Compelxity: O(L), L is length of word.

// Constraints:
// 1 ≤ N, M ≤ 100
// 1 ≤ L ≤ N*M

// View Bookmarked Problems

class Solution
{
public:
    int dfs(int a, int b, vector<vector<int>> &vis, vector<vector<char>> &board, int ind, string word)
    {
        int len = word.length();
        vis[a][b] = 1;
        if (ind == len)
            return 1;
        int i, row[4] = {1, -1, 0, 0}, col[4] = {0, 0, -1, 1}, n = board.size(), m = board[0].size();
        for (i = 0; i < 4; i++)
        {
            int r = a + row[i], c = b + col[i];
            if (r >= 0 && r < n && c >= 0 && c < m && vis[r][c] == 0 && board[r][c] == word[ind])
            {
                int p = dfs(r, c, vis, board, ind + 1, word);
                if (p == 1)
                    return 1;
            }
        }
        vis[a][b] = 0;
        return 0;
    }
    bool isWordExist(vector<vector<char>> &board, string word)
    {
        int i, j, ind = 0, n = board.size(), m = board[0].size(), len = word.length();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (vis[i][j] == 0 && board[i][j] == word[ind])
                {
                    int p = dfs(i, j, vis, board, ind + 1, word);
                    if (p == 1)
                        return true;
                }
            }
        }
        return false;
    }
};
