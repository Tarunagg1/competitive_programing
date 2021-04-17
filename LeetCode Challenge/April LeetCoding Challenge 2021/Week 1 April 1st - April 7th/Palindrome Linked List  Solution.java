/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null){
            return true;
        }
        int len = 0;
        ListNode slow=head;
        while(slow != null){
            len++;
            slow=slow.next;
        }
        int arr[] = new int[len/2];
        arr[0] = head.val;
        ListNode  fast =head;
        slow=head;
         int i=1;
          while(fast.next!=null && fast.next.next!=null){
            slow=slow.next;
            if(i<arr.length)
            arr[i++] = slow.val;
            fast= fast.next.next;
          }
         i = arr.length - 1;
          slow = slow.next;
            while(slow!=null){
              if(arr[i--] != slow.val)
                return false;
              slow=slow.next;

            }
          return true;
    }
}