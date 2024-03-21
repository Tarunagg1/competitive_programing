// ZigZag Tree Traversal
// MediumAccuracy: 54.05%Submissions: 136K+Points: 4
// Maximize your earnings for your published articles in Dev Scripter 2024! Gain recognition & extra compensation while elevating your tech profile.

// banner
// Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.

// Example 1:

// Input:
//         1
//       /   \
//      2    3
//     / \    /   \
//    4   5 6   7
// Output:
// 1 3 2 4 5 6 7
// Example 2:

// Input:
//            7
//         /     \
//        9      7
//      /  \      /
//     8   8  6
//    /  \
//   10  9
// Output:
// 7 7 9 8 8 6 9 10
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the zig-zag level-order traversal of the tree.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(n).

// Constraints:
// 1 <= n <= 105

// Company Tags

class Solution
{
public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        // Code here
        vector<int> ans;
        stack<Node *> s1, s2;
        if (root)
            s1.push(root);

        while (!s1.empty() || !s2.empty())
        {
            while (!s1.empty())
            {
                Node *top = s1.top();
                ans.push_back(top->data);
                s1.pop();
                if (top->left)
                    s2.push(top->left);
                if (top->right)
                    s2.push(top->right);
            }
            while (!s2.empty())
            {
                Node *top = s2.top();
                ans.push_back(top->data);
                s2.pop();
                if (top->right)
                    s1.push(top->right);
                if (top->left)
                    s1.push(top->left);
            }
        }
        return ans;
    }
};
