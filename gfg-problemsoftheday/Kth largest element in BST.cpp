// Kth largest element in BST
// EasyAccuracy: 49.31%Submissions: 111K+Points: 2
// Given a Binary Search Tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

// Example 1:

// Input:
//       4
//     /   \
//    2     9
// k = 2 
// Output: 4
// Example 2:

// Input:
//        9
//         \ 
//           10
// K = 1
// Output: 10
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the root of the BST and an integer K as inputs and returns the Kth largest element in the given BST.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(H) where H is max recursion stack of height H at a given time.

// Constraints:
// 1 <= N <= 105
// 1 <= K <= N

// Company Tags
// Topic Tags


class Solution
{
    public:
    int ans=0;
    
    int t=0;
    
    void find(Node* root,int k)
    {
        if(!root) return;
        
        find(root->right,k);
        t++;
        if(t==k)
        {
            ans=root->data;
            return;
         }
        find(root->left,k);
     }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        
        find(root,K);
        return ans;
     }
};

























