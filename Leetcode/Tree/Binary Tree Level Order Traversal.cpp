// 102. Binary Tree Level Order Traversal
// Medium

// 6664

// 135

// Add to List

// Share
// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []

// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000
// Accepted
// 1,063,936
// Submissions
// 1,784,181

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;

        q.push(root);

        if (root == NULL)
            return ans;

        while (1)
        {
            int size = q.size();

            if (size == 0)
                return ans;

            vector<int> data;

            while (size > 0)
            {
                TreeNode *temp = q.front();
                q.pop();

                data.push_back(temp->val);

                if (temp->left != NULL)
                    q.push(temp->left);

                if (temp->right != NULL)
                    q.push(temp->right);
                size--;
            }
            ans.push_back(data);
        }

        return ans;
    }
};
