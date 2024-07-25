// Array to BST
// Difficulty: EasyAccuracy: 46.02%Submissions: 62K+Points: 2
// Given a sorted array. Convert it into a Height Balanced Binary Search Tree (BST). Return the root of the BST.

// Height-balanced BST means a binary tree in which the depth of the left subtree and the right subtree of every node never differ by more than 1.

// Note: The driver code will check the BST, if it is a Height-balanced BST, the output will be true otherwise the output will be false.

// Examples :

// Input: nums = [1, 2, 3, 4]
// Output: true
// Explanation: The preorder traversal of the following BST formed is [2, 1, 3, 4]:
//            2
//          /   \
//         1     3
//                \
//                 4
// Input: nums = [1, 2, 3, 4, 5, 6, 7]
// Ouput: true
// Explanation: The preorder traversal of the following BST formed is [4, 2, 1, 3, 6, 5, 7]:
//         4
//        / \
//       2   6
//      / \   / \
//     1 3  5 7
// Expected Time Complexity: O(n)
// Expected Auxillary Space: O(n)

// Constraints:
// 1 ≤ nums.size() ≤ 105
// 1 ≤ nums[i] ≤ 105

// Seen this question in a real interview before ?
// Yes
// No
// Company Tags
// SnapdealAdobeCisco

class Solution
{
public:
    Node *setNode(int l, int h, vector<int> &nums)
    {
        if (l >= h)
            return NULL;

        int mid = (l + h) / 2;
        Node *root = new Node(nums[mid]);
        root->left = setNode(l, mid, nums);
        root->right = setNode(mid + 1, h, nums);
        return root;
    }

    Node *sortedArrayToBST(vector<int> &nums)
    {
        return setNode(0, nums.size(), nums);
    }
};
