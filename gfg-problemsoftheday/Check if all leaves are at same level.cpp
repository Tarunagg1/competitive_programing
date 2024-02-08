// Check if all leaves are at same level
// EasyAccuracy: 39.47%Submissions: 95K+Points: 2
// Three 90 Challenge Extended On Popular Demand! Don't Miss Out Now 

// banner
// Given a binary tree with n nodes, determine whether all the leaf nodes are at the same level or not. Return true if all leaf nodes are at the same level, and false otherwise.

// Example 1:

// Input:
// Tree:
//     1
//    / \
//   2   3
// Output:
// true
// Explanation:
// The binary tree has a height of 2 and the leaves are at the same level.
// Example 2:

// Input:
// Tree:
//     10
//    /  \
//  20   30
//  /  \
//  10   15
// Output:
// false
// Explanation:
// The binary tree has a height of 3 and the leaves are not at the same level.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(height of tree)

// Your Task:
// Implement the function check() that checks whether all the leaf nodes in the given binary tree are at the same level or not. The function takes the root node of the tree as an input and should return a boolean value (true/false) based on the condition.

// Constraints:
// 1 ≤ n ≤ 105


class Solution{
  public:
    /*You are required to complete this method*/
      unordered_set<int> st = {};
    bool check(Node *root, int level = 0)
    {
        //Your code here
        if(!root) return true;
        if(st.size()>1)return false;
        if(!root->left && !root->right){
            st.insert(level);
            if(st.size()>1)return false;
        }
        return check(root->left,level + 1) && check(root->right, level + 1);
    }
};





















