// Level order traversal in spiral form
// EasyAccuracy: 36.43%Submissions: 174K+Points: 2
// POTD July Placement Special : All POTD in the month of July are based on popular interview questions. Solve every day to ace the upcoming Placement Season !
// Given a binary tree and the task is to find the spiral order traversal of the tree.

// Spiral order Traversal mean: Starting from level 0 for root node, for all the even levels we print the node's value from right to left and for all the odd levels we print the node's value from left to right.

// For below tree, function should return 1, 2, 3, 4, 5, 6, 7.

// Example 1:

// Input:
//       1
//     /   \
//    3     2
// Output:1 3 2

// Example 2:

// Input:
//            10
//          /     \
//         20     30
//       /    \
//     40     60
// Output: 10 20 30 60 40
// Your Task:
// The task is to complete the function findSpiral() which takes root node as input parameter and returns the elements in spiral form of level order traversal as a list. The newline is automatically appended by the driver code.
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= Number of nodes <= 105
// 0 <= Data of a node <= 105

vector<int> findSpiral(Node *root)
{
    // Your code here
    stack<Node *> s1;
    stack<Node *> s2;

    vector<int> v;

    s1.push(root);
    v.push_back(root->data);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {

            if (s1.top()->left != NULL)
            {
                s2.push(s1.top()->left);
                v.push_back(s1.top()->left->data);
            }

            if (s1.top()->right != NULL)
            {
                s2.push(s1.top()->right);
                v.push_back(s1.top()->right->data);
            }

            s1.pop();
        }

        while (!s2.empty())
        {
            if (s2.top()->right != NULL)
            {
                s1.push(s2.top()->right);
                v.push_back(s2.top()->right->data);
            }

            if (s2.top()->left != NULL)
            {
                s1.push(s2.top()->left);
                v.push_back(s2.top()->left->data);
            }

            s2.pop();
        }
    }

    return v;
}
