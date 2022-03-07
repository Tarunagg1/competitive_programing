// Merge K sorted linked lists 
// Medium Accuracy: 41.42% Submissions: 43671 Points: 4
// Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

// Example 1:

// Input:
// K = 4
// value = {{1,2,3},{4 5},{5 6},{7,8}}
// Output: 1 2 3 4 5 5 6 7 8
// Explanation:
// The test case has 4 sorted linked 
// list of size 3, 2, 2, 2
// 1st    list     1 -> 2-> 3
// 2nd   list      4->5
// 3rd    list      5->6
// 4th    list      7->8
// The merged list will be
// 1->2->3->4->5->5->6->7->8.
// Example 2:

// Input:
// K = 3
// value = {{1,3},{4,5,6},{8}}
// Output: 1 3 4 5 6 8
// Explanation:
// The test case has 3 sorted linked
// list of size 2, 3, 1.
// 1st list 1 -> 3
// 2nd list 4 -> 5 -> 6
// 3rd list 8
// The merged list will be
// 1->3->4->5->6->8.
// Your Task:
// The task is to complete the function mergeKList() which merges the K given lists into a sorted one. The printing is done automatically by the driver code.

// Expected Time Complexity: O(nk Logk)
// Expected Auxiliary Space: O(k)
// Note: n is the maximum size of all the k link list

// Constraints
// 1 <= K <= 103

class Solution{
  public:
  
    Node* sMerge(Node* a,Node* b){
        Node* result = NULL;
        
        if(a == NULL) return (b);
        else if(b == NULL) return (a);
        
        if(a->data <= b->data){
            result = a;
            result->next = sMerge(a->next,b);
        }else{
            result = b;
            result->next = sMerge(a,b->next);
        }
        
        return result;
    }
    
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
         // Your code here
         int i=0; 
         int last = K-1;
         int j;
         
         while(last != 0){
            i=0;
            j=last;
            
            while(i<j){
                arr[i] = sMerge(arr[i],arr[j]);
                i++;
                j--;
                if(i>=j){
                    last = j;
                }
            }
         }
         return arr[0];
    }
};



































