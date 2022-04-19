// Partition a Linked List around a given value 
// Medium Accuracy: 66.89% Submissions: 7453 Points: 4
// Given a linked list and a value x, partition it such that all nodes less than x come first, then all nodes with value equal to x and finally nodes with value greater than or equal to x. The original relative order of the nodes in each of the three partitions should be preserved. The partition must work in-place.
 
// Example 1:
// Input:
// 1->4->3->2->5->2->3,
// x = 3
// Output:
// 1->2->2->3->3->4->5
// Explanation: 
// Nodes with value less than 3 come first, 
// then equal to 3 and then greater than 3.
// Example 2:
// Input:
// 1->4->2->10 
// x = 3
// Output: 
// 1->2->4->10
// Explanation:
// Nodes with value less than 3 come first,
// then equal to 3 and then greater than 3.
// Your task:
// You don't need to read input or print anything. Your task is to complete the function partition() which takes the head of the inked list and an integer x as input, and returns the head of the modified linked list after arranging the values according to x.
 
// Expected time complexity : O(n)
// Expected Auxiliary Space: O(n)
 
// Constraints:
// 1 <= N <= 105
// 1 <= k <= 105
// View Bookmarked Problems
// Company Tags
// Topic Tags
// Related Courses
// We are replacing the old Disqus forum with the new Discussions section given below.
// Click here to view old Disqus comments.






struct Node* partition(struct Node* head, int x) {
    // code here
    
    vector<int> a,b,c;
    Node *itr=head;
    while(itr!=NULL)
    {
        if(itr->data==x)
        b.push_back(itr->data);
        if(itr->data<x)
        a.push_back(itr->data);
        if(itr->data>x)
        c.push_back(itr->data);
        itr=itr->next;
    }
    Node *it2=head;
    for(int i=0;i<a.size();i++)
    {
        it2->data=a[i];
        it2=it2->next;
    }
     for(int i=0;i<b.size();i++)
    {
        it2->data=b[i];
        it2=it2->next;
    }
     for(int i=0;i<c.size();i++)
    {
        it2->data=c[i];
        it2=it2->next;
    }
    return head;
}



















