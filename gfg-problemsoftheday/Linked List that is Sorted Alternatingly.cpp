// Linked List that is Sorted Alternatingly
// MediumAccuracy: 33.67%Submissions: 30K+Points: 4
// Share your experience with the world! Submit your admission, interview, campus or any other experience and reach an audience of millions today!

// banner
// You are given a Linked list of size n. The list is in alternating ascending and descending orders. Sort the given linked list in non-decreasing order.

// Example 1:

// Input:
// n = 6
// LinkedList = 1->9->2->8->3->7
// Output: 1 2 3 7 8 9
// Explanation:
// After sorting the given list will be 1->2->3->7->8->9.
// Example 2:

// Input:
// n = 5
// LinkedList = 13->99->21->80->50
// Output: 13 21 50 80 99
// Explanation:
// After sorting the given list will be 13->21->50->80->99.
// Your Task:
// You do not need to read input or print anything. The task is to complete the function sort() which should sort the linked list of size n in non-decreasing order.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= Number of nodes <= 100
// 0 <= Values of the elements in linked list <= 103

class Solution
{
public:
    // your task is to complete this function
    void sort(Node **head)
    {
        // Code here
        if ((*head) == NULL || (*head)->next == NULL)
            return;

        vector<int> v;
        Node *temp = *head;
        while (temp)
        {
            int val = temp->data;
            v.push_back(val);
            temp = temp->next;
        }

        std::sort(v.begin(), v.end());

        //   for(int i=0;i<v.size();i++){
        //       cout<<v[i]<<" ";
        //   }
        //   cout<<endl;

        temp = *head;
        for (int i = 0; i < v.size(); i++)
        {
            temp->data = v[i];
            temp = temp->next;
        }
    }
};
