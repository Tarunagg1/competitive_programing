// Multiply two linked lists
// Difficulty: EasyAccuracy: 46.33%Submissions: 62K+Points: 2
// Given elements as nodes of the two singly linked lists. The task is to multiply these two linked lists, say L1 and L2.

// Note: The output could be large take modulo 10^9+7.

// Examples :

// Input: LinkedList L1 : 3->2 , LinkedList L2 : 2
// Output: 64
// Explanation:

// Multiplication of 32 and 2 gives 64.
// Input: LinkedList L1: 1->0->0 , LinkedList L2 : 1->0
// Output: 1000
// Explanation:

// Multiplication of 100 and 10 gives 1000.
// Expected Time Complexity: O(max(n,m))
// Expected Auxilliary Space: O(1)
// where n is the size of L1 and m is the size of L2

// Constraints:
// 1 <= number of nodes <= 105
// 1 <= node->data <= 103

const int c = 1e9 + 7;

long long convert(Node *x)
{
    long long ans = 0;
    Node *temp = x;
    while (temp)
    {
        ans = ((ans * 10) % c + (temp->data) % c) % c;
        temp = temp->next;
    }
    return ans % c;
}
class solution
{
public:
    long long multiplyTwoLists(Node *first, Node *second)
    {
        long long x = convert(first);
        long long y = convert(second);
        long long ans = (x * y) % c;
    }
};
