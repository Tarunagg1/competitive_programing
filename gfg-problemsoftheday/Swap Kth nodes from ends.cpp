// Swap Kth nodes from ends 
// Medium Accuracy: 46.75% Submissions: 31575 Points: 4
// Given a singly linked list of size N, and an integer K. You need to swap the Kth node from the beginning and Kth node from the end of the linked list. Swap the nodes through the links. Do not change the content of the nodes.

 

// Example 1:

// Input:
// N = 4,  K = 1
// value[] = {1,2,3,4}
// Output: 1
// Explanation: Here K = 1, hence after
// swapping the 1st node from the beginning
// and end thenew list will be 4 2 3 1.
 

// Example 2:

// Input:
// N = 5,  K = 7
// value[] = {1,2,3,4,5}
// Output: 1
// Explanation: K > N. Swapping is invalid. 
// Return the head node as it is.
 

// Your Task: 
// You do not need to read input or print anything. The task is to complete the function swapkthnode(), which has takes head of link list, N and K as input parameters and returns the new head.
// The generated output will be 1 if you are able to complete your task. 

 

// Expected Time Complexity: O(n)
// Expected Auxillary space Complexity: O(1)

 

// Constraints:
// 1 <= N <= 103
// 1 <= K <= 103

 

// View Bookmarked Problems


void swap(Node* preva, Node* a, Node* prevb, Node* b) {
     if(a == prevb) {
         preva->next = b;
         a->next = b->next;
         b->next = a;
     } else if(b == preva) {
         prevb->next = a;
         b->next = a->next;
         a->next = b;
         
     } else {
         
         Node* aNext = a->next;
         preva->next = b;
         prevb->next = a;
         
         a->next = b->next;
         b->next = aNext;
     }
 }
 
Node *swapkthnode(Node* head, int num, int K)
{
    // Your Code here
    if(K > num) return head;
  Node* dummy = new Node(-1);
  dummy->next = head;
  
  
//   find the kth node from the begiing
    Node* p = head;
    Node* prev1 = dummy;
    int cnt = 1;
    while(cnt < K) {
        prev1 = p;
        p = p->next;
        cnt += 1;
    }
    
    Node* q = head;
    Node* prev2 = dummy;
    cnt = 1;
    while(cnt < (num - K+1)) {
        prev2 = q;
        q = q->next;
        cnt += 1;
    }
    
   swap(prev1, p, prev2, q);
    return dummy->next;
    
}























