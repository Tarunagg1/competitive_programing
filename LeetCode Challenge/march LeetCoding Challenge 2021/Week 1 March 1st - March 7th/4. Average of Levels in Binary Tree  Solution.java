/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List < Double > averageOfLevels(TreeNode root) {
        List < Double > result = new ArrayList < > ();
        Queue < TreeNode > q = new LinkedList < > ();
        q.add(root);
        while (!q.isEmpty()) {
            int count = q.size();
            int size = count;
            double curr = 0;
            while (count != 0) {
                TreeNode temp = q.remove();
                curr += (double) temp.val;
                if (temp.left != null)
                    q.add(temp.left);
                if (temp.right != null)
                    q.add(temp.right);
                count--;
            }
            result.add(curr / size);
        }
        return result;
    }
}