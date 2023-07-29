// Median of BST
// EasyAccuracy: 27.43%Submissions: 51K+Points: 2
// POTD July Placement Special : All POTD in the month of July are based on popular interview questions. Solve every day to ace the upcoming Placement Season !
// Given a Binary Search Tree of size N, find the Median of its Node values.

// Example 1:

// Input:
//        6
//      /   \
//    3      8
//  /  \    /  \
// 1    4  7    9
// Output: 6
// Explanation: Inorder of Given BST will be:
// 1, 3, 4, 6, 7, 8, 9. So, here median will 6.

// Example 2:

// Input:
//        6
//      /   \
//    3      8
//  /   \    /
// 1    4   7
// Output: 5
// Explanation:Inorder of Given BST will be:
// 1, 3, 4, 6, 7, 8. So, here median will
// (4 + 6)/2 = 10/2 = 5.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findMedian() which takes the root of the Binary Search Tree as input and returns the Median of Node values in the given BST.
// Median of the BST is:

// If number of nodes are even: then median = (N/2 th node + (N/2)+1 th node)/2
// If number of nodes are odd : then median = (N+1)/2th node.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 1<=N<=10000

int count(Node *p)
{
    if (!p)
        return 0;
    return 1 + count(p->left) + count(p->right);
}

void inorder(Node *p, int &cnt, float arr[])
{
    if (!p)
        return;
    if (cnt < -1)
        return;

    inorder(p->left, cnt, arr);
    cnt--;
    if (cnt == 0)
        arr[1] = p->data;
    if (cnt == -1)
        arr[0] = p->data;
    inorder(p->right, cnt, arr);
}

float findMedian(struct Node *root)
{
    // Code here
    int n = count(root);
    int cnt = n / 2;
    float arr[2] = {0};
    inorder(root, cnt, arr);
    // cout<<arr[0]<<","<<arr[1];
    if (n & 1)
        return arr[0];
    return (arr[0] + arr[1]) / 2;
}
