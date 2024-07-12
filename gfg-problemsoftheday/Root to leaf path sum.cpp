// Root to leaf path sum
// Difficulty: EasyAccuracy: 40.79%Submissions: 103K+Points: 2
// Given a binary tree and an integer target, check whether there is a root-to-leaf path with its sum as target.

// Examples :

// Input: tree = 1, target = 2
//             /   \
//           2     3
// Output: false
// Explanation: There is no root to leaf path with sum 2.
// Input: tree = 1,  target = 4
//             /   \
//           2     3
// Output: true
// Explanation: The sum of path from leaf node 3 to root 1 is 4.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(height of tree)

// Constraints:
// 1 ≤ number of nodes ≤ 104
// 1 ≤ target ≤ 106

// Seen this question in a real interview before ?
// Yes
// No
// Company Tags
// AccoliteAmazonMicrosoftSamsungFactSetHousing.comOracleGoldman SachsAdobeCouponDuniaAtlassian




class Solution {
  public:
    bool fn(Node* root, int target, int sum){
        if(!root){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            sum+=root->data;
            if(sum==target){
                return 1;
            }
            sum-=root->data;
            return 0;
        }
        bool leftAns=fn(root->left,target,sum+root->data);
        bool rightAns=fn(root->right,target,sum+root->data);
        return leftAns || rightAns;
    }
    bool hasPathSum(Node *root, int target) {
        // Your code here
        return fn(root,target,0);
    }
};
























