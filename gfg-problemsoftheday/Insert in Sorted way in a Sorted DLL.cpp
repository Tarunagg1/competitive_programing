// Insert in Sorted way in a Sorted DLL
// Difficulty: MediumAccuracy: 28.25%Submissions: 43K+Points: 4
// Given a sorted doubly linked list and an element x, you need to insert the element x into the correct position in the sorted Doubly linked list(DLL).

// Note: The DLL is sorted in ascending order

// Example:

// Input: LinkedList: 3->5->8->10->12 , x = 9

// Output: 3->5->8->9->10->12

// Explanation: Here node 9 is inserted in the Doubly Linked-List.
// Input: LinkedList: 1->4->10->11 , x = 15

// Output: 1->4->10->11->15

// Constraints:
// 1 <= number of nodes <= 103
// 1 <= node -> data , x <= 104

class Solution
{
public:
    Node *sortedInsert(Node *head, int x)
    {
        // Code here
        struct Node *pTemp = NULL;
        struct Node *pNewNode = NULL;
        // Code here
        pNewNode = new struct Node;

        if (NULL == pNewNode) // if memory allocation is failed
            return head;

        pNewNode->data = x;

        if (head->data >= x)
        {
            pNewNode->next = head;
            head->prev = pNewNode;

            head = pNewNode;
        }
        else
        {
            pTemp = head;

            while (pTemp->data < x && pTemp->next != NULL)
            {
                pTemp = pTemp->next;
            }

            if (pTemp->data >= x)
            {
                pNewNode->next = pTemp;
                pNewNode->prev = pTemp->prev;

                pTemp->prev->next = pNewNode;
                pTemp->prev = pNewNode;
            }
            else
            {
                pNewNode->next = NULL;
                pNewNode->prev = pTemp;

                pTemp->next = pNewNode;
            }
        }

        if (pTemp != NULL)
        {
            pTemp = NULL;
        }

        return head;
    }
};
