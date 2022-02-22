// Spidey Sense
// Medium Accuracy: 91.1% Submissions: 1780 Points: 4
// Spiderman is stuck in a difficult situation. His arch-enemy the Green Goblin has planted several of his infamous Pumpkin Bombs in various locations in a building. Help Spiderman activate his Spidey Sense and identify the impact zones.
// He has a blueprint of the building which is a M x N matrix that is filled with the characters O, B, and W where:
// O represents an open space.
// B represents a bomb.
// W represents a wall.
// You have to replace all of the Os (open spaces) in the matrix with their shortest distance from a bomb without being able to go through any walls. Also, replace the bombs with 0 and walls with -1 in the resultant matrix. If no path exists between a bomb and an open space replace the corresponding 'O' with -1.

// Example 1:

// Input: N = 3, M = 3
// A[] = {{O, O, O},
//        {W, B, B},
//        {W, O, O}}
// Output: {{2, 1, 1},
//          {-1, 0, 0},
//          {-1, 1, 1}}
// Explanation: The walls at (1,0) and (2,0)
// are replaced by -1. The bombs at (1,1) and
// (1,2) are replaced by 0. The impact zone
// for the bomb at (1,1) includes open spaces
// at index (0,0), (0,1) and (2,1) with distance
// from bomb calculated as 2,1,1 respectively.
// The impact zone for the bomb at (1,2)
// includes open spaces at index (0,3) and (2,2)
// with distance from bomb calculated as 1,1
// respectively.

// Example 2:

// IInput: N = 2, M = 2
// A[] = {{O, O},
//        {O, O}}
// Output: {{-1, -1}
//          {-1, -1}
// Your Task:
// You don't need to read input or print anything. Complete the function findDistance() which takes the matrix A[], M, and N as input parameters and the resultant matrix

// Expected Time Complexity: O(M*N)
// Expected Auxiliary Space: O(M*N)

// Constraints:
// 1 ≤ N*M ≤ 106

class Solution
{
public:
    int row, col;

    bool isValid(int x, int y)
    {
        return x >= 0 && x < row && y >= 0 && y < col;
    }

    vector<vector<int>> findDistance(vector<vector<char>> &a, int M, int N)
    {
        row = a.size(), col = a[0].size();
        vector<vector<int>> res(row, vector<int>(col, -1));
        deque<pair<pair<int, int>, int>> q;
        set<pair<int, int>> vis;
        for (int k = 0; k < row; k++)
        {
            for (int x = 0; x < col; x++)
            {
                if (a[k][x] == 'B')
                {
                    q.push_back({{k, x}, 0});
                    vis.insert({k, x});
                }
            }
        }
        vector<int> dirs = {0, 1, 0, -1, 0};
        while (!q.empty())
        {
            int x = q.front().first.first, y = q.front().first.second, c = q.front().second;
            q.pop_front();
            res[x][y] = c;
            for (int k = 1; k <= 4; k++)
            {
                int nx = (x + dirs[k - 1]), ny = (y + dirs[k]);
                if (isValid(nx, ny) && a[nx][ny] == 'O' && vis.find({nx, ny}) == vis.end())
                {
                    vis.insert({nx, ny});
                    q.push_back({{nx, ny}, c + 1});
                }
            }
        }
        return res;
    }
}
