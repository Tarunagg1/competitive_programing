// Merge two sorted linked lists 
// Medium Accuracy: 49.26% Submissions: 92236 Points: 4
// Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
 

// Example 1:

// Input:
// N = 4, M = 3 
// valueN[] = {5,10,15,40}
// valueM[] = {2,3,20}
// Output: 2 3 5 10 15 20 40
// Explanation: After merging the two linked
// lists, we have merged list as 2, 3, 5,
// 10, 15, 20, 40.
// Example 2:

// Input:
// N = 2, M = 2
// valueN[] = {1,1}
// valueM[] = {2,4}
// Output:1 1 2 4
// Explanation: After merging the given two
// linked list , we have 1, 1, 2, 4 as
// output.
// Your Task:
// The task is to complete the function sortedMerge() which takes references to the heads of two linked lists as the arguments and returns the head of merged linked list.

// Expected Time Complexity : O(n+m)
// Expected Auxilliary Space : O(1)

// Constraints:
// 1 <= N, M <= 104
// 1 <= Node's data <= 105

// View Bookmarked Problems
// Company Tags



Node* sortedMerge(Node* head1, Node* head2)  
{  
   // code here
   Node* ptr1 = head1;
   Node* ptr2 = head2;
   Node* dummynode = new Node(-1);
   Node* ptr3 = dummynode;
   while(ptr1 != NULL && ptr2 != NULL ){
       if(ptr1->data < ptr2->data){
           
           ptr3->next = ptr1;
           ptr1 = ptr1->next;
           
       }
       else{
      ptr3->next  = ptr2;
      ptr2= ptr2->next;

       }
       ptr3= ptr3->next;
       }
       while(ptr1 != NULL){
           
           ptr3->next = ptr1;
           ptr1 = ptr1->next;
           ptr3 = ptr3->next;
           
           }
           while(ptr2 != NULL){
           
           ptr3->next = ptr2;
           ptr2 = ptr2->next;
           ptr3 = ptr3->next;
           
           }
           
           return dummynode->next;
       
       
}  
























