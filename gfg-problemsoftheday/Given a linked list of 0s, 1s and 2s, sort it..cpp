// Given a linked list of 0s, 1s and 2s, sort it.
// EasyAccuracy: 60.75%Submissions: 122K+Points: 2
// POTD July Placement Special : All POTD in the month of July are based on popular interview questions. Solve every day to ace the upcoming Placement Season !
// Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

// Example 1:

// Input:
// N = 8
// value[] = {1,2,2,1,2,0,2,2}
// Output: 0 1 1 2 2 2 2 2
// Explanation: All the 0s are segregated
// to the left end of the linked list,
// 2s to the right end of the list, and
// 1s in between.
// Example 2:

// Input:
// N = 4
// value[] = {2,2,0,1}
// Output: 0 1 2 2
// Explanation: After arranging all the
// 0s,1s and 2s in the given format,
// the output will be 0 1 2 2.
// Your Task:
// The task is to complete the function segregate() which segregates the nodes in the linked list as asked in the problem statement and returns the head of the modified linked list. The printing is done automatically by the driver code.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 106

class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {

        // Add code here
        int z = 0;
        int o = 0;
        int t = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            int x = temp->data;
            if (x == 0)
            {
                z++;
            }
            else if (x == 1)
            {
                o++;
            }
            else
            {
                t++;
            }
            temp = temp->next;
        }
        temp = head;
        while (z)
        {
            temp->data = 0;
            temp = temp->next;
            z--;
        }
        while (o)
        {
            temp->data = 1;
            temp = temp->next;
            o--;
        }
        while (t)
        {
            temp->data = 2;
            temp = temp->next;
            t--;
        }
        return head;
    }
};
