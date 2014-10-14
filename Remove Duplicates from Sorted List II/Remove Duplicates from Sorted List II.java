/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return head;
        ListNode dummy = new ListNode(0);
        ListNode node = dummy;
        dummy.next = head;
        while (node.next != null && node.next.next != null) {
            if (node.next.val == node.next.next.val) {
                int val = node.next.val;
                ListNode tmp = node;
                while (tmp.next != null && tmp.next.val == val) tmp = tmp.next;
                node.next = tmp.next;
            } else node = node.next;
        }
        return dummy.next;
    }
}