// Determine if Two Trees are Identical
// EasyAccuracy: 50.01%Submissions: 217K+Points: 2
// Exclusively for Freshers! Participate for Free on 21st November & Fast-Track Your Resume to Top Tech Companies

// banner
// Given two binary trees, the task is to find if both of them are identical or not.
// Note: You need to return true or false, the printing is done by the driver code.

// Example 1:

// Input:
//      1          1
//    /   \      /   \
//   2     3    2     3
// Output:
// Yes
// Explanation:
// There are two trees both having 3 nodes and 2 edges, both trees are identical having the root as 1, left child of 1 is 2 and right child of 1 is 3.
// Example 2:

// Input:
//     1       1
//   /  \     /  \
//  2    3   3    2
// Output:
// No
// Explanation: There are two trees both having 3 nodes and 2 edges, but both trees are not identical.
// Your task:
// Since this is a functional problem you don't have to worry about input, you just have to complete the function isIdentical() that takes two roots as parameters and returns true or false. The printing is done by the driver code.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 1 <= Number of nodes <= 105
// 1 <=Data of a node <= 109

class Solution
{
public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        // Your Code here
        if (!r1 && !r2)
            return true;

        if (!r1 || !r2)
            return false;

        if (r1->data != r2->data)
            return false;

        return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
    }
};
