// Intersection Point in Y Shaped Linked Lists
// MediumAccuracy: 67.14%Submissions: 3K+Points: 4
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

// Example 1:

// Input:
// LinkList1 = 3->6->9->common
// LinkList2 = 10->common
// common = 15->30->NULL
// Output: 15
// Explanation:
// Y ShapedLinked List
// Example 2:

// Input:
// Linked List 1 = 4->1->common
// Linked List 2 = 5->6->1->common
// common = 8->4->5->NULL
// Output: 8
// Explanation:

// 4              5
// |              |
// 1              6
//  \             /
//   8   -----  1
//    |
//    4
//    |
//   5
//   |
//   NULL
// Your Task:
// You don't need to read input or print anything. The task is to complete the function intersetPoint() which takes the pointer to the head of linklist1(head1) and linklist2(head2) as input parameters and returns data value of a node where two linked lists intersect. If linked list do not merge at any point, then it should return -1.
// Challenge : Try to solve the problem without using any extra space.

// Expected Time Complexity: O(N+M)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N + M ≤ 2*105
// -1000 ≤ value ≤ 1000

// View Bookmarked Problems

class Solution
{
public:
    int intersectPoint(Node *head1, Node *head2)

    {

        int len1 = 0, len2 = 0;

        Node *temp1 = head1, *temp2 = head2;

        while (temp1)
        {

            len1++;

            temp1 = temp1->next;
        }

        while (temp2)
        {

            len2++;

            temp2 = temp2->next;
        }

        temp1 = head1, temp2 = head2;

        if (len1 > len2)
        {

            for (int i = 0; i < len1 - len2; i++)

                temp1 = temp1->next;
        }
        else
        {

            for (int i = 0; i < len2 - len1; i++)

                temp2 = temp2->next;
        }

        while (temp1 != temp2)
        {

            temp1 = temp1->next;

            temp2 = temp2->next;
        }

        return temp1->data;
    }
};
