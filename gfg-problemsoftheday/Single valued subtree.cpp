// Single valued subtree
// MediumAccuracy: 68.33%Submissions: 5K+Points: 4
// Lamp
// Stand out from the crowd. Prepare with Complete Interview Preparation

// Given a binary tree, count the number of Single Valued Subtrees. A Single Valued Subtree is one in which all the nodes have same value.

// Example 1

// Input :
//               5
//              / \
//             1   5
//            / \   \
//           5   5   5
// Output : 4
// Explanation :
// There are 4 subtrees with single values.
// Example 2:

// Input:
//               5
//              / \
//             4   5
//            / \   \
//           4   4   5
// Output: 5
// Explanation:
// There are five subtrees with single values.
// Your task :
// You don't have to read input or print anything. Your task is to complete the function singlevalued() which takes the root of the tree as input and returns the count of single valued subtrees.

// Expected Time Complexity : O(n)
// Expected Auxiliary Space : O(n)

// Constraints :
// 1 <= n <= 10^5
// View Bookmarked Problems

class Solution
{
    int f(Node *root)
    {
        if (!root)
        {
            return -2;
        }

        int left = f(root->left);
        int right = f(root->right);

        if (left == -2 and right == -2)
        {
            ans++;
            return root->data;
        }
        else if (right == -2 || left == -2)
        {
            if (left == root->data || right == root->data)
            {
                ans++;
                return root->data;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            if (root->data == right && root->data == left)
            {
                ans++;
                return root->data;
            }
            else
            {
                return -1;
            }
        }
    }

public:
    int ans = 0;
    int singlevalued(Node *root)
    {
        // code here

        f(root);
        return ans;
    }
};
