// Normal BST to Balanced BST
// EasyAccuracy: 66.08%Submissions: 27K+Points: 2
// We've got offers as great as this problem! Explore Geek Week 2023

// banner
// Given a Binary Search Tree, modify the given BST such that it is balanced and has minimum possible height. Return the balanced BST.

// Example1:

// Input:
//        30
//       /
//      20
//     /
//    10
// Output:
//      20
//    /   \
//  10     30
// Example2:

// Input:
//          4
//         /
//        3
//       /
//      2
//     /
//    1
// Output:
//       3            3           2
//     /  \         /  \        /  \
//    1    4   OR  2    4  OR  1    3
//     \          /                  \ 
//      2        1                    4

// Your Task:
// The task is to complete the function buildBalancedTree() which takes root as the input argument and returns the root of tree after converting the given BST into a balanced BST with minimum possible height. The driver code will print the height of the updated tree in output itself.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)
// Here N denotes total number of nodes in given BST.

// Constraints:
// 1 <= N <= 105
// 1 <= Node data <= 109

class Solution
{

public:
    // Your are required to complete this function
    // function should return root of the modified BST

    vector<int> arr;

    void inOrder(Node *root)
    {
        if (!root)
        {
            return;
        }
        inOrder(root->left);
        arr.push_back(root->data);
        inOrder(root->right);
    }

    Node *buildTree(int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }

        int mid = (start + end) / 2;
        Node *root = new Node(arr[mid]);

        root->left = buildTree(start, mid - 1);
        root->right = buildTree(mid + 1, end);

        return root;
    }

    Node *buildBalancedTree(Node *root)
    {
        // Code here
        inOrder(root);
        return buildTree(0, arr.size() - 1);
    }
};
