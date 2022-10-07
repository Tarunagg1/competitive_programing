// Flatten binary tree to linked list
// HardAccuracy: 66.45%Submissions: 12853Points: 8
// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same Node class where the right child pointer points to the next   node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.
// Example 1:

// Input :
//           1
//         /   \
//        2     5
//       / \     \
//      3   4     6
// Output :
// 1 2 3 4 5 6
// Explanation:
// After flattening, the tree looks
// like this
//     1
//      \
//       2
//        \
//         3
//          \
//           4
//            \
//             5
//              \
//               6
// Here, left of each node points
// to NULL and right contains the
// next node in preorder.The inorder
// traversal of this flattened tree
// is 1 2 3 4 5 6.
// Example 2:

// Input :
//         1
//        / \
//       3   4
//          /
//         2
//          \
//           5
// Output :
// 1 3 4 2 5
// Explanation :
// After flattening, the tree looks
// like this
//      1
//       \
//        3
//         \
//          4
//           \
//            2
//             \ 
//              5
// Here, left of each node points
// to NULL and right contains the
// next node in preorder.The inorder
// traversal of this flattened tree
// is 1 3 4 2 5.
// Your task:
// You don't have to read input or print anything. Your task is to complete the function flatten() which takes the root of the tree and flattens the tree into a linkes list without using any auxiliary space.
// Note : The driver code prints the inorder traversal of the flattened binary tree.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints :
// 1<=n<=10^5

class Solution
{
public:
    void preorder(Node *root, vector<int> &v)
    {
        if (!root)
            return;
        v.push_back(root->key);
        preorder(root->left, v);
        preorder(root->right, v);
    }
    void flatten(Node *root)
    {
        // code here
        vector<int> v;
        Node *temp = root, *temp1 = root;
        preorder(temp, v);
        root->left = NULL;
        for (int i = 1; i < v.size(); i++)
        {
            Node *n = newNode(v[i]);
            temp1->right = n;
            temp1 = temp1->right;
        }
    }
};
