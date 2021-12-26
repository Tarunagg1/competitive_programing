// 110. Balanced Binary Tree
// Easy

// 4794

// 271

// Add to List

// Share
// Given a binary tree, determine if it is height-balanced.

// For this problem, a height-balanced binary tree is defined as:

// a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: true
// Example 2:

// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false
// Example 3:

// Input: root = []
// Output: true

// Constraints:

// The number of nodes in the tree is in the range [0, 5000].
// -104 <= Node.val <= 104
// Accepted
// 675,108
// Submissions
// 1,466,282

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else
            return max(height(root->left), height(root->right));
    }
    void inorderUtil(TreeNode *root, bool &ans)
    {
        if (root != NULL)
        {
            inorderUtil(root->left, ans);
            int lh = height(root->left);
            int rh = height(root->right);
            if (abs(lh - rh) > 1)
                ans = ans && false;
            inorderUtil(root->right, ans);
        }
    }
    bool isBalanced(TreeNode *root)
    {
        bool ans = true;
        inorderUtil(root, ans);
        return ans;
    }
};
