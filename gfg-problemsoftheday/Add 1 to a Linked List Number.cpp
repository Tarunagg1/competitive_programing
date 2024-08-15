// Add 1 to a Linked List Number
// Difficulty: MediumAccuracy: 31.91%Submissions: 221K+Points: 4
// You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list.

// Note: The head represents the first element of the given array.

// Examples :

// Input: LinkedList: 4->5->6
// Output: 457

// Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457.
// Input: LinkedList: 1->2->3
// Output: 124

// Explanation:  1->2->3 represents 123 and when 1 is added it becomes 124.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= len(list) <= 105
// 0 <= list[i] <= 105

Node *revLL(Node *head)
{
    Node *temp = head;
    Node *prev = NULL;
    Node *front = NULL;

    while (temp)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

class Solution
{
public:
    Node *addOne(Node *head)
    {
        // Your Code here
        // return head of list after adding one

        head = revLL(head);

        int carry = 1, val = 0;

        Node *temp = head;
        Node *newHead;

        while (temp)
        {
            int x = temp->data;
            temp->data = (temp->data + carry) % 10;
            carry = (x + carry) / 10;
            temp = temp->next;
        }

        head = revLL(head);

        if (carry > 0)
        {
            newHead = new Node(carry);
            newHead->next = head;
        }
        else
            newHead = head;

        return newHead;
    }
};
