// Leaf under budget
// EasyAccuracy: 50.05%Submissions: 13K+Points: 2
// Given a binary tree and a budget. Assume you are at the root of the tree(level 1), you need to maximise the count of leaf nodes you can visit in your budget if the cost of visiting a leaf node is equal to the level of that leaf node.

// Example 1:

// Input:
//                   10
//                 /    \
//                8      2
//              /      /   \
//             3      3     6
//                     \
//                      4
// and budget = 8
// Output: 2
// Explanation:
// Cost For visiting Leaf Node 3: 3
// Cost For visiting Leaf Node 4: 4
// Cost For visiting Leaf Node 6: 3
// In budget 8 one can visit Max 2 Leaf Nodes.
// Example 2:

// Input:
//          1
//        /   \
//       2     3
//      / \   / \
//     4   5 6   7
// and budget = 5
// Output: 1
// Explanation: We can only visit either node 4 or 5.
// Your Task:

// You don't need to read input or print anything. Your task is to complete the function getCount() which takes root node of the tree and a integer denoting the budget as input parameters and returns an integer denoting the count of visited leaf nodes of the tree.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1<=N<=105
// 1<=budget<=104

// Company Tags

class Solution
{
public:
    int getCount(Node *root, int k)
    {
        // code here
        if (!root)
            return 0;

        queue<pair<Node *, int>> q;
        q.push({root, 1});

        int count = 0;
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();

            Node *node = p.first;
            int lvl = p.second;

            if (!node->left and !node->right)
            {
                if (k - lvl < 0)
                    break;

                k -= lvl;
                count++;
            }

            if (node->left)
                q.push({node->left, lvl + 1});

            if (node->right)
                q.push({node->right, lvl + 1});
        }

        return count;
    }
};
