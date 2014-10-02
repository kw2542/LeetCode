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
    public ListNode rotateRight(ListNode head, int n) {
        if (head == null || n == 0) return head;
        ListNode fast = head;
        ListNode node = head;
        int count = 1;
        while (node.next != null) {
            count++;
            node = node.next;
        }
        node.next = head;
        node = head;
        n = n % count;
        for (int i = 0; i <= n; ++i) fast = fast.next;
        
        while (fast != head) {
            fast = fast.next;
            node = node.next;
        }
        ListNode newHead = node.next;
        node.next = null;
        return newHead;
    }
}