// Left View of Binary Tree
// Difficulty: EasyAccuracy: 33.74%Submissions: 501K+Points: 2
// Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument. If no left view is possible, return an empty tree.

// Left view of following tree is 1 2 4 8.

//           1
//        /     \
//      2        3
//    /     \    /    \
//   4     5   6    7
//    \
//      8

// Examples :

// Input:
//    1
//  /  \
// 3    2
// Output: 1 3

// Input:

// Output: 10 20 40
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 0 <= Number of nodes <= 105
// 0 <= Data of a node <= 105

// Seen this question in a real interview before ?

int levels(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(levels(root->left), levels(root->right));
}
void postorder(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;
    postorder(root->right, ans, level + 1);
    postorder(root->left, ans, level + 1);
    ans[level] = root->data;
}
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> ans(levels(root), 0);
    postorder(root, ans, 0);
    return ans;
}
