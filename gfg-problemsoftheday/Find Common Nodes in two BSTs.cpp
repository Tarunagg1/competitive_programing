// Find Common Nodes in two BSTs
// EasyAccuracy: 51.7%Submissions: 33K+Points: 2
// We've got offers as great as this problem! Explore Geek Week 2023

// banner
// Given two Binary Search Trees. Find the nodes that are common in both of them, ie- find the intersection of the two BSTs.

// Note: Return the common nodes in sorted order.

// Example 1:

// Input:
// BST1:
//                   5
//                /     \
//              1        10
//            /   \      /
//           0     4    7
//                       \
//                        9
// BST2:
//                 10 
//               /    \
//              7     20
//            /   \ 
//           4     9
// Output: 4 7 9 10

// Example 2:

// Input:
// BST1:
//      10
//     /  \
//    2   11
//   /  \
//  1   3
// BST2:
//        2
//      /  \
//     1    3
// Output: 1 2 3
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findCommon() that takes roots of the two BSTs as input parameters and returns a list of integers containing the common nodes in sorted order. 

// Expected Time Complexity: O(N1 + N2) where N1 and N2 are the sizes of the 2 BSTs.
// Expected Auxiliary Space: O(H1 + H2) where H1 and H2 are the heights of the 2 BSTs.

// Constraints:
// 1 <= Number of Nodes <= 105
// 1 <= Node data <= 109

// Company Tags


class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
   void help(Node*root,map<int,int>&val)
    {
        if(!root) return;
        
        help(root->left,val);
        val[root->data]++;
        help(root->right,val);
    }
    
    
    vector <int> findCommon(Node *root1, Node *root2)
    {
     
     map<int,int>val;
     help(root1,val);
     help(root2,val);
     vector<int>ans;
     for(auto it:val)
     {
         if(it.second>1) ans.push_back(it.first);
     }
     return ans;
    }
};





























