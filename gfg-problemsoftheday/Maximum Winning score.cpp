// Maximum Winning score 
// Medium Accuracy: 87.68% Submissions: 1279 Points: 4
// In an online game, N blocks are arranged in a hierarchical manner. All the blocks are connected together by a total of N-1 connections. Each block is given an ID from 1 to N. A block may be further connected to other blocks. Each block is also assigned a specific point value.

// A player starts from Block 1. She must move forward from each block to a directly connected block until she reaches the final block, which has no further connection. When the player lands on a block, she collects the point value of that block. The players score is calculated as the product of point values that the player collects.
// Find the maximum score a player can achieve.
// Note: The answer can always be represented with 64 bits.


// Example 1:

// Input:
//      4
//     / \
//    2   8
//   / \ / \
//  2  1 3  4
// Output: 128
// Explanation: Path in the given tree 
// goes like 4, 8, 4 which gives the max
// score of 4x8x4 = 128.
// Example 2:

// Input:
//      10
//    /    \
//   7      5
//           \
//            1
// Output: 70
// Explanation: The path 10, 7 gives a 
// score of 70 which is the maximum possible.

// Your Task:
// You don't need to take input or print anything. Your task is to complete the function findMaxScore() that takes root as input and returns max score possible.


// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).


// Constraints:
// 1 ≤ Number of nodes ≤ 103
// 1 ≤ Data on node ≤ 10
// It is guaranteed that the answer will always fit in the 64-bit Integer
// View Bookmarked Problems


class Solution {
  public:
    //Function to return maximum path product from any node in a tree.
    long long findMaxScore(Node* root)
    {
        // Your code goes here
        if(!root){
            return 0;
        }
        
        if(root->left == NULL && root->right == NULL) return (long long) root->data;
        
        return (long long) root->data * max(findMaxScore(root->left),findMaxScore(root->right));
        
    }
};

























