// Predecessor and Successor
// MediumAccuracy: 47.36%Submissions: 65K+Points: 4
// Getting a High Paying Job Now Easier Than Today's Problem! Apply For Mega Job-A-Thon

// There is BST given with the root node with the key part as an integer only. You need to find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.

// Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor.

// Example 1:

// Input:
//         10
//       /   \
//      2    11
//    /  \ 
//   1    5
//       /  \
//      3    6
//       \
//        4
// key = 8
// Output:
// 6 10
// Explanation:
// In the given BST the inorder predecessor of 8 is 6 and inorder successor of 8 is 10.
// Example 2:

// Input:
//       8
//     /   \
//    1     9
//     \     \
//      4    10
//     /
//    3
// key = 11
// Output:
// 10 -1
// Explanation:
// In given BST, the inorder predecessor of 11 is 10 whereas it does not have any inorder successor.
// Your Task: You don't need to print anything. You need to update pre with the predecessor of the key or NULL if the predecessor doesn't exist and succ to the successor of the key or NULL if the successor doesn't exist. pre and succ are passed as an argument to the function findPreSuc().

// Expected Time Complexity: O(Height of the BST).
// Expected Auxiliary Space: O(Height of the BST).

// Constraints:
// 1 <= Number of nodes <= 104
// 1 <= key of node <= 107
// 1 <= key <= 107

// View Bookmarked Problems

class Solution
{
    void dfs(Node *root, Node *&pre, Node *&suc, int key, int min, int max)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->key > key)
        {
            //   cout<<root->key<<" ";
            if (min > root->key)
            {
                min = root->key;
                suc = root;
            }
        }
        if (root->key < key)
        {
            if (max < root->key)
            {
                max = root->key;
                pre = root;
            }
        }
        dfs(root->left, pre, suc, key, min, max);
        dfs(root->right, pre, suc, key, min, max);
    }

public:
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        // Your code goes here
        dfs(root, pre, suc, key, INT_MAX, INT_MIN);
    }
};
