// Insertion Sort for Singly Linked List
// MediumAccuracy: 69.66%Submissions: 16K+Points: 4
// You've won Geekbits by solving daily. Now win 90% of your money-back by learning daily!

// banner
// Given a singly linked list, sort the list (in ascending order) using insertion sort algorithm.

// Example 1:

// Input:
// N = 10
// Linked List = 30->23->28->30->11->14->
//               19->16->21->25
// Output :
// 11 14 16 19 21 23 25 28 30 30
// Explanation :
// The resultant linked list is sorted.
// Example 2:

// Input :
// N = 7
// Linked List=19->20->16->24->12->29->30
// Output :
// 12 16 19 20 24 29 30
// Explanation :
// The resultant linked list is sorted.
// Your task:
// You don't need to read input or print anything. Your task is to complete the function insertionSort() which takes the head of the linked list, sorts the list using insertion sort algorithm and returns the head of the sorted linked list.

// Expected Time Complexity : O(n2)
// Expected Auxiliary Space : O(1)

// Constraints:
// 0 <= n <= 5*103

class Solution
{
public:
    Node *insert(Node *ans, Node *head)
    {
        Node *root = ans;
        Node *prev = ans;
        if (ans->data >= head->data)
        {
            head->next = ans;
            return head;
        }
        else
        {
            while (ans->next != nullptr)
            {
                if (ans->data < head->data)
                {
                    prev = ans;
                    ans = ans->next;
                }
                else
                    break;
            }
        }
        if (ans->next == nullptr)
        {
            if (ans->data <= head->data)
            {
                ans->next = head;
                head->next = nullptr;
            }
            else
            {
                prev->next = head;
                head->next = ans;
            }
        }
        else
        {
            prev->next = head;
            head->next = ans;
        }
        return root;
    }

public:
    Node *insertionSort(struct Node *head_ref)
    {
        if (head_ref == nullptr)
            return head_ref;
        Node *head = head_ref->next;
        Node *ans = head_ref;
        ans->next = nullptr;
        while (head != nullptr)
        {
            Node *next = head->next;
            head->next = nullptr;
            ans = insert(ans, head);
            head = next;
        }
        return ans;
    }
};
