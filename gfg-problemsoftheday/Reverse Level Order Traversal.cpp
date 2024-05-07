// Reverse Level Order Traversal
// EasyAccuracy: 62.26%Submissions: 116K+Points: 2
//  Done with winning Geekbits? Now win GfG Bag, GfG T-shirt & much more just by writing your experiences. Start Writing, Start Winning.
// banner
// Given a binary tree of size n, find its reverse level order traversal. ie- the traversal must begin from the last level.

// Example 1:

// Input :
//         1
//       /   \
//      3     2

// Output:
// 3 2 1
// Explanation:
// Traversing level 1 : 3 2
// Traversing level 0 : 1
// Example 2:

// Input :
//        10
//       /  \
//      20   30
//     / \ 
//    40  60

// Output:
// 40 60 20 30 10
// Explanation:
// Traversing level 2 : 40 60
// Traversing level 1 : 20 30
// Traversing level 0 : 10
// Your Task:
// You don't need to read input or print anything. Complete the function reverseLevelOrder() which takes the root of the tree as input parameter and returns a list containing the reverse level order traversal of the given tree.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 ≤ n ≤ 104

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    queue<Node *> q;
    q.push(root);
    vector<int> v;
    vector<vector<int>> ans;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            v.push_back(temp->data);
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        ans.push_back(v);
        v.clear();
    }
    reverse(ans.begin(), ans.end());
    // return ans;
    v.clear();
    for (auto x : ans)
    {
        for (int i = 0; i < x.size(); i++)
        {
            v.push_back(x[i]);
        }
    }
    return v;
}
