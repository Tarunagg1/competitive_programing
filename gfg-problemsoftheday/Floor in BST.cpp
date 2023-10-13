// Floor in BST
// MediumAccuracy: 51.06%Submissions: 26K+Points: 4
// Hack you way to glory and win from a cash pool prize of INR 15,000. Register for free now

// banner
// You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
// Note: when x is smaller than the smallest node of BST then returns -1.

// Example:

// Input:
// n = 7               2
//                      \
//                       81
//                     /     \
//                  42       87
//                    \       \
//                     66      90
//                    /
//                  45
// x = 87
// Output:
// 87
// Explanation:
// 87 is present in tree so floor will be 87.
// Example 2:

// Input:
// n = 4                     6
//                            \
//                             8
//                           /   \
//                         7       9
// x = 11
// Output:
// 9
// Your Task:-
// You don't need to read input or print anything. Complete the function floor() which takes the integer n and BST and integer x returns the floor value.

// Constraint:
// 1 <= Noda data <= 109
// 1 <= n <= 105

// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)

class Solution
{

public:
    int temp = -1;
    void solve(Node *root, int x)
    {
        if (root == NULL)
            return;
        if (root->data <= x)
        {
            temp = root->data;
            solve(root->right, x);
        }
        else if (root->data > x)
        {
            solve(root->left, x);
        }
    }
    int floor(Node *root, int x)
    {
        // Code here
        solve(root, x);
        return temp;
    }
};
