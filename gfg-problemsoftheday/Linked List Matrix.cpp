// Linked List Matrix
// Difficulty: EasyAccuracy: 67.33%Submissions: 19K+Points: 2
// Given a Matrix mat of n*n size. Your task is constructing a 2D linked list representation of the given matrix.

// Input: mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
// Output:

// Input: mat = [[23, 28], [23, 28]]
// Output:

// Expected Time Complexity: O(n2)
// Expected Space Complexity: O(n2)

// Constraints:
// 1 <= mat.size() <=15
// 1 <= mat[i][j] <=104

class Solution
{
public:
    Node *constructLinkedMatrix(vector<vector<int>> &mat)
    {
        // code Here
        int n = mat.size();
        vector<vector<Node *>> linked(n, vector<Node *>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                linked[i][j] = new Node(mat[i][j]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                linked[i][j]->right = (j == n - 1) ? NULL : linked[i][j + 1];
                linked[i][j]->down = (i == n - 1) ? NULL : linked[i + 1][j];
            }
        }
        return linked[0][0];
    }
};
