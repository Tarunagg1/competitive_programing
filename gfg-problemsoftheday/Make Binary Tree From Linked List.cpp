// Make Binary Tree From Linked List
// Difficulty: MediumAccuracy: 65.65%Submissions: 37K+Points: 4
// Given a Linked List Representation of Complete Binary Tree. The task is to construct the Binary tree and print the level order traversal of the Binary tree.
// Note: The complete binary tree is represented as a linked list in a way where if the root node is stored at position i, its left, and right children are stored at position 2*i+1, and 2*i+2 respectively. H is the height of the tree and this space is used implicitly for the recursion stack.

// Examples:

// Input: n = 5, k = 1->2->3->4->5
// Output: 1 2 3 4 5
// Explanation: The tree would look like
//       1
//     /   \
//    2     3
//  /  \
// 4   5
// Now, the level order traversal of
// the above tree is 1 2 3 4 5.
// Input: n = 5, k = 5->4->3->2->1
// Output: 5 4 3 2 1
// Explanation: The tree would look like
//      5
//    /  \
//   4    3
//  / \
// 2   1
// Now, the level order traversal of
// the above tree is 5 4 3 2 1.
// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(n).
// Constraints:
// 1 <= n <= 105
// 1 <= ki <= 105

void constructTree(vector<int> &v, int indx, TreeNode *root)
{
    // Base case: if the index is out of bounds, return
    if (indx >= v.size())
    {
        return;
    }

    // Calculate the indices for left and right children
    int leftChildIndex = 2 * indx + 1;
    int rightChildIndex = 2 * indx + 2;

    // Construct left subtree if left child index is within bounds
    if (leftChildIndex < v.size())
    {
        root->left = new TreeNode(v[leftChildIndex]);
        constructTree(v, leftChildIndex, root->left);
    }

    // Construct right subtree if right child index is within bounds
    if (rightChildIndex < v.size())
    {
        root->right = new TreeNode(v[rightChildIndex]);
        constructTree(v, rightChildIndex, root->right);
    }
}

// Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root)
{
    // Step-1: Convert the linked list into a vector
    vector<int> v;
    Node *temp = head;
    while (temp != NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }

    // Step-2: Create the root node and construct the binary tree
    if (!v.empty())
    {
        root = new TreeNode(v[0]);
        constructTree(v, 0, root);
    }
}
