// Subtraction in Linked List
// HardAccuracy: 12.94%Submissions: 41K+Points: 8
// Three 90 Challenge Extended On Popular Demand! Don't Miss Out Now 

// banner
// You are given two linked lists that represent two large positive numbers. From the two numbers represented by the linked lists, subtract the smaller number from the larger one. Look at the examples to get a better understanding of the task.

// Example 1:

// Input:
// L1 = 1->0->0
// L2 = 1->2
// Output: 88
// Explanation:  
// First linked list represents 100 and the
// second one represents 12. 12 subtracted from 100
// gives us 88 as the result. It is represented
// as 8->8 in the linked list.
// Example 2:

// Input:
// L1 = 0->0->6->3
// L2 = 7->1->0
// Output: 647
// Explanation: 
// First linked list represents 0063 => 63 and 
// the second one represents 710. 63 subtracted 
// from 710 gives us 647 as the result. It is
// represented as 6->4->7 in the linked list.
// Your Task:
// You do not have to take any input or print anything. The task is to complete the function subLinkedList() that takes heads of two linked lists as input parameters and which should subtract the smaller number from the larger one represented by the given linked lists and return the head of the linked list representing the result.

// n and m are the length of the two linked lists respectively.
// Expected Time Complexity:  O(n+m)
// Expected Auxiliary Space: O(n+m)

// Constraints:
// 1 <= n <= 10000
// 0 <= values represented by the linked lists < 10n
// 0 <= values represented by the linked lists < 10m

// Company Tags



class Solution {
public:
    
    

Node* reverse(Node* head){
        Node *prev = NULL , *curr = head , *nxt = head;
        while(nxt){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        Node* ans = head2;
        while(head1){
            if(head1->data == 0){
                head1 = head1->next;
            }
            else{
                break;
            }
        }
        while(head2){
            if(head2->data == 0){
                head2 = head2->next;
            }
            else{
                break;
            }
        }
        if(head1 == NULL && head2 == NULL){
            ans->next = NULL;
            return ans;
        }
        else if(head1 == NULL){
            return head2;
        }
        else if(head2 == NULL){
            return head1;
        }
        Node* temp1 = head1;
        Node* temp2 = head2;
        int count1 = 0;
        int count2 = 0;
        while(temp1){
            temp1 = temp1->next;
            count1++;
        }
        while(temp2){
            temp2 = temp2->next;
            count2++;
        }
        if(count1 == count2){
            if(head1->data == head2->data){
                while(head1 && head1->data == head2->data){
                    head1 = head1->next;
                    head2 = head2->next;
                }
                if(head1 == NULL && head2 == NULL){
                    ans->data = 0;
                    ans->next = NULL;
                    return ans;
                }
            }
            if(head1->data > head2->data){
                temp1 = head1;
            }
            else{
                temp1 = head2;
            }
        }
        else if(count1>count2){
            temp1 = head1;
        }
        else{
            temp1 = head2;
        }
        if(temp1 == head1){
            temp1 = reverse(head1);
            temp2 = reverse(head2);
        }
        else{
            temp1 = reverse(head2);
            temp2 = reverse(head1);
        }
        head1 = temp1;
        head2 = temp2;
        bool flag = false;
        while(temp2){
            if(flag == true){
                if(temp1->data == 0){
                    temp1->data = 9;
                    flag = true;
                }
                else{
                    temp1->data = temp1->data - 1;
                    flag = false;
                }
            }
            if(temp1->data >= temp2->data){
                temp1->data = temp1->data - temp2->data;
            }
            else{
                int n  = 10 - temp2->data;
                temp1->data = temp1->data + n;
                flag = true;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(flag == true){
            while(temp1->data == 0){
                temp1->data = 9;
                temp1 = temp1->next;
            }
            temp1->data = temp1->data -1;
        }
        temp1 = reverse(head1);
        while(temp1){
            if(temp1->data == 0){
                temp1 = temp1->next;
            }
            else{
                break;
            }
        }
        return temp1;
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        return NULL;
    }
};
















