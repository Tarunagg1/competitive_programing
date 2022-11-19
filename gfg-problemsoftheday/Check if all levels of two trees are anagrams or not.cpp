// Check if all levels of two trees are anagrams or not
// HardAccuracy: 68.33%Submissions: 2891Points: 8
// Given two binary trees, the task is to check if each of their levels are anagrams of each other or not.

// Example 1:

// Input:

// Output: 1
// Explanation:
// Tree 1:
// Level 0 : 1
// Level 1 : 3, 2
// Level 2 : 5, 4

// Tree 2:
// Level 0 : 1
// Level 1 : 2, 3
// Level 2 : 4, 5

// As we can clearly see all the levels of above two binary trees
// are anagrams of each other, hence return true.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function areAnagrams() which takes the root of two trees as input and returns an 1 if all the levels are anagrams, else returns 0 as output.

// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <= 104
// 1 <= tree.val <= 109

// View Bookmarked Problems

class Solution
{
public:
    bool areAnagrams(Node *root1, Node *root2)
    {
        queue<Node *> q1;

        q1.push(root1);

        vector<set<int>> v1;

        while (!q1.empty())

        {

            set<int> st;

            int n = q1.size();

            while (n)

            {

                auto temp = q1.front();

                st.insert(temp->data);

                q1.pop();

                if (temp->left)
                    q1.push(temp->left);

                if (temp->right)
                    q1.push(temp->right);

                n--;
            }

            v1.push_back(st);
        }

        queue<Node *> q2;

        q2.push(root2);

        vector<set<int>> v2;

        while (!q2.empty())

        {

            set<int> st;

            int n = q2.size();

            while (n)

            {

                auto temp = q2.front();

                st.insert(temp->data);

                q2.pop();

                if (temp->left)
                    q2.push(temp->left);

                if (temp->right)
                    q2.push(temp->right);

                n--;
            }

            v2.push_back(st);
        }

        if (v1.size() != v2.size())

            return false;

        for (int i = 0; i < v1.size(); i++)

        {

            if (v1[i] != v2[i])

                return false;
        }

        return true;
    }
};
