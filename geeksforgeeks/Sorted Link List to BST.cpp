// Sorted Link List to BST 
// Hard Accuracy: 64.63% Submissions: 7991 Points: 8
// Given a Singly Linked List which has data members sorted in ascending order. Construct a Balanced Binary Search Tree which has same data members as the given Linked List.
// Note: There might be nodes with same value.

// Example 1:

// Input:
// Linked List: 1->2->3->4->5->6->7
// Output:
// 4 2 1 3 6 5 7
// Explanation :
// The BST formed using elements of the 
// linked list is,
//         4
//       /   \
//      2     6
//    /  \   / \
//   1   3  5   7  
// Hence, preorder traversal of this 
// tree is 4 2 1 3 6 5 7
// Example 2:

// Input:
// Linked List : 1->2->3->4
// Ouput:
// 3 2 1 4
// Exaplanation:
// The BST formed using elements of the 
// linked list is,
//       3   
//     /  \  
//    2    4 
//  / 
// 1
// Hence, the preorder traversal of this 
// tree is 3 2 1 4
// Your task :
// You don't have to read input or print anything. Your task is to complete the function sortedListToBST(), which takes head of the linked list as an input parameter and returns the root of the BST created.
 
// Expected Time Complexity: O(N), N = number of Nodes
// Expected Auxiliary Space: O(N), N = number of Nodes
 
// Constraints:
// 1 ≤ Number of Nodes ≤ 106
// 1 ≤ Value of each node ≤ 106
// View Bookmarked Problems
// Company Tags




class Solution{
  public:
    TNode* sortedListToBST(LNode *head) {
        //code here
        
         if(head == NULL) return NULL;
        // find mid;
        LNode* fast = head, *slow = head;
        LNode* prev = NULL;
       
        while(fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        
        if(prev == NULL) return new TNode(head->data);
        
        LNode *mid = prev->next;
        prev->next = NULL;
        
        TNode *newHead = new TNode(mid->data);
        newHead->left = sortedListToBST(head);
        newHead->right = sortedListToBST(mid->next);
        
        return newHead;
    }
};






























