// Vertical Width of a Binary Tree 
// Easy Accuracy: 49.45% Submissions: 17535 Points: 2
// Given a Binary Tree of N nodes. Find the vertical width of the tree.

// Example 1:

// Input:
//           1
//        /    \
//       2      3
//      / \    / \
//     4   5  6   7
//             \   \
//              8   9
// Output: 6
// Explanation: The width of a binary tree is
// the number of vertical paths in that tree.



// The above tree contains 6 vertical lines.
 

// Example 2:

// Input:
//       1
//     /  \
//    2    3
// Output: 3
 

// Your Task:

// You don't have to read input or print anything. Your task is to complete the function verticalWidth() which takes root as the only parameter, and returns the vertical width of the binary tree.

 

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

 

// Constraints:
// 1 <= Number of nodes <= 105

// View Bookmarked Problems





unordered_set<int> st;

void inOrder(Node *root, int hd){
    if(root != NULL){
        inOrder(root->left,hd-1);
        st.insert(hd);
        inOrder(root->right,hd+1);
    }
}


int verticalWidth(Node* root)
{
    // Code here
    st.clear();
    inOrder(root,0);
    return st.size();
}







