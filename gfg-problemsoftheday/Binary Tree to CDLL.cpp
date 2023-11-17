// Binary Tree to CDLL
// MediumAccuracy: 71.66%Submissions: 31K+Points: 4
// Exclusively for Freshers! Participate for Free on 21st November & Fast-Track Your Resume to Top Tech Companies

// banner
// Given a Binary Tree of N edges. The task is to convert this to a Circular Doubly Linked List (CDLL) in-place. The left and right pointers in nodes are to be used as previous and next pointers respectively in CDLL. The order of nodes in CDLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (left most node in BT) must be head node of the CDLL.

// Example 1:

// Input:
//       1
//     /   \
//    3     2
// Output:
// 3 1 2
// 2 1 3
// Explanation: After converting tree to CDLL
// when CDLL is is traversed from head to
// tail and then tail to head, elements
// are displayed as in the output.
// Example 2:

// Input:
//      10
//    /    \
//   20    30
//  /  \
// 40  60
// Output:
// 40 20 60 10 30
// 30 10 60 20 40
// Explanation:After converting tree to CDLL,
// when CDLL is is traversed from head to
// tail and then tail to head, elements
// are displayed as in the output.
// Your Task:
// You don't have to take input or print anything. Complete the function bTreeToCList() that takes root as a parameter and returns the head of the list. The driver code prints the linked list twice, first time in the right order, and another time in reverse order.

// Constraints:
// 1 <= N <= 103
// 1 <= Data of a node <= 104

// Expected time complexity: O(N)

// Expected auxiliary space: O(h) , where h = height of tree

// Company Tags

class Solution
{
public:
    // Function to convert binary tree into circular doubly linked list.
    Node *head, *prev;
    void inorder(Node *root)
    {
        if (root)
        {
            inorder(root->left);
            if (prev)
            {
                prev->right = root;
                root->left = prev;
            }

            else
                head = root;
            prev = root;
            inorder(root->right);
        }
    }
    Node *bTreeToCList(Node *root)
    {
        prev = NULL, head = NULL;
        inorder(root);
        head->left = prev;  // for making circular last next will be the left of start node i.e head->left
        prev->right = head; // last->irght=head makes it complete circular
        return head;
    }
};
