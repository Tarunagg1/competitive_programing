// Connect Nodes at Same Level
// MediumAccuracy: 87.16%Submissions: 3K+Points: 4
// Lamp
// Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!

// Given a binary tree, connect the nodes that are at the same level. The structure of the tree Node contains an addition nextRight pointer for this purpose.

// Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.

//        10                       10 ------> NULL
//       / \                       /      \
//      3   5       =>     3 ------> 5 --------> NULL
//     / \     \               /  \           \
//    4   1   2          4 --> 1 -----> 2 -------> NULL

// Example 1:

// Input:
//      3
//    /  \
//   1    2
// Output:
// 3 1 2
// 1 3 2
// Explanation:The connected tree is
//        3 ------> NULL
//      /   \
//     1---> 2 -----> NULL
// Example 2:

// Input:
//       10
//     /   \
//    20   30
//   /  \
//  40  60
// Output:
// 10 20 30 40 60
// 40 20 60 10 30
// Explanation:The connected tree is
//         10 ---> NULL
//        /   \
//      20---> 30 ---> NULL
//    /   \
//  40---> 60 ---> NULL
// Your Task:
// You don't have to read input or print anything. Complete the function connect() that takes the root of the tree as  input parameter and connects the nodes that lie at the same level.

// Note: The generated output will contain 2 lines. First line contains the level order traversal of the tree and second line contains the inorder traversal of the tree.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 0 ≤ Data of a node ≤ 105

// View Bookmarked Problems

class Solution
{
public:
    void connect(Node *root)
    {
        // Code Here
        queue<Node *> q;
        q.push(root);
        int level = 0;

        while (!q.empty())
        {
            int size = q.size();
            Node *prev = NULL;
            for (int i = 0; i < size; i++)
            {
                auto curr = q.front();
                q.pop();

                if (prev)
                    prev->nextRight = curr;

                prev = curr;

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            level++;
        }
    }
};
