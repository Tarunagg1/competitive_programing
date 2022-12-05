// Shortest Path by Removing K walls
// HardAccuracy: 15.85%Submissions: 2495Points: 8
// Given a 2-D binary matrix of size n*m, where 0 represents an empty space while 1 represents a wall you cannot walk through. You are also given an integer k.
// You can walk up, down, left, or right. Given that you can remove up to k walls, return the minimum number of steps to walk from the top left corner (0, 0) to the bottom right corner (n-1, m-1).
// Note: If there is no way to walk from the top left corner to the bottom right corner, return -1.

// Example 1:

// Input: n = 3, m = 3, k = 1
// mat = {{0, 0, 0},
//        {0, 0, 1},
//        {0, 1, 0}}
// Output:
// 4
// Explanation:
// We can remove any one of the walls and
// reach the bottom in 4 moves.
// Example 2:

// Input:
// n = 2, m = 2, k = 0
// mat[] = {{0, 1},
//          {1, 0}}
// Output:
// -1
// Explanation:
// There's no way of reaching the bottom
// corner without removing any walls.

// Your Task:
// The task is to complete the function shotestPath() which takes three integers n, m, and k and also a matrix of size n*m as input and returns the minimum number of steps to walk from the top left corner to the bottom right corner.

// Constraints:
// 1 ≤ n,m ≤ 50
// 0 ≤ k ≤ n*m
// Top left and bottom right corners doesn't have 1

// Expected Time Complexity: O(n*m*k).
// Expected Auxiliary Space: O(n*m*k).

// View Bookmarked Problems

class Solution
{
public:
    int shotestPath(vector<vector<int>> arr, int n, int m, int k)
    {
        // code here
        int row = arr.size();
        int col = arr[0].size();

        // This vector stores the number of obstacles that we can still remove after walking through that cell
        vector<vector<int>> visited(row, vector<int>(col, -1));

        queue<vector<int>> q;
        // x,   y, currentLength, remaining k
        // q.push({0,   0,         0,       k});

        q.push({0, 0, 0, k});

        while (q.empty() == false)
        {
            auto curr = q.front();
            q.pop();

            // indices in array
            int x = curr[0];
            int y = curr[1];

            // handling edge cases
            if (x < 0 || y < 0 || x >= row || y >= col)
                continue;

            // If you've reached the end, return the currentLength!
            if (x == row - 1 && y == col - 1)
                return curr[2];

            // If we hit an obstacle & we don't have any Ks remaining, continue
            // If we still have Ks to spend, we spend 1.
            if (arr[x][y] == 1)
                if (curr[3] > 0)
                    curr[3]--;
                else
                    continue;

            // If this cell is already visited with a K value lesser than this one, we would want to save Ks for future use, so we continue
            // This is the most important condition and part of the solution!
            if (visited[x][y] != -1 && visited[x][y] >= curr[3])
            {
                continue;
            }

            // We store the currentRemaining K after spending K (if required) into the visited matrix.
            visited[x][y] = curr[3];

            // Push the adjacent nodes in the queue.
            q.push({x + 1, y, curr[2] + 1, curr[3]});
            q.push({x - 1, y, curr[2] + 1, curr[3]});
            q.push({x, y + 1, curr[2] + 1, curr[3]});
            q.push({x, y - 1, curr[2] + 1, curr[3]});
        }

        return -1;
    }
};
