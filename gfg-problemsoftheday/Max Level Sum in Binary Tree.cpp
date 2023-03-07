// Max Level Sum in Binary Tree
// EasyAccuracy: 81.56%Submissions: 4K+Points: 2
// Lamp
// Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!

// Given a Binary Tree having positive and negative nodes. Find the maximum sum of a level in the given Binary Tree.

// Example 1:

// Input :
//              4
//           /    \
//          2     -5
//         / \    / \
//       -1   3  -2  6

// Output: 6

// Explanation :
// Sum of all nodes of 0'th level is 4
// Sum of all nodes of 1'th level is -3
// Sum of all nodes of 2'th level is 6
// Hence maximum sum is 6

// Example 2:

// Input :
//             1
//           /   \
//          2     3
//         / \     \
//        4   5     8
//                 / \
//                6   7

// Output :  17

// Explanation: Maximum sum is at level 2.

// Your Task:
// You dont need to read input or print anything. Complete the function maxLevelSum() which takes root node as input parameter and returns the maximum sum of any horizontal level in the given Binary Tree.

// Expected Time Complexity: O(N), where N is no of node.
// Expected Auxiliary Space: O(W), Where W is the max width of the tree.

// Constraints:
// 1 ≤ N ≤ 104

// View Bookmarked Problems

class Solution
{
public:
    /*You are required to complete below method */

    vector<long long int> sum;

    void func(Node *root, int level)
    {
        if (root == NULL)
            return;
        // add level index in vector
        if (sum.size() == level)
            sum.push_back(root->data);
        else
            sum[level] += root->data;

        // traverse further
        func(root->left, level + 1);
        func(root->right, level + 1);
    }

    int maxLevelSum(Node *root)
    {
        // Your code here
        func(root, 0);
        long long int ret = sum[0];
        for (int i = 1; i < sum.size(); i++)
        {
            if (sum[i] > ret)
                ret = sum[i];
        }
        return ret;
    }
};
