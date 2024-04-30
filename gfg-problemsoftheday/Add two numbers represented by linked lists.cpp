// Add two numbers represented by linked lists
// MediumAccuracy: 34.52%Submissions: 241K+Points: 4
//  Done with winning Geekbits? Now win GfG Bag, GfG T-shirt & much more just by writing your experiences. Start Writing, Start Winning.
// banner
// Given two decimal numbers, num1 and num2, represented by linked lists of size n and m respectively. The task is to return a linked list that represents the sum of these two numbers.

// For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

// Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

// Example 1:

// Input:
// n = 2
// num1 = 45 (4->5->null)
// m = 3
// num2 = 345 (3->4->5->null)
// Output:
// 3->9->0->null
// Explanation:
// For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).
// Example 2:

// Input:
// n = 4
// num1 = 0063 (0->0->6->3->null)
// m = 2
// num2 = 07 (0->7->null)
// Output:
// 7->0->null
// Explanation:
// For the given two linked list (0 0 6 3) and (0 7), after adding the two linked list resultant linked list will be (7 0).
// Your Task:
// The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.

// Expected Time Complexity: O(n+m)
// Expected Auxiliary Space: O(max(n,m)) for the resultant list.

// Constraints:
// 1 <= n, m <= 104

// Seen this question in a real interview before ?
// 1/4
// Yes
// No
// Company Tags

class Solution
{
public:
    // Function to add two numbers represented by linked list.
    Node *Reverse(Node *head)
    {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *curr = head;
        Node *prev = NULL;

        while (curr != NULL)
        {

            Node *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
    struct Node *addTwoLists(struct Node *num1, struct Node *num2)
    {

        num1 = Reverse(num1);
        num2 = Reverse(num2);

        int c = 0;
        Node *prev = NULL;
        Node *head = NULL;

        while (num1 != NULL || num2 != NULL || c != 0)
        {
            int d1 = 0;
            if (num1 != NULL)
            {
                d1 = num1->data;
            }

            int d2 = 0;
            if (num2 != NULL)
            {
                d2 = num2->data;
            }

            int d = d1 + d2 + c;
            int r = d % 10;
            c = d / 10;
            Node *newNode = new Node(r);
            if (prev != NULL)
            {
                prev->next = newNode;
            }
            else
            {
                head = newNode;
            }
            prev = newNode;

            if (num1 != NULL)
            {
                num1 = num1->next;
            }
            if (num2 != NULL)
            {
                num2 = num2->next;
            }
        }

        head = Reverse(head);

        while (head != NULL && head->data == 0)
        {
            head = head->next;
        }

        if (head == NULL)
        {
            return new Node(0);
        }

        return head;
    }
};
