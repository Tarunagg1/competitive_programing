// Preorder to BST
// MediumAccuracy: 56.79%Submissions: 20689Points: 4
// Given an array arr[] of N nodes representing preorder traversal of some BST. You have to build the exact BST from it's given preorder traversal.
// In Pre-Order traversal, the root node is visited before the left child and right child nodes.

// Example 1:

// Input:
// N = 5
// arr[]  = {40,30,35,80,100}
// Output: 35 30 100 80 40
// Explanation: PreOrder: 40 30 35 80 100
// InOrder: 30 35 40 80 100
// Therefore, the BST will be:
//               40
//            /      \
//          30       80
//            \        \   
//            35      100
// Hence, the postOrder traversal will
// be: 35 30 100 80 40
// Example 2:

// Input:
// N = 8
// arr[]  = {40,30,32,35,80,90,100,120}
// Output: 35 32 30 120 100 90 80 40
// Your Task:
// You need to complete the given function and return the root of the tree. The driver code will then use this root to print the post order traversal.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 103
// 1 <= arr[i] <= 104

class Solution
{
public:
    // Function that constructs BST from its preorder traversal.
    Node *post_order(int pre[], int size)
    {
        int idx = 0;
        Node *root = buildTree(pre, idx, size);
        return root;
    }

    Node *buildTree(int pre[], int &idx, int size, int Min = -1e8, int Max = 1e8)
    {

        if (idx >= size)
            return NULL;

        if (pre[idx] < Min || pre[idx] > Max)
            return NULL;

        Node *root = newNode(pre[idx]);
        idx++;

        root->left = buildTree(pre, idx, size, Min, root->data - 1);

        root->right = buildTree(pre, idx, size, root->data + 1, Max);

        return root;
    }
};
