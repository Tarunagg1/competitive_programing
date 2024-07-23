// Merge two BST 's
// Difficulty: MediumAccuracy: 64.95%Submissions: 62K+Points: 4
// Given two BSTs, return elements of merged BSTs in sorted form.

// Examples :

// Input:
// BST1:
//        5
//      /   \
//     3     6
//    / \
//   2   4
// BST2:
//         2
//       /   \
//      1     3
//             \
//              7
//             /
//            6
// Output: 1 2 2 3 3 4 5 6 6 7
// Explanation: After merging and sorting the two BST we get 1 2 2 3 3 4 5 6 6 7.
// Input:
// BST1:
//        12
//      /
//     9
//    / \    
//   6   11
// BST2:
//       8
//     /  \
//    5    10
//   /
//  2
// Output: 2 5 6 8 9 10 11 12
// Explanation: After merging and sorting the two BST we get 2 5 6 8 9 10 11 12.
// Expected Time Complexity: O(m+n)
// Expected Auxiliary Space: O(Height of BST1 + Height of BST2 + m + n)

// Constraints:
// 1 ≤ Number of Nodes ≤ 105

class Solution
{
public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void inorder(Node *root, vector<int> &data)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, data);
        data.push_back(root->data);
        inorder(root->right, data);
    }
    vector<int> mergeArrays(vector<int> &a, vector<int> &b)
    {
        vector<int> ans(a.size() + b.size());
        int n = a.size();
        int m = b.size();
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < n && j < m)
        {
            if (a[i] < b[j])
            {
                ans[k++] = a[i];
                i++;
            }
            else
            {
                ans[k++] = b[j];
                j++;
            }
        }
        while (i < n)
        {
            ans[k++] = a[i];
            i++;
        }
        while (j < m)
        {
            ans[k++] = b[j];
            j++;
        }
        return ans;
    }
    Node *inoderToBST(int start, int end, vector<int> &data)
    {
        int mid = start + (end - start) / 2;
        if (start > end)
        {
            return NULL;
        }
        Node *root = new Node(data[mid]);
        root->left = inoderToBST(start, mid - 1, data);
        root->right = inoderToBST(mid + 1, end, data);

        return root;
    }
    vector<int> merge(Node *root1, Node *root2)
    {
        // Your code here
        vector<int> bst1, bst2;
        inorder(root1, bst1);
        inorder(root2, bst2);

        vector<int> mergedArray = mergeArrays(bst1, bst2);
        int start = 0;
        int end = mergedArray.size() - 1;
        Node *mergedRoot = inoderToBST(start, end, mergedArray);

        vector<int> result;
        inorder(mergedRoot, result);
        return result;
    }
};
