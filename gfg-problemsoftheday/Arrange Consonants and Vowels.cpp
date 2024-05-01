// Arrange Consonants and Vowels
// MediumAccuracy: 49.98%Submissions: 17K+Points: 4
//  Done with winning Geekbits? Now win GfG Bag, GfG T-shirt & much more just by writing your experiences. Start Writing, Start Winning.
// banner
// Given a singly linked list having n nodes containing english alphabets ('a'-'z'). Rearrange the linked list in such a way that all the vowels come before the consonants while maintaining the order of their arrival.

// Example 1:

// Input:
// n = 9
// linked list: a -> b -> c -> d -> e -> f -> g -> h -> i
// Output:
// a -> e -> i -> b -> c -> d -> f -> g -> h
// Explanation:
// After rearranging the input linked list according to the condition the resultant linked list will be as shown in output.
// Example 2:

// Input:
// n = 8
// linked list: a -> b -> a -> b -> d -> e -> e -> d
// Output:
// a -> a -> e -> e -> b -> b -> d -> d
// Explanation:
// After rearranging the input linked list according to the condition the resultant linked list will be as shown in output.
// Your Task:
// Your task is to complete the function arrangeCV(), which takes head of linked list and arranges the list in such a way that all the vowels come before the consonants while maintaining the order of their arrival and returns the head of the updated linked list.

// Expected Time Complexity :  O(n)
// Expected Auxiliary Space :  O(1)

// Constraints:
// 1 <= n <= 104
// 'a' <= elements of linked list <= 'z'

class Solution
{
public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node *arrangeCV(Node *head)
    {
        // Code here
        struct Node *dummy = new Node(-1);
        struct Node *dummy1 = new Node(-1);
        struct Node *tmp = dummy;
        struct Node *tmp1 = dummy1;
        struct Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data - 'a' == 0 || temp->data - 'a' == 4 || temp->data - 'a' == 8 || temp->data - 'a' == 14 || temp->data - 'a' == 20)
            {
                struct Node *newNode = new Node(temp->data);
                tmp->next = newNode;
                tmp = tmp->next;
            }
            else
            {
                struct Node *nNode = new Node(temp->data);
                tmp1->next = nNode;
                tmp1 = tmp1->next;
            }
            temp = temp->next;
        }
        tmp->next = dummy1->next;
        return dummy->next;
    }
};
