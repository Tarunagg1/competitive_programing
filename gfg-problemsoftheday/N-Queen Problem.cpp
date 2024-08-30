// N-Queen Problem
// Difficulty: HardAccuracy: 35.43%Submissions: 79K+Points: 8
// The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
// Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].

// Examples:

// Input: 1
// Output: [1]
// Explaination: Only one queen can be placed in the single cell available.
// Input: 4
// Output: [[2 4 1 3 ],[3 1 4 2 ]]
// Explaination: These are the 2 possible solutions.
// Expected Time Complexity: O(n!)
// Expected Auxiliary Space: O(n2)

// Constraints:
// 1 ≤ n ≤ 10

// Seen this question in a real interview before ?

class Solution
{
public:
    bool canPlace(vector<vector<int>> &board, int x, int y)
    {
        int n = board.size();

        for (int i = 0; i < x; i++)
        {
            if (board[i][y] == 1)
                return false;
        }

        int i = x, j = y;
        while (i >= 0 && j >= 0)
        {
            if (board[i][j] == 1)
                return false;
            i--;
            j--;
        }

        i = x;
        j = y;
        while (i >= 0 && j < n)
        {
            if (board[i][j] == 1)
                return false;
            i--;
            j++;
        }

        return true;
    }

    void nQueenHelper(vector<vector<int>> &board, int i, int n, vector<vector<int>> &solutions)
    {
        if (i == n)
        {
            vector<int> currentSolution;
            for (int row = 0; row < n; row++)
            {
                for (int col = 0; col < n; col++)
                {
                    if (board[row][col] == 1)
                    {
                        currentSolution.push_back(col + 1);
                    }
                }
            }
            solutions.push_back(currentSolution);
            return;
        }

        for (int j = 0; j < n; j++)
        {
            if (canPlace(board, i, j))
            {
                board[i][j] = 1;
                nQueenHelper(board, i + 1, n, solutions);
                board[i][j] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n)
    {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<int>> solutions;
        nQueenHelper(board, 0, n, solutions);
        return solutions;
    }
};
