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
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode p = dummy;
        while(p != null && p.next !=null && p.next.next != null) {
            ListNode t = p.next;
            p.next = t.next;
            t.next = t.next.next;
            p.next.next = t;
            p = t;
        }
        return dummy.next;
    }
}