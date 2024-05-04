// Construct Binary Tree from Inorder and Postorder
// MediumAccuracy: 64.78%Submissions: 59K+Points: 4
//  Done with winning Geekbits? Now win GfG Bag, GfG T-shirt & much more just by writing your experiences. Start Writing, Start Winning.
// banner
// Given inorder and postorder traversals of a binary tree(having n nodes) in the arrays in[] and post[] respectively. The task is to construct a binary tree from these traversals.

// Driver code will print the preorder traversal of the constructed tree.

// Example 1:

// Input:
// n = 8
// in[] = {4, 8, 2, 5, 1, 6, 3, 7}
// post[] = {8, 4, 5, 2, 6, 7, 3, 1}
// Output: 
// 1 2 4 8 5 3 6 7
// Explanation: 
// For the given postorder and inorder traversal of tree the  resultant binary tree will be
//           1
//        /      \
//      2        3
//    /  \      /  \
//   4   5    6   7
//    \
//     8
// Example 2:

// Input:
// n = 5
// in[] = {9, 5, 2, 3, 4}
// post[] = {5, 9, 3, 4, 2}
// Output: 
// 2 9 5 4 3
// Explanation:  
// The  resultant binary tree will be
//            2
//         /     \
//        9      4
//         \     /
//          5   3
// Your Task:
// You do not need to read input or print anything. Complete the function buildTree() which takes the inorder, postorder traversals and the number of nodes in the tree as input parameters and returns the root node of the newly constructed Binary Tree.

// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= n <= 103
// 1 <= in[i], post[i] <= 106


class Solution
{
     public:
 int position(int in[], int inStart, int inEnd, int val){
        for(int i=inStart; i<=inEnd; i++){
            if(in[i]==val)
            return i;
        }
        return -1;
    }
    Node *tree(int in[], int post[], int &postind, int inStart, int inEnd){
        if(postind<0 || inStart>inEnd)
        return NULL;
        
        int val=post[postind--];
        Node *node=new Node(val);
        
        int pos=position(in, inStart, inEnd, val);
        
        node->right=tree(in, post, postind, pos+1, inEnd);
        node->left=tree(in, post, postind, inStart, pos-1);
        
        return node;
        
        
    }
    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        int postind=n-1;
        Node *ans=tree(in, post, postind, 0, n-1);
        return ans;
    }
};






















