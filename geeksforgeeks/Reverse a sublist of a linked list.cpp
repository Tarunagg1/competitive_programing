// Reverse a sublist of a linked list 
// Hard Accuracy: 78.42% Submissions: 3837 Points: 8
// Given a linked list and positions m and n. Reverse the linked list from position m to n.

// Example 1:

// Input :
// N = 10
// Linked List = 1->7->5->3->9->8->10
//                       ->2->2->5->NULL
// m = 1, n = 8
// Output : 2 10 8 9 3 5 7 1 2 5 
// Explanation :
// The nodes from position 1 to 8 
// are reversed, resulting in 
// 2 10 8 9 3 5 7 1 2 5.

// Example 2:

// Input:
// N = 6
// Linked List = 1->2->3->4->5->6->NULL
// m = 2, n = 4
// Output: 1 4 3 2 5 6
// Explanation:
// Nodes from position 2 to 4 
// are reversed resulting in
// 1 4 3 2 5 6.
// Your task :
// You don't need to read input or print anything. Your task is to complete the function reverseBetween() which takes the head of the linked list and two integers m and n as input and returns the head of the new linked list after reversing the nodes from position m to n.
 
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)
 
// Constraints:
// 1<=N<=10^5
// View Bookmarked Problems
// Company Tags





class Solution
{
    public:
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
        stack<int>s;
       Node *curr = head;
       for(int i=1;i<m;i++)
       {
           curr = curr->next;
       }
       for(int i=m-1;i<n;i++)
       {
          s.push(curr->data);
          curr = curr->next;
       }
       Node*curr2,*res;
       if(m==1){
           
       res = new Node(s.top());
        curr2 = res;
       s.pop();}
       else{
           res = head;
       curr2 = res;
           for(int i=1;i<m-1;i++)
           {
               res->next = head->next;
               res = res->next;
               head = head->next;
           }
       }
       while(s.empty()==false)
       {
           res->next = new Node(s.top());
           res = res->next;
           s.pop();
       }
       res->next = curr;
       
       return curr2;
    }
};


































