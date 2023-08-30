// Delete a Node in Single Linked List
// EasyAccuracy: 39.85%Submissions: 151K+Points: 2
// Win from a prize pool of INR 15K and get exciting merch! Register your team for Hack-A-Thon today!

// Given a singly linked list and an integer x.Delete xth node from the singly linked list.

// Example 1:

// Input: 1 -> 3 -> 4 
//        x = 3
// Output: 1 -> 3
// Explanation:
// After deleting the node at 3rd
// position (1-base indexing), the
// linked list is as 1 -> 3. 
// Example 2:

// Input: 1 -> 5 -> 2 -> 9 
// x = 2
// Output: 1 -> 2 -> 9
// Explanation: 
// After deleting the node at 2nd
// position (1-based indexing), the
// linked list is as 1 -> 2 -> 9.
// Your task: Your task is to complete the method deleteNode() which takes two arguments: the address of the head of the linked list and an integer x. The function returns the head of the modified linked list.

// Constraints:
// 2 <= N <= 105
// 1 <= x <= N



Node* deleteNode(Node *head,int x)
{
    //Your code here
      int n=1;
    if(x==1){
        Node* c=head;
        delete(c);
        head=head->next;
        return head;
    }
    Node* temp=head;
    while(n<x-1){
        temp=temp->next;
        n++;
    }
    Node* del=temp->next;
    temp->next=temp->next->next;
    delete del;
    return head;
}



















