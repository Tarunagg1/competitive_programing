// Rotate a Linked List
// Difficulty: MediumAccuracy: 39.95%Submissions: 225K+Points: 4
// Given the head of a singly linked list, the task is to rotate the linked list clockwise by k nodes, i.e., left-shift the linked list by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

// Examples:

// Input: linkedlist: 2->4->7->8->9 , k = 3
// Output: 8->9->2->4->7
// Explanation:
// Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
// Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
// Rotate 3: 8 -> 9 -> 2 -> 4 -> 7

// Input: linkedlist: 1->2->3->4->5->6->7->8 , k = 4
// Output: 5->6->7->8->1->2->3->4

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= number of nodes <= 103
// 1 <= node -> data <= 104
// 1 <= k <= number of nodes 

class Solution {
  public:
    // Function to rotate a linked list.
    Node* rotate(Node* head, int k) {
        // Your code here
           Node* temp=head;
        
        while(temp->next)
            temp=temp->next;
            
        temp->next=head;//make the linked list circular
        temp=head;
        
        for(int i=1;i<k;i++)//find position where LL is to be broken
            temp=temp->next;
        
        Node* newHead=temp->next;//put null at last node according to k
        temp->next=NULL;
        
       
        return newHead;
    }
};


















