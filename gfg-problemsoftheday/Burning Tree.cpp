// Burning Tree
// Difficulty: HardAccuracy: 53.53%Submissions: 69K+Points: 8
// Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
// Note: The tree contains unique values.

// Examples :

// Input:
//           1
//         /   \
//       2      3
//     /  \      \
//    4    5      6
//        / \      \
//       7   8      9
//                    \
//                    10
// Target Node = 8
// Output: 7
// Explanation: If leaf with the value 8 is set on fire.
// After 1 sec: 5 is set on fire.
// After 2 sec: 2, 7 are set to fire.
// After 3 sec: 4, 1 are set to fire.
// After 4 sec: 3 is set to fire.
// After 5 sec: 6 is set to fire.
// After 6 sec: 9 is set to fire.
// After 7 sec: 10 is set to fire.
// It takes 7s to burn the complete tree.
// Input:
//           1
//         /   \
//       2      3
//     /  \      \
//    4    5      7
//   /    /
//  8    10
// Target Node = 10
// Output: 5

// Expected Time Complexity: O(number of nodes)
// Expected Auxiliary Space: O(height of tree)

// Constraints:
// 1 ≤ number of nodes ≤ 105

// 1 ≤ values of nodes ≤ 105

class Solution
{
public:
    map<Node *, Node *> parent(Node *root, int target, Node *&t)
    {
        map<Node *, Node *> par;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            if (node->data == target)
                t = node;
            if (node->left)
            {
                q.push(node->left);
                par[node->left] = node;
            }
            if (node->right)
            {
                q.push(node->right);
                par[node->right] = node;
            }
        }
        return par;
    }
    int minTime(Node *root, int target)
    {
        Node *t;
        map<Node *, Node *> par = parent(root, target, t);
        queue<Node *> q;
        q.push(t);
        set<Node *> vis;
        vis.insert(t);
        int steps = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                Node *node = q.front();
                q.pop();
                if (node->left && vis.find(node->left) == vis.end())
                {
                    vis.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && vis.find(node->right) == vis.end())
                {
                    vis.insert(node->right);
                    q.push(node->right);
                }
                if (par.find(node) != par.end() && vis.find(par[node]) == vis.end())
                {
                    vis.insert(par[node]);
                    q.push(par[node]);
                }
            }
            steps++;
        }
        return steps - 1;
    }
};
