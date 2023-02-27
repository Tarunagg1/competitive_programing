// Reverse both parts
// EasyAccuracy: 89.92%Submissions: 2K+Points: 2
// Lamp
// Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!

// Given a linked list and a number k. You have to reverse first part of linked list with k nodes and the second part with n-k nodes.

// Example 1:

// Input: 1 -> 2 -> 3 -> 4 -> 5
// k = 2
// Output: 2 -> 1 -> 5 -> 4 -> 3
// Explanation: As k = 2 , so the first part 2
// nodes: 1 -> 2 and the second part with 3 nodes:
// 3 -> 4 -> 5. Now after reversing the first part:
// 2 -> 1 and the second part: 5 -> 4 -> 3.
// So the output is: 2 -> 1 -> 5 -> 4 -> 3
// Example 2:

// Input: 1 -> 2 -> 4 -> 3
// k = 3
// Output: 4 -> 2 -> 1 -> 3
// Explanation: As k = 3 , so the first part
// 3 nodes: 4 -> 2 -> 1 and the second part
// with 1 nodes: 3. Now after reversing the
// first part: 1 -> 2 -> 4 and the
// second part: 3. So the output is: 1 -> 2 -> 4 -> 3

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function reverse() which takes head node of the linked list and a integer k as input parameters and returns head node of the linked list after reversing both parts.

// Constraints:
// 1 <= N <= 105
// 1 <= k < N

// Expected Time Complexity: O(N)
// Expected Space Complexity: O(1)

// View Bookmarked Problems

class Solution
{
public:
    Node *reversing(Node *head)
    {
        Node *current = head;
        Node *prev = NULL, *next = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
    Node *reverse(Node *head, int k)
    {
        struct Node *s = head;
        int c = 0;
        while ((c + 1 != k))
        {
            s = s->next;
            c++;
        }
        struct Node *head2 = s->next;
        s->next = NULL;
        struct Node *a = reversing(head);
        struct Node *b = reversing(head2);
        s = a;
        while (s->next != NULL)
        {
            s = s->next;
        }
        s->next = b;
        return a;
    }
};
