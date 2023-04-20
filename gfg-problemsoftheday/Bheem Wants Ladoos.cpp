// Bheem Wants Ladoos
// MediumAccuracy: 81.62%Submissions: 4K+Points: 4
// Unlock your coding potential - join our Hiring Coding Contest and land your dream job!

// Chhota Bheem wants to eat the maximum number of ladoos in Dholakpur on Independence Day. The houses in Dholakpur are arranged in the form of a binary tree and have ladoos the same as their house number. Chhota Bheem is standing at his home initially.
// Find the maximum ladoos he can eat if he can go to houses within a maximum distance k from his house. The number of ladoos at his home should also be included in the sum.

// Note: Every house has distinct ladoos in it.
// Example 1:

// Input:
//                    1
//                  /    \
//                 2      9
//                /      /  \
//               4      5     7
//             /   \         /  \
//            8     19     20    11
//           /     /  \
//          30   40   50
// home = 9, K = 1
// Output:
// 22
// Explanation:
// Initially Bheem at 9, so sum = 9
// In 2nd move he went to 5, sum=9+5=14
// In 3rd move he went to 7, sum=14+7=21
// In 4th move he went to 1, sum=21+1=22
// So within K distance bheem can get 22 ladoos.
// Example 2:

// Input:
//                    1
//                  /    \
//                 2      9
//                /      /  \
//               4      5     7
//             /   \         /  \
//            8     19     20    11
//           /     /  \
//          30   40   50
// home = 40, K = 2
// Output:
// 113
// Explanation:
// Initially Bheem at 40, so sum = 40
// In 2nd move he went to 19, sum=40+19=59
// In 3rd move he went to 4, sum=59+4=63
// In 4th move he went to 50, sum=63+50=113
// So within K distance bheem can get 113 ladoos.
// Your Task:
// You don't need to read input or print anything. Complete the function ladoos() which takes the root of the tree, home, and K  as input parameters and returns the maximum number of ladoos he can eat.

// Expected Time Complexity: O(N), where N is no. of nodes
// Expected Space Complexity: O(1)

// Constraints:
// 1 ≤ N, Home ≤ 105
// 1 ≤ K ≤ 20

// View Bookmarked Problems
// Topic Tags

class Solution
{
private:
    void parent(Node *root, unordered_map<Node *, Node *> &mp, int home, Node *&target)
    {
        if (!root)
            return;
        if (root->data == home)
            target = root;
        if (root->left)
            mp[root->left] = root;
        if (root->right)
            mp[root->right] = root;
        parent(root->left, mp, home, target);
        parent(root->right, mp, home, target);
    }

public:
    int ladoos(Node *root, int home, int k)
    {
        // Your code goes here
        unordered_map<Node *, Node *> mp;
        Node *target = NULL;
        parent(root, mp, home, target);
        queue<Node *> q;
        unordered_set<Node *> st;

        q.push(target);
        int sum = 0;
        while (!q.empty())
        {
            int size = q.size(), flag = 0;
            if (k == -1)
                break;
            k--;
            for (int i = 0; i < size; i++)
            {

                Node *t = q.front();
                sum += t->data;
                q.pop();
                if (t->left && st.find(t->left) == st.end())
                {
                    q.push(t->left);
                }
                if (t->right && st.find(t->right) == st.end())
                {
                    q.push(t->right);
                }
                if (mp[t] && st.find(mp[t]) == st.end())
                {
                    q.push(mp[t]);
                }

                st.insert(t);
            }
            if (flag)
                break;
        }

        return sum;
    }
};
