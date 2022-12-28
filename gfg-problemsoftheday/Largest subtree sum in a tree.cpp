// Largest subtree sum in a tree
// HardAccuracy: 69.96%Submissions: 1K+Points: 8
// Lamp
// Land your Dream Job with Mega Job-a-thon. Register Now!

// Given a binary tree. The task is to find subtree with maximum sum in the tree and return its sum.

// Example 1:

// Input:
//               1
//             /   \
//            2      3
//           / \    / \
//          4   5  6   7
// Output: 28
// Explanation:
// As all the tree elements are positive,
// the largest subtree sum is equal to
// sum of all tree elements.

// Example 2:
// Input:
//                1
//             /    \
//           -2      3
//           / \    /  \
//          4   5  -6   2
// Output: 7
// Explanation:
// Subtree with largest sum is :
//   -2
//  /  \ 
// 4    5
// Also, entire tree sum is also 7.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findLargestSubtreeSum() which takes the root of a binary tree and returns an integer.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <= 10^5
// -10^3 <= tree.val <= 10^3

// View Bookmarked Problems

class Solution
{
public:
    // Function to find largest subtree sum.
    int solve(Node *root, int &maxi)
    {

        if (!root)
            return 0;

        int left = solve(root->left, maxi);

        int right = solve(root->right, maxi);

        maxi = max(maxi, left + right + root->data);

        return left + right + root->data;
    }

    // Function to find largest subtree sum.

    int findLargestSubtreeSum(Node *root)

    {

        // Write your code here

        int maxi = INT_MIN;

        solve(root, maxi);

        return maxi;
    }
};
