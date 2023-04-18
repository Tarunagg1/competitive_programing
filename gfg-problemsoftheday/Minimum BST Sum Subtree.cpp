// Minimum BST Sum Subtree
// HardAccuracy: 76.75%Submissions: 5K+Points: 8
// Unlock your coding potential - join our Hiring Coding Contest and land your dream job!

// Given a binary tree and a target, find the length of minimum sub-tree with the given sum equal to target which is also a binary search tree.

// Example 1:

// Input:
//            13
//          /    \
//        5       23
//       / \      / \
//      N   17   N   N
//          /
//         16
// Target: 38
// Output: 3
// Explanation: 5,17,16 is the smallest subtree
// with length 3.

// Example 2:

// Input:
//              7
//            /   \
//           N    23
//              /   \
//             10    23
//            /  \   / \
//           N   17 N   N
// Target: 73
// Output: -1
// Explanation: No subtree is bst for the given target.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function minSubtreeSumBST() which takes the tree root and target as input parameters which is a binary Tree and returns length of minimum subtree having sum equal to the target but which is binary search tree.

// Expected Time Complexity:O(N), where N is no. of nodes
// Expected Space Complexity:O(1)

// Constraints:
// 1 <= N <= 10^5

// View Bookmarked Problems

class Solution
{
public:
    int tar, ans;
    // size, max on the left, min on the right, sum of the subtree
    vector<int> solve(Node *root)
    {
        // null
        if (!root)
            return {0, INT_MIN, INT_MAX, 0};

        // leaf
        if (!root->left and !root->right)
        {
            if (root->data == tar)
                ans = min(ans, 1);
            return {1, root->data, root->data, root->data};
        }

        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);

        // check if bst
        if (l[1] < root->data && root->data < r[2])
        {
            if ((root->data + l[3] + r[3]) == tar)
                ans = min(ans, 1 + l[0] + r[0]);
            return {1 + l[0] + r[0], max(root->data, r[1]), min(root->data, l[2]), root->data + l[3] + r[3]};
        }

        return {min(l[0], r[0]), INT_MAX, INT_MIN, root->data + l[3] + r[3]};
    }

    int minSubtreeSumBST(int target, Node *root)
    {
        tar = target, ans = 1e9;
        solve(root);
        return ans == 1e9 ? -1 : ans;
    }
};
