// Sum of k smallest elements in BST
// EasyAccuracy: 65.33%Submissions: 3171Points: 2
//  Given a Binary Search Tree. Find sum of all elements smaller than and equal to Kth smallest element.

// Example 1:

// Input:
//           20
//         /    \
//        8     22
//      /    \
//     4     12
//          /    \
//         10    14   , K=3

// Output: 22
// Explanation:
// Sum of 3 smallest elements are:
// 4 + 8 + 10 = 22
// Example 2:
// Input:
//      10
//     /  \
//    5    11
//   / \ 
//  4   7
//       \
//        8 , K=2

// Output: 9
// Explanation:
// The sum of two smallest elements
// is 4+5=9.

// Your task:
// You don't need to read input or print anything. Your task is to complete the function sum() which takes the root node and an integer K as input parameters and returns the sum of all elements smaller than and equal to kth smallest element.

// Expected Time Complexity: O(K)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<=Number of nodes in BST<=100
// 1<=K<=N

void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int sum(Node *root, int k)
{

    // Your code here
    vector<int> v;
    inorder(root, v);

    int Sum = 0;
    for (int i = 0; i < k; i++)
    {
        Sum += v[i];
    }

    return Sum;
}
