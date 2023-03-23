// BST Maximum Difference
// MediumAccuracy: 64.03%Submissions: 3K+Points: 4
// Win Prize worth ₹6000 with Ease. Register for the Easiest Coding Challenge!

// You are given a Binary Search Tree and a target value. You must find the maximum difference between the sum of node data from root to target and from target to a child leaf node (target exclusive). Initially, you are at the root node.
// Note: If the target node is not present in the tree then return -1.

// Example 1:

// Input:

// Target = 20
// Output: 10
// Explanation: From root to target the sum of node data is 25 and from target to the children leaf nodes the sums of the node data are 15 and 22. So, the maximum difference will be (25-15) = 10.
// Example 2:

// Input:

// Target = 50
// Output: -1
// Explanation: The target node is not present in the tree.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maxDifferenceBST() which takes BST(you are given the root node of the BST ) and target as input, and returns an interger value as the required answer. If the target is not present in the BST then return -1.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(H), H - Height of the Tree.

// Constraints:
// 1 <= n < 10^4
// 1 <= node.data < 10^5
// 1 <= target < 10^5

// View Bookmarked Problems

class Solution
{
public:
    Node *fun(Node *root, int t)
    {
        if (root == NULL)
            return NULL;

        int val = root->data;

        if (val == t)
            return root;

        if (t > val)
            fun(root->right, t);
        else
            fun(root->left, t);
    }

    int fun2(Node *root, int t)
    {
        if (root == NULL)
            return 0;

        int val = root->data;

        if (val == t)
            return t;

        if (t > val)
            return val + fun2(root->right, t);
        else
            return val + fun2(root->left, t);
    }

    int fun3(Node *root, int store)
    {
        if (root->left == NULL and root->right == NULL)
            return store - root->data;

        int a = INT_MIN;
        int b = INT_MIN;

        if (root->left != NULL)
            a = fun3(root->left, store - root->data);

        if (root->right != NULL)
            b = fun3(root->right, store - root->data);

        return max(a, b);
    }

    int maxDifferenceBST(Node *root, int target)
    {
        // Code here

        // return the node of target
        Node *val = fun(root, target);

        if (val == NULL)
            return -1;

        // returns the sum till target
        int store = fun2(root, target);

        // returns the maxdiff possible
        return fun3(val, store);
    }
};
