// Middle of a Linked List
// Difficulty: EasyAccuracy: 57.93%Submissions: 327K+Points: 2
// Given the head of a linked list, the task is to find the middle. For example, the middle of 1-> 2->3->4->5 is 3. If there are two middle nodes (even count), return the second middle. For example, middle of 1->2->3->4->5->6 is 4.

// Examples:

// Input: Linked list: 1->2->3->4->5
// Output: 3

// Explanation: The given linked list is 1->2->3->4->5 and its middle is 3.
// Input: Linked list: 2->4->6->7->5->1
// Output: 7

// Explanation: The given linked list is 2->4->6->7->5->1 and its middle is 7.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= no. of nodes <= 105

// Seen this question in a real interview before ?

class Solution
{
public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node *head)
    {
        // code here
        int cnt = 0;
        Node *t = head;
        while (t)
        {
            t = t->next;
            cnt++;
        }
        int ind = cnt / 2;
        int i = 1;
        Node *curr = head;
        while (i <= ind)
        {
            curr = curr->next;
            i++;
        }
        return curr->data;
    }
};
