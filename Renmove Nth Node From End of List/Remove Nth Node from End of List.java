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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode p = head;
        ListNode q = head;
        for (int i = 0; i < n; ++i) {
            if (q != null) q = q.next;
            else break;
        }
        if (q == null) return head.next; // remove head
        while (q.next != null) {
            p = p.next;
            q = q.next;
        }
        if (p.next != null) p.next = p.next.next; // not remove the tail
        return head;
    }
}