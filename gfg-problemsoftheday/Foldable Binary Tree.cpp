// Foldable Binary Tree
// MediumAccuracy: 50.45%Submissions: 24316Points: 4
// Given a binary tree, check if the tree can be folded or not. A tree can be folded if left and right subtrees of the tree are structure wise same. An empty tree is considered as foldable.
// Consider the below trees:
// (a) and (b) can be folded.
// (c) and (d) cannot be folded.

// (a)
//        10
//      /    \
//     7      15
//      \    /
//       9  11
// (b)
//         10
//        /  \
//       7    15
//      /      \
//     9       11
// (c)
//         10
//        /  \
//       7   15
//      /    /
//     5   11
// (d)
//          10
//        /   \
//       7     15
//     /  \    /
//    9   10  12

// Example 1:

// Input:
//      10
//     /    \
//    7     15
//  /  \   /  \
// N   9  11   N
// Output:Yes
// Explaination:Structure of every left and right subtree are same.
// Example 2:

// Input:
//       10
//     /    \
//    7     15
//  /  \   /  \
// 5   N  11   N
// Output: No
// Explaination: 7's left child is not NULL and right child is NULL. That's why the tree is not foldable.

// Your Task:
// The task is to complete the function isFoldable() that takes root of the tree as input and returns true or false depending upon whether the tree is foldable or not.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 0 <= n <= 103
// 1 <= data of node <= 104

Node *cloneBinaryTree(Node *root)
{
    // base case
    if (root == nullptr)
    {
        return nullptr;
    }

    // create a new node with the same data as the root node
    root->data = 1;
    Node *root_copy = new Node(root->data);

    // clone the left and right subtree
    root_copy->left = cloneBinaryTree(root->left);
    root_copy->right = cloneBinaryTree(root->right);

    // return cloned root node
    return root_copy;
}
void convertTreeToItsMirror(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        Node *temp;
        convertTreeToItsMirror(node->left);
        convertTreeToItsMirror(node->right);
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}
bool check(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return 1;
    }
    if (r1 != NULL && r2 != NULL)
    {
        return (check(r1->left, r2->left) && check(r1->right, r2->right));
    }
    return 0;
}
bool IsFoldable(Node *root)
{
    // Your code goes here
    Node *r = cloneBinaryTree(root);
    convertTreeToItsMirror(r);
    bool ans = check(r, root);
    return ans;
}
