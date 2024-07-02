// linked list of strings forms a palindrome
// Difficulty: EasyAccuracy: 58.6%Submissions: 25K+Points: 2
// Given a linked list with string data, check whether the combined string formed is palindrome. If the combined string is palindrome then return true otherwise return false.

// Example:

// Input:

// Output : true
// Explanation: As string "abcddcba" is palindrome the function should return true.
// Input:

// Output : false
// Explanation: As string "abcdba" is not palindrome the function should return false.
// Expected Time Complexity:  O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= Node.data.length<= 103
// 1<=list.length<=103



class Solution {
  public:
    bool compute(Node* head) {
        // Your code goes here
          string ans="";
        Node* temp=head;
        while(temp){
            ans+=temp->data;
            temp=temp->next;
        }
        int i=0,j=ans.length()-1;
        while(i<=j){
            if(ans[i]!=ans[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};