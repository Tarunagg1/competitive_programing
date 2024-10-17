// Split Linked List Alternatingly
// Difficulty: EasyAccuracy: 42.46%Submissions: 22K+Points: 2
// Given a singly linked list's head. Your task is to complete the function alternatingSplitList() that splits the given linked list into two smaller lists. The sublists should be made from alternating elements from the original list.
// Note:

// The sublist should be in the order with respect to the original list.
// Your have to return an array containing the both sub-linked lists.
// Examples:

// Input: LinkedList = 0->1->0->1->0->1
// Output: 0->0->0 , 1->1->1
// Explanation: After forming two sublists of the given list as required, we have two lists as: 0->0->0 and 1->1->1.

// Input: LinkedList = 2->5->8->9->6
// Output: 2->8->6 , 5->9
// Explanation: After forming two sublists of the given list as required, we have two lists as: 2->8->6 and 5->9.
// Input: LinkedList: 7
// Output: 7 , <empty linked list>
// Constraints:
// 1 <= number of nodes <= 100
// 1 <= node -> data <= 104

class Solution
{
public:
    // Function to split a linked list into two lists alternately
    vector<Node *> alternatingSplitList(struct Node *head)
    {
        // Your code here
        if (!head)
            return {nullptr, nullptr};
        if (!head->next)
            return {head, nullptr};

        Node *first = head;        // Start of the first list (odd indexed)
        Node *second = head->next; // Start of the second list (even indexed)

        Node *odd = first;   // Pointer to the current node in the first list
        Node *even = second; // Pointer to the current node in the second list

        while (odd && even)
        {
            odd->next = even->next; // Link the odd indexed node to the next odd indexed node
            odd = odd->next;        // Move to the next odd indexed node

            if (odd)
            {                           // Check if the next odd node is not null
                even->next = odd->next; // Link the even indexed node to the next even indexed node
                even = even->next;      // Move to the next even indexed node
            }
            else
            {
                even->next = nullptr; // If there are no more odd nodes, terminate the even list
            }
        }

        // Ensure the last nodes point to nullptr
        if (odd)
            odd->next = nullptr;
        if (even)
            even->next = nullptr;

        return {first, second};
    }
};
