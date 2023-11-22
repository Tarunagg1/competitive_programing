// Symmetric Tree
// EasyAccuracy: 44.96%Submissions: 118K+Points: 2
// GfG Weekly + You = Perfect Sunday Evenings!
// Register for free now

// banner
// Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself or not.

// Example 1:

// Input:
//          5
//        /   \
//       1     1
//      /       \
//     2         2
// Output:
// True
// Explanation:
// Tree is mirror image of itself i.e. tree is symmetric
// Example 2:

// Input:
//          5
//        /   \
//       10     10
//      /  \     \
//     20  20     30
// Output:
// False
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isSymmetric() which takes the root of the Binary Tree as its input and returns True if the given Binary Tree is the same as the Mirror image of itself. Else, it returns False.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 0<=N<=105

class Solution
{
public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isIdentical(Node *r1, Node *r2)
    {
        // Your Code here
        if (r1 == NULL)
            return r2 == NULL;
        if (r2 == NULL)
            return r1 == NULL;
        return r1->data == r2->data && isIdentical(r1->left, r2->right) && isIdentical(r1->right, r2->left);
    }
    bool isSymmetric(struct Node *root)
    {
        return isIdentical(root, root);
    }
};
