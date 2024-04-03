// Kth common ancestor in BST
// MediumAccuracy: 68.42%Submissions: 9K+Points: 4
// Given a BST with n (n>=2) nodes, find the kth common ancestor of nodes x and y in the given tree. Return -1 if kth ancestor does not exist.

// Nodes x and y will always be present in the input of a BST, and x != y.

// Example 1:

// Input: 
// Input tree

// k = 2, x = 40, y = 60 
// Output:
// 30
// Explanation:
// Their 2nd common ancestor is 30.
// Example 2:

// Input: 
// Input tree

// k = 2, x = 40, y = 60
// Output:
// -1
// Explanation:
// LCA of 40 and 60 is 50, which is root itself. There does not exists 2nd common ancestor in this case.
// Your task :
// You don't have to read input or print anything. Your task is to complete the function kthCommonAncestor() that takes the root of the tree, k, x and y as input and returns the kth common ancestor of x and y.
 
// Expected Time Complexity: O(Height of the Tree)
// Expected Space Complexity: O(Height of the Tree)
 
// Your Task :
// 1 <= n, k <= 105
// 1 <= node->data, x, y <= 109
// Topic Tags









class Solution
{
    public:
    
    
    void fill(Node* root, Node* lca, int &f, vector<Node*> &ancestors){
        if(!root or !f) return;
        if(f) ancestors.push_back(root);
        fill(root->left, lca, f, ancestors);
        if(root == lca) f = 0;
        fill(root->right, lca, f, ancestors);
        if(f) ancestors.pop_back();
    }
    Node* lca(Node *root, int x, int y){
        if(!root) return nullptr;
        if(root->data == x or root->data == y) return root; 
        Node *l = lca(root->left, x, y), *r = lca(root->right, x, y); 
        if(l == nullptr and r == nullptr) return nullptr;
        if(l and r) return root; 
        if(l) return l;
        return r;
    }
    int kthCommonAncestor(Node *root, int k,int x, int y){ 
        Node *LCA = lca(root, x, y); 
        vector<Node*> ancestors;
        int f = 1;
        fill(root, LCA, f, ancestors); 
        int n = ancestors.size();
        if(n < k) return -1;
        return ancestors[n-k]->data;
    }
};




















