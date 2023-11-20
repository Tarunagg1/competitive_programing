// K Sum Paths
// MediumAccuracy: 44.73%Submissions: 62K+Points: 4
// Exclusively for Freshers! Participate for Free on 21st November & Fast-Track Your Resume to Top Tech Companies

// banner
// Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
// A path may start from any node and end at any node in the downward direction.
// Since the answer may be very large, compute it modulo 109+7.

// Example 1:

// Input:
// Tree =
//           1
//         /   \                          
//        2     3
// K = 3
// Output:
// 2
// Explanation:
// Path 1 : 1 + 2 = 3
// Path 2 : only leaf node 3
// Example 2:

// Input:
// Tree =
//            1
//         /     \
//       3        -1
//     /   \     /   \
//    2     1   4     5
//         /   / \     \                    
//        1   1   2     6
// K = 5
// Output:
// 8
// Explanation:
// The following paths sum to K.
// 3 2
// 3 1 1
// 1 3 1
// 4 1
// 1 -1 4 1
// -1 4 2
// 5
// 1 -1 5
// Your Task:
// You don't need to read input or print anything. Complete the function sumK() which takes root node and integer K as input parameters and returns the number of paths that have sum K.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(Height of Tree)

// Constraints:
// 1 ≤ N ≤ 2*104
// -105 ≤ Node Value ≤ 105
// -109 ≤ K ≤ 109

class Solution
{
public:
    int sumK(Node *root, int k)
    {
        // code here
        unordered_map<int, int> f;
        f[0] = 1;

        long long ans = 0;
        const long long mod = 1e9 + 7;

        function<void(Node *, int)> dfs = [&](Node *node, int sum)
        {
            if (node == nullptr)
                return 0;

            sum += node->data;

            if (f.find(sum - k) != f.end())
                ans = (ans + f[sum - k]) % mod;

            ++f[sum];

            dfs(node->left, sum);
            dfs(node->right, sum);

            --f[sum];

            if (f[sum] == 0)
                f.erase(sum);
        };

        dfs(root, 0);

        return ans;
    }
};
