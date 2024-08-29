// Find length of Loop
// Difficulty: EasyAccuracy: 44.26%Submissions: 174K+Points: 2
// Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return 0.

// Note: 'c' is the position of the node which is the next pointer of the last node of the linkedlist. If c is 0, then there is no loop.

// Examples:

// Input: LinkedList: 25->14->19->33->10->21->39->90->58->45, c = 4
// Output: 7
// Explanation: The loop is from 33 to 45. So length of loop is 33->10->21->39-> 90->58->45 = 7.
// The number 33 is connected to the last node of the linkedlist to form the loop because according to the input the 4th node from the beginning(1 based indexing)
// will be connected to the last node for the loop.

// Input: LinkedList: 5->4, c = 0
// Output: 0
// Explanation: There is no loop.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= no. of nodes <= 106
// 0 <= node.data <=106
// 0 <= c<= n-1

class Solution
{
public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head)
    {
        // Code here
        Node *slow = head;
        Node *fast = head;
        bool loop = false;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                loop = true;
                break;
            }
        }

        if (loop)
        {
            int cnt = 1;
            slow = slow->next;
            fast = fast->next->next;
            while (slow != fast)
            {
                cnt++;
                slow = slow->next;
                fast = fast->next->next;
            }
            return cnt;
        }
        return 0;
    }
};
