// Height of Binary Tree
// EasyAccuracy: 78.58%Submissions: 226K+Points: 2
// Given a binary tree, find its height.

// Example 1:

// Input:
//      1
//     /  \
//    2    3
// Output: 2
// Example 2:

// Input:
//   2
//    \
//     1
//    /
//  3
// Output: 3
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function height() which takes root node of the tree as input parameter and returns an integer denoting the height of the tree. If the tree is empty, return 0.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= Number of nodes <= 105
// 1 <= Data of a node <= 109

class Solution
{
public:
    // Function to find the height of a binary tree.
    void dfs(struct Node *vertex, int &h, int &n)
    {
        h = max(n, h);
        n++;
        if (vertex->left != nullptr)
            dfs(vertex->left, h, n);
        if (vertex->right != nullptr)
            dfs(vertex->right, h, n);
        n--;
    }
    int height(struct Node *root)
    {
        int h = 1;
        int n = 1;
        dfs(root, h, n);
        return h;
    }
};
