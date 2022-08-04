// Complete Binary Tree
// MediumAccuracy: 40.66%Submissions: 8325Points: 4
// Given a Binary Tree, write a function to check whether the given Binary Tree is Complete Binary Tree or not. A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

// Example 1:
// Input:
//        1
//       / \
//      2   3
// Output:
// Complete Binary Tree
// Example 2:

// Input:
//               1
//             /   \
//           2      3
//            \    /  \
//             4  5    6
// Output:
// Not Complete Binary Tree
// Constraints:
// 1<=Number of Node<=100
// 0 <= Data of a node <= 106

// Your Task:
// You don't need to take input. Just complete the function isCompleteBT() that takes root node as a parameter and returns true, if the tree is Complete else returns false.

class Solution
{
public:
    bool isCompleteBT(Node *root)
    {
        // code here
        queue<Node *> q;
        q.push(root);

        bool f = 0;
        while (q.size())
        {
            auto it = q.front();
            q.pop();
            if (!it)
            {
                f = 1;
                continue;
            }

            // Check if a NUll pointer had already traversed before a not Null Node
            if (f)
                return 0;
            q.push(it->left);
            q.push(it->right);
        }
        return 1;
    }
};
