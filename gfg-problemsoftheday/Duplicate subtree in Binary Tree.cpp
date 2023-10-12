// uplicate subtree in Binary Tree
// MediumAccuracy: 34.23%Submissions: 65K+Points: 4
// Hack you way to glory and win from a cash pool prize of INR 15,000. Register for free now

// banner
// Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.

// Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one.

// Example 1 :

// Input :
//                1
//              /   \ 
//            2       3
//          /   \       \    
//         4     5       2
//                      /  \    
//                     4    5
// Output : 1
// Explanation :
//     2
//   /   \    
//  4     5
// is the duplicate sub-tree.
// Example 2 :

// Input :
//                1
//              /   \ 
//            2       3
// Output: 0
// Explanation: There is no duplicate sub-tree
// in the given binary tree.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function dupSub() which takes root of the tree as the only argument and returns 1 if the binary tree contains a duplicate sub-tree of size two or more, else 0.

// Expected Time Complexity: O(N)
// Expected Space Complexity: O(N)

// Constraints:
// 0 ≤ Number of nodes ≤ 9

class Solution
{
public:
    /*This function returns true if the tree contains
    a duplicate subtree of size 2 or more else returns false*/
    string solve(Node *root, unordered_map<string, int> &m)
    {
        if (!root)
            return "$";
        string s = "";
        if (!root->left && !root->right)
        {
            s = to_string(root->data);
            return s;
        }
        s = s + to_string(root->data);
        s = s + solve(root->left, m);
        s = s + solve(root->right, m);
        m[s]++;
        return s;
    }

    int dupSub(Node *root)
    {

        unordered_map<string, int> m;
        m.clear();
        solve(root, m);
        for (auto x : m)
        {
            if (x.second >= 2)
                return true;
        }
        return false;
    }
};
