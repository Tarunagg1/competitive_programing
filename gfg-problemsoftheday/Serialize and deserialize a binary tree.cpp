// Serialize and deserialize a binary tree
// MediumAccuracy: 51.67%Submissions: 63K+Points: 4
//  Done with winning Geekbits? Now win GfG Bag, GfG T-shirt & much more just by writing your experiences. Start Writing, Start Winning.
// banner
// Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions

// serialize() : stores the tree into an array a and returns the array.
// deSerialize() : deserializes the array to the tree and returns the root of the tree.
// Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver code will print the in-order traversal of the tree returned by deSerialize(serialize(input_tree)).

// Example 1:

// Input:
//       1
//     /   \
//    2     3
// Output:
// 2 1 3
// Example 2:

// Input:
//          10
//        /    \
//       20    30
//     /   \
//    40  60
// Output:
// 40 20 60 10 30
// Your Task:
// The task is to complete two functions serialize which takes the root node of the tree as input and stores the tree into an array and deSerialize which deserializes the array to the original tree and returns the root of it.

// Expected Time Complexity: O(Number of nodes).
// Expected Auxiliary Space: O(Number of nodes).

// Constraints:
// 1 <= Number of nodes <= 104
// 1 <= Data of a node <= 109

class Solution
{
public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        vector<int> v;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();

            if (node)
                v.push_back(node->data);
            else
                v.push_back(-1);

            if (node)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return v;
    }

    Node *deSerialize(vector<int> &A)
    {
        Node *root = new Node(A[0]);
        queue<Node *> q;
        q.push(root);
        int i = 1;

        while (!q.empty() and i < A.size())
        {
            Node *node = q.front();
            q.pop();

            bool FR = 0;
            bool FL = 0;
            if (A[i] == -1)
            {
                node->left = NULL;
                FL = 1;
            }

            if (A[i + 1] == -1)
            {
                node->right = NULL;
                FR = 1;
            }

            if (!FL)
            {
                Node *newNode1 = new Node(A[i]);
                node->left = newNode1;
                q.push(newNode1);
            }

            if (!FR)
            {
                Node *newNode1 = new Node(A[i + 1]);
                node->right = newNode1;
                q.push(newNode1);
            }

            i += 2;
        }
        return root;
    }
};
