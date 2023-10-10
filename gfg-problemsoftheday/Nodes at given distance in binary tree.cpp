// Nodes at given distance in binary tree
// HardAccuracy: 32.36%Submissions: 50K+Points: 8
// Hack you way to glory and win from a cash pool prize of INR 15,000. Register for free now

// banner
// Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at distance k from the given target node. No parent pointers are available.
// Note:

// You have to return the list in sorted order.
// The tree may contain duplicate values.
// Example 1:

// Input:
//           20
//         /    \
//       8       22
//     /   \
//    4    12
//        /   \
//       10    14
// Target Node = 8
// K = 2
// Output: 10 14 22
// Explanation: The three nodes at distance 2
// from node 8 are 10, 14, 22.

// Example 2:

// Input:
//          20
//        /    \
//       7      24
//     /   \
//    4     3
//         /
//        1
// Target Node = 7
// K = 2
// Output: 1 24
// Your Task:
// You don't need to read input or print anything. Complete the function KDistanceNodes() which takes the root of the tree, target, and K as input parameters and returns a list of nodes at k distance from target in a sorted order.

// Expected Time Complexity: O(N*logN)
// Expected Auxiliary Space: O(Height of tree)

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ data of node ≤ 109
// 1 ≤ target ≤ 109
// 1 ≤ k ≤ 20

void parent(Node *root, Node *p, unordered_map<Node *, Node *> &mp, int target, Node *&t)
{
    if (!root)
        return;
    mp[root] = p;
    if (!t && root->data == target)
        t = root;
    parent(root->left, root, mp, target, t);
    parent(root->right, root, mp, target, t);
}
vector<int> KDistanceNodes(Node *root, int target, int k)
{
    vector<int> ans;
    unordered_map<Node *, Node *> m;
    Node *tar = NULL;
    parent(root, NULL, m, target, tar);

    auto getlower = [](Node *r, int k, vector<int> &ans)
    {
        if (!r)
            return;
        queue<pair<int, Node *>> q;
        q.push({0, r});
        while (!q.empty())
        {
            int key = q.front().first;
            Node *t = q.front().second;
            q.pop();
            if (key > k)
                return;
            if (key == k)
                ans.push_back(t->data);
            if (t->left)
                q.push({key + 1, t->left});
            if (t->right)
                q.push({key + 1, t->right});
        }
    };
    getlower(tar, k, ans);

    // this while loop is for getting the node from the ancestors of the target node
    while (m[tar] != NULL && k)
    {
        Node *p = m[tar];
        k--;
        if (k == 0)
        {
            ans.push_back(p->data);
            break;
        }
        if (p->left && p->left != tar)
            getlower(p->left, k - 1, ans);
        if (p->right && p->right != tar)
            getlower(p->right, k - 1, ans);
        tar = p;
    }

    sort(ans.begin(), ans.end());
    return ans;
}
