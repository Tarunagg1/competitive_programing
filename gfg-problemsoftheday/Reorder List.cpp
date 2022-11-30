// Reorder List
// HardAccuracy: 47.9%Submissions: 37758Points: 8
// Given a singly linked list: A0→A1→...→An-2→An-1, reorder it to: A0→An-1→A1→An-2→A2→An-3→...
// For example: Given 1->2->3->4->5 its reorder is 1->5->2->4->3.

// Note: It is recommended do this in-place without altering the node's values.

// Example 1:

// Input:
// LinkedList: 1->2->3
// Output: 1 3 2
// Explanation:
// Here n=3, so the correct
// order is A0→A2→A1
// Example 2:

// Input:
// Explanation: 1->7->3->4
// Output: 1 4 7 3
// Explanation:
// Here n=4, so the correct
// order is A0→A3→A1→A2
// Your Task:
// The task is to complete the function reorderList() which should reorder the list as required. The reorder list is automatically printed by the driver's code.

// Note: Try to solve without using any auxilliary space.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 5*105
// 1 <= A[ i ] <= 105

// View Bookmarked Problems

class Solution
{

public:
    Node *findmiddle(Node *head)
    {

        Node *slow = head, *fast = head;

        while (fast != NULL && fast->next != NULL)
        {

            slow = slow->next;

            fast = fast->next->next;
        }

        return slow;
    }

    Node *reverse(Node *mid)
    {

        Node *prev = NULL;

        Node *curr = mid;

        while (curr != NULL)
        {

            Node *next = curr->next;

            curr->next = prev;

            prev = curr;

            curr = next;
        }

        return prev;
    }

    void reorderList(Node *head)
    {

        if (head == NULL || head->next == NULL)
            return;

        Node *mid = findmiddle(head);

        Node *last = reverse(mid);

        Node *iter = head;

        while (iter->next != mid && last->next != NULL)
        {

            Node *temp = iter->next;

            iter->next = last;

            Node *another = last->next;

            last->next = temp;

            iter = temp;

            last = another;
        }

        iter->next = last;
    }
};
