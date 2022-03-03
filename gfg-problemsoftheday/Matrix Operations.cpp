// Matrix Operations
// Easy Accuracy: 79.5% Submissions: 1055 Points: 2
// Given a binary matrix of dimensions N * M. One can perform the given operation in the matrix.

// If the value of matrix[i][j] is 0, then traverse in the same direction and check the next value.
// If the value of matrix[i][j] is 1, then update matrix[i][j] to 0 and change the current direction from up, right, down, or left to the directions right, down, left, and up respectively.
// Initially you start from cell(0, 0), moving in right direction.

// The task is to find the indices of the matrix  which leads to outside the matrix from the traversal of the given matrix from the cell (0, 0) by performing the operations.

// Example 1:

// Input:
// matrix[][] = {{0,1},
//               {1,0}}

// Output: (1,1)
// Explanation:

// Example 2:

// Input:
// matrix[][] = {{0, 1, 1, 1, 0},
//                    {1, 0, 1, 0, 1},
//               {1, 1, 1, 0, 0}}

// Output: (2,0)
// Your Task:
// You don't need to read input or print anything. Complete the function endPoints() that take the matrix as input parameter and output the last cell before the pointer gets outside of the matrix.

// Constrains:
// 1<= N, M <=1000
// 0<= matrix[i][j] <=1

// View Bookmarked Problems
// Company Tags
// Topic Tags

class Solution
{
public:
    pair<int, int> endPoints(vector<vector<int>> mo)
    {
        // code here
        int max = 0;
        int min = 0;

        map<int, char> m;

        char k = 'r';
        int op = mo.size() - 1;
        int got = (mo[0].size()) - 1;

        while (((max >= 0) && (min >= 0)) && (max <= op && min <= got))
        {
            if (mo[max][min] == 0)
            {
                if (k == 'r')
                {
                    min++;
                }
                else if (k == 'u')
                {
                    max--;
                }
                else if (k == 'd')
                {
                    max++;
                }
                else if (k == '1')
                {
                    min--;
                }
            }
            else
            {
                mo[max][min] = 0;
                if (k == 'r')
                {
                    k = 'd';
                    max++;
                }
                else if (k == 'u')
                {
                    k = 'r';
                    min++;
                }
                else if (k == 'd')
                {
                    k = '1';
                    min--;
                }
                else if (k == '1')
                {
                    k = 'u';
                    max--;
                }
            }
        }

        if (max < 0)
        {
            max = 0;
        }
        else if (max > op)
        {
            max = op;
        }
        else if (min < 0)
        {
            min = 0;
        }
        else if (min > got)
        {
            min = got;
        }

        pair<int, int> po = {max, min};

        return po;
    }
};
