// QuickSort on Doubly Linked List
// HardAccuracy: 66.72%Submissions: 9086Points: 8
// Sort the given doubly linked list of size N using quicksort. Just complete the partition function using the quicksort technique.

// Example 1:

// Input:
// LinkedList: 4->2->9
// Output:
// 2 4 9
// Explaination: After sorting output will look like this.

// Example 2:
// Input:
// LinkedList: 1->4->9->2
// Output:
// 1 2 4 9
// Explaination: After sorting output will look like this.

// Your Task:
// Your task is to complete the given function partition(), which accepts the first and last node of the given linked list as input parameters and returns the pivot's address.

// Expected Time Complexity: O(NlogN)
// Expected Auxilliary Space: O(1)

// Constraints:
// 1 <= N <= 2000
// 1 <= Each Element of Double Linked List <= 105

// View Bookmarked Problems

class Solution
{
public:
    Node *partition(Node *l, Node *h)
    {
        // Your code goes here
        Node *pivot = l;
        Node *i = l, *j = h;
        bool flag = false;

        while (!flag)
        {
            while (i != NULL && i->data <= pivot->data)
            {
                if (i == j)
                    flag = true;
                i = i->next;
            }

            while (j != NULL && j->data > pivot->data)
            {
                if (i == j)
                    flag = true;
                j = j->prev;
            }

            if (!flag)
                swap(i->data, j->data);
        }

        if (flag)
        {
            swap(pivot->data, j->data);
        }

        return j;
    }
};
