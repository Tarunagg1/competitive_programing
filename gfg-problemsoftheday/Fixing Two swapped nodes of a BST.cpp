// Fixing Two swapped nodes of a BST
// HardAccuracy: 87.66%Submissions: 2K+Points: 8
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
// Note: It is guaranteed than the given input will form BST, except for 2 nodes that will be wrong.

// Example 1:
// Input:
//        10
//      /    \
//     5      8
//    / \
//   2   20
// Output: 1
// Explanation:

// Example 2:

// Input:
//          11
//        /    \
//       3      17
//        \    /
//         4  10
// Output: 1
// Explanation:
// By swapping nodes 11 and 10, the BST
// can be fixed.
// Your Task:
// You don't need to take any input. Just complete the function correctBst() that takes root node as parameter. The function should return the root of corrected BST. BST will then be checked by driver code and 0 or 1 will be printed.

// Expected Time Complexity : O(Number of nodes)
// Expected Auxiliary Space : O(logN), N = number of nodes

// Constraints:
// 1 <= Number of nodes <= 10^5
// View Bookmarked Problems

class Solution
{
public:
    void solve(Node *root, vector<int> &v)
    {

        if (!root)
            return;

        solve(root->left, v);
        v.push_back(root->data);
        solve(root->right, v);
    }
    void get(Node *root, vector<int> &v, int &i)
    {

        if (!root)
            return;
        get(root->left, v, i);
        root->data = v[i];
        i++;
        get(root->right, v, i);
    }

    struct Node *correctBST(struct Node *root)
    {
        // code here

        vector<int> v;
        solve(root, v);
        int i = 0;
        sort(v.begin(), v.end());
        get(root, v, i);

        return root;
    }
};
