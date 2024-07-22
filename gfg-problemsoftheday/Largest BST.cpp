// Largest BST
// Difficulty: MediumAccuracy: 29.73%Submissions: 126K+Points: 4
// Given a binary tree. Find the size of its largest subtree which is a Binary Search Tree.
// Note: Here Size equals the number of nodes in the subtree.

// Examples :

// Input:   1
//         /  \
//         4   4
//        / \ 
//       6   8
// Output: 1
// Explanation: There's no sub-tree with size greater than 1 which forms a BST. All the leaf Nodes are the BSTs with size equal to 1.

// Input:    6
//         /   \
//       6      2
//        \    / \
//         2  1   3
// Output: 3
// Explanation: The following sub-tree is a BST of size 3:  2
//                                                        /   \
//                                                       1     3
// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(Height of the BST).

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 1 ≤ Data of a node ≤ 106

class Solution
{
public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int a;
    vector<int> ans(Node *ptr)
    {
        if (!ptr)
        {
            return {INT_MAX, INT_MIN, 0};
        }
        vector<int> p = ans(ptr->left);
        vector<int> pt = ans(ptr->right);
        if (p[1] < ptr->data && pt[0] > ptr->data)
        {
            a = max(a, 1 + p[2] + pt[2]);
            return {min(p[0], ptr->data), max(pt[1], ptr->data), 1 + p[2] + pt[2]};
        }
        return {INT_MIN, INT_MAX};
    }
    int largestBst(Node *root)
    {
        a = 1;
        ans(root);
        return a;
        // Your code here
    }
};
