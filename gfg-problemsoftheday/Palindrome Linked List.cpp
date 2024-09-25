// Palindrome Linked List
// Difficulty: MediumAccuracy: 41.48%Submissions: 325K+Points: 4
// Given a singly linked list of integers. The task is to check if the given linked list is palindrome or not.

// Examples:

// Input: LinkedList: 1->2->1->1->2->1
// Output: true
// Explanation: The given linked list is 1->2->1->1->2->1 , which is a palindrome and Hence, the output is true.

// Input: LinkedList: 1->2->3->4
// Output: false
// Explanation: The given linked list is 1->2->3->4, which is not a palindrome and Hence, the output is false.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)
// Note: You should not use the recursive stack space as well

// Constraints:
// 1 <= number of nodes <= 105
// 1 ≤ node->data ≤ 103

// Seen this question in a real interview before ?

class Solution
{
public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        // Your code here
        Node *i = head, *j = head, *pre = NULL, *nxt;
        while (j && j->next)
        {
            j = j->next->next;
            nxt = i->next;
            i->next = pre;
            pre = i;
            i = nxt;
        }
        if (pre == NULL)
            return true;
        if (i->data != pre->data)
        {
            i = i->next;
        }
        while (i && pre)
        {
            if (i->data != pre->data)
                return false;
            i = i->next;
            pre = pre->next;
        }
        if (i != pre)
            return false;
        return true;
    }
};
