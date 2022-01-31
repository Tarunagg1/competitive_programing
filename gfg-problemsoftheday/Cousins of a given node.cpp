// Cousins of a given node 
// Medium Accuracy: 63.23% Submissions: 4490 Points: 4
// Given a binary tree and a node, print all cousins of given node in order of their appearance. Note that siblings should not be printed.

// Example 1:

// Input : 
//              1
//            /   \
//           2     3
//         /   \  /  \
//        4    5  6   7

// Given node : 5
// Output : 6 7
// Explanation :
// Nodes 6 and 7 are on the same level 
// as 5 and have different parents.

// Example 2 :

// Input :
//          9
//         /
//        5
// Given node : 5
// Output : -1
// Explanation :
// There no other nodes than 5 in the same level.
// Your task :
// You don't have to read input or print anything. Your task is to complete the function printCousins() which takes the root node of the tree and the node whose cousins need to be found, as input and returns a list containing the cousins of the given node in order of their appearance in the tree. If there is no cousin of the given node, return -1 as the first element of the list.
 
// Expected Time Complexity : O(n)
// Expected Auxiliary Space : O(n)
 
// Constraints :
// 1 <= n <=10^5


class Solution
{
    public:
    vector<int> printCousins(Node* root, Node* node_to_find)
    {
        //code here
        queue<Node*> q;
        q.push(root);
        bool marker = true;
        vector<int> ans;
        
        while(!q.empty() && marker){
            int n = q.size();
            
            for(int i=0; i<n; i++){
                Node* node = q.front();
                q.pop();
                
                if(node->left == node_to_find || node->right == node_to_find ){
                    marker = false;
                }else{

                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                }
             
            }
        }
        
        if(q.empty()){
            ans.push_back(-1);
        }else{
            while(!q.empty()){
                ans.push_back(q.front()->data);
                q.pop();
            }
        }
        return ans;
    }
    
};




















