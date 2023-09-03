// Check if Tree is Isomorphic
// EasyAccuracy: 49.11%Submissions: 69K+Points: 2
// Given two Binary Trees. Check whether they are Isomorphic or not.

// Note:
// Two trees are called isomorphic if one can be obtained from another by a series of flips, i.e. by swapping left and right children of several nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.
// For example, the following two trees are isomorphic with the following sub-trees flipped: 2 and 3, NULL and 6, 7 and 8.
// ISomorphicTrees

// Example 1:

// Input:
//  T1    1     T2:   1
//      /   \        /  \
//     2     3      3    2
//    /            /
//   4            4
// Output: No

// Example 2:

// Input:
// T1    1     T2:    1
//     /  \         /   \
//    2    3       3     2
//   /                    \
//   4                     4
// Output: Yes
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isomorphic() that takes the root nodes of both the Binary Trees as its input and returns True if the two trees are isomorphic. Else, it returns False. (The driver code will print Yes if the returned values are true, otherwise false.)

// Expected Time Complexity: O(min(M, N)) where M and N are the sizes of the two trees.
// Expected Auxiliary Space: O(min(H1, H2)) where H1 and H2 are the heights of the two trees.

// Constraints:
// 1<=Number of nodes<=105

// Company Tags

class Solution
{
public:
    // Return True if the given trees are isomotphic. Else return False.
    void inorder(Node *root, vector<int> &v)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    bool isIsomorphic(Node *root1, Node *root2)
    {
        // add code here.

        if (root1 == NULL && root2 == NULL)
        {
            return true;
        }

        vector<int> v1;
        vector<int> v2;

        inorder(root1, v1);
        inorder(root2, v2);

        if (v1 == v2)
        {
            return true;
        }
        int i = 0;
        int j = v2.size() - 1;

        while (i < v2.size() && j >= 0)
        {

            if (v1[i] != v2[j])
            {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};
