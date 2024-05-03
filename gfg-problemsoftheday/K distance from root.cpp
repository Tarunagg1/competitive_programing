// K distance from root
// EasyAccuracy: 52.18%Submissions: 84K+Points: 2
//  Done with winning Geekbits? Now win GfG Bag, GfG T-shirt & much more just by writing your experiences. Start Writing, Start Winning.
// banner
// Given a binary tree having n nodes and an integer k. Print all nodes that are at distance k from the root (root is considered at distance 0 from itself). Nodes should be printed from left to right.

// Example 1:

// Input:
// k = 0
//       1
//     /   \
//    3     2
// Output:
// 1
// Explanation:
// 1 is the only node which is 0 distance from the root 1.
// Example 2:

// Input:
// k = 3
//         1
//        /
//       2
//        \
//         1
//       /  \
//      5    3
// Output:
// 5 3
// Explanation:
// 5 and 3 are the nodes which are at distance 3 from the root 3.
// Here, returning 3 5 will be incorrect.
// Your Task:
// You don't have to take input. Complete the function Kdistance() that accepts root node and k as parameters and returns the value of the nodes that are at a distance k from the root.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 1 <= n <= 104
// 0 <= k <= 30


class Solution
{
    public:
    // function should print the nodes at k distance from root
     vector<int> Kdistance(struct Node *root, int k)
    {
        // If k is 0, return the data of the current node
        if(k == 0) return {root->data};
        
        // Initialize an empty queue and push the root node into it
        queue<Node*> q;
        q.push(root);
        
        // Traverse the tree using BFS
        while(!q.empty())
        {
            // Get the size of the current level
            int sz = q.size();
            
            // If k is 0, return the data of the nodes at this level
            if(k == 0)
            {
                vector<int> ans;
                for(int i = 0; i<sz; ++i)
                {
                    Node* temp = q.front(); q.pop();
                    ans.push_back(temp->data);
                }
                return ans;
            }
            
            // Pop the nodes from the front of the queue and push their children into the queue
            for(int i =0 ; i<sz; ++i)
            {
                Node* top = q.front(); q.pop();
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            
            // Decrement k to move to the next level
            k--;
        }
        
        // If we reach here, it means there are no nodes at the desired distance
        return {};
    }
};
