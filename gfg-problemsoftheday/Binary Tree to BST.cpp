// Binary Tree to BST
// EasyAccuracy: 60.75%Submissions: 50K+Points: 2
// Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
//  Example 1:

// Input:
//       1
//     /   \
//    2     3
// Output: 
// 1 2 3
// Explanation:
// The converted BST will be 
//       2
//     /   \
//    1     3

// Example 2:

// Input:
//           1
//        /    \
//      2       3
//    /        
//  4       
// Output: 
// 1 2 3 4
// Explanation:
// The converted BST will be

//         3
//       /   \
//     2     4
//   /
//  1
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function binaryTreeToBST() which takes the root of the Binary tree as input and returns the root of the BST. The driver code will print inorder traversal of the converted BST.

// Expected Time Complexity: O(NLogN).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= Number of nodes <= 105



class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void inorder(Node* root,vector<int>&nodelist){
        //base case
        if(root==NULL){
            return;
        }
        //LNR(inorder)
        inorder(root->left,nodelist);
        nodelist.push_back(root->data);
        inorder(root->right,nodelist);
    }
    Node* sortedArrTOBST(int start,int end,vector<int>&nodelist){ 
        //base case
        if(start>end){
            return NULL;
        }
        
        int mid = start+(end-start)/2;
        Node* newNode = new Node(nodelist[mid]);
        //recursive call root->left and root->right
        newNode->left = sortedArrTOBST(start,mid-1,nodelist);
        newNode->right = sortedArrTOBST(mid+1,end,nodelist);
        
        return newNode;
    }
    Node *binaryTreeToBST (Node *root)
    {
        vector<int>nodelist;
        //extract values using inorder traversal
        inorder(root, nodelist);
        
        sort(nodelist.begin(), nodelist.end());
        //convert the sorted values back to BST
        return sortedArrTOBST(0,nodelist.size()-1,nodelist);
    }
};

























