// Sum of nodes within k distance from target 
// Medium Accuracy: 70.08% Submissions: 744 Points: 4
// Lamp Geeks Summer Carnival is LIVE NOW   
// Note: This POTD is a part of Geek Summer Carnival. Solve all POTD consecutively from 5th to 10th April and get a chance to win exclusive discount vouchers on our GfG courses.

// Geek is at the geek summer carnival. To unlock discounts on exclusive courses he is given a card with a binary tree, a target node and a positive integer k on it. 
// He needs to find the sum of all nodes within a max distance k from target node such that the target node is included in sum.

// Example 1:

// Input:
// target = 9 
// k = 1
// Binary Tree = 
//             1
//            /  \
//           2    9
//         /     /  \
//        4     5    7
//       /  \       /  \
//      8    19    20   11
//     /   /   \
//   30   40   50

// Output: 22

// Explanation: 
// Nodes within distance 1 from 9 
// 9 + 5 + 7 + 1 = 22

// Example 2:

// Input:
// target = 40 
// k = 2
// Binary Tree = 
//             1
//            /  \
//           2    9
//         /     /  \
//        4     5    7
//       /  \       /  \
//      8    19    20   11
//     /   /   \
//   30   40   50

// Output: 113

// Explanation:
// Nodes within distance 2 from 40,
// 40 + 19 + 50 + 4 = 113
// Your Task:
// You don't need to read input or print anything. Complete the function sum_at_distK() that takes the root of the given binary tree, target and k as input parameters and return the required sum. 

// Expected time complexity: O(n)
// Expected space complexity: O(n)

// Constraints:
// 1 <= number of nodes <= 1000
// 1 <= data in nodes,target <= 10000
// 1 <= k <= 20

// View Bookmarked Problems
// Topic Tags



class Solution{
public:
    Node* locate(Node* root, int target){
       if(root==NULL) return NULL;
       if(root -> data == target)
           return root;
       Node* lNode = locate(root -> left, target);
       Node* rNode = locate(root -> right, target);
       
       if(lNode) return lNode;
       if(rNode) return rNode;
       
       return NULL;
   }
   void markParent(Node* root, unordered_map<Node*, Node*>&umap){
       if(root==NULL) return;
       queue<Node*>q;
       umap.insert({root, NULL});
       q.push(root);
       while(!q.empty()){
           Node* tmp = q.front();
           q.pop();
           
           if(tmp){
               if(tmp -> left){
                   umap.insert({tmp -> left, tmp});
                   q.push(tmp -> left);
               }
               if(tmp -> right){
                   umap.insert({tmp -> right, tmp});
                   q.push(tmp -> right);
               }
           }
       }
   }
   int sum_at_distK(Node* root, int target, int k)
   {
       if(root==NULL)
           return 0;
       
       Node* tar = locate(root, target);
       unordered_map<Node*, Node*>umap;
       markParent(root, umap);
       
       int dist=0, sum=0;
       queue<Node*>q;
       q.push(tar);
       unordered_set<Node*>check;
       check.insert(tar);
       
       while(!q.empty()){
           if(dist++>k)
               break;
           int size = q.size();
           for(int i=0;i<size;i++){
               Node* tmp = q.front();
               q.pop();
               sum+=tmp -> data;
               
               if(tmp -> left && check.count(tmp -> left)==0){
                   q.push(tmp -> left);
                   check.insert(tmp -> left);
               }                
               
               if(tmp -> right && check.count(tmp -> right)==0){
                   q.push(tmp -> right);
                   check.insert(tmp -> right);
               }
               
               if(umap[tmp] && check.count(umap[tmp])==0){
                   q.push(umap[tmp]);
                   check.insert(umap[tmp]);
               }
               
           }
       }
       
       return sum;
   }
};























