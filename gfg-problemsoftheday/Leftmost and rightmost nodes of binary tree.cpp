// Leftmost and rightmost nodes of binary tree
// MediumAccuracy: 52.58%Submissions: 26K+Points: 4
// Given a Binary Tree of size N, Print the corner nodes ie- the node at the leftmost and rightmost of each level.

// Example 1:

// Input :
//          1
//        /  \
//      2      3
//     / \    / \
//    4   5  6   7
// Output: 1 2 3 4 7
// Explanation:
// Corners at level 0: 1
// Corners at level 1: 2 3
// Corners at level 2: 4 7
// Example 2:

// Input:

//         10
//       /    \
//      20     30
//     / \  
//    40  60
// Output: 10 20 30 40 60
// Your Task:
// You dont need to read input. Complete the function printCorner() which takes root node as input parameter and prints the corner nodes separated by spaces. The left corner should be printed before the right for each level starting from level 0.
// Note: Don't print a new line after printing all the corner nodes.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(number of nodes in a level)

// Constraints:
// 1 ≤ N ≤ 10^5

void printCorner(Node *root)
{

    // Your code goes here

    vector<vector<int>> level;
    queue<Node *> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        for (int i = 0; i < size; i++)
        {
            auto fron = q.front();
            q.pop();
            temp.push_back(fron->data);
            if (fron->left != NULL)
                q.push(fron->left);
            if (fron->right != NULL)
                q.push(fron->right);
        }
        if (temp.size() == 1)
            ans.push_back(temp[0]);
        else
        {
            ans.push_back(temp[0]);
            ans.push_back(temp[temp.size() - 1]);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
