// Modify Linked List-1
// MediumAccuracy: 86.61%Submissions: 3K+Points: 4
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// Given a singly linked list containing N nodes. Modify the Linked list as follows:

// 1. Modify the value of the first half nodes such that 1st node's new value is equal to the value of the last node minus the first node's current value, 2nd node's new value is equal to the second last nodes value minus 2nd nodes current value, likewise for first half nodes.
// 2. Replace the second half of nodes with the initial values of the first half nodes(values before modifying the nodes).
// 3. If N is odd then the value of the middle node remains unchanged.

// Example 1:

// Input:
// N = 5
// linked list = 10 -> 4 -> 5 -> 3 -> 6
// Output:
// -4 -1 5 4 10
// Explanation:
// For first half nodes modified list will be:
// -4 -> -1 -> 5 -> 3 -> 6
// For second half nodes modified list will be:
// -4 -> -1 -> 5 -> 4 -> 10
// Example 2:

// Input:
// N = 6
// linked list = 2 -> 9 -> 8 -> 12 -> 7 -> 10
// Output:
// 8 -2 4 8 9 2
// Explanation:
// After modifying the linked list as required,
// we have a new linked list containing the elements as
// 8 -> -2 -> 4 -> 8 -> 9 -> 2.
// YourTask:
// The task is to complete the function modifyTheList() which should modify the list as required.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 105
// -105  <= Node->data <= 105

// View Bookmarked Problems
// Company Tags

class Solution
{
public:
    struct Node *modifyTheList(struct Node *head)
    {
        // add code here.
        Node *temp = head;
        vector<int> v;
        while (temp != 0)
        {
            v.push_back(temp->data);
            temp = temp->next;
        }
        for (int i = 0; i < v.size() / 2; i++)
        {
            v[i] = v[v.size() - 1 - i] - v[i];
            v[v.size() - 1 - i] -= v[i];
        }
        temp = head;
        int i = 0;
        while (temp != 0)
        {
            temp->data = v[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};
