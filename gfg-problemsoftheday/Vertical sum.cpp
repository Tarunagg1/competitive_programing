// Vertical sum
// MediumAccuracy: 64.76%Submissions: 37K+Points: 4
//  Done with winning Geekbits? Now win GfG Bag, GfG T-shirt & much more just by writing your experiences. Start Writing, Start Winning.
// banner
// Given a binary tree having n nodes, find the vertical sum of the nodes that are in the same vertical line. Return all sums through different vertical lines starting from the left-most vertical line to the right-most vertical line.

// Example 1:

// Input:
//        1
//     /    \
//   2      3
//  /  \    /  \
// 4   5  6   7
// Output:
// 4 2 12 3 7
// Explanation:
// The tree has 5 vertical lines
// Line 1 has only one node 4 => vertical sum is 4.
// Line 2 has only one node 2 => vertical sum is 2.
// Line-3 has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12.
// Line-4 has only one node 3 => vertical sum is 3.
// Line-5 has only one node 7 => vertical sum is 7.
// Example 2:

// Input:
//           1
//          /
//         2
//        /
//       3
//      /
//     4
//    /
//   6
//  /
// 7
// Output:
// 7 6 5 4 3 2 1
// Explanation:
// There are seven vertical lines each having one node.
// Your Task:
// You don't need to take input. Just complete the function verticalSum() that takes root node of the tree as parameter and returns an array containing the vertical sum of tree from left to right.

// Expected Time Complexity: O(nlogn).
// Expected Auxiliary Space: O(n).

// Constraints:
// 1<=n<=104
// 1<= Node value <= 105

class Solution
{
public:
    vector<int> verticalSum(Node *root)
    {
        // add code here.
        map<int, int> mp;
        queue<pair<Node *, int>> q; // node, horizontal dis

        q.push({root, 0});

        while (!q.empty())
        {
            Node *temp = q.front().first;
            int hd = q.front().second;
            q.pop();
            mp[hd] += temp->data;

            if (temp->left)
                q.push({temp->left, hd - 1});
            if (temp->right)
                q.push({temp->right, hd + 1});
        }
        vector<int> ans;
        for (auto i : mp)
            ans.push_back(i.second);
        return ans;
    }
};
