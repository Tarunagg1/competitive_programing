// Root to Leaf Paths
// MediumAccuracy: 43.65%Submissions: 61K+Points: 4
//  Done with winning Geekbits? Now win GfG Bag, GfG T-shirt & much more just by writing your experiences. Start Writing, Start Winning.
// banner
// Given a Binary Tree of nodes, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

// Example 1:

// Input:
//        1
//     /     \
//    2       3
// Output:
// 1 2
// 1 3
// Explanation:
// All possible paths:
// 1->2
// 1->3
// Example 2:

// Input:
//          10
//        /    \
//       20    30
//      /  \
//     40   60
// Output:
// 10 20 40
// 10 20 60
// 10 30
// Your Task:
// Your task is to complete the function Paths() which takes the root node as an argument and returns all the possible paths. (All the paths are printed in new lines by the driver's code.)

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(height of the tree)

// Constraints:
// 1<=n<=104

class Solution
{
public:
    vector<vector<int>> Paths(Node *root)
    {
        vector<vector<int>> ans;
        vector<int> tmp;
        FindAll(root, ans, tmp);
        return ans;
    }

    void FindAll(Node *root, vector<vector<int>> &ans, vector<int> &tmp)
    {
        // code here
        if (!root)
            return;

        tmp.push_back(root->data);

        if (!root->left && !root->right)
        {
            ans.push_back(tmp);
        }
        else
        {
            if (root->left)
            {
                FindAll(root->left, ans, tmp);
                tmp.pop_back();
            }
            if (root->right)
            {
                FindAll(root->right, ans, tmp);
                tmp.pop_back();
            }
        }
    }
};
