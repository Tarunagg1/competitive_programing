// Merge Sort on Doubly Linked List
// MediumAccuracy: 68.49%Submissions: 24K+Points: 4
//  Done with winning Geekbits? Now win GfG Bag, GfG T-shirt & much more just by writing your experiences. Start Writing, Start Winning.
// banner
// Given Pointer/Reference to the head of a doubly linked list of n nodes, the task is to Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing order.

// Example 1:

// Input:
// n = 8
// value[] = {7,3,5,2,6,4,1,8}
// Output:
// 1 2 3 4 5 6 7 8
// 8 7 6 5 4 3 2 1
// Explanation: After sorting the given
// linked list in both ways, resultant
// matrix will be as given in the first
// two line of output, where first line
// is the output for non-decreasing
// order and next line is for non-
// increasing order.
// Example 2:

// Input:
// n = 5
// value[] = {9,15,0,-1,0}
// Output:
// -1 0 0 9 15
// 15 9 0 0 -1
// Explanation: After sorting the given
// linked list in both ways, the
// resultant list will be -1 0 0 9 15
// in non-decreasing order and
// 15 9 0 0 -1 in non-increasing order.
// Your Task:
// The task is to complete the function sortDoubly() which takes reference to the head of the doubly linked and Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing. The printing is done automatically by the driver code.

// Expected Time Complexity: O(nlogn)
// Expected Space Complexity: O(logn)

// Constraints:
// 1 <= n <= 104
// 0 <= values[i] <= 105

class Solution
{
public:
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *merge(struct Node *a, struct Node *b)
    {
        struct Node *dummy = new Node(-1);
        struct Node *ptr = dummy;

        while (a && b)
        {
            if (a->data <= b->data)
            {
                ptr->next = a;
                a->prev = ptr;
                a = a->next;
            }
            else
            {
                ptr->next = b;
                b->prev = ptr;
                b = b->next;
            }
            ptr = ptr->next;
        }

        while (a)
        {
            ptr->next = a;
            a->prev = ptr;
            a = a->next;
            ptr = ptr->next;
        }
        while (b)
        {
            ptr->next = b;
            b->prev = ptr;
            b = b->next;
            ptr = ptr->next;
        }

        struct Node *ans = dummy->next;
        ans->prev = NULL;
        return ans;
    }
    struct Node *sortDoubly(struct Node *head)
    {
        // Your code here
        if (head == NULL || head->next == NULL)
            return head;

        struct Node *fast = head;
        struct Node *slow = head;
        struct Node *temp = NULL;

        while (fast && fast->next)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;

        struct Node *a = sortDoubly(head);
        struct Node *b = sortDoubly(slow);

        return merge(a, b);
    }
};
