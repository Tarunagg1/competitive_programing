// Next Right Node
// EasyAccuracy: 41.45%Submissions: 5472Points: 2
// Given a Binary tree and a key in the binary tree, find the node right to the given key. If there is no node on right side, then return a node with value -1.

// Example 1:

// Input:

//        10
//      /    \
//     2      6
//    / \      \
//   8   4      5
// and key = 2
// Output: 6
// Explanation: We can see in the above tree
// that the next right node of 2 is 6.
// Example 2:

// Input:
//       10
//     /     \
//    2       6
//   / \       \
//  8   4       5
// and key = 5
// Output: -1
// Explanation: We can see in the above tree
// that there's No next right node of 5.
// So, the output is -1.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function nextRight() which takes root node of the tree and an integer key as input parameters and returns the next right node of the node with value key.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1<=N<=103
// 1<=data of node<=103
// 1<=key<=103

class Solution
{
public:
    Node *nextRight(Node *root, int key)
    {
        // code here
        queue<Node *> q;
        vector<int> lev;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp != NULL)
            {
                lev.push_back(temp->data);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            else if (!q.empty())
            {
                q.push(NULL);
                lev.push_back(INT_MAX);
            }
        }

        Node *temp = new Node(-1);
        int i = 0;
        for (int i = 0; i < lev.size(); i++)
        {
            if (lev[i] == key && i + 1 < lev.size())
            {
                if (lev[i + 1] == INT_MAX)
                {
                    return temp;
                }
                else
                {
                    Node *ret = new Node(lev[i + 1]);
                    return ret;
                }
            }
            else if (lev[i] == key && i == lev.size() - 1)
            {
                return temp;
            }
        }
        return temp;
    }
};
