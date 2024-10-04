// Deletion and Reverse in Circular Linked List
// Difficulty: MediumAccuracy: 60.7%Submissions: 33K+Points: 4
// Given a Circular Linked List. The task is to delete the given node, key in the circular linked list, and reverse the circular linked list.

// Note: You don't have to print anything, just return head of the modified list in each function.

// Examples:

// Input: Linked List: 2->5->7->8->10, key = 8

// Output: 10->7->5->2

// Explanation:
// After deleting 8 from the given circular linked list, it has elements as 2, 5, 7, 10. Now, reversing this list will result in 10, 7, 5, 2.
// Input: Linked List: 1->7->8->10, key = 8

// Output: 10->7->1

// Explanation:
// After deleting 8 from the given circular linked list, it has elements as 1, 7,10. Now, reversing this list will result in 10, 7, 1.
// Expected Time Complexity: O(n)
// Expected Auxillary Space: O(1)

// Constraints:
// 2 <= number of nodes, key  <= 105
// 1 <= node -> data <= 105

class Solution
{
public:
    // Function to reverse a circular linked list
    Node *reverse(Node *head)
    {
        Node *Prev = NULL;
        Node *Curr = head;
        Node *Next = Curr->next;

        while (Next != head)
        {
            Curr->next = Prev;
            Prev = Curr;
            Curr = Next;
            Next = Next->next;
        }
        // at this point next = head & Curr = last node
        Next->next = Curr;
        Curr->next = Prev;

        return Curr;
    }

    // Function to delete a node from the circular linked list
    Node *deleteNode(Node *head, int key)
    {
        Node *temp = head->next;
        Node *ptr = head;

        if (head->data == key)
        {
            while (ptr->next != head)
                ptr = ptr->next;

            ptr->next = temp;
            delete head;

            return temp;
        }

        else
        {
            while (temp->data != key && temp != head)
            {
                ptr = temp;
                temp = temp->next;
            }
            if (temp->data == key)
            {
                ptr->next = temp->next;
                delete temp;
            }
        }

        return head;
    }
};
