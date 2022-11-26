// Construct Binary Tree from String with bracket representation
// MediumAccuracy: 33.98%Submissions: 2368Points: 4
// Lamp
// Save 25% with Black Friday Offers. Explore Now!

// Construct a binary tree from a string consisting of parenthesis and integers. The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the roots value and a pair of parenthesis contains a child binary tree with the same structure. Always start to construct the left child node of the parent first if it exists.

// Example 1:

// Input: "1(2)(3)"
// Output: 2 1 3
// Explanation:
//            1
//           / \
//          2   3
// Explanation: first pair of parenthesis contains
// left subtree and second one contains the right
// subtree. Inorder of above tree is "2 1 3".
// Example 2:

// Input: "4(2(3)(1))(6(5))"
// Output: 3 2 1 4 5 6
// Explanation:
//            4
//          /   \
//         2     6
//        / \   /
//       3   1 5
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function treeFromString() which takes a string str as input parameter and returns the root node of the tree.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= |str| <= 105

// View Bookmarked Problems
// Topic Tags

class Solution
{
public:
    // function to construct tree from string
    Node *treeFromString(string str)
    {
        // code here
        stack<int> stk;
        map<int, Node *> mp;

        for (int i = 0; i < str.length(); i++)
        {

            if (str[i] == ')')
            {

                int child = stk.top();
                Node *chd;
                if (mp.find(child) == mp.end())
                    chd = new Node(child);
                else
                    chd = mp[child];

                stk.pop();
                stk.pop();

                int parent = stk.top();

                if (mp.find(parent) == mp.end())
                {
                    Node *par = new Node(parent);
                    par->left = chd;
                    mp[parent] = par;
                }
                else
                {
                    Node *par = mp[parent];
                    par->right = chd;
                }
            }
            else
            {
                int num = 0;
                if (str[i] == '(')
                {
                    stk.push(-1);
                }
                else
                {
                    while (isdigit(str[i]))
                    {
                        num = num * 10 + (str[i] - '0');
                        i++;
                    }
                    i--;
                    stk.push(num);
                }
            }
        }
        if (mp.size() == 0)
            return new Node(stk.top());
        return mp[stk.top()];
    }
};
