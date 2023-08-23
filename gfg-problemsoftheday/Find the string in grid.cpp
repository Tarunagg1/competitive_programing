// Find the string in grid
// MediumAccuracy: 22.88%Submissions: 39K+Points: 4
// Win from a prize pool of INR 15K and get exciting merch! Register your team for Hack-A-Thon today!

// Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said to be found in a direction if all characters match in this direction (not in zig-zag form). The 8 directions are, horizontally left, horizontally right, vertically up, vertically down, and 4 diagonal directions.

// Note: The returning list should be lexicographically smallest. If the word can be found in multiple directions starting from the same coordinates, the list should contain the coordinates only once.

// Example 1:

// Input:
// grid = {{a,b,c},{d,r,f},{g,h,i}},
// word = "abc"
// Output:
// {{0,0}}
// Explanation:
// From (0,0) we can find "abc" in horizontally right direction.
// Example 2:

// Input:
// grid = {{a,b,a,b},{a,b,e,b},{e,b,e,b}}
// word = "abe"
// Output:
// {{0,0},{0,2},{1,0}}
// Explanation:
// From (0,0) we can find "abe" in right-down diagonal.
// From (0,2) we can find "abe" in left-down diagonal.
// From (1,0) we can find "abe" in horizontally right direction.
// Your Task:
// You don't need to read or print anything, Your task is to complete the function searchWord() which takes grid and word as input parameters and returns a list containing the positions from where the word originates in any direction. If there is no such position then returns an empty list.

// Expected Time Complexity: O(n*m*k) where k is constant
// Expected Space Complexity: O(1)

// Constraints:
// 1 <= n <= m <= 50
// 1 <= |word| <= 15

class Solution
{
public:
    bool f(int ind, int i, int j, vector<vector<char>> grid, string word, int dir_x, int dir_y)
    {
        if (ind >= word.size())
            return true;
        int n = grid.size();
        int m = grid[0].size();
        int row = i + dir_x;
        int col = j + dir_y;
        if (row >= 0 and row < n and col >= 0 and col < m and grid[row][col] == word[ind])
        {
            return f(ind + 1, row, col, grid, word, dir_x, dir_y);
        }
        return false;
    }
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
    {
        // Code here
        int di[] = {1, 1, 1, 0, 0, -1, -1, -1};
        int dj[] = {1, 0, -1, -1, 1, 0, 1, -1};
        set<vector<int>> s;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == word[0])
                {
                    for (int k = 0; k < 8; k++)
                    {
                        if (f(1, i, j, grid, word, di[k], dj[k]))
                        {
                            s.insert({i, j});
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for (auto it : s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};
