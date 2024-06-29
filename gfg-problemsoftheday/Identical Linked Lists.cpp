// Identical Linked Lists
// Difficulty: BasicAccuracy: 47.49%Submissions: 129K+Points: 1
// Given the two singly Linked Lists respectively. The task is to check whether two linked lists are identical or not.
// Two Linked Lists are identical when they have the same data and with the same arrangement too. If both Linked Lists are identical then return true otherwise return false.

// Examples:

// Input:
// LinkedList1: 1->2->3->4->5->6
// LinkedList2: 99->59->42->20
// Output: false
// Explanation:

// As shown in figure linkedlists are not identical.
// Input:
// LinkedList1: 1->2->3->4->5
// LinkedList2: 1->2->3->4->5
// Output: true
// Explanation:

// As shown in figure both are identical.
// Expected Time Complexity: O(n)
// Expected Auxilliary Space: O(1)

// Constraints:
// 1 <= length of lists <= 103

bool areIdentical(struct Node *head1, struct Node *head2)
{
    // Code here
    struct Node *curr1 = head1;
    struct Node *curr2 = head2;
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data != curr2->data)
        {
            return false;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    if (curr1 != NULL || curr2 != NULL)
    {
        return false;
    }
    return true;
}
