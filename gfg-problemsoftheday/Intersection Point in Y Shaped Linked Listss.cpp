// Intersection Point in Y Shaped Linked Lists
// Difficulty: MediumAccuracy: 44.67%Submissions: 280K+Points: 4
// Given two singly linked lists, return the point where two linked lists intersect.

// Note: If the linked lists do not merge at any point, return -1.

// Examples:

// Input: Linked list 1: 4->4->4->4->4, Linked list 2: 4->4->4

// Output: 4
// Explanation: From the above image, it is clearly seen that the common part is 4->4 whose starting point is 4.

// Input: Linked list 1: 4->1->8->4->5, Linked List 2: 5->6->1->8->4->5

// Output: 8
// Explanation: From the above image, it is clearly seen that the common part is 8->4->5 whose starting point is 8.
// Input: Linked list 1: 1->2->3, Linked list 2: 4->5->6
// Output: -1
// Explanation: There is no common part, so there is no interaction point.
// Try to solve the problem without using any extra space.

// Constraints:
// 2 ≤ size of first linkedist + size of second linkedlist ≤ 2*105
// -1000 ≤ data of nodes ≤ 1000

class Solution
{
public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node *head1, Node *head2)
    {
        // Your Code Here

        set<Node *> st;
        while (head2)
        {
            st.insert(head2);
            head2 = head2->next;
        }

        while (head1)
        {
            if (st.find(head1) != st.end())
            {
                return head1->data;
            }
            st.insert(head1);
            head1 = head1->next;
        }

        return -1;
    }
};
