// Largest BST 
// Medium Accuracy: 30.88% Submissions: 61994 Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.   
// Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
// Note: Here Size is equal to the number of nodes in the subtree.

// Example 1:

// Input:
//         1
//       /   \
//      4     4
//    /   \
//   6     8
// Output: 1
// Explanation: There's no sub-tree with size
// greater than 1 which forms a BST. All the
// leaf Nodes are the BSTs with size equal
// to 1.
// Example 2:

// Input: 6 6 3 N 2 9 3 N 8 8 2
//             6
//         /       \
//        6         3
//         \      /   \
//          2    9     3
//           \  /  \
//           8 8    2 
// Output: 2
// Explanation: The following sub-tree is a
// BST of size 2: 
//        2
//     /    \ 
//    N      8
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function largestBst() that takes the root node of the Binary Tree as its input and returns the size of the largest subtree which is also the BST. If the complete Binary Tree is a BST, return the size of the complete Binary Tree. 

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the BST).

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 1 ≤ Data of a node ≤ 106

// View Bookmarked Problems


struct bst{
    bool isBST;
    int size;
    int mx;
    int mn;
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    bst Large(Node* root)
    {
        if(!root){
            bst b={true,0,INT_MIN,INT_MAX};
            return b;
        }
        bst l=Large(root->left);
        bst r=Large(root->right);
        bst b;
        if(l.isBST && r.isBST && l.mx<root->data && r.mn>root->data)
            bst b={true,l.size+r.size+1,max(root->data,r.mx),min(root->data,l.mn)};
        else
            bst b={false,max(l.size,r.size),-1,-1};
        return b;
    }
    
    
    int largestBst(Node *root)
    {
    	//Your code here
    	bst b=Large(root);
        return b.size;
    }
};




















































