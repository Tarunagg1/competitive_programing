// Minimum Absolute Difference In BST
// MediumAccuracy: 66.33%Submissions: 8K+Points: 4
// Given a binary search tree having n (n>1) nodes, the task is to find the minimum absolute difference between any two nodes.

// Example 1:

// Input:
// Input tree

// Output:
// 10
// Explanation:
// There are no two nodes whose absolute difference in smaller than 10.
// Example 2:

// Input:
// Input tree

// Output:
// 20
// Explanation:
// There are no two nodes whose absolute difference in smaller than 20.
// Your Task:
// You don't have to take any input. Just complete the function absolute_diff() , that takes root as input and return minimum absolute difference between any two nodes.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 2 <= n <= 105
// 1 <= Node->data <= 109




class Solution
{
    public:
    int mini,prev;
    void find(Node *root)
    {
        if(!root) return;
        find(root->left);
        if(prev!=-1) mini=min(mini,abs(prev-root->data));
        prev=root->data;
        find(root->right);
    }
    int absolute_diff(Node *root)
    {
       mini=INT_MAX;
       prev=-1;
       find(root);
       return mini;
    }
};
























