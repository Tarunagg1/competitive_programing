// Right View of Binary Tree
// EasyAccuracy: 65.18%Submissions: 130K+Points: 2
// POTD July Placement Special : All POTD in the month of July are based on popular interview questions. Solve every day to ace the upcoming Placement Season !
// Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

// Right view of following tree is 1 3 7 8.

//           1
//        /     \
//      2        3
//    /   \      /    \
//   4     5   6    7
//     \
//      8

// Example 1:

// Input:
//        1
//     /    \
//    3      2
// Output: 1 2
// Example 2:

// Input:
//      10
//     /   \
//   20     30
//  /   \
// 40  60
// Output: 10 30 60
// Your Task:
// Just complete the function rightView() that takes node as parameter and returns the right view as a list.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 0 ≤ Data of a node ≤ 105

class Solution
{
public:
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        // Your Code here
        vector<int> ans;
        if (!root)
            return ans;
        queue<Node *> q;
        q.push(root);
        while (q.size())
        {
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                Node *temp = q.front();
                q.pop();
                if (i == s - 1)
                {
                    ans.push_back(temp->data);
                }
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
        return ans;
    }
};
