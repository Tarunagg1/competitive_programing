// 876. Middle of the Linked List
// Easy

// 3626

// 97

// Add to List

// Share
// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

 

// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.
// Example 2:


// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

// Constraints:

// The number of nodes in the list is in the range [1, 100].
// 1 <= Node.val <= 100
// Accepted
// 441,776
// Submissions
// 624,546



/// code Method 1

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode *temp = head;
        
        while(temp != NULL){
             count++;
             temp = temp->next;
         }
        
         count = count / 2;
         ListNode *ans = head;
        
        int i =0;
        
        while(i<=count){
            ans =head;
            head = head->next;
            i++;
        }
        return ans;
    }
};

/// code Method 2

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> v = {head};
        while(v.back()->next != NULL){
            v.push_back(v.back()->next);
        }
        return v[(int)v.size()/2];
    }
};
























