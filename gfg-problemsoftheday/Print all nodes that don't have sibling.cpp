// Print all nodes that don't have sibling
// EasyAccuracy: 18.01%Submissions: 147K+Points: 2
//  Done with winning Geekbits? Now win GfG Bag, GfG T-shirt & much more just by writing your experiences. Start Writing, Start Winning.
// banner
// Given a Binary Tree of n nodes, find all the nodes that don't have any siblings. You need to return a list of integers containing all the nodes that don't have a sibling in sorted order (Increasing).

// Two nodes are said to be siblings if they are present at the same level, and their parents are the same.

// Note: The root node can not have a sibling so it cannot be included in our answer.

// Example 1:

// Input :
//        37
//       /   
//     20
//     /     
//   113 

// Output: 
// 20 113
// Explanation: 
// Nodes 20 and 113 dont have any siblings.

// Example 2:

// Input :
//        1
//       / \
//      2   3 

// Output: 
// -1
// Explanation: 
// Every node has a sibling.
// Your Task:  
// You don't need to read input or print anything. Complete the function noSibling() which takes the root of the tree as input parameter and returns a list of integers containing all the nodes that don't have a sibling in sorted order. If all nodes have a sibling, then the returning list should contain only one element -1.

// Expected Time Complexity: O(nlogn)
// Expected Auxiliary Space: O(Height of the tree)

// Constraints:
// 1 ≤ n ≤ 104



void solve(Node* root, vector<int>&v)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->left!=NULL and root->right==NULL)
    {
        v.push_back(root->left->data);
    }
    if(root->left==NULL and root->right!=NULL)
    {
        v.push_back(root->right->data);
    }
    solve(root->left,v);
    solve(root->right,v);
}
vector<int> noSibling(Node* node)
{
    // code here
    vector<int>ans;
    solve(node,ans);
    if(ans.size()==0)
    {
        return {-1};
    }
    sort(ans.begin(),ans.end());
    return ans;
}












