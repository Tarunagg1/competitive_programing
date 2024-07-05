// Vertical Width of a Binary Tree
// Difficulty: MediumAccuracy: 43.48%Submissions: 43K+Points: 4
// Given a Binary Tree. You need to find and return the vertical width of the tree.

// Examples :

// Input:
//          1
//        /    \
//       2      3
//      / \    /  \
//     4   5  6   7
//             \   \
//              8   9
// Output: 6
// Explanation: The width of a binary tree is
// the number of vertical paths in that tree.



// The above tree contains 6 vertical lines.
// Input:
//      1
//     /  \
//    2    3
// Output: 3
// Explanation: The above tree has 3 vertical lines, hence the answer is 3.
// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(height of the tree).

// Constraints:
// 0 <= number of nodes <= 104



class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    void calVertiWid(Node* root,unordered_set<int> &s,int pos){
        if(!root) return;
        if(root->left) calVertiWid(root->left,s,pos-1);
        
        if(root->right) calVertiWid(root->right,s,pos+1);
        s.insert(pos);
    }
  public:
    // Function to find the vertical width of a Binary Tree.
    int verticalWidth(Node* root) {
       unordered_set<int> s;
       calVertiWid(root,s,0);
       
       return s.size();
    }
};













