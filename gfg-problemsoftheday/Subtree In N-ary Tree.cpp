// Subtree In N-ary Tree
// MediumAccuracy: 85.54%Submissions: 5K+Points: 4
// Explore Job Fair for students & freshers for daily new opportunities. Find A Job Today!

// Given the root of a n-ary tree find the number of duplicate subtrees in the n-ary tree. Two trees are duplicates if they have the same structure with the same node values.

// Example 1:

// Input:
// 1 N 2 2 3 N 4 N 4 4 3 N N N N N

// Output:
// 2
// Explanation:
// [4], [3] are duplicate subtree.
// Example 2:

// Input:
// 1 N 2 3 N 4 5 6 N N N N

// Output:
// 0
// Explanation:
// No duplicate subtree found.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function duplicateSubtreeNaryTree() which takes the root of the n-ary tree as input and returns an integer value as a number of duplicate subtrees.

// Expected Time Complexity: O(n), n is the total no of nodes
// Expected Space Complexity: O(n2)

// Constraints:
//    1 <= n < 103
//    1 <= node.key< 103

// View Bookmarked Problems

class Solution
{
public:
    int duplicateSubtreeNaryTree(Node *root)
    {
        unordered_map<string, int> mp;
        dfs(root, mp);
        int ans = 0;
        for (auto &e : mp)
        {
            if (e.second > 1)
                ans++;
        }
        return ans;
    }

    string dfs(Node *root, unordered_map<string, int> &mp)
    {
        if (!root)
            return "";
        string key = to_string(root->data) + "[";
        for (auto &child : root->children)
            key += dfs(child, mp);
        key += "]";
        mp[key]++;
        return key;
    }
};
