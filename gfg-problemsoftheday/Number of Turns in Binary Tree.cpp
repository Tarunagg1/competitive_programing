// Number of Turns in Binary Tree
// HardAccuracy: 44.27%Submissions: 10206Points: 8
// Given a binary tree and data value of two of its nodes. Find the number of turns needed to reach from one node to another in the given binary tree.

// Example 1:

// Input:
// Tree =
//            1
//         /    \
//        2       3
//      /  \     /  \
//     4    5   6    7
//    /        / \                        
//   8        9   10
// first node = 5
// second node = 10
// Output: 4
// Explanation:
// Turns will be at 2, 1, 3, 6.
// Example 2:

// Input:
// Tree =
//            1
//         /     \
//        2        3
//      /  \      /  \
//     4    5    6    7
//    /         / \                        
//   8         9   10
// first node = 1
// second node = 4
// Output: -1
// Explanation: No turn is required since
// they are in a straight line.

// Your Task:
// You don't need to read input or print anything. Complete the function NumberOFTurns() which takes root node and data value of 2 nodes as input parameters and returns the number of turns required to navigate between them. If the two nodes are in a straight line, ie- the path does not involve any turns, return -1.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(Height of Tree)

// Constraints:
// 1 ≤ N ≤ 103

// View Bookmarked Problems

class Solution
{
public:
    // function should return the number of turns required to go from first node to second node

    int NumberOFTurns(struct Node *root, int first, int second)
    {
        Node *lca = LCA(root, first, second);

        // When two Nodes will be having a common ancestor then the two might be in a straight line
        if (lca->data == first || lca->data == second)
        {
            pair<int, char> t;
            if (lca->data == first)
            {
                t = helper(lca, second, -1);
            }
            else
            {
                t = helper(lca, first, -1);
            }
            if (t.first == 0)
                return -1;
            return t.first;
        }
        pair<int, char> turnL = helper(lca, first, -1);
        pair<int, char> turnR = helper(lca, second, -1);
        return turnL.first + turnR.first + 1;
    }
    Node *LCA(Node *root, int first, int second)
    {
        if (root == NULL)
            return NULL;

        Node *L = LCA(root->left, first, second);
        Node *R = LCA(root->right, first, second);

        if (L && R)
            return root;

        if (root->data == first || root->data == second)
            return root;
        if (L)
            return L;
        return R;
    }

    pair<int, char> helper(Node *root, int key1, int key2)
    {
        if (root == NULL)
            return {-1, 'x'};
        if (root->data == key1 || root->data == key2)
            return {0, 'o'};

        pair<int, char> L = helper(root->left, key1, key2);
        pair<int, char> R = helper(root->right, key1, key2);

        if (L.second == 'o' || L.second == 'l')
        {
            return {L.first, 'l'};
        }
        else if (L.second == 'r')
        {
            return {L.first + 1, 'l'};
        }
        else if (R.second == 'o' || R.second == 'r')
        {
            return {R.first, 'r'};
        }
        else if (R.second == 'l')
        {
            return {R.first + 1, 'r'};
        }
        return {-1, 'x'};
    }
};
