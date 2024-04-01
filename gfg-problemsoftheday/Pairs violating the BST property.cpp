// Pairs violating the BST property
// MediumAccuracy: 78.82%Submissions: 3K+Points: 4
// Given a binary tree with n nodes, find the number of pairs violating the BST property.
// BST has the following properties:-

// Every node is greater than its left child and less than its right child.
// Every node is greater than the maximum value of in its left subtree and less than the minimum value in its right subtree.
// The maximum in the left sub-tree must be less than the minimum in the right subtree.
// Example 1:

// Input :
// n = 5
// Input tree

// Output :
// 5
// Explanation :
// Pairs violating BST property are:-
// (10,50), 10 should be greater than its left child value.
// (40,30), 40 should be less than its right child value.
// (50,20), (50,30) and (50,40), maximum of left subtree of 10 is 50 greater than 20, 30 and 40 of its right subtree.
// Example 2:

// Input :
// n = 6
// Input tree

// Output :
// 5
// Explanation :
// Pairs violating BST property are:-
// (80,30), greater than its right child.
// (80,60), greater than node on its right side.
// (80,70), greater than node on its right side.
// (30,60), the value of 3 is not more than its left child.
// (40,30), the value in the left subtree is greater than the value of the right subtree.
// Your task :
// You don't have to read input or print anything. Your task is to complete the function pairsViolatingBST() that takes the root of the tree and n as input and returns number of pairs violating BST property.

// Expected Time Complexity: O(n*logn)
// Expected Space Complexity: O(n)

// Your Task :
// 1 <= n <= 2*104
// -109 <= node->data <= 109

class Solution
{
public:
    /*You are required to complete below function */
    void fun(Node *root, vector<int> &v)
    {
        if (!root)
            return;
        fun(root->left, v);
        v.push_back(root->data);
        fun(root->right, v);
    }

    void merge(vector<int> &v, int l, int mid, int r, int &count)
    {
        vector<int> ans(r - l + 1);
        int left = l, right = mid + 1, k = 0;
        while (left <= mid && right <= r)
        {
            if (v[left] <= v[right])
            {
                ans[k++] = v[left++];
            }
            else
            {
                ans[k++] = v[right++];
                count += (mid - left + 1); // Count inversions
            }
        }
        while (left <= mid)
        {
            ans[k++] = v[left++];
        }
        while (right <= r)
        {
            ans[k++] = v[right++];
        }
        for (int i = 0; i < k; i++)
        {
            v[l + i] = ans[i];
        }
    }

    void mergeSortAndCount(vector<int> &v, int l, int r, int &count)
    {
        if (l < r)
        {
            int mid = l + (r - l) / 2;
            mergeSortAndCount(v, l, mid, count);
            mergeSortAndCount(v, mid + 1, r, count);
            merge(v, l, mid, r, count);
        }
    }

    int pairsViolatingBST(int n, Node *root)
    {
        vector<int> v;
        fun(root, v);
        int count = 0;
        mergeSortAndCount(v, 0, n - 1, count);
        return count;
    }
};
