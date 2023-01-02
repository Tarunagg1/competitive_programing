// Maximum Value
// MediumAccuracy: 87.37%Submissions: 103+Points: 4
// Lamp
// Stand out from the crowd. Prepare with Complete Interview Preparation

// Given a binary tree, find the largest value in each level.

// Example 1:

// Input:
//         1
//        / \
//       2   3
// Output:
// 1 3
// Explanation:
// At 0 level, values of nodes are {1}
//                  Maximum value is 1
// At 1 level, values of nodes are {2,3}
//                 Maximum value is 3
// Example 2:

// Input:
//         4
//        / \
//       9   2
//      / \   \
//     3   5   7
// Output:
// 4 9 7
// Explanation:
// At 0 level, values of nodes are {4}
//                  Maximum value is 4
// At 1 level, values of nodes are {9,2}
//                  Maximum value is 9
// At 2 level, values of nodes are {3,5,7}
//                  Maximum value is 7

// Your Task:

// You don't need to read input or print anything.Your task is to complete the function maximumValue() that takes root node as input parameter and returns a list of integers containing the maximum value at each level. The size of the resultant list should be equal to the height of the binary tree and result[i] should store the maximum value at level i.

// Expected Time Complexity: O(N), where N is the number of nodes.
// Expected Auxiliary Space: O(H), where H is the height of binary tree.

// Constraints:
// 1 ≤ Number of nodes ≤ 10^4
// 1 ≤ Data of a node ≤ 10^5

// View Bookmarked Problems

class Solution
{
public:
    vector<int> maximumValue(Node *node)
    {
        // code here
        vector<int> ans;
        queue<Node *> q;
        q.push(node);
        while (!q.empty())
        {
            int size = q.size(), maxi = 0;
            while (size--)
            {
                Node *temp = q.front();
                q.pop();
                maxi = max(maxi, temp->data);
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};
